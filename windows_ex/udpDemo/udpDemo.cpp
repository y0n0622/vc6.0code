// udpDemo.cpp : Defines the entry point for the console application.
//UDP·þÎñ¶Ë

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
		printf("socket failed! %d \n", WSAGetLastError());
		WSACleanup();
		return -1;
	}

	SOCKADDR_IN servAddr;
	servAddr.sin_family = AF_INET;
	servAddr.sin_port = htons((short)5000);
	servAddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if(SOCKET_ERROR == bind(s, (SOCKADDR *)&servAddr, sizeof(servAddr)))
	{
		printf("bind failed! %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return -1;
	}

	char buf[256];
	SOCKADDR_IN clientAddr;
	int nClientLen = sizeof(clientAddr);
	if(SOCKET_ERROR == recvfrom(s, buf, sizeof(buf), 0, (SOCKADDR*)&clientAddr, &nClientLen))
	{
		printf("recvfrom failed! %d\n", WSAGetLastError());
		closesocket(s);
		WSACleanup();
		return -1;
	}

	printf("%s\n", buf);

	closesocket(s);
	WSACleanup();

	return 0;
}

