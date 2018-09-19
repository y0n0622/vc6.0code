// MoveTextView.cpp : implementation of the CMoveTextView class
//

#include "stdafx.h"
#include "MoveText.h"

#include "MoveTextDoc.h"
#include "MoveTextView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMoveTextView

IMPLEMENT_DYNCREATE(CMoveTextView, CView)

BEGIN_MESSAGE_MAP(CMoveTextView, CView)
	//{{AFX_MSG_MAP(CMoveTextView)
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMoveTextView construction/destruction

CMoveTextView::CMoveTextView()
{
	// TODO: add construction code here
	x = 50;
	y = 50;
	m_string.Empty();
}

CMoveTextView::~CMoveTextView()
{
}

BOOL CMoveTextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CMoveTextView drawing

void CMoveTextView::OnDraw(CDC* pDC)
{
	CMoveTextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	pDC->TextOut(x, y, m_string);
}

/////////////////////////////////////////////////////////////////////////////
// CMoveTextView printing

BOOL CMoveTextView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMoveTextView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMoveTextView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CMoveTextView diagnostics

#ifdef _DEBUG
void CMoveTextView::AssertValid() const
{
	CView::AssertValid();
}

void CMoveTextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMoveTextDoc* CMoveTextView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMoveTextDoc)));
	return (CMoveTextDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMoveTextView message handlers

void CMoveTextView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	m_string += nChar;
	Invalidate();
	CView::OnChar(nChar, nRepCnt, nFlags);
}

void CMoveTextView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	// TODO: Add your message handler code here and/or call default
	switch(nChar)
	{
	case VK_LEFT:
		x--;
		break;
	case VK_RIGHT:
		x++;
		break;
	case VK_UP:
		y--;
		break;
	case VK_DOWN:
		y++;
		break;
	}
	Invalidate();
	CView::OnKeyDown(nChar, nRepCnt, nFlags);
}
