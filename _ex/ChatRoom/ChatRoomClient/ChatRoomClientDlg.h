// ChatRoomClientDlg.h : header file
//

#if !defined(AFX_CHATROOMCLIENTDLG_H__E87C03E5_259E_4C7E_BB45_6252943D9549__INCLUDED_)
#define AFX_CHATROOMCLIENTDLG_H__E87C03E5_259E_4C7E_BB45_6252943D9549__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChatRoomClientDlg dialog

class CChatRoomClientDlg : public CDialog
{
// Construction
public:
	CChatRoomClientDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CChatRoomClientDlg)
	enum { IDD = IDD_CHATROOMCLIENT_DIALOG };
	CButton	m_stopButton;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatRoomClientDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChatRoomClientDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATROOMCLIENTDLG_H__E87C03E5_259E_4C7E_BB45_6252943D9549__INCLUDED_)
