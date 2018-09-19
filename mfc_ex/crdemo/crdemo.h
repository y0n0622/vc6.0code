// crdemo.h : main header file for the CRDEMO application
//

#if !defined(AFX_CRDEMO_H__109D4D2C_86D0_4E9A_9E59_539A0874513B__INCLUDED_)
#define AFX_CRDEMO_H__109D4D2C_86D0_4E9A_9E59_539A0874513B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CCrdemoApp:
// See crdemo.cpp for the implementation of this class
//

class CCrdemoApp : public CWinApp
{
public:
	CCrdemoApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCrdemoApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CCrdemoApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CRDEMO_H__109D4D2C_86D0_4E9A_9E59_539A0874513B__INCLUDED_)
