// VCActiveEx.h : main header file for the VCACTIVEEX application
//

#if !defined(AFX_VCACTIVEEX_H__D3BA6399_520A_49B8_8304_07F516A855CD__INCLUDED_)
#define AFX_VCACTIVEEX_H__D3BA6399_520A_49B8_8304_07F516A855CD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CVCActiveExApp:
// See VCActiveEx.cpp for the implementation of this class
//

class CVCActiveExApp : public CWinApp
{
public:
	CVCActiveExApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVCActiveExApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CVCActiveExApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VCACTIVEEX_H__D3BA6399_520A_49B8_8304_07F516A855CD__INCLUDED_)
