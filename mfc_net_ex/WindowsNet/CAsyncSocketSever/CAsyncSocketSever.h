// CAsyncSocketSever.h : main header file for the CASYNCSOCKETSEVER application
//

#if !defined(AFX_CASYNCSOCKETSEVER_H__DB3BD675_7C19_49C6_847D_905787D9CB36__INCLUDED_)
#define AFX_CASYNCSOCKETSEVER_H__DB3BD675_7C19_49C6_847D_905787D9CB36__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCAsyncSocketSeverApp:
// See CAsyncSocketSever.cpp for the implementation of this class
//

class CCAsyncSocketSeverApp : public CWinApp
{
public:
	CCAsyncSocketSeverApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCAsyncSocketSeverApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCAsyncSocketSeverApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CASYNCSOCKETSEVER_H__DB3BD675_7C19_49C6_847D_905787D9CB36__INCLUDED_)
