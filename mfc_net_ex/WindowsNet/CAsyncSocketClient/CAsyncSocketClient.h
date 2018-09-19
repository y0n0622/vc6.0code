// CAsyncSocketClient.h : main header file for the CASYNCSOCKETCLIENT application
//

#if !defined(AFX_CASYNCSOCKETCLIENT_H__F437898C_B477_4AF3_99AC_FDE32B80E415__INCLUDED_)
#define AFX_CASYNCSOCKETCLIENT_H__F437898C_B477_4AF3_99AC_FDE32B80E415__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCAsyncSocketClientApp:
// See CAsyncSocketClient.cpp for the implementation of this class
//

class CCAsyncSocketClientApp : public CWinApp
{
public:
	CCAsyncSocketClientApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCAsyncSocketClientApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCAsyncSocketClientApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CASYNCSOCKETCLIENT_H__F437898C_B477_4AF3_99AC_FDE32B80E415__INCLUDED_)
