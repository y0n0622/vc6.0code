// DBView.cpp : implementation of the CDBView class
//

#include "stdafx.h"
#include "DB.h"

#include "DBDoc.h"
#include "DBView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDBView

IMPLEMENT_DYNCREATE(CDBView, CView)

BEGIN_MESSAGE_MAP(CDBView, CView)
	//{{AFX_MSG_MAP(CDBView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDBView construction/destruction

CDBView::CDBView()
{
	// TODO: add construction code here

}

CDBView::~CDBView()
{
}

BOOL CDBView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CDBView drawing

void CDBView::OnDraw(CDC* pDC)
{
	CDBDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(10, 10, pDoc->m_csData);
	
}

/////////////////////////////////////////////////////////////////////////////
// CDBView diagnostics

#ifdef _DEBUG
void CDBView::AssertValid() const
{
	CView::AssertValid();
}

void CDBView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CDBDoc* CDBView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CDBDoc)));
	return (CDBDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDBView message handlers
