// CAsyncSocketSeverDlg.h : header file
//

#if !defined(AFX_CASYNCSOCKETSEVERDLG_H__A3412C7D_761B_49E5_8665_0820BDA6751E__INCLUDED_)
#define AFX_CASYNCSOCKETSEVERDLG_H__A3412C7D_761B_49E5_8665_0820BDA6751E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCAsyncSocketSeverDlg dialog

class CCAsyncSocketSeverDlg : public CDialog
{
// Construction
public:
	CCAsyncSocketSeverDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCAsyncSocketSeverDlg)
	enum { IDD = IDD_CASYNCSOCKETSEVER_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCAsyncSocketSeverDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCAsyncSocketSeverDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnStar();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CASYNCSOCKETSEVERDLG_H__A3412C7D_761B_49E5_8665_0820BDA6751E__INCLUDED_)
