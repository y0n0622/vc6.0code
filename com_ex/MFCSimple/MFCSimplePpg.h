#if !defined(AFX_MFCSIMPLEPPG_H__3D4CEBCA_2B33_493B_9F11_4DAB9B3BCA81__INCLUDED_)
#define AFX_MFCSIMPLEPPG_H__3D4CEBCA_2B33_493B_9F11_4DAB9B3BCA81__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// MFCSimplePpg.h : Declaration of the CMFCSimplePropPage property page class.

////////////////////////////////////////////////////////////////////////////
// CMFCSimplePropPage : See MFCSimplePpg.cpp.cpp for implementation.

class CMFCSimplePropPage : public COlePropertyPage
{
	DECLARE_DYNCREATE(CMFCSimplePropPage)
	DECLARE_OLECREATE_EX(CMFCSimplePropPage)

// Constructor
public:
	CMFCSimplePropPage();

// Dialog Data
	//{{AFX_DATA(CMFCSimplePropPage)
	enum { IDD = IDD_PROPPAGE_MFCSIMPLE };
		// NOTE - ClassWizard will add data members here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA

// Implementation
protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Message maps
protected:
	//{{AFX_MSG(CMFCSimplePropPage)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCSIMPLEPPG_H__3D4CEBCA_2B33_493B_9F11_4DAB9B3BCA81__INCLUDED)
