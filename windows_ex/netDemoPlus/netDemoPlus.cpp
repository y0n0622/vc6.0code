// netDemoPlus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Winsock2.h"
#pragma comment(lib, "Ws2_32.lib")
#define SERVER_DLL_ERROR -1
#define SERVER_API_ERROR 0
#define SERVER_PORT	5555

char *bufRecv;
char bufSend[256];
SOCKET sServer;
SOCKET sClient;
BOOL bConning;

void InitMember()
{
	memset(bufRecv, 0, sizeof(bufRecv));
	memset(bufSend, 0, sizeof(bufSend));

	sServer = INVALID_SOCKET;
	sClient = INVALID_SOCKET;

	bConning = FALSE;

}

void ShowSocketMsg(char msg[])
{		
		printf(msg);
}

int HandleSocketError(char *str)
{
	ShowSocketMsg(str);
	WSACleanup();
	return SERVER_API_ERROR;
	
}
int InitSocketDll()
{
	WORD wVersionRequested;
	WSADATA wsaData;

	wVersionRequested = MAKEWORD(1, 1);
	int retVal = WSAStartup(wVersionRequested, &wsaData);
	if(0 != retVal)
	{
		ShowSocketMsg("can not use socket dll!\n");
		return SERVER_DLL_ERROR;
	}

	if(LOBYTE(wsaData.wVersion) != 1 || HIBYTE(wsaData.wVersion) != 1)
	{
		ShowSocketMsg("can not use socket dll!\n");
		WSACleanup();
		return SERVER_DLL_ERROR;
	}
	return retVal;
	
}

SOCKET CreateSocket()
{
	SOCKET s;
	s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(INVALID_SOCKET == sServer)
	{
		return HandleSocketError("Failed Socket()!");
	}
	return s;
}

int BindSocket(SOCKET sServer)
{
	SOCKADDR_IN addrServ;
	addrServ.sin_family = AF_INET;
	addrServ.sin_port = htons(SERVER_PORT);
	addrServ.sin_addr.s_addr = INADDR_ANY;
	int retVal = bind(sServer, (LPSOCKADDR)&addrServ, sizeof(SOCKADDR_IN));
	if(SOCKET_ERROR == retVal)
	{
		closesocket(sServer);
		return HandleSocketError("failed bind()!");
	}
	return retVal;
}

int ListenSocket(SOCKET sServer)
{
	int retVal = listen(sServer, 1);
	if(SOCKET_ERROR == retVal)
	{
		closesocket(sServer);
		return HandleSocketError("failed listen()!");
	}
	cout << "Server succeeded!" << endl;
	cout << "Waiting for new client ...." << endl;
	return retVal;
}

SOCKET AcceptSocket(SOCKET sServer)
{
	sockaddr_in addrClient;
	int addrClientLen = sizeof(addrClient);
	sClient = accept(sServer, (sockaddr FAR*)&addrClient, &addrClientLen);
	if(INVALID_SOCKET == sClient)
	{
		closesocket(sServer);
		return HandleSocketError("failed accept()!");
	}
	else
	{
		bConning = TRUE;
	}

	char *pClientIP = inet_ntoa(addrClient.sin_addr);
	u_short clientPort = ntohs(addrClient.sin_port);
	cout << "Accept a client " << endl;
	cout << "IP:" << pClientIP << endl;
	cout << "Port:" << clientPort << endl;
	
	return sClient;
}
/*

	char buf[256] = "\0";
    retVal = recv(sClient, buf, sizeof(buf), 0);
	printf("%s\n", buf);
*/
char* RecvLine(SOCKET sClient, char *buf)
{
	BOOL retVal = TRUE;
	BOOL bLineEnd = FALSE;
	int nReadLen = 0;
	int nDataLen = 0;
	while(!bLineEnd && bConning)
	{
		nReadLen = recv(sClient, buf + nDataLen, 1, 0);

		if(SOCKET_ERROR == nReadLen)
		{
			int nErrCode = WSAGetLastError();
			if(WSAENOTCONN == nErrCode)
			{
				ShowSocketMsg("the socket is not connected!");
			}
			else if(WSAESHUTDOWN == nErrCode)
			{
				ShowSocketMsg("the socket has been shut down!");
			}
			else if(WSAETIMEDOUT == nErrCode)
			{
				ShowSocketMsg("the socket has been dropped!");
			}
			else if(WSAECONNRESET == nErrCode)
			{
				ShowSocketMsg("the virtual circuit was reset by the remote side!");
			}
			else
			{
				
			}
			retVal = FALSE;
			break;
		}

		if(0 == nReadLen)
		{
			retVal = FALSE;
			break;	
		}

		if('\n' == *(buf + nDataLen))
		{
			bLineEnd = TRUE;
		}
		else
		{
			nDataLen += nReadLen;
		}
	}
	return buf;
}

BOOL SendLine(SOCKET sClient, char *str)
{
	int retVal;
	retVal = send(sClient, str, strlen(str), 0);
	
	if(SOCKET_ERROR == retVal)
	{
		int nErrCode = WSAGetLastError();
		if(WSAENOTCONN == nErrCode)
		{
			ShowSocketMsg("the socket is not connected!");
		}
		else if(WSAESHUTDOWN == nErrCode)
		{
			ShowSocketMsg("the socket has been shut down!");
		}
		else if(WSAETIMEDOUT == nErrCode)
		{
			ShowSocketMsg("the socket has been dropped!");
		}
		else
		{
			
		}
		return FALSE;
	}
	return TRUE;
}

int ExitClient(int nEixt)
{
	closesocket(sServer);
	closesocket(sClient);
	WSACleanup();
	return nEixt;
}

int main(int argc, char* argv[])
{
	InitMember();

	if(0 == InitSocketDll())
	{
		ShowSocketMsg("InitSocketDll succeeded!");
	}
	else
	{
		ShowSocketMsg("InitSocketDll failed!");
	};

	sServer = CreateSocket();

	if(0 == BindSocket(sServer))
	{
		ShowSocketMsg("BindSocket succeeded!");
	}
	else
	{
		ShowSocketMsg("BindSocket failed!");
	};
	
	if(0 == ListenSocket(sServer))
	{
		ShowSocketMsg("ListenSocket succeeded!");
	}
	else
	{
		ShowSocketMsg("ListenSocket failed!");
	};
	
	sClient = AcceptSocket(sServer);
	
	bufRecv = RecvLine(sClient, bufRecv);
	printf("Client : %s\n", *bufRecv);
	
	strcpy(bufSend, "Hello, Client!\n");
	if(!SendLine(sClient, bufSend))
	{
		return ExitClient(SERVER_API_ERROR);
	}
	
	ExitClient(0);
	return 0;
}

