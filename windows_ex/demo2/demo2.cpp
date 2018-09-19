// demo2.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "windows.h"

LRESULT CALLBACK WndProc( HWND, UINT, WPARAM, LPARAM );

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	HWND hwnd;
	MSG msg;
	WNDCLASS wc;
	wc.style = 0;
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon( NULL, IDI_WINLOGO );
	wc.hCursor = LoadCursor( NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1 );
	wc.lpszMenuName = NULL;
	wc.lpszClassName = TEXT("MyWndClass");
	
	RegisterClass(&wc);

	hwnd = CreateWindow( TEXT("MyWndClass"),
						 TEXT("Hello SDK"),
						 WS_OVERLAPPEDWINDOW,
						 CW_USEDEFAULT,
						 CW_USEDEFAULT,
						 CW_USEDEFAULT,
						 CW_USEDEFAULT,
						 NULL,
						 NULL,
						 hInstance,
						 NULL );
	ShowWindow( hwnd, nCmdShow );
	UpdateWindow( hwnd );
	while(GetMessage(&msg,NULL,0,0)){
		TranslateMessage(&msg);
		DispatchMessage(&msg);//转发到窗口过程
	}

	return msg.wParam;
	
}

LRESULT CALLBACK WndProc( HWND hwnd, UINT message, 
						  WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	RECT rect;
	switch( message )
	{
	case WM_SIZE:

		break;
	case WM_LBUTTONDOWN:
		MessageBox( hwnd, TEXT("click"), TEXT("xiao xi"), MB_OK);
		break;
	case WM_PAINT:
		hdc = BeginPaint( hwnd, &ps );
		GetClientRect( hwnd, &rect );
		Ellipse( hdc, 0, 0, 200, 100 );
		DrawText( hdc, TEXT("hello,window"), -1, &rect, 
				  DT_SINGLELINE | DT_CENTER | DT_VCENTER );
		EndPaint( hwnd, &ps );
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc( hwnd, message, wParam, lParam );
}



