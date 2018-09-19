// FileMappingRecvDlg.h : header file
//

#if !defined(AFX_FILEMAPPINGRECVDLG_H__5FA6B5AB_BB2B_40B9_AAF4_CDE644468B05__INCLUDED_)
#define AFX_FILEMAPPINGRECVDLG_H__5FA6B5AB_BB2B_40B9_AAF4_CDE644468B05__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CFileMappingRecvDlg dialog

class CFileMappingRecvDlg : public CDialog
{
// Construction
public:
	CFileMappingRecvDlg(CWnd* pParent = NULL);	// standard constructor
	~CFileMappingRecvDlg();
// Dialog Data
	//{{AFX_DATA(CFileMappingRecvDlg)
	enum { IDD = IDD_FILEMAPPINGRECV_DIALOG };
	CString	m_strText;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileMappingRecvDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	HANDLE m_hMapObject;
	LPSTR m_pszMapView;
	// Generated message map functions
	//{{AFX_MSG(CFileMappingRecvDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEMAPPINGRECVDLG_H__5FA6B5AB_BB2B_40B9_AAF4_CDE644468B05__INCLUDED_)
