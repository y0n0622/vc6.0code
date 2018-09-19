// ChatRoomServerDlg.h : header file
//

#if !defined(AFX_CHATROOMSERVERDLG_H__8806F343_AF3C_414A_B795_6CBDBDABD573__INCLUDED_)
#define AFX_CHATROOMSERVERDLG_H__8806F343_AF3C_414A_B795_6CBDBDABD573__INCLUDED_

#if _MSC_VER > 1000
#pragma once
class CClientItem;
#include <afxtempl.h>
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CChatRoomServerDlg dialog

class CChatRoomServerDlg : public CDialog
{
// Construction
public:
	CChatRoomServerDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CChatRoomServerDlg)
	enum { IDD = IDD_CHATROOMSERVER_DIALOG };
	CEdit	m_MsgEdit;
	CButton	m_stopButton;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChatRoomServerDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CChatRoomServerDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStartService();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

public:
	SOCKET m_ListenSock;
	HANDLE m_hListenThread;
	CArray <CClientItem, CClientItem>m_ClientArray;
	void ShowMsg(CString strMsg);
	void RemoveClientFromArray(CClientItem in_Item);
};

//class define

class CClientItem
{
public:
	CString m_strIP;
	SOCKET m_Socket;
	HANDLE hThread;
	CChatRoomServerDlg *m_pMainWnd;
	CClientItem()
	{
		m_pMainWnd = NULL;
		m_Socket = INVALID_SOCKET;
		hThread = NULL;
	}
};
//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHATROOMSERVERDLG_H__8806F343_AF3C_414A_B795_6CBDBDABD573__INCLUDED_)
