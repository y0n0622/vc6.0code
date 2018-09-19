// ChatRoomServerDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ChatRoomServer.h"
#include "ChatRoomServerDlg.h"

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
// CChatRoomServerDlg dialog

CChatRoomServerDlg::CChatRoomServerDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CChatRoomServerDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CChatRoomServerDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_ListenSock = INVALID_SOCKET;
	m_hListenThread = NULL;
}

void CChatRoomServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CChatRoomServerDlg)
	DDX_Control(pDX, IDC_SHOW_MSG, m_MsgEdit);
	DDX_Control(pDX, IDC_BTN_STOP, m_stopButton);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CChatRoomServerDlg, CDialog)
	//{{AFX_MSG_MAP(CChatRoomServerDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START_SERVICE, OnStartService)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChatRoomServerDlg message handlers

BOOL CChatRoomServerDlg::OnInitDialog()
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
	//设置服务器默认端口
	SetDlgItemText(IDC_LISTEN_PORT, _T("5566"));
	m_stopButton.EnableWindow(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CChatRoomServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CChatRoomServerDlg::OnPaint() 
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
HCURSOR CChatRoomServerDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

DWORD WINAPI ListenThreadFunc(LPVOID lpParameter);
DWORD WINAPI ClientThreadProc(LPVOID lpParameter);

void CChatRoomServerDlg::OnStartService() 
{
	// TODO: Add your control notification handler code here
	m_hListenThread = CreateThread(NULL, 0, ListenThreadFunc, this, 0, NULL);
/*__Error_End:
	{
		closesocket(m_ListenSock);
	}

	m_ListenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(m_ListenSock == INVALID_SOCKET)
	{
		AfxMessageBox(_T("新建SOCKET失败!"));
		return ;
	}
	UINT uPort = GetDlgItemInt(IDC_LISTEN_PORT);
	if (uPort <= 0 || uPort > 65535)
	{
		AfxMessageBox(_T("请输入合适的端口:1-65535"));
		goto __Error_End;
	}
	sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = INADDR_ANY;
	service.sin_port = htons(uPort);
	if (bind(m_ListenSock, (sockaddr*)&service, sizeof(sockaddr_in)) == SOCKET_ERROR)
	{
		AfxMessageBox(_T("绑定端口失败！"));
		goto __Error_End;
	}
	if (listen(m_ListenSock, 5) == SOCKET_ERROR)
	{
		AfxMessageBox(_T("监听失败！"));
		goto __Error_End;
	}
	sockaddr_in clientAddr;
	int iLen = sizeof(sockaddr_in);
	SOCKET accSock = accept(m_ListenSock, (struct sockaddr*)&clientAddr, &iLen);
	if (accSock == INVALID_SOCKET)
	{
		AfxMessageBox(_T("接受客户端失败！"));
		goto __Error_End;
	}
*/
}

void CChatRoomServerDlg::ShowMsg(CString strMsg)
{
	m_MsgEdit.SetSel(-1, -1);
	m_MsgEdit.ReplaceSel(strMsg + _T("\r\n"));
}

void CChatRoomServerDlg::RemoveClientFromArray(CClientItem in_Item)
{
	for (int idx = 0; idx < m_ClientArray.GetSize(); idx++)
	{
		CClientItem tItem = m_ClientArray.GetAt(idx);
		if (tItem.m_Socket == in_Item.m_Socket && tItem.m_strIP == in_Item.m_strIP && tItem.hThread == in_Item.hThread)
		{
			m_ClientArray.RemoveAt(idx);
		}
	}
}


//select_socket
BOOL SocketSelect(SOCKET hSocket, int nTimeOut, BOOL bRead)
{
	fd_set fdset;
	timeval tv;
	FD_ZERO(&fdset);
	FD_SET(hSocket, &fdset);
	nTimeOut = nTimeOut > 1000 ? 1000 : nTimeOut;
	tv.tv_sec = 0;
	tv.tv_usec = nTimeOut;
	
	int iRet = 0;
	if (bRead)
	{
		iRet = select(0, &fdset, NULL, NULL, &tv);
	}
	else
	{
		iRet = select(0, NULL, &fdset, NULL, &tv);
	}

	if (iRet <= 0)
	{
		return FALSE;
	}
	else if(FD_ISSET(hSocket, &fdset))
	{
		return TRUE;
	
	}
	return FALSE;
}

//service thread
DWORD WINAPI ListenThreadFunc(LPVOID lpParameter)
{
	CChatRoomServerDlg *pChatRoom = (CChatRoomServerDlg*)lpParameter;
	ASSERT(pChatRoom != NULL);
	pChatRoom->m_ListenSock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if(pChatRoom->m_ListenSock == INVALID_SOCKET)
	{
		AfxMessageBox(_T("新建SOCKET失败!"));
		return FALSE;
	}
	UINT uPort = pChatRoom->GetDlgItemInt(IDC_LISTEN_PORT);
	if (uPort <= 0 || uPort > 65535)
	{
		AfxMessageBox(_T("请输入合适的端口:1-65535"));
		goto __Error_End;
	}
	sockaddr_in service;
	service.sin_family = AF_INET;
	service.sin_addr.s_addr = INADDR_ANY;
	service.sin_port = htons(uPort);
	if (bind(pChatRoom->m_ListenSock, (sockaddr*)&service, sizeof(sockaddr_in)) == SOCKET_ERROR)
	{
		AfxMessageBox(_T("绑定端口失败！"));
		goto __Error_End;
	}
	if (listen(pChatRoom->m_ListenSock, 5) == SOCKET_ERROR)
	{
		AfxMessageBox(_T("监听失败！"));
		goto __Error_End;
	}
	while (TRUE)
	{
		if (SocketSelect(pChatRoom->m_ListenSock, 100, TRUE))
		{
			sockaddr_in clientAddr;
			int iLen = sizeof(sockaddr_in);
			SOCKET accSock = accept(pChatRoom->m_ListenSock, (struct sockaddr*)&clientAddr, &iLen);
			if (accSock == INVALID_SOCKET)
			{
				continue;
			}
			//do other something
			CClientItem tItem;
			tItem.m_Socket = accSock;
			tItem.m_strIP = inet_ntoa(clientAddr.sin_addr);
			tItem.m_pMainWnd = pChatRoom;
			INT_PTR idx = pChatRoom->m_ClientArray.Add(tItem);
			tItem.hThread = CreateThread(NULL, 0, ClientThreadProc, &(pChatRoom->m_ClientArray.GetAt(idx)), CREATE_SUSPENDED, NULL);
			//pChatRoom->m_ClientArray.GetAt(idx).hThread = tItem.hThread;
			ResumeThread(tItem.hThread);
			
			Sleep(100);
		}
	}
__Error_End:
	
		closesocket(pChatRoom->m_ListenSock);
		return TRUE;
}

//client thread
#define  MAX_BUF_SIZE  1024
DWORD WINAPI ClientThreadProc(LPVOID lpParameter)
{
	CString strMsg;
	CClientItem m_ClientItem = *(CClientItem*)lpParameter;
	while (TRUE)
	{
		if (SocketSelect(m_ClientItem.m_Socket, 100, TRUE))
		{
			TCHAR szBuf[MAX_BUF_SIZE] = {0};
			int iRet = recv(m_ClientItem.m_Socket, (char*)szBuf, MAX_BUF_SIZE, 0);
			if (iRet > 0)
			{
				strMsg.Format(_T("%s"), szBuf);
				strMsg = _T("客户端：") + m_ClientItem.m_strIP + _T(">") + strMsg;
				m_ClientItem.m_pMainWnd->ShowMsg(strMsg);
			}
			else
			{
				strMsg = _T("客户端：") + m_ClientItem.m_strIP + _T("离开了聊天室！");
				m_ClientItem.m_pMainWnd->ShowMsg(strMsg);
				m_ClientItem.m_pMainWnd->RemoveClientFromArray(m_ClientItem);
				break;
			}
		}
		Sleep(500);
	}
	return TRUE;
}