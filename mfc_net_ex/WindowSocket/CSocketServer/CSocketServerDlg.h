// CSocketServerDlg.h : header file
//

#if !defined(AFX_CSOCKETSERVERDLG_H__010851E6_EEDE_499F_BE41_A7AF7964FED8__INCLUDED_)
#define AFX_CSOCKETSERVERDLG_H__010851E6_EEDE_499F_BE41_A7AF7964FED8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCSocketServerDlg dialog

class CCSocketServerDlg : public CDialog
{
// Construction
public:
	CCSocketServerDlg(CWnd* pParent = NULL);	// standard constructor
    CSocket m_sockListen;
	CSocket m_sockSend;
	//CString m_ServerStatus;
// Dialog Data
	//{{AFX_DATA(CCSocketServerDlg)
	enum { IDD = IDD_CSOCKETSERVER_DIALOG };
	CString	m_ServerStatus;
	int		m_sendcount;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCSocketServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCSocketServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnSend();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSOCKETSERVERDLG_H__010851E6_EEDE_499F_BE41_A7AF7964FED8__INCLUDED_)
