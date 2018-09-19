// MoveText.h : main header file for the MOVETEXT application
//

#if !defined(AFX_MOVETEXT_H__5DED4D94_BBD3_49F1_A7CC_D9369A591FEF__INCLUDED_)
#define AFX_MOVETEXT_H__5DED4D94_BBD3_49F1_A7CC_D9369A591FEF__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMoveTextApp:
// See MoveText.cpp for the implementation of this class
//

class CMoveTextApp : public CWinApp
{
public:
	CMoveTextApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMoveTextApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CMoveTextApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MOVETEXT_H__5DED4D94_BBD3_49F1_A7CC_D9369A591FEF__INCLUDED_)
