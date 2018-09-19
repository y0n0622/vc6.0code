// NewSocket.cpp : implementation file
//

#include "stdafx.h"
#include "CAsyncSocketSever.h"
#include "NewSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CNewSocket

CNewSocket::CNewSocket()
{
}

CNewSocket::~CNewSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CNewSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CNewSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CNewSocket member functions

void CNewSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
//	char m_szBuffer[4096];
	m_nLength = Receive(m_szBuffer, sizeof(m_szBuffer), 0);
	AsyncSelect(FD_WRITE);

	CAsyncSocket::OnReceive(nErrorCode);
}

void CNewSocket::OnSend(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	char m_sendBuffer[4096];
//	char m_szBuffer[4096];
	memcpy(m_sendBuffer, "服务器转发：", 24);
	strncat(m_sendBuffer, m_szBuffer, m_nLength);
	Send(m_sendBuffer, sizeof(m_sendBuffer));
	AsyncSelect(FD_READ);
	CAsyncSocket::OnSend(nErrorCode);
}
