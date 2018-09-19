// MappingFileRead.h : main header file for the MAPPINGFILEREAD application
//

#if !defined(AFX_MAPPINGFILEREAD_H__21B47749_3577_4544_B1A5_59C4301F5EA7__INCLUDED_)
#define AFX_MAPPINGFILEREAD_H__21B47749_3577_4544_B1A5_59C4301F5EA7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CMappingFileReadApp:
// See MappingFileRead.cpp for the implementation of this class
//

class CMappingFileReadApp : public CWinApp
{
public:
	CMappingFileReadApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMappingFileReadApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CMappingFileReadApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAPPINGFILEREAD_H__21B47749_3577_4544_B1A5_59C4301F5EA7__INCLUDED_)
