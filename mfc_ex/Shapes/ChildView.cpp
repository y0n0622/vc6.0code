// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Shapes.h"
#include "ChildView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildView

CChildView::CChildView()
{
	m_nShape = 1;
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView,CWnd )
	//{{AFX_MSG_MAP(CChildView)
	ON_WM_PAINT()
	ON_COMMAND(ID_SHAPE_CIRCLE, OnShapeCircle)
	ON_COMMAND(ID_SHAPE_SQUARE, OnShapeSquare)
	ON_COMMAND(ID_SHAPE_TRIANGLE, OnShapeTriangle)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_CIRCLE, OnUpdateShapeCircle)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_SQUARE, OnUpdateShapeSquare)
	ON_UPDATE_COMMAND_UI(ID_SHAPE_TRIANGLE, OnUpdateShapeTriangle)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(NULL, IDC_ARROW), HBRUSH(COLOR_WINDOW+1), NULL);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	CPoint points[3];
	
	CRect rcClient;
	GetClientRect(&rcClient);
	int cx = rcClient.Width() / 2;
	int cy = rcClient.Height() /2;
	CRect rcShape(cx - 45, cy - 45, cx + 45, cy + 45);

	CBrush brush(RGB(255, 0, 0));

	CBrush *pOldBrush = dc.SelectObject(&brush);
	switch(m_nShape)
	{
	case 0:
		dc.Ellipse(rcShape);
		break;

	case 1:
		points[0].x = cx - 45;
		points[0].y = cy + 45;
		points[1].x = cx;
		points[1].y = cy - 45;
		points[2].x = cx + 45;
		points[2].y = cy + 45;
		dc.Polygon(points, 3);
		break;

	case 2:
		dc.Rectangle(rcShape);
		break;
	}
	dc.SelectObject(pOldBrush);

	// Do not call CWnd::OnPaint() for painting messages
}


void CChildView::OnShapeCircle() 
{
	// TODO: Add your command handler code here
	m_nShape = 0;
	Invalidate();
}

void CChildView::OnShapeSquare() 
{
	// TODO: Add your command handler code here
	m_nShape = 2;
	Invalidate();
}

void CChildView::OnShapeTriangle() 
{
	// TODO: Add your command handler code here
	m_nShape = 1;
	Invalidate();
}

void CChildView::OnUpdateShapeCircle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nShape == 0);
}

void CChildView::OnUpdateShapeSquare(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nShape == 2);
}

void CChildView::OnUpdateShapeTriangle(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->SetCheck(m_nShape == 1);
}
