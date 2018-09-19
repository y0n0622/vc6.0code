// FileMappingDlg.h : header file
//

#if !defined(AFX_FILEMAPPINGDLG_H__E3B49C26_3AD3_46D0_9BE3_DB72CAA3B841__INCLUDED_)
#define AFX_FILEMAPPINGDLG_H__E3B49C26_3AD3_46D0_9BE3_DB72CAA3B841__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileMappingDlg dialog

class CFileMappingDlg : public CDialog
{
// Construction
public:
	CFileMappingDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CFileMappingDlg)
	enum { IDD = IDD_FILEMAPPING_DIALOG };
	CString	m_strSend;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileMappingDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HANDLE m_hMapObject;
	HICON m_hIcon;
	LPSTR m_pszMapView;
	// Generated message map functions
	//{{AFX_MSG(CFileMappingDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnBnSend();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEMAPPINGDLG_H__E3B49C26_3AD3_46D0_9BE3_DB72CAA3B841__INCLUDED_)
