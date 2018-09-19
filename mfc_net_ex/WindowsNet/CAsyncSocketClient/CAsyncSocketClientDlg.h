// CAsyncSocketClientDlg.h : header file
//

#if !defined(AFX_CASYNCSOCKETCLIENTDLG_H__86381238_045D_41D1_A55A_0CE7A73B0642__INCLUDED_)
#define AFX_CASYNCSOCKETCLIENTDLG_H__86381238_045D_41D1_A55A_0CE7A73B0642__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCAsyncSocketClientDlg dialog
#include "ClientSocket.h"


class CCAsyncSocketClientDlg : public CDialog
{
// Construction
public:
	CCAsyncSocketClientDlg(CWnd* pParent = NULL);	// standard constructor
	char m_szServerAdr[4096];
	CListBox* m_MsgR;
	CWnd m_MsgS;
	CString m_ServerAddress;
	int TryCount;
	int m_szPort;
	CClientSocket m_clientSocket;
// Dialog Data
	//{{AFX_DATA(CCAsyncSocketClientDlg)
	enum { IDD = IDD_CASYNCSOCKETCLIENT_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCAsyncSocketClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCAsyncSocketClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnConnect();
	afx_msg void OnClose();
	afx_msg void OnSend();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CASYNCSOCKETCLIENTDLG_H__86381238_045D_41D1_A55A_0CE7A73B0642__INCLUDED_)
