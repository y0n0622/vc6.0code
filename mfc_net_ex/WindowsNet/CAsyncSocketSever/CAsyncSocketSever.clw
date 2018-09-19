; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CCAsyncSocketSeverDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "casyncsocketsever.h"
LastPage=0

ClassCount=5
Class1=CCAsyncSocketSeverApp
Class2=CAboutDlg
Class3=CCAsyncSocketSeverDlg
Class4=CListenSocket
Class5=CNewSocket

ResourceCount=2
Resource1=IDD_CASYNCSOCKETSEVER_DIALOG
Resource2=IDD_ABOUTBOX

[CLS:CCAsyncSocketSeverApp]
Type=0
BaseClass=CWinApp
HeaderFile=CAsyncSocketSever.h
ImplementationFile=CAsyncSocketSever.cpp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=CAsyncSocketSeverDlg.cpp
ImplementationFile=CAsyncSocketSeverDlg.cpp

[CLS:CCAsyncSocketSeverDlg]
Type=0
BaseClass=CDialog
HeaderFile=CAsyncSocketSeverDlg.h
ImplementationFile=CAsyncSocketSeverDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=IDC_Star

[CLS:CListenSocket]
Type=0
BaseClass=CAsyncSocket
HeaderFile=ListenSocket.h
ImplementationFile=ListenSocket.cpp

[CLS:CNewSocket]
Type=0
BaseClass=CAsyncSocket
HeaderFile=NewSocket.h
ImplementationFile=NewSocket.cpp

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_CASYNCSOCKETSEVER_DIALOG]
Type=1
Class=CCAsyncSocketSeverDlg
ControlCount=2
Control1=IDC_STATIC,static,1342308352
Control2=IDC_Star,button,1342242816

