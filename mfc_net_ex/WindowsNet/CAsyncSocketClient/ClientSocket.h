#if !defined(AFX_CLIENTSOCKET_H__46FFCE63_0211_4BAF_9277_3DB5D9C89378__INCLUDED_)
#define AFX_CLIENTSOCKET_H__46FFCE63_0211_4BAF_9277_3DB5D9C89378__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientSocket.h : header file
//
#include "CAsyncSocketClientDlg.h"


/////////////////////////////////////////////////////////////////////////////
// CClientSocket command target

class CClientSocket : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	CClientSocket();
	virtual ~CClientSocket();

// Overrides
public:
	BOOL m_bConnected;
	char m_szBuffer[4096];
	int m_nLength;
//	CCAsyncSocketClientDlg* pDlg;
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientSocket)
	public:
	virtual void OnConnect(int nErrorCode);
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CClientSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSOCKET_H__46FFCE63_0211_4BAF_9277_3DB5D9C89378__INCLUDED_)
