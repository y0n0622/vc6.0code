// VCActiveExDlg.h : header file
//

#if !defined(AFX_VCACTIVEEXDLG_H__80D7C6F4_8730_4624_8574_B20652C66422__INCLUDED_)
#define AFX_VCACTIVEEXDLG_H__80D7C6F4_8730_4624_8574_B20652C66422__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CVCActiveExDlg dialog

class CVCActiveExDlg : public CDialog
{
// Construction
public:
	CVCActiveExDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CVCActiveExDlg)
	enum { IDD = IDD_VCACTIVEEX_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVCActiveExDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVCActiveExDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VCACTIVEEXDLG_H__80D7C6F4_8730_4624_8574_B20652C66422__INCLUDED_)
