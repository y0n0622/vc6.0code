class CMyApp:public CWinApp
{
public:
	virtual BOOL InitInstance();

};
class CMainWindow:public CFrameWnd
{
protected:
	BOOL m_bTracking;
	BOOL m_bCaptureEnabled;
	CPoint m_ptFrom;
	CPoint m_ptTo;
	
	void InvertLine(CDC *pDC, CPoint ptFrom, CPoint ptTo);

public:
	CMainWindow();

protected:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnNcLButtonDown(UINT nHitTest, CPoint point);

	DECLARE_MESSAGE_MAP()
};