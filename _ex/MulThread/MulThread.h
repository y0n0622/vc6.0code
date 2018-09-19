// MulThread.h : main header file for the MULTHREAD application
//

#if !defined(AFX_MULTHREAD_H__E50C4147_D4E8_4EE0_8205_9EEABCF74B54__INCLUDED_)
#define AFX_MULTHREAD_H__E50C4147_D4E8_4EE0_8205_9EEABCF74B54__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMulThreadApp:
// See MulThread.cpp for the implementation of this class
//

class CMulThreadApp : public CWinApp
{
public:
	CMulThreadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMulThreadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMulThreadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MULTHREAD_H__E50C4147_D4E8_4EE0_8205_9EEABCF74B54__INCLUDED_)
