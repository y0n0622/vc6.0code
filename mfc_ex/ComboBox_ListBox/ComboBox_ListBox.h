// ComboBox_ListBox.h : main header file for the COMBOBOX_LISTBOX application
//

#if !defined(AFX_COMBOBOX_LISTBOX_H__F2445F8A_85D2_4853_9EFB_72402365C15E__INCLUDED_)
#define AFX_COMBOBOX_LISTBOX_H__F2445F8A_85D2_4853_9EFB_72402365C15E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CComboBox_ListBoxApp:
// See ComboBox_ListBox.cpp for the implementation of this class
//

class CComboBox_ListBoxApp : public CWinApp
{
public:
	CComboBox_ListBoxApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CComboBox_ListBoxApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CComboBox_ListBoxApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COMBOBOX_LISTBOX_H__F2445F8A_85D2_4853_9EFB_72402365C15E__INCLUDED_)
