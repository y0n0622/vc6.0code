// ComboBox_ListBoxDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ComboBox_ListBox.h"
#include "ComboBox_ListBoxDlg.h"

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
// CComboBox_ListBoxDlg dialog

CComboBox_ListBoxDlg::CComboBox_ListBoxDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CComboBox_ListBoxDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CComboBox_ListBoxDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CComboBox_ListBoxDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CComboBox_ListBoxDlg)
	DDX_Control(pDX, IDC_LIST1, m_lst);
	DDX_Control(pDX, IDC_COMBO1, m_cmb);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CComboBox_ListBoxDlg, CDialog)
	//{{AFX_MSG_MAP(CComboBox_ListBoxDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CComboBox_ListBoxDlg message handlers

BOOL CComboBox_ListBoxDlg::OnInitDialog()
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

void CComboBox_ListBoxDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CComboBox_ListBoxDlg::OnPaint() 
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
HCURSOR CComboBox_ListBoxDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CComboBox_ListBoxDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	CString strText;
	GetDlgItemText(IDC_EDIT1, strText);
	m_cmb.AddString(strText);
	m_cmb.SetCurSel(m_cmb.GetCount()-1);

	m_lst.AddString(strText);
	m_lst.SetCurSel(m_lst.GetCount()-1);
}

void CComboBox_ListBoxDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	int nIndex;

	nIndex = m_cmb.GetCurSel();
	if(nIndex > -1)
	{
		m_cmb.DeleteString(nIndex);	
		if(nIndex < m_cmb.GetCount())
		{
			m_cmb.SetCurSel(nIndex);
		}
		else
		{
			m_cmb.SetCurSel(0);
		}
	}
	nIndex = m_lst.GetCurSel();
	if(nIndex > -1)
	{
		m_lst.DeleteString(nIndex);	
		if(nIndex < m_lst.GetCount())
		{
			m_lst.SetCurSel(nIndex);
		}
		else
		{
			m_lst.SetCurSel(0);
		}	
	}
}
