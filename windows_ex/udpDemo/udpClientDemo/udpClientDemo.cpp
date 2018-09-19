// udpClientDemo.cpp : Defines the entry point for the console application.
//UDP¿Í»§¶Ë

#include "stdafx.h"
#include "Winsock2.h"
#pragma comment(lib, "Ws2_32.lib")
int main(int argc, char* argv[])
{
	WSADATA wsd;
	SOCKET s;

	if(WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		printf("WSAStartup failed!\n");
		return -1;
	}

	s = socket(AF_INET, SOCK_DGRAM, 0);
	if(INVALID_SOCKET == s)
	{
		printf("socket failed %d\n", WSAGetLastError());
		return -1;
	}
	char buf[256];
	strcpy(buf, "myudp");
	
	SOCKADDR_IN servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servAddr.sin_port = htons((short)5000);
	int nServAddlen = sizeof(servAddr);

	if(SOCKET_ERROR == sendto(s, buf, sizeof(buf), 0, (SOCKADDR*)&servAddr, nServAddlen))
	{
		printf("recvfrom failed %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return -1;
	}

	closesocket(s);
	WSACleanup();
	getchar();
	return 0;
}

