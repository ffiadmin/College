#include "ns3/core-module.h"
#include "ns3/network-module.h"
#include "ns3/csma-module.h"
#include "ns3/internet-module.h"
#include "ns3/point-to-point-module.h"
#include "ns3/applications-module.h"
#include "ns3/ipv4-global-routing-helper.h"

// Default Network Topology
//
//       10.1.1.0
// n0 -------------- n1   n2   n3   n4
//    point-to-point  |    |    |    |
//                    ================
//                      LAN 10.1.2.0

using namespace ns3;

int main(int argc, char *argv[])
{
NS_LOG_COMPONENT_DEFINE ("SecondScriptExample");
bool verbose = true;
uint32_t nCsma = 6;

CommandLine cmd;
cmd.AddValue ("nCsma", "Number of \"extra\" CSMA nodes/devices", nCsma);
cmd.AddValue ("verbose", "Tell echo applications to log if true", verbose);

cmd.Parse (argc, argv);

if (verbose)
{
  LogComponentEnable("UdpEchoClientApplication", LOG_LEVEL_INFO);
  LogComponentEnable("UdpEchoServerApplication", LOG_LEVEL_INFO);
}

nCsma = nCsma == 0 ? 1 : nCsma;

NodeContainer csmaNodes;
csmaNodes.Create(nCsma);

CsmaHelper csma;
csma.SetChannelAttribute("DataRate", StringValue("10Mbps"));
csma.SetChannelAttribute("Delay", TimeValue(NanoSeconds(0)));

NetDeviceContainer csmaDevices;
csmaDevices = csma.Install(csmaNodes);

InternetStackHelper stack;
stack.Install(csmaNodes);

Ipv4AddressHelper address;
address.SetBase("10.1.2.0","255.255.255.0");
Ipv4InterfaceContainer csmaInterfaces;
//assigns ip addresses to all nodes in container
csmaInterfaces = address.Assign(csmaDevices);

ApplicationContainer serverApps;
ApplicationContainer clientApps;

for(unsigned int i = 0; i < nCsma; i++)
   {     
     UdpEchoServerHelper echoServer(i);
     serverApps.Add(echoServer.Install(csmaNodes.Get(i)));
   }

serverApps.Start(Seconds(1.0));
serverApps.Stop(Seconds(10.0));

//loops through and gives the client the server of the next node
 for(unsigned int i = 0; i < nCsma-1; i++)
   {
     UdpEchoClientHelper echoClient(csmaInterfaces.GetAddress(i+1),i+1);
     echoClient.SetAttribute ("MaxPackets", UintegerValue (8000));
     echoClient.SetAttribute ("Interval", TimeValue (Seconds (0.02)));
     echoClient.SetAttribute ("PacketSize", UintegerValue (1024));

     clientApps.Add(echoClient.Install(csmaNodes.Get(i))); 
   }

UdpEchoClientHelper echoClient(csmaInterfaces.GetAddress(0),0);
echoClient.SetAttribute ("MaxPackets", UintegerValue (8000));
echoClient.SetAttribute ("Interval", TimeValue (Seconds (0.02)));
echoClient.SetAttribute ("PacketSize", UintegerValue (1024));

clientApps.Add(echoClient.Install(csmaNodes.Get(nCsma-1))); 
 
clientApps.Start(Seconds(0.0));
clientApps.Stop(Seconds(10.0));

Ipv4GlobalRoutingHelper::PopulateRoutingTables();

 for(unsigned int i = 0; i < nCsma; i++)
   {
     csma.EnablePcap("bus",csmaDevices.Get(i),true);
   }

Simulator::Run();
Simulator::Destroy();
return 0;
}
