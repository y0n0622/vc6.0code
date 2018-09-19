// CSocketServer.h : main header file for the CSOCKETSERVER application
//

#if !defined(AFX_CSOCKETSERVER_H__3B6758CD_393F_4537_A16D_F83AFA97D5D5__INCLUDED_)
#define AFX_CSOCKETSERVER_H__3B6758CD_393F_4537_A16D_F83AFA97D5D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCSocketServerApp:
// See CSocketServer.cpp for the implementation of this class
//

class CCSocketServerApp : public CWinApp
{
public:
	CCSocketServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCSocketServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCSocketServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSOCKETSERVER_H__3B6758CD_393F_4537_A16D_F83AFA97D5D5__INCLUDED_)
