// PointCommuniteCtlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "PointCommuniteCtl.h"
#include "PointCommuniteCtlDlg.h"

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
// CPointCommuniteCtlDlg dialog

CPointCommuniteCtlDlg::CPointCommuniteCtlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPointCommuniteCtlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPointCommuniteCtlDlg)
	m_strWrite = _T("");
	m_strRead = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPointCommuniteCtlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPointCommuniteCtlDlg)
	DDX_Text(pDX, IDC_EDIT_WRITE, m_strWrite);
	DDX_Text(pDX, IDC_EDIT_READ, m_strRead);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPointCommuniteCtlDlg, CDialog)
	//{{AFX_MSG_MAP(CPointCommuniteCtlDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_READ, OnBtnRead)
	ON_BN_CLICKED(IDC_BTN_WRITE, OnBtnWrite)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPointCommuniteCtlDlg message handlers

BOOL CPointCommuniteCtlDlg::OnInitDialog()
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

void CPointCommuniteCtlDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CPointCommuniteCtlDlg::OnPaint() 
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
HCURSOR CPointCommuniteCtlDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPointCommuniteCtlDlg::OnBtnRead() 
{
	// TODO: Add your control notification handler code here
	DWORD pid;
	HWND hwnd = ::FindWindow(NULL, _T("PointCommuniteServer"));
	if (!hwnd)
	{
		AfxMessageBox(_T("没有找到进程PointCommuniteServer"));
		return ;
	}
	::GetWindowThreadProcessId(hwnd, &pid);
	HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	LPVOID lpBaseAddress = (LPVOID)0x12feac;
	DWORD dwValue;

	if (!::ReadProcessMemory(hProcess, lpBaseAddress, (void*)&dwValue, sizeof(DWORD), 0))
	{
		return;
	}

	m_strRead.Format("%d", dwValue);
	UpdateData(FALSE);
}

void CPointCommuniteCtlDlg::OnBtnWrite() 
{
	// TODO: Add your control notification handler code here
	DWORD pid;
	HWND hwnd = ::FindWindow(NULL, _T("PointCommuniteServer"));
	if (!hwnd)
	{
		AfxMessageBox(_T("没有找到PointCommuniteServer进程"));
		return ;
	}
	::GetWindowThreadProcessId(hwnd, &pid);
	HANDLE hProcess = ::OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);

	LPVOID lpBaseAddress = (LPVOID)0x12feac;
	UpdateData();
	DWORD dwValue = atoi(m_strWrite);

	if (!::WriteProcessMemory(hProcess, lpBaseAddress, (void*)&dwValue, sizeof(DWORD), 0))
	{
		return ;
	}
}
