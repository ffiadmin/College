#define _CRT_SECURE_NO_WARNINGS
#pragma comment(lib, "Ws2_32.lib")

#include <algorithm>
#include <ctime>
#include <direct.h>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <winsock2.h>
#include <ws2tcpip.h>

#define SERVER_TCP_PORT 80

using namespace std;

int main (int argc, char **argv) {
	WSADATA wsa_data;

//Get CWD, thanks to: http://stackoverflow.com/a/145309/663604
	char cCurrentPath[FILENAME_MAX];

	if (!_getcwd(cCurrentPath, sizeof(cCurrentPath))) {
		cerr << "I don't know where I am. So disoriented..." << endl;

		return 1;
    }

	const string CWD = cCurrentPath;

//Initialize WinSock library (use version 2.0)
	if (WSAStartup(MAKEWORD(2, 0), &wsa_data) != 0) {
		cerr << "Error while initializing socket library" << endl;

		return 1;
	}
	
//Open a listening socket on the server
	int listen_sock = socket(AF_INET, SOCK_STREAM, 0);

	if (listen_sock < 0) {
		cerr << "Error while opening listening socket: " << WSAGetLastError() << endl;

		return 1;
	}

//Bind the server listening socket to the server TCP port number
	sockaddr_in server_addr;

	memset(&server_addr, 0, sizeof(sockaddr_in));
	server_addr.sin_family = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port = htons(SERVER_TCP_PORT);

	if (bind(listen_sock, (sockaddr*)&server_addr, sizeof(sockaddr_in)) != 0) {
		cerr << "Error while binding server socket to port "
			 << SERVER_TCP_PORT << ": " << WSAGetLastError() << endl;

		closesocket(listen_sock);
	    return 1;
	}

//Start listening for client connections on the server listening socket
	if (listen(listen_sock, 1024) != 0) {
		cerr << "Error while initializing listening socket: " << WSAGetLastError() << endl;

		closesocket(listen_sock);
		return 1;
	}

//Wait for and accept client connection
	sockaddr_in client_addr;
	memset(&client_addr, 0, sizeof(sockaddr_in));
	socklen_t addr_len = sizeof(sockaddr_in);
	int comm_sock = accept(listen_sock, (sockaddr *) &client_addr, &addr_len);

	cout << "Waiting for client connections..." << endl;
	
	if (comm_sock < 0) {
		cerr << "Error while accepting client connection: " << WSAGetLastError() << endl;

		closesocket(listen_sock);
		return 1;
	}

	cout << "Accepted connection from IP address " << inet_ntoa(client_addr.sin_addr)
		 << ", TCP port " << ntohs(client_addr.sin_port) << endl;

//Receive message from client
	string msg_recvd;
	char msg_buf[1024];
	memset(msg_buf, 0, sizeof(msg_buf));
	int bytes_recvd = recv(comm_sock, msg_buf, sizeof(msg_buf), 0);

	if (bytes_recvd < 0) {
		cerr << "Error while receiving data from client: " << WSAGetLastError() << endl;
		closesocket(comm_sock);
		closesocket(listen_sock);
		return 1;
	}

	msg_recvd.append(msg_buf, bytes_recvd);
	cout << "Received message from client: " << msg_recvd.c_str() << endl;

//Parse the request file name
	vector<string> result;
    size_t pos = 0, lastPos = 0;

    while ((pos = msg_recvd.find_first_of(" \n", lastPos)) != string::npos) {
        result.push_back(msg_recvd.substr(lastPos, pos-lastPos+1));
        lastPos = pos+1;
    }

    result.push_back(msg_recvd.substr(lastPos));

//Get the request string and replace all of the / with "\"
	string request = result[1];
	replace(request.begin(), request.end(), '/', '\\');
	request = request.substr(0, request.size() - 1);

//Extract the HTTP version
	string HTTPVersion = result[2];
	pos = HTTPVersion.find_first_of("\r\n");
	HTTPVersion.erase(pos, HTTPVersion.size() - pos);

//Get the file
	string line;
	stringstream out;
	string response = "200 OK";
	ifstream fin;
	string dir;

	if (request == "\\") {
		dir = CWD + "\\index.html";
	} else {
		dir = CWD + request;
	}

	fin.open(dir);

//Generate the content length
	fin.seekg(0, fin.end);
    int length = fin.tellg();
	fin.seekg(0, fin.beg);

	if (fin.fail()) {
		response = "404 Not Found";
		length = 0;
	} else {
		while (getline(fin, line)) {
			out << line << "\r\n";
		}
	}

	fin.close();

//Generate the time
	/*time_t now = time(0);
	char buf[80];
	tm *GMT = gmtime(&now);

	strftime(buf, 80, "%a, %d %b %Y %H:%M:%S", GMT);
	puts (buf);*/

//Begin building the header and body
	stringstream header;
	header << HTTPVersion << " " << response << "\r\n";
	header << "Connection: close\r\n";
	//header << "Date: " << buf << " GMT\r\n";
	//header << "Server: Spryn-Gearhart/1.0.0\r\n";
	//header << "Content-Type: text/html\r\n";
	//header << "Content-Length: " << out.str().size() * sizeof(out.str().c_str()) << "\r\n";
	header << "Content-Length: " << length << "\r\n";
	//header << "X-Powered-By: Awesome\r\n";
	header << "\r\n";
	header << out.str();

	string msg_to_send = header.str();
	cout << "Sending message to client: " << msg_to_send << endl;

	// send message to server
	// send data repeatedly until the whole message has been sent
	size_t total_sent = 0;
	while (total_sent < msg_to_send.length()) {
		int bytes_sent = send(comm_sock, msg_to_send.c_str() + total_sent, msg_to_send.length() - total_sent, 0);
		if (bytes_sent < 0) {
			cerr << "Error while sending message to client: " << WSAGetLastError() << endl;
			closesocket(comm_sock);
			closesocket(listen_sock);
			return 1;
		}
		else if (bytes_sent == 0) {
			cerr << "Client unexpectedly terminated the connection." << endl;
			closesocket(comm_sock);
			closesocket(listen_sock);
			return 1;
		}

		total_sent += bytes_sent;
	}

//Close listening and communication socket
	closesocket(comm_sock);
	closesocket(listen_sock);

//Clean up WinSock library
	WSACleanup();

	cout << "Press any key to close server..." << endl;
	cin.ignore(1);

	return 0;
}