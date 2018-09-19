// FileMapping.h : main header file for the FILEMAPPING application
//

#if !defined(AFX_FILEMAPPING_H__724F4849_4C90_44BD_9DF8_37BB56724FED__INCLUDED_)
#define AFX_FILEMAPPING_H__724F4849_4C90_44BD_9DF8_37BB56724FED__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CFileMappingApp:
// See FileMapping.cpp for the implementation of this class
//

class CFileMappingApp : public CWinApp
{
public:
	CFileMappingApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CFileMappingApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CFileMappingApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_FILEMAPPING_H__724F4849_4C90_44BD_9DF8_37BB56724FED__INCLUDED_)
