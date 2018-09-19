// MoveTextView.h : interface of the CMoveTextView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MOVETEXTVIEW_H__DA9CC3C7_CCEE_4E24_853B_23C1AC703E29__INCLUDED_)
#define AFX_MOVETEXTVIEW_H__DA9CC3C7_CCEE_4E24_853B_23C1AC703E29__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CMoveTextView : public CView
{
protected: // create from serialization only
	CMoveTextView();
	DECLARE_DYNCREATE(CMoveTextView)

// Attributes
public:
	CMoveTextDoc* GetDocument();
	
	CString m_string;
	int x;
	int y;
// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMoveTextView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMoveTextView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CMoveTextView)
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in MoveTextView.cpp
inline CMoveTextDoc* CMoveTextView::GetDocument()
   { return (CMoveTextDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOVETEXTVIEW_H__DA9CC3C7_CCEE_4E24_853B_23C1AC703E29__INCLUDED_)
