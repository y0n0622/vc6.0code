; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CChildView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Colors.h"
LastPage=0

ClassCount=4
Class1=CColorsApp
Class3=CMainFrame
Class4=CAboutDlg

ResourceCount=3
Resource1=IDR_MAINFRAME
Class2=CChildView
Resource2=IDD_ABOUTBOX
Resource3=IDR_CONTEXTMENU

[CLS:CColorsApp]
Type=0
HeaderFile=Colors.h
ImplementationFile=Colors.cpp
Filter=N

[CLS:CChildView]
Type=0
HeaderFile=ChildView.h
ImplementationFile=ChildView.cpp
Filter=W
BaseClass=CWnd 
VirtualFilter=WC
LastObject=CChildView

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=W
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=Colors.cpp
ImplementationFile=Colors.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_APP_EXIT
Command2=ID_SHAPE_CIRCLE
Command3=ID_SHAPE_TRIANGLE
Command4=ID_SHAPE_SQUARE
Command5=ID_COLOR_RED
Command6=ID_COLOR_YELLOW
Command7=ID_COLOR_GREEN
Command8=ID_COLOR_CYAN
Command9=ID_COLOR_BLUE
CommandCount=9

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_EDIT_COPY
Command2=ID_EDIT_PASTE
Command3=ID_EDIT_UNDO
Command4=ID_EDIT_CUT
Command5=ID_NEXT_PANE
Command6=ID_PREV_PANE
Command7=ID_SHAPE_CIRCLE
Command8=ID_SHAPE_TRIANGLE
Command9=ID_SHAPE_SQUARE
Command10=ID_EDIT_COPY
Command11=ID_EDIT_PASTE
Command12=ID_EDIT_CUT
Command13=ID_EDIT_UNDO
CommandCount=13

[MNU:IDR_CONTEXTMENU]
Type=1
Command1=ID_SHAPE_CIRCLE
Command2=ID_SHAPE_TRIANGLE
Command3=ID_SHAPE_SQUARE
Command4=ID_COLOR_RED
Command5=ID_COLOR_YELLOW
Command6=ID_COLOR_GREEN
Command7=ID_COLOR_CYAN
Command8=ID_COLOR_BLUE
CommandCount=8

