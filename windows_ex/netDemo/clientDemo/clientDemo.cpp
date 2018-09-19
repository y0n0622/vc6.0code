// clientDemo.cpp : Defines the entry point for the console application.
//一个简单的客户端，向服务端发送字符串

#include "stdafx.h"
#include "Winsock2.h"
#pragma comment(lib, "Ws2_32.lib")
#define BUF_SIZE 256
int main(int argc, char* argv[])
{

    WSADATA wsd;
	SOCKET sHost;
	SOCKADDR_IN servAddr;
	char buf[BUF_SIZE];
	int retVal;

	if(WSAStartup(MAKEWORD(2, 2), &wsd) != 0)
	{
		printf("WSAStarup failed!\n");
		return -1;
	}

	sHost = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(INVALID_SOCKET == sHost)
	{
		printf("socket failed!\n");
		WSACleanup();
		return -1;
	}

	servAddr.sin_family = AF_INET;
	servAddr.sin_addr.s_addr = inet_addr("127.0.0.1");
	servAddr.sin_port = htons((short)4999);
	int nServAddlen = sizeof(servAddr);

	retVal = connect(sHost, (LPSOCKADDR)&servAddr, sizeof(servAddr));
	if(SOCKET_ERROR == retVal)
	{
	    printf("connect failed!\n");
		closesocket(sHost);
		return -1;
	}

//	buf[256] = {"0"};
	strcpy(buf, "mytcp");
	retVal = send(sHost, buf, strlen(buf), 0);
	if(SOCKET_ERROR == retVal)
	{
		printf("send failed!\n");
		closesocket(sHost);
		WSACleanup();
		return -1;
	}

	closesocket(sHost);
	WSACleanup();
	getchar();
	return 0;
}

