// ChildView.cpp : implementation of the CChildView class
//

#include "stdafx.h"
#include "Colors.h"
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
	m_nColor = 0;
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
	ON_WM_CONTEXTMENU()
	//}}AFX_MSG_MAP

	ON_COMMAND_RANGE(ID_COLOR_RED, ID_COLOR_BLUE, OnColor)
	ON_UPDATE_COMMAND_UI_RANGE(ID_COLOR_RED, ID_COLOR_BLUE, OnUpdateColor)
END_MESSAGE_MAP()
const COLORREF CChildView::m_clrColors[5] = {
					RGB(255, 0, 0),
					RGB(255, 255, 0),
					RGB(0, 255, 0),
					RGB(0, 255, 255),
					RGB(0, 0, 255),
					};

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

	CBrush brush(m_clrColors[m_nColor]);

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

void CChildView::OnContextMenu(CWnd* pWnd, CPoint point) 
{
	// TODO: Add your message handler code here
	CRect rcClient;
	GetClientRect(&rcClient);
	int cx = rcClient.Width() / 2;
	int cy = rcClient.Height() / 2;
	CRect rcShape(cx - 45, cy - 45, cx + 45, cy + 45);
	CPoint pos = point;
	ScreenToClient(&pos);
	CPoint points[3];
	BOOL bShapeClicked = FALSE;
	int dx, dy;

	switch(m_nShape)
	{
	case 0:
		dx = pos.x - cx;
		dy = pos.y - cy;
		if((dx * dx) + (dy * dy) <= (45 * 45))
			bShapeClicked = TRUE;

		break;

	case 1:
		if(rcShape.PtInRect(pos))
		{
			dx = min(pos.x - rcShape.left, rcShape.right - pos.x);
			if((rcShape.bottom - pos.y) < (2 * dx))
				bShapeClicked = TRUE;
		}
		break;
	case 2:
		if(rcShape.PtInRect(pos))
		{
			bShapeClicked = TRUE;
		}
		break;
	}

	if(bShapeClicked)
	{
		CMenu menu;
		menu.LoadMenu(IDR_CONTEXTMENU);
		CMenu *pContextMenu = menu.GetSubMenu(0);

		for(int i = 0; i < 5; i++)
		{
			pContextMenu->ModifyMenu(ID_COLOR_RED + i, 
				MF_BYCOMMAND|MF_OWNERDRAW, ID_COLOR_RED + i);


		}

		pContextMenu->TrackPopupMenu(TPM_LEFTALIGN|TPM_LEFTBUTTON|TPM_RIGHTBUTTON, point.x, point.y, AfxGetMainWnd());
		return ;
	}
	CWnd::OnContextMenu(pWnd, point);
}

void CChildView::OnColor(UINT nID) 
{
	// TODO: Add your message handler code here
	m_nColor = nID - ID_COLOR_RED;
	Invalidate();
}

void CChildView::OnUpdateColor(CCmdUI *pCmdUI) 
{
	// TODO: Add your message handler code here
	pCmdUI->SetCheck((int)pCmdUI->m_nID - ID_COLOR_RED == m_nColor);
}