#pragma comment(lib,"Ws2_32.lib")

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, char *argv[])
{
	if(argc==1)
	{
		cout << "You at least need to specify a host name or ip";
		return 0;
	}
	string hostName = argv[1];
	string filePath = "";
	if(argc>2)
	{
		filePath = argv[2];
	}
	ofstream fout;
	fout.open("receivedFile.txt");
	WSADATA wsa_data;

	// Initialize WinSock library (use version 2.0)
	if (WSAStartup(MAKEWORD(2, 0), &wsa_data) != 0) {
		cerr << "Error while initializing socket library" << endl;
		return 1;
	}

	//get host information
	struct hostent *host;
	//hostName.c_str()
	host = gethostbyname(hostName.c_str());//change this to the host!

	if(host == 0)
	{
		cout << "host not found: " << WSAGetLastError();
		exit(1);
	}
	
	int serverPortTCP = 8080;
	
	//format like an http header
	//request file and get it back

	// Open the client socket
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	if (sock == -1) {
		cerr << "Error while opening client socket: " << WSAGetLastError() << endl;
		return 1;
	}

	// Set the IP address of the server host and the 
	// TCP port of the server application to connect to
	struct sockaddr_in server_addr;
	memset(&server_addr, 0, sizeof(sockaddr_in));
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(80);

	server_addr.sin_addr.s_addr = ((struct in_addr *)(host->h_addr))->s_addr;

	/*if (inet_pton(AF_INET,inet_ntoa( *( struct in_addr*)( host -> h_addr_list[0])) , &server_addr.sin_addr) == 0) {
		cerr << "Error while setting server IP address: " << WSAGetLastError() << endl;
		return 1;
	}*/

	// connect to the server application at the 
	// specified server IP address and TCP port number

	if (connect(sock, (sockaddr*)&server_addr, sizeof(sockaddr_in)) != 0) {
		cerr << "Error while connecting to server: " << WSAGetLastError() << endl;
		return 1;
	}

	string msg_to_send = "";

	//build http request
	//put file path
	if(argc>2)
	{
		msg_to_send = "GET /";
		msg_to_send += filePath;
		msg_to_send += " HTTP/1.0\r\n\r\n";
	}
	else
	{
		msg_to_send+="GET /index.html HTTP/1.0\r\n\r\n";
	}
	cout << "Sending message to server: " << msg_to_send.c_str() << endl;

	// send message to server
	// send data repeatedly until the whole message has been sent
	size_t total_sent = 0;
	while (total_sent < msg_to_send.length()) {
		int bytes_sent = send(sock, msg_to_send.c_str() + total_sent, msg_to_send.length() - total_sent, 0);
		if (bytes_sent < 0) {
			cerr << "Error while sending message: " << WSAGetLastError() << endl;
			closesocket(sock);
			return 1;
		}
		else if (bytes_sent == 0) {
			cerr << "Server unexpectedly terminated the connection." << endl;
			closesocket(sock);
			return 1;
		}

		total_sent += bytes_sent;
	}
	
	string msg_recvd;
	char msg_buf[1024];

	// receive message from server
	// try to receive data repeatedly until server application closes the connection
	while (1) {
		memset(msg_buf, 0, sizeof(msg_buf));
		int bytes_recvd = recv(sock, msg_buf, sizeof(msg_buf), 0);
		if (bytes_recvd < 0) {
			cerr << "Error while receiving message: " << WSAGetLastError() << endl;
			closesocket(sock);
			return 1;
		}
		else if (bytes_recvd == 0)
			break;

		msg_recvd.append(msg_buf, bytes_recvd);
	}
	//writing response to a file
	//make sure it is http and check error code
	//only output html

	int location = msg_recvd.find("\r\n\r\n");

	string header = msg_recvd.substr(0,location);
	string html = msg_recvd.substr(location,msg_recvd.length());

	vector<string> result;
	size_t pos = 0, lastPos = 0;
	int i = 0, start = 0;
	while ((pos = header.find_first_of(" \n", lastPos)) != string::npos) {
		if(header.substr(lastPos, pos-lastPos+1).c_str()=="Connection: ")
		{
			start = i;
		}
		result.push_back(header.substr(lastPos, pos-lastPos+1));
		lastPos = pos+1;
		i++;
	}

	fout << html;
	cout << "Received message from server, storing in file" << endl;

	// close socket and free TCP connection resources
	closesocket(sock);

	// Cleanup WinSock library
	WSACleanup();

	cout << "Press any key to close client..." << endl;
	cin.ignore(1);

	fout.close();

	return 0;
}