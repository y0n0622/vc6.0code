// MulThreadDlg.h : header file
//

#if !defined(AFX_MULTHREADDLG_H__A30BC7A3_3A2C_4859_BDBF_53F78CBE1E00__INCLUDED_)
#define AFX_MULTHREADDLG_H__A30BC7A3_3A2C_4859_BDBF_53F78CBE1E00__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMulThreadDlg dialog

class CMulThreadDlg : public CDialog
{
// Construction
public:
	CMulThreadDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMulThreadDlg)
	enum { IDD = IDD_MULTHREAD_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMulThreadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CMulThreadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnStart();
	afx_msg void OnBtnStop();
	afx_msg void OnBtnError();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTHREADDLG_H__A30BC7A3_3A2C_4859_BDBF_53F78CBE1E00__INCLUDED_)
