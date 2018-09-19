// demo3.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include <windows.h>

//���ڹ��̻ص�����       H��Handler�ļ�д�����
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

//�൱�� int main()
//                 ʵ�����
int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPSTR lpszCmdLine,
				   int nCmdShow)
{
	HWND hwnd;//���ھ��
	MSG msg;//��Ϣ
	WNDCLASS wc;//������
	
	//1.���һ��������
	wc.style = 0;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(NULL, IDI_WINLOGO);
	wc.hCursor = LoadCursor(NULL,IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszMenuName = NULL;
	wc.lpszClassName = TEXT("MyWndClass");

	//2.ע�ᴰ����
	RegisterClass(&wc);

	//3.��������
	hwnd = CreateWindow(
		TEXT("MyWndClass"),
		TEXT("Hello SDK Application"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,//�����ھ��
		NULL,//���ڲ˵����
		hInstance,
		NULL);

	//4.��ʾ�͸��´���
	ShowWindow(hwnd,nCmdShow);
	UpdateWindow(hwnd);
	//5.��Ϣѭ��
	while(GetMessage(&msg,NULL,0,0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);//ת�������ڹ���
	}

	return msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd,
						 UINT message,
						 WPARAM wParam,
						 LPARAM lParam)
{
	HDC hdc;
	static int cyChar;
	PAINTSTRUCT ps;
	//�Ը�����Ϣ���д���
	switch(message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 0, 0, TEXT("hello"), 5);
		TextOut(hdc, 0, cyChar, TEXT("hello 2"), 7);
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY://���ٴ�����Ϣ���رգ�
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd,message,wParam,lParam);
}



