class CMyApp : public CWinApp
{
public:
	virtual BOOL InitInstance();
};
class CMainWindow : public CFrameWnd
{

protected:

	int m_nCellWidth;
	int m_nCellHeight;
	int m_nRibbonWidth;
	int m_nViewWidth;
	int m_nViewHeight;
	int m_nHScrollPos;
	int m_nVScrollPos;
	int m_nHPageSize;
	int m_nVPageSize;


public:
	CMainWindow();


protected:
	afx_msg void OnPaint();

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnHScroll(UINT nCode, UINT nPos, CScrollBar *pScrollBar);
	afx_msg void OnVScroll(UINT nCode, UINT nPos, CScrollBar *pScrollBar);

	DECLARE_MESSAGE_MAP();

	
	
};