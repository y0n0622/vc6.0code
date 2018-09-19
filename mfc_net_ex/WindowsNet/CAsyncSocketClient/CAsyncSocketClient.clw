; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCAsyncSocketClientDlg
LastTemplate=CAsyncSocket
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "CAsyncSocketClient.h"

ClassCount=4
Class1=CCAsyncSocketClientApp
Class2=CCAsyncSocketClientDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class4=CClientSocket
Resource3=IDD_CASYNCSOCKETCLIENT_DIALOG

[CLS:CCAsyncSocketClientApp]
Type=0
HeaderFile=CAsyncSocketClient.h
ImplementationFile=CAsyncSocketClient.cpp
Filter=N
LastObject=CCAsyncSocketClientApp

[CLS:CCAsyncSocketClientDlg]
Type=0
HeaderFile=CAsyncSocketClientDlg.h
ImplementationFile=CAsyncSocketClientDlg.cpp
Filter=D
LastObject=CCAsyncSocketClientDlg
BaseClass=CDialog
VirtualFilter=dWC

[CLS:CAboutDlg]
Type=0
HeaderFile=CAsyncSocketClientDlg.h
ImplementationFile=CAsyncSocketClientDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CASYNCSOCKETCLIENT_DIALOG]
Type=1
Class=CCAsyncSocketClientDlg
ControlCount=10
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=IDC_EDIT1,edit,1350631424
Control4=IDC_CONNECT,button,1342242816
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_EDIT3,edit,1350631552
Control8=IDC_SEND,button,1342242816
Control9=IDC_BUTTON3,button,1342242816
Control10=IDC_LIST1,listbox,1352728835

[CLS:CClientSocket]
Type=0
HeaderFile=ClientSocket.h
ImplementationFile=ClientSocket.cpp
BaseClass=CAsyncSocket
Filter=C
VirtualFilter=q
LastObject=CClientSocket

