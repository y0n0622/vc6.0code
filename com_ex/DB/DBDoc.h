// DBDoc.h : interface of the CDBDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBDOC_H__8BC815B8_A5EF_4552_A0E9_D092A8B16178__INCLUDED_)
#define AFX_DBDOC_H__8BC815B8_A5EF_4552_A0E9_D092A8B16178__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
#include "../com_text/DBsrv.h"

class CDBDoc : public CDocument
{
protected: // create from serialization only
	CDBDoc();
	DECLARE_DYNCREATE(CDBDoc)

// Attributes
public:
    DBsrv *m_pDB;
	CString m_csData;
	int m_nCount;
	short m_nTable;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDBDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDBDoc)
	afx_msg void OnCreatetable();
	afx_msg void OnReadtable();
	afx_msg void OnWritetable();
	afx_msg void OnUpdateWritetable(CCmdUI* pCmdUI);
	afx_msg void OnUpdateReadtable(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBDOC_H__8BC815B8_A5EF_4552_A0E9_D092A8B16178__INCLUDED_)
