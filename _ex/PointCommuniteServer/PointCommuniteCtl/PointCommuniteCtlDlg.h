// PointCommuniteCtlDlg.h : header file
//

#if !defined(AFX_POINTCOMMUNITECTLDLG_H__39029406_281F_465C_9EEE_EE87B3CA1369__INCLUDED_)
#define AFX_POINTCOMMUNITECTLDLG_H__39029406_281F_465C_9EEE_EE87B3CA1369__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPointCommuniteCtlDlg dialog

class CPointCommuniteCtlDlg : public CDialog
{
// Construction
public:
	CPointCommuniteCtlDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPointCommuniteCtlDlg)
	enum { IDD = IDD_POINTCOMMUNITECTL_DIALOG };
	CString	m_strWrite;
	CString	m_strRead;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPointCommuniteCtlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPointCommuniteCtlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBtnRead();
	afx_msg void OnBtnWrite();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POINTCOMMUNITECTLDLG_H__39029406_281F_465C_9EEE_EE87B3CA1369__INCLUDED_)
