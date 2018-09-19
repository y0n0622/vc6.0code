#define MAX_STRINGS 12

class CMyApp:public CWinApp
{
public:
	virtual BOOL InitInstance();

};
class CMainWindow:public CWnd
{
protected:
	int m_cxChar;
	int m_cyChar;
	int m_cyLine;
	int m_nTextPos;
	int m_nTabStops[7];
	int m_nTextLimit;
	int m_nMsgPos;

	HCURSOR m_hCursorArrow;
	HCURSOR m_hCursorIBeam;

	CPoint m_ptTextOrigin;
	CPoint m_ptHeaderOrigin;
	CPoint m_ptUpperMsgOrigin;
	CPoint m_ptLowerMsgOrigin;
	CPoint m_ptCaretPos;

	CRect m_rcTextBox;
	CRect m_rcTextBoxBorder;
	CRect m_rcMsgBoxBorder;
	CRect m_rcScroll;

	CString m_strInputText;
	CString m_strMessages[MAX_STRINGS];

public:
	CMainWindow();

protected:
	int GetNearestPos(CPoint point);
	void PositionCaret(CDC *pDC = NULL);
	void DrawInputText(CDC *pDC);
	void ShowMessage(LPCTSTR pszMessage, UINT nChar, UINT nRepCnt, UINT nFlags);
	void DrawMessageHeader(CDC *pDC);
	void DrawMessages(CDC *pDC);

protected:
	virtual void PostNcDestroy();

	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd *pWnd);
	afx_msg void OnKillFocus(CWnd *pWnd);
	afx_msg BOOL OnSetCursor(CWnd *pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSysChar(UINT nChar, UINT nRepCnt, UINT nFlags);

	DECLARE_MESSAGE_MAP()
};