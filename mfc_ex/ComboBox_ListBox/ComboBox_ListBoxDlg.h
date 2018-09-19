// ComboBox_ListBoxDlg.h : header file
//

#if !defined(AFX_COMBOBOX_LISTBOXDLG_H__C6D7F24B_C22D_4F54_A080_550A6B7802A6__INCLUDED_)
#define AFX_COMBOBOX_LISTBOXDLG_H__C6D7F24B_C22D_4F54_A080_550A6B7802A6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CComboBox_ListBoxDlg dialog

class CComboBox_ListBoxDlg : public CDialog
{
// Construction
public:
	CComboBox_ListBoxDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CComboBox_ListBoxDlg)
	enum { IDD = IDD_COMBOBOX_LISTBOX_DIALOG };
	CListBox	m_lst;
	CComboBox	m_cmb;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboBox_ListBoxDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CComboBox_ListBoxDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOBOX_LISTBOXDLG_H__C6D7F24B_C22D_4F54_A080_550A6B7802A6__INCLUDED_)
