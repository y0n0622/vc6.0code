#if !defined(AFX_NEWSOCKET_H__E6B6C162_2DE7_4F08_B071_5683C2BD4350__INCLUDED_)
#define AFX_NEWSOCKET_H__E6B6C162_2DE7_4F08_B071_5683C2BD4350__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// NewSocket.h : header file
//



/////////////////////////////////////////////////////////////////////////////
// CNewSocket command target

class CNewSocket : public CAsyncSocket
{
// Attributes
public:

// Operations
public:
	CNewSocket();
	virtual ~CNewSocket();
	int m_nLength;
	char m_szBuffer[4096];
// Overrides
public:
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CNewSocket)
	public:
	virtual void OnReceive(int nErrorCode);
	virtual void OnSend(int nErrorCode);
	//}}AFX_VIRTUAL

	// Generated message map functions
	//{{AFX_MSG(CNewSocket)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

// Implementation
protected:
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_NEWSOCKET_H__E6B6C162_2DE7_4F08_B071_5683C2BD4350__INCLUDED_)
