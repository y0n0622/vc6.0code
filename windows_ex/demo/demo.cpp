// demo.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include <stdio.h>
#include <windows.h>
#include <tchar.h>
#include <stdarg.h>

int CDECL MessageBoxPrintf(TCHAR * szCaption, TCHAR * szFormat,...)
{
	TCHAR szBuffer[1024];
	va_list pArgList;
	va_start(pArgList,szFormat);
	_vsntprintf(szBuffer,sizeof(szBuffer)/sizeof(TCHAR),szFormat,pArgList);
	va_end(pArgList);

	return MessageBox(NULL,szBuffer,szCaption,MB_OK | MB_ICONINFORMATION);
}

int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstane,
				   PSTR szCmdLine,
				   int iCmdShow)
{
	int x = 100, y = 200, z = 300;
	int cxScreen, cyScreen;

	cxScreen = GetSystemMetrics(SM_CXSCREEN);
	cyScreen = GetSystemMetrics(SM_CYSCREEN);

	MessageBoxPrintf(TEXT("�ҵı���"),TEXT("Hello %d, %d, %d"),x,y,z);
	MessageBoxPrintf(TEXT("��Ļ��С"),TEXT("�ҵ���Ļ�����: %d, �߶���: %d"),cxScreen,cyScreen);

	return 0;
}



