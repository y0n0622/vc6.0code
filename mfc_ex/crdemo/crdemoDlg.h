// crdemoDlg.h : header file
//

#if !defined(AFX_CRDEMODLG_H__502E4A9B_9448_4DE8_BF80_FD1D7BE1B7DC__INCLUDED_)
#define AFX_CRDEMODLG_H__502E4A9B_9448_4DE8_BF80_FD1D7BE1B7DC__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CCrdemoDlg dialog

class CCrdemoDlg : public CDialog
{
// Construction
public:
	CCrdemoDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CCrdemoDlg)
	enum { IDD = IDD_CRDEMO_DIALOG };
	CButton	m_radio1;
	CButton	m_check3;
	CButton	m_check2;
	CButton	m_check1;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCrdemoDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CCrdemoDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnCheck3();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CRDEMODLG_H__502E4A9B_9448_4DE8_BF80_FD1D7BE1B7DC__INCLUDED_)
