// CAsyncSocketClientDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CAsyncSocketClient.h"
#include "CAsyncSocketClientDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCAsyncSocketClientDlg dialog

CCAsyncSocketClientDlg::CCAsyncSocketClientDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CCAsyncSocketClientDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCAsyncSocketClientDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCAsyncSocketClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCAsyncSocketClientDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CCAsyncSocketClientDlg, CDialog)
	//{{AFX_MSG_MAP(CCAsyncSocketClientDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT, OnConnect)
	ON_BN_CLICKED(IDC_BUTTON3, OnClose)
	ON_BN_CLICKED(IDC_SEND, OnSend)
	ON_WM_TIMER()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCAsyncSocketClientDlg message handlers

BOOL CCAsyncSocketClientDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CCAsyncSocketClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CCAsyncSocketClientDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CCAsyncSocketClientDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CCAsyncSocketClientDlg::OnConnect() 
{
	// TODO: Add your control notification handler code here
	CClientSocket m_clientSocket;
	m_clientSocket.ShutDown(2);
	m_clientSocket.m_hSocket = INVALID_SOCKET;
	m_clientSocket.m_bConnected = FALSE;
	GetDlgItem(IDC_CONNECT)->EnableWindow(false);
	m_szPort = 4088;
	UpdateData(true);
	if(!m_ServerAddress.IsEmpty())
	{
		GetDlgItem(IDC_EDIT1)->EnableWindow(false);
		memcpy(m_szServerAdr, m_ServerAddress, sizeof(m_szServerAdr));
		SetTimer(1, 1000, NULL);
		TryCount = 0;
	}
}


void CCAsyncSocketClientDlg::OnClose() 
{
	// TODO: Add your control notification handler code here
	m_clientSocket.Close();
	PostQuitMessage(0);
	return ;
}

void CCAsyncSocketClientDlg::OnSend() 
{
	// TODO: Add your control notification handler code here
	if(m_clientSocket.m_bConnected)
	{
		m_clientSocket.m_nLength = m_MsgS.GetWindowText(m_clientSocket.m_szBuffer, sizeof(m_clientSocket.m_szBuffer));
		m_clientSocket.AsyncSelect(FD_WRITE);
	}
}

void CCAsyncSocketClientDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(m_clientSocket.m_hSocket == INVALID_SOCKET)
	{
		BOOL bFlag = m_clientSocket.Create(0, SOCK_STREAM, FD_CONNECT);
		if(!bFlag)
		{
			AfxMessageBox("Socket创建错误！");
			m_clientSocket.Close();
			GetDlgItem(IDC_EDIT1)->EnableWindow(true);
			return ;
		}
	}
	m_clientSocket.Connect(m_szServerAdr, m_szPort);
	TryCount++;
	if(TryCount >= 10 || m_clientSocket.m_bConnected)
	{
		KillTimer(1);
		if(TryCount >= 10)
		{
			AfxMessageBox("连接失败！");
			GetDlgItem(IDC_CONNECT)->EnableWindow(true);
			GetDlgItem(IDC_EDIT1)->EnableWindow(true);
		}
		return ;
	}
	CDialog::OnTimer(nIDEvent);
}
