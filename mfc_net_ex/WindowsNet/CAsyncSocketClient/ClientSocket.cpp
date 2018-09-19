// ClientSocket.cpp : implementation file
//

#include "stdafx.h"
#include "CAsyncSocketClient.h"

#include "ClientSocket.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CClientSocket

CClientSocket::CClientSocket()
{
}

CClientSocket::~CClientSocket()
{
}


// Do not edit the following lines, which are needed by ClassWizard.
#if 0
BEGIN_MESSAGE_MAP(CClientSocket, CAsyncSocket)
	//{{AFX_MSG_MAP(CClientSocket)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()
#endif	// 0

/////////////////////////////////////////////////////////////////////////////
// CClientSocket member functions

void CClientSocket::OnConnect(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	if(nErrorCode == 0)
	{
		m_bConnected = TRUE;
		CCAsyncSocketClientApp* pApp = (CCAsyncSocketClientApp*)AfxGetApp();
		CCAsyncSocketClientDlg* pDlg = (CCAsyncSocketClientDlg*)pApp->m_pMainWnd;
		memcpy(m_szBuffer, "Á¬½Óµ½£º", 13);
		strncat(m_szBuffer, pDlg->m_szServerAdr, sizeof(pDlg->m_szServerAdr));
		pDlg->m_MsgR->InsertString(0, m_szBuffer);
		pDlg->GetDlgItem(IDC_SEND)->EnableWindow(true);
		AsyncSelect(FD_READ);
	}
	CAsyncSocket::OnConnect(nErrorCode);
}

void CClientSocket::OnReceive(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	m_nLength = Receive(m_szBuffer, sizeof(m_szBuffer), 0);

	CCAsyncSocketClientApp* pApp = (CCAsyncSocketClientApp*)AfxGetApp();
	CCAsyncSocketClientDlg* pDlg = (CCAsyncSocketClientDlg*)pApp->m_pMainWnd;
	pDlg->m_MsgR->InsertString(0, m_szBuffer);
	memset(m_szBuffer, 0, sizeof(m_szBuffer));

	CAsyncSocket::OnReceive(nErrorCode);
}

void CClientSocket::OnSend(int nErrorCode) 
{
	// TODO: Add your specialized code here and/or call the base class
	Send(m_szBuffer, m_nLength, 0);
	m_nLength = 0;
	memset(m_szBuffer, 0, sizeof(m_szBuffer));
	AsyncSelect(FD_READ);
	CAsyncSocket::OnSend(nErrorCode);
}
