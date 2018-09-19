#if !defined(AFX_MFCSIMPLE_H__825BF6FE_BC96_4D10_A09E_2DABEDB5862F__INCLUDED_)
#define AFX_MFCSIMPLE_H__825BF6FE_BC96_4D10_A09E_2DABEDB5862F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// MFCSimple.h : main header file for MFCSIMPLE.DLL

#if !defined( __AFXCTL_H__ )
	#error include 'afxctl.h' before including this file
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CMFCSimpleApp : See MFCSimple.cpp for implementation.

class CMFCSimpleApp : public COleControlModule
{
public:
	BOOL InitInstance();
	int ExitInstance();
};

extern const GUID CDECL _tlid;
extern const WORD _wVerMajor;
extern const WORD _wVerMinor;

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCSIMPLE_H__825BF6FE_BC96_4D10_A09E_2DABEDB5862F__INCLUDED)
