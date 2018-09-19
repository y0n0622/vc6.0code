// MoveTextDoc.h : interface of the CMoveTextDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOVETEXTDOC_H__CC19184F_4541_40BF_B090_D9D5DAA5D729__INCLUDED_)
#define AFX_MOVETEXTDOC_H__CC19184F_4541_40BF_B090_D9D5DAA5D729__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMoveTextDoc : public CDocument
{
protected: // create from serialization only
	CMoveTextDoc();
	DECLARE_DYNCREATE(CMoveTextDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMoveTextDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMoveTextDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMoveTextDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOVETEXTDOC_H__CC19184F_4541_40BF_B090_D9D5DAA5D729__INCLUDED_)
