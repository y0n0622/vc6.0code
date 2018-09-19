// demo5.cpp : Defines the entry point for the application.
//

#include "stdafx.h"
#include "resource.h"
//#include "math.h"

#define MAX_LOADSTRING 100
//#define NUM 1000
//#define TWOPI (2 * 3.14159)
// Global Variables:
HINSTANCE hInst;								// current instance
TCHAR szTitle[MAX_LOADSTRING];								// The title bar text
TCHAR szWindowClass[MAX_LOADSTRING];								// The title bar text

// Foward declarations of functions included in this code module:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK	About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY WinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPSTR     lpCmdLine,
                     int       nCmdShow)
{
 	// TODO: Place code here.
	MSG msg;
	HACCEL hAccelTable;

	// Initialize global strings
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_DEMO5, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Perform application initialization:
	if (!InitInstance (hInstance, nCmdShow)) 
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, (LPCTSTR)IDC_DEMO5);

	// Main message loop:
	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
//  COMMENTS:
//
//    This function and its usage is only necessary if you want this code
//    to be compatible with Win32 systems prior to the 'RegisterClassEx'
//    function that was added to Windows 95. It is important to call this function
//    so that the application will get 'well formed' small icons associated
//    with it.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, (LPCTSTR)IDI_DEMO5);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= NULL;//(LPCSTR)IDC_DEMO5;
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	return RegisterClassEx(&wcex);
}

//
//   FUNCTION: InitInstance(HANDLE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd;

   hInst = hInstance; // Store instance handle in our global variable

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, unsigned, WORD, LONG)
//
//  PURPOSE:  Processes messages for the main window.
//
//  WM_COMMAND	- process the application menu
//  WM_PAINT	- Paint the main window
//  WM_DESTROY	- post a quit message and return
//
//

void DrawBezier(HDC hdc, POINT apt[])
{
	PolyBezier(hdc, apt, 4);
	MoveToEx(hdc, apt[0].x, apt[0].y, NULL);
	LineTo(hdc, apt[1].x, apt[1].y);

	MoveToEx(hdc, apt[2].x, apt[2].y, NULL);
	LineTo(hdc, apt[3].x, apt[3].y);
}








LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR szHello[MAX_LOADSTRING];
	LoadString(hInst, IDS_HELLO, szHello, MAX_LOADSTRING);

	//int red, green, blue;
//	TCHAR szBuffer[1024];

	//RECT rect;
//	POINT apt[5] = {300, 100, 400, 100, 400 ,200, 300, 200, 300, 100};
//	POINT apt2[5] = {500, 100, 600, 100, 600 ,200, 500, 200, 500, 100};

	static int cxClient, cyClient;
//	POINT apt[NUM];

	static POINT apt[4];

	switch (message) 
	{
	case WM_SIZE:
		cxClient = LOWORD(lParam);
		cyClient = HIWORD(lParam);
		
		apt[0].x = cxClient / 4;
		apt[0].y = cyClient / 2;

		apt[1].x = cxClient / 2;
		apt[1].y = cyClient / 4;

		apt[2].x = cxClient / 2;
		apt[2].y = 3 * cyClient / 4;

		apt[3].x = 3 * cxClient / 4;
		apt[3].y = cyClient / 2;

		break;

	case WM_RBUTTONDOWN:
	case WM_MOUSEMOVE:
	case WM_LBUTTONDOWN:
		if(wParam & MK_LBUTTON || wParam & MK_RBUTTON)
		{	hdc = GetDC(hWnd);
		SelectObject(hdc, GetStockObject(WHITE_PEN));
		DrawBezier(hdc, apt);
		if(wParam & MK_LBUTTON)
		{
			apt[1].x = LOWORD(lParam);
			apt[1].y = HIWORD(lParam);
		}
			if(wParam & MK_RBUTTON)
		{
			apt[2].x = LOWORD(lParam);
			apt[2].y = HIWORD(lParam);
		}
		SelectObject(hdc, GetStockObject(BLACK_PEN));
		DrawBezier(hdc, apt);

		ReleaseDC(hWnd, hdc);
		}
		break;
		case WM_COMMAND:
			wmId    = LOWORD(wParam); 
			wmEvent = HIWORD(wParam); 
			// Parse the menu selections:
			switch (wmId)
			{
				case IDM_ABOUT:
				   DialogBox(hInst, (LPCTSTR)IDD_ABOUTBOX, hWnd, (DLGPROC)About);
				   break;
				case IDM_EXIT:
				   DestroyWindow(hWnd);
				   break;
				default:
				   return DefWindowProc(hWnd, message, wParam, lParam);
			}
			break;
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);
			// TODO: Add any drawing code here...
			
			/*COLORREF color;
			color = RGB(255, 255, 0);
			int i;
			for(i = 0; i<100; i++)
			{
				SetPixel(hdc, 100 + i, 100, color);
			}
			RECT rect;
			GetClientRect(hWnd, &rect);

			int m, n;
			for(m = 0; m <= rect.right; ++m)
			{
				for(n = rect.top; n <= rect.bottom; ++n)
				{
					color = RGB(rand()%256*2, rand()%256*2, rand()%256*2);
					SetPixel(hdc, m, n, color);
				}
			}

			color = GetPixel(hdc, 200, 200);
			red = GetRValue(color);
			green = GetGValue(color);
			blue = GetBValue(color);
			wsprintf(szBuffer, TEXT("%d, %d, %d"), red, green, blue);
			TextOut(hdc, 0, 0, szBuffer,lstrlen(szBuffer));
		*/	

			
		/*	MoveToEx(hdc, 100, 100, NULL);
			LineTo(hdc, 200, 100);
			LineTo(hdc, 200, 200);
			LineTo(hdc, 100, 200);
			LineTo(hdc, 100, 100);

			MoveToEx(hdc, apt[0].x, apt[0].y, NULL);
			int i;
			for(i = 1; i < 5; i++)
			{
				LineTo(hdc, apt[i].x, apt[i].y);
			}
			
		//	Polyline(hdc, apt2, 5);

			MoveToEx(hdc, apt2[0].x, apt2[0].y, NULL);
			PolylineTo(hdc, apt2 + 1, 4);*/

		/*	MoveToEx(hdc, 150, 150, NULL);
			LineTo(hdc, 250, 150);
			LineTo(hdc, 250, 250);
			LineTo(hdc, 150, 250);
			LineTo(hdc, 150, 150);*/


		/*	GetClientRect(hWnd, &rect);
			int x;
			for(x = 0; x < rect.right; x += 100)
			{
				MoveToEx(hdc, x, 0, NULL);
				LineTo(hdc, x, rect.bottom);
			}
			int y;
			for(y = 0; y < rect.bottom; y += 100)
			{
				MoveToEx(hdc, 0, y, NULL);
				LineTo(hdc, rect.right, y);
			}*/

		/*	MoveToEx(hdc, 0, cyClient / 2, NULL);
			LineTo(hdc, cxClient, cyClient / 2);
			int i;
			for(i = 0; i < NUM; ++i)
			{
				apt[i].x = i * cxClient / NUM;
				apt[i].y = (int)(cyClient / 2 * (1 - sin(i * TWOPI/NUM)));
			}
			
			Polyline(hdc, apt, NUM);*/
			
		/*	Rectangle(hdc, 100, 100, 400, 300);
			Ellipse(hdc, 100, 100, 400, 300);
			RoundRect(hdc, 100, 100, 400, 300, 100, 100);
			Arc(hdc, 100, 100, 400, 300, 250, 10, 2, 300);
			Chord(hdc, 100, 100, 400, 300, 250, 10, 2, 300);
			Pie(hdc, 100, 100, 400, 300, 250, 10, 2, 300);
*/

		/*	Rectangle(hdc, cxClient / 8, cyClient / 8, cxClient * 7 / 8, cyClient * 7 / 8);
			MoveToEx(hdc, 0, 0, NULL);
			LineTo(hdc, cxClient, cyClient);

			MoveToEx(hdc, 0, cyClient, NULL);
			LineTo(hdc, cxClient, 0);

			Ellipse(hdc, cxClient / 8, cyClient / 8, cxClient * 7 / 8, cyClient * 7 / 8);
			RoundRect(hdc, cxClient / 4, cyClient / 4, cxClient * 3 / 4, cyClient * 3 / 4, cxClient / 4, cyClient /4);
*/
			//PolyBezier(hdc, apt, iCount);
			
		/*	apt[0].x = 100;
			apt[0].y = 100;
			
			apt[1].x = 50;
			apt[1].y = 50;

			apt[2].x = 250;
			apt[2].y = 50;

			apt[3].x = 200;
			apt[3].y = 100;
*/


			DrawBezier(hdc, apt);

			EndPaint(hWnd, &ps);


			

			break;
		case WM_DESTROY:
			PostQuitMessage(0);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
   }
   return 0;
}

// Mesage handler for about box.
LRESULT CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
		case WM_INITDIALOG:
				return TRUE;

		case WM_COMMAND:
			if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL) 
			{
				EndDialog(hDlg, LOWORD(wParam));
				return TRUE;
			}
			break;
	}
    return FALSE;
}
