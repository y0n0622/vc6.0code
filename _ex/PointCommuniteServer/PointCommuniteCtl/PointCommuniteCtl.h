// PointCommuniteCtl.h : main header file for the POINTCOMMUNITECTL application
//

#if !defined(AFX_POINTCOMMUNITECTL_H__263C94C1_15B0_4467_9B94_D48D7A1952A8__INCLUDED_)
#define AFX_POINTCOMMUNITECTL_H__263C94C1_15B0_4467_9B94_D48D7A1952A8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPointCommuniteCtlApp:
// See PointCommuniteCtl.cpp for the implementation of this class
//

class CPointCommuniteCtlApp : public CWinApp
{
public:
	CPointCommuniteCtlApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPointCommuniteCtlApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPointCommuniteCtlApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POINTCOMMUNITECTL_H__263C94C1_15B0_4467_9B94_D48D7A1952A8__INCLUDED_)
