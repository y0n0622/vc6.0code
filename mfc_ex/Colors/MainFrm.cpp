// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "Colors.h"

#include "MainFrm.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_SETFOCUS()
	ON_WM_CREATE()
	ON_WM_DRAWITEM()
	ON_WM_MEASUREITEM()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame()
{
	// TODO: add member initialization code here
	
}

CMainFrame::~CMainFrame()
{
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	cs.dwExStyle &= ~WS_EX_CLIENTEDGE;
	cs.lpszClass = AfxRegisterWndClass(0);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers
void CMainFrame::OnSetFocus(CWnd* pOldWnd)
{
	// forward focus to the view window
	m_wndView.SetFocus();
}

BOOL CMainFrame::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo)
{
	// let the view have first crack at the command
	if (m_wndView.OnCmdMsg(nID, nCode, pExtra, pHandlerInfo))
		return TRUE;

	// otherwise, do default handling
	return CFrameWnd::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}


int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;
	
	// TODO: Add your specialized creation code here
	if(!m_wndView.Create(NULL, NULL, AFX_WS_DEFAULT_VIEW, 
		CRect(0, 0, 0, 0), this, AFX_IDW_PANE_FIRST, NULL))
	{
		TRACE0("Failed to create view window\n");
		return -1;
	}
	return 0;
}

void CMainFrame::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct) 
{
	// TODO: Add your message handler code here and/or call default
	BITMAP bm;
	CBitmap bitmap;
	bitmap.LoadOEMBitmap(OBM_CHECKBOXES);
	bitmap.GetObject(sizeof(bm), &bm);

	CDC dc;
	dc.Attach(lpDrawItemStruct->hDC);

	CBrush *pBrush = new CBrush(::GetSysColor((lpDrawItemStruct->itemState &ODS_SELECTED) ? COLOR_HIGHLIGHT : COLOR_MENU));
	dc.FrameRect(&(lpDrawItemStruct->rcItem), pBrush);
	delete pBrush;

	if(lpDrawItemStruct->itemState &ODS_CHECKED)
	{
		CDC dcMem;
		dcMem.CreateCompatibleDC(&dc);
		CBitmap *pOldBitmap = dcMem.SelectObject(&bitmap);

		dc.BitBlt(lpDrawItemStruct->rcItem.left + 4, 
			lpDrawItemStruct->rcItem.top + (((lpDrawItemStruct->rcItem.bottom - lpDrawItemStruct->rcItem.top) - bm.bmHeight) / 2),
			bm.bmWidth, bm.bmHeight, &dcMem,
			0, 0, SRCCOPY);
		dcMem.SelectObject(pOldBitmap);
	}

	UINT itemID = lpDrawItemStruct->itemID &0xFFFF;
	pBrush = new CBrush(m_wndView.m_clrColors[itemID - ID_COLOR_RED]);
	CRect rect = lpDrawItemStruct->rcItem;
	rect.DeflateRect(6, 4);
	rect.left += bm.bmWidth;
	dc.FillRect(rect, pBrush);
	delete pBrush;
	dc.Detach();
	CFrameWnd::OnDrawItem(nIDCtl, lpDrawItemStruct);
}

void CMainFrame::OnMeasureItem(int nIDCtl, LPMEASUREITEMSTRUCT lpMeasureItemStruct) 
{
	// TODO: Add your message handler code here and/or call default
	lpMeasureItemStruct->itemWidth = ::GetSystemMetrics(SM_CYMENU) * 4;
	lpMeasureItemStruct->itemHeight = ::GetSystemMetrics(SM_CYMENU);
	CFrameWnd::OnMeasureItem(nIDCtl, lpMeasureItemStruct);
}
