#include <iostream>
#include <sstream>
#include <WS2tcpip.h>

#pragma comment (lib , "ws2_32.lib")

using namespace std; //

void main()
{
	//start winSock 
	WSAData data;
	WORD version = MAKEWORD(2, 2);

	int wsOk = WSAStartup(version, &data);

	if (wsOk != 0) {

		cout << " Can't Start WinSock " << wsOk;
		return;
	}

	// bind socket to ip 
	//inet ipv4
	SOCKET	in = socket(AF_INET, SOCK_DGRAM, 0);

	//initialize socketaddress structure 
	sockaddr_in serverHint;
	serverHint.sin_addr.S_un.S_addr = ADDR_ANY;
	serverHint.sin_family = AF_INET;

	serverHint.sin_port = htons(54000); // Convert from little to big endian //port pc 

	//assign address to socket 

	if (bind(in, (sockaddr*)&serverHint, sizeof(serverHint)) == SOCKET_ERROR)
	{
		cout << "Can't bind socket!" << WSAGetLastError() << endl;
		return;
	}

	//client 
	sockaddr_in client;
	int clientLength = sizeof(client);
	ZeroMemory(&client, clientLength);

	//buffer 

	char buf[1024];

	//enter loop 
		//wait for request 
		// send temperature 
		//wait for a second

	//initialize connection

		//free up the buffer
	ZeroMemory(buf, 1024);

	//wait for request from client
	//in socket
	int bytesIn = recvfrom(in, buf, 1024, 0, (sockaddr*)&client, &clientLength);

	if (bytesIn == SOCKET_ERROR) {
		cout << "Error receiving request from client " << WSAGetLastError() << endl;
	}

	char clientIp[256];
	ZeroMemory(clientIp, 256);

	inet_ntop(AF_INET, &client.sin_addr, clientIp, 256);

	cout << "Request received from " << clientIp << endl;

	std::string s = std::to_string(50);
	char const* pchar = s.c_str();  //use char const* as target type

	while (true) {

		int sendOk = sendto(in, pchar, sizeof(pchar) + 1, 0, (sockaddr*)&client, sizeof(client));

		if (sendOk == SOCKET_ERROR) {
			cout << WSAGetLastError() << endl;
		}
		Sleep(1000);
	}


	//Close Socket 

	closesocket(in);

	//Shutdown WinSock 

	WSACleanup();

}