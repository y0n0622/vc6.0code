// PointCommuniteServer.h : main header file for the POINTCOMMUNITESERVER application
//

#if !defined(AFX_POINTCOMMUNITESERVER_H__9C8EE211_93C7_47AA_A595_4AF8AF95C05A__INCLUDED_)
#define AFX_POINTCOMMUNITESERVER_H__9C8EE211_93C7_47AA_A595_4AF8AF95C05A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CPointCommuniteServerApp:
// See PointCommuniteServer.cpp for the implementation of this class
//

class CPointCommuniteServerApp : public CWinApp
{
public:
	CPointCommuniteServerApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPointCommuniteServerApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CPointCommuniteServerApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POINTCOMMUNITESERVER_H__9C8EE211_93C7_47AA_A595_4AF8AF95C05A__INCLUDED_)
