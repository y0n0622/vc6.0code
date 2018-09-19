// MappingFileReadDlg.h : header file
//

#if !defined(AFX_MAPPINGFILEREADDLG_H__9D6B591B_817E_4CCA_A845_3C02D875BA95__INCLUDED_)
#define AFX_MAPPINGFILEREADDLG_H__9D6B591B_817E_4CCA_A845_3C02D875BA95__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CMappingFileReadDlg dialog

class CMappingFileReadDlg : public CDialog
{
// Construction
public:
	CMappingFileReadDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CMappingFileReadDlg)
	enum { IDD = IDD_MAPPINGFILEREAD_DIALOG };
	CString	m_strText;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMappingFileReadDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	BOOL LoadFile(CString strFileName);
	// Generated message map functions
	//{{AFX_MSG(CMappingFileReadDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPPINGFILEREADDLG_H__9D6B591B_817E_4CCA_A845_3C02D875BA95__INCLUDED_)
