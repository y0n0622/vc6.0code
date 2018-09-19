// netDemo.cpp : Defines the entry point for the console application.
//这是一个简单的服务端，用来接收客户端发送过来的字符串

#include "stdafx.h"
#include "Winsock2.h"
#pragma comment(lib, "Ws2_32.lib")
int main(int argc, char* argv[])
{
	WSADATA wsd;
	SOCKET sServer;
	SOCKET sClient;
	int retVal;

	if(WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		printf("WSAStartup filed!\n");
		return 1;
	}

	sServer = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(INVALID_SOCKET == sServer)
	{
		printf("socket filed!");
		WSACleanup();
		return -1;
	}

	SOCKADDR_IN addrServ;
	addrServ.sin_family = AF_INET;
	addrServ.sin_port = htons(4999);
	addrServ.sin_addr.s_addr = INADDR_ANY;

	retVal = bind(sServer, (LPSOCKADDR)&addrServ, sizeof(SOCKADDR_IN));
	if(SOCKET_ERROR == retVal)
	{
		printf("bind filed!\n");
		closesocket(sServer);
		WSACleanup();
		return -1;
	}
	printf("开始监听。。。\n");
	retVal = listen(sServer, 20);
	if(SOCKET_ERROR == retVal)
	{
		printf("listen filed!\n");
		closesocket(sServer);
		WSACleanup();
		return -1;
	}

	sockaddr_in addrClient;
	int addrClientlen = sizeof(addrClient);
	sClient = accept(sServer, (sockaddr FAR*)&addrClient, &addrClientlen);
	if(INVALID_SOCKET == sClient)
	{
		printf("accept filed!\n");
		closesocket(sServer);
		WSACleanup();
		return -1;
	}
	
	char buf[256] = "\0";
    retVal = recv(sClient, buf, sizeof(buf), 0);
	if(SOCKET_ERROR == retVal)
	{
		printf("recv filed!\n");
		closesocket(sServer);
		closesocket(sClient);
		WSACleanup();
		return -1;
	}
	printf("%s\n", buf);

	closesocket(sServer);
	closesocket(sClient);
	WSACleanup();
	return 0;
}

