/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#include "ns3/core-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/network-module.h"
#include "ns3/applications-module.h"
#include "ns3/wifi-module.h"
#include "ns3/mobility-module.h"
#include "ns3/internet-module.h"

#include <cmath>

using namespace ns3;
using namespace std;

NS_LOG_COMPONENT_DEFINE("ThirdScriptExample");

int main(int argc, char *argv[]) {
//Configuration
	bool verbose = true;
	uint32_t nWifi = 6;
        unsigned int radius = 20;
        int maxPackets = 8000;
        float interval = 0.02f;
        int packetSize = 1024;
        float startSec = 1.0f;
        float stopSec = 10.0f;
        char baseIP[] = "10.1.1.0";
        char baseSubNet[] = "255.255.255.0";

//Parse the command line arguments
	CommandLine cmd;
	cmd.AddValue("nWifi", "Number of wifi STA devices", nWifi);
	cmd.AddValue("verbose", "Tell echo applications to log if true", verbose);

	cmd.Parse(argc, argv);

//Perliminary setup
	if (nWifi > 18) {
		cout << "Number of wifi nodes " << nWifi << " specified exceeds the mobility bounding box" << endl;
		exit(1);
	}

	if (verbose) {
		LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
		LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);
	}

//Create the wireless access point node
	NodeContainer wifiApNode;
	wifiApNode.Create(1);

//Create the wireless nodes which will connect to the access point
	NodeContainer wifiStaNodes;
	wifiStaNodes.Create(nWifi);

//Set up wireless channels and helpers
	YansWifiChannelHelper channel = YansWifiChannelHelper::Default();
	YansWifiPhyHelper phy = YansWifiPhyHelper::Default();
	phy.SetChannel(channel.Create());

	WifiHelper wifi = WifiHelper::Default();
	wifi.SetRemoteStationManager("ns3::AarfWifiManager");

//Create a MAC address and SSID
	NqosWifiMacHelper mac = NqosWifiMacHelper::Default();
        Ssid ssid = Ssid("ns-3-ssid");

//Assign an SSID and MAC address to the nodes
	mac.SetType("ns3::StaWifiMac", "Ssid", SsidValue(ssid), "ActiveProbing", BooleanValue(false));

	NetDeviceContainer staDevices;
	staDevices = wifi.Install(phy, mac, wifiStaNodes);

//Assign an SSID and MAC address to the access point
	mac.SetType("ns3::ApWifiMac", "Ssid", SsidValue(ssid));

	NetDeviceContainer apDevices;
	apDevices = wifi.Install(phy, mac, wifiApNode);

//Set the mobility capibilities for each of the nodes
	MobilityHelper mobility;
	mobility.SetPositionAllocator (
                "ns3::GridPositionAllocator",
		"MinX",       DoubleValue(0.0),
		"MinY",       DoubleValue(0.0),
		"DeltaX",     DoubleValue(5.0),
		"DeltaY",     DoubleValue(10.0),
		"GridWidth",  UintegerValue(3),
		"LayoutType", StringValue("RowFirst")
        );

        mobility.SetMobilityModel("ns3::ConstantPositionMobilityModel");
	mobility.Install(wifiApNode);

        Ptr<ListPositionAllocator> initialAlloc = CreateObject<ListPositionAllocator>();
        float convert = M_PI / 180.0f;
        float circleStuff = (360.0f / static_cast<float>(nWifi)) * convert;
        float position = 0.0f;

        for (unsigned int i = 0; i < nWifi; ++i) {
                position = circleStuff * i;

                initialAlloc->Add(Vector(sin(position) * radius, cos(position) * radius, 0.));
        }

	mobility.SetPositionAllocator(initialAlloc);
	mobility.Install(wifiStaNodes);

//Install the access point and nodes into the Internet stack
	InternetStackHelper stack;
	stack.Install(wifiApNode);
	stack.Install(wifiStaNodes);

//Generate an IP address for the access point and nodes
	Ipv4AddressHelper address;
        Ipv4InterfaceContainer IPInterfacesAP;
        Ipv4InterfaceContainer IPInterfacesNode;
	address.SetBase(baseIP, baseSubNet);
        IPInterfacesAP = address.Assign(apDevices);
	IPInterfacesNode = address.Assign(staDevices);
	
//Create the servers
	ApplicationContainer serverApps;
        UdpEchoServerHelper echoServerAP(nWifi);
        serverApps.Add(echoServerAP.Install(wifiApNode.Get(0)));

        for (unsigned int i = 0; i < nWifi - 1; ++i) {
                UdpEchoServerHelper echoServer(i);
                serverApps.Add(echoServer.Install(wifiStaNodes.Get(i)));
        }

//Create the clients
        ApplicationContainer clientApps;

        UdpEchoClientHelper echoClientAP(IPInterfacesAP.GetAddress(0), 0);
        echoClientAP.SetAttribute ("MaxPackets", UintegerValue (maxPackets));
        echoClientAP.SetAttribute ("Interval", TimeValue (Seconds (interval)));
        echoClientAP.SetAttribute ("PacketSize", UintegerValue (packetSize));
        clientApps.Add(echoClientAP.Install(wifiApNode.Get(0))); 
        
        for (unsigned int i = 0; i < nWifi - 1; ++i) {
                UdpEchoClientHelper echoClient(IPInterfacesNode.GetAddress(i + 1), i + 1);
                echoClient.SetAttribute ("MaxPackets", UintegerValue (maxPackets));
                echoClient.SetAttribute ("Interval", TimeValue (Seconds (interval)));
                echoClient.SetAttribute ("PacketSize", UintegerValue (packetSize));

                clientApps.Add(echoClient.Install(wifiStaNodes.Get(i))); 
        }

        UdpEchoClientHelper echoClient(IPInterfacesNode.GetAddress(0), 0);
        echoClient.SetAttribute ("MaxPackets", UintegerValue (maxPackets));
        echoClient.SetAttribute ("Interval", TimeValue (Seconds (interval)));
        echoClient.SetAttribute ("PacketSize", UintegerValue (packetSize));
        clientApps.Add(echoClient.Install(wifiStaNodes.Get(nWifi - 1)));

//Release the hounds!
        serverApps.Start(Seconds(startSec));
	serverApps.Stop(Seconds(stopSec));

        clientApps.Start(Seconds(startSec));
	clientApps.Stop(Seconds(stopSec));

//Populate the routing tables
	Ipv4GlobalRoutingHelper::PopulateRoutingTables();

//Enable PCap ouput
	phy.EnablePcap("wireless", apDevices.Get(0), true);

        for (unsigned int i = 0; i < nWifi; ++i) {
                phy.EnablePcap("wireless", staDevices.Get(i), true);
        }

//Execute the simulator
	Simulator::Run();
	Simulator::Destroy();

	return 0;
}
