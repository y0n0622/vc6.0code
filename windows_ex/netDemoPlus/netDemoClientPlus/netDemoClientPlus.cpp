// netDemoClientPlus.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Winsock2.h"
#pragma comment(lib, "Ws2_32.lib")
#define CLIENT_SOCKET_DLL_ERROR -1
#define CLIENT_API_ERROR 0
#define MAX_NUM_BUF 256
#define SERVERPORT 5555
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
int InitSocketDll()
{
	WSADATA wsaData;
	WORD wVersionRequested;
	wVersionRequested = MAKEWORD(1, 1);
	int err = WSAStartup(wVersionRequested, (LPWSADATA)&wsaData);
	if(0 != err)
	{
		MessageBox(NULL, "Can not find a windows socket dll!", "error", MB_OK);
		return CLIENT_SOCKET_DLL_ERROR;
	}
	return err;
}

int ExitClient(int nEixt)
{
	closesocket(sServer);
	closesocket(sClient);
	WSACleanup();
	return nEixt;
}

void ShowErrorMsg()
{
	int nErrCode = WSAGetLastError();
	HLOCAL hlocal = NULL;

	BOOL fOk = FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_ALLOCATE_BUFFER, NULL, nErrCode, MAKELANGID(LANG_ENGLISH, SUBLANG_ENGLISH_US), (PTSTR)&hlocal, 0, NULL);

	if(hlocal != NULL)
	{
		MessageBox(NULL, (char*)LocalLock(hlocal), "CLIENT ERROR", MB_OK);
		LocalFree(hlocal);
	}
}

SOCKET CreateSocket()
{
	SOCKET sHost;
	sHost = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(INVALID_SOCKET == sHost)
	{
		ShowErrorMsg();
		WSACleanup();
		return CLIENT_API_ERROR;
	}
	return sHost;
}

int ConnectServer(SOCKET sHost)
{
	LPHOSTENT hostEntry;
	char hostname[MAX_NUM_BUF];
	gethostname(hostname, MAX_NUM_BUF);
	hostEntry = gethostbyname(hostname);
	if(!hostEntry)
	{
		ShowErrorMsg();
		return ExitClient(CLIENT_API_ERROR);

	}
	SOCKADDR_IN addrServ;
	addrServ.sin_family = AF_INET;
	addrServ.sin_addr = *((LPIN_ADDR)*hostEntry->h_addr_list);
	addrServ.sin_port = htons(SERVERPORT);

	int retVal = connect(sHost, (LPSOCKADDR)&addrServ, sizeof(SOCKADDR_IN));
	if(SOCKET_ERROR == retVal)
	{
		ShowErrorMsg();
		return ExitClient(CLIENT_API_ERROR);
	}
	else
	{
		bConning = TRUE;
	}
	return retVal;
}

int SendMsg(SOCKET sHost)
{
	strcpy(bufSend, "Hello, Server!\n");
	int retVal = send(sHost, bufSend, strlen(bufSend), 0);
	if(SOCKET_ERROR == retVal)
	{
		ShowErrorMsg();
		return ExitClient(CLIENT_API_ERROR);
	}
	return retVal;
}
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
	return buf + nDataLen;
}
int main(int argc, char* argv[])
{
	InitMember();

	if(0 == InitSocketDll())
	{
		printf("InitSocket finish!");
	}
	else
	{
		ShowErrorMsg();
	};
	
	sClient = CreateSocket();
	ConnectServer(sClient);
	SendMsg(sClient);
	bufRecv = RecvLine(sClient, bufRecv);
	printf("Client : %s\n", *bufRecv);
	
	
	
	ExitClient(0);
	
	

	return 0;
}

