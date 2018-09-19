// demo3.cpp : Defines the entry point for the application.
//

#include "stdafx.h"

#include <windows.h>

//窗口过程回调函数       H是Handler的简写，句柄
LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);

//相当于 int main()
//                 实例句柄
int WINAPI WinMain(HINSTANCE hInstance,
				   HINSTANCE hPrevInstance,
				   LPSTR lpszCmdLine,
				   int nCmdShow)
{
	HWND hwnd;//窗口句柄
	MSG msg;//消息
	WNDCLASS wc;//窗口类
	
	//1.设计一个窗口类
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

	//2.注册窗口类
	RegisterClass(&wc);

	//3.创建窗口
	hwnd = CreateWindow(
		TEXT("MyWndClass"),
		TEXT("Hello SDK Application"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,//父窗口句柄
		NULL,//窗口菜单句柄
		hInstance,
		NULL);

	//4.显示和更新窗口
	ShowWindow(hwnd,nCmdShow);
	UpdateWindow(hwnd);
	//5.消息循环
	while(GetMessage(&msg,NULL,0,0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);//转发到窗口过程
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
	//对各种消息进行处理
	switch(message)
	{
	case WM_PAINT:
		hdc = BeginPaint(hwnd, &ps);
		TextOut(hdc, 0, 0, TEXT("hello"), 5);
		TextOut(hdc, 0, cyChar, TEXT("hello 2"), 7);
		EndPaint(hwnd, &ps);
		break;
	case WM_DESTROY://销毁窗口消息（关闭）
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd,message,wParam,lParam);
}



