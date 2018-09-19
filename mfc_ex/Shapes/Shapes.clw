; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CChildView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Shapes.h"
LastPage=0

ClassCount=4
Class1=CShapesApp
Class3=CMainFrame
Class4=CAboutDlg

ResourceCount=2
Resource1=IDD_ABOUTBOX
Class2=CChildView
Resource2=IDR_MAINFRAME

[CLS:CShapesApp]
Type=0
HeaderFile=Shapes.h
ImplementationFile=Shapes.cpp
Filter=N

[CLS:CChildView]
Type=0
HeaderFile=ChildView.h
ImplementationFile=ChildView.cpp
Filter=N
BaseClass=CWnd 
VirtualFilter=WC
LastObject=ID_SHAPE_TRIANGLE

[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=Shapes.cpp
ImplementationFile=Shapes.cpp
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
Command5=ID_OPTIONS_COLOR
Command6=ID_OPTIONS_SIZE
CommandCount=6

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

