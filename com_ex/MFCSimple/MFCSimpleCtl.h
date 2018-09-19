#if !defined(AFX_MFCSIMPLECTL_H__2B94DA32_EAF5_48B7_8B2F_E8AB7412BD7E__INCLUDED_)
#define AFX_MFCSIMPLECTL_H__2B94DA32_EAF5_48B7_8B2F_E8AB7412BD7E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

// MFCSimpleCtl.h : Declaration of the CMFCSimpleCtrl ActiveX Control class.

/////////////////////////////////////////////////////////////////////////////
// CMFCSimpleCtrl : See MFCSimpleCtl.cpp for implementation.

class CMFCSimpleCtrl : public COleControl
{
	DECLARE_DYNCREATE(CMFCSimpleCtrl)

// Constructor
public:
	CMFCSimpleCtrl();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMFCSimpleCtrl)
	public:
	virtual void OnDraw(CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid);
	virtual void DoPropExchange(CPropExchange* pPX);
	virtual void OnResetState();
	//}}AFX_VIRTUAL

// Implementation
protected:
	~CMFCSimpleCtrl();

	DECLARE_OLECREATE_EX(CMFCSimpleCtrl)    // Class factory and guid
	DECLARE_OLETYPELIB(CMFCSimpleCtrl)      // GetTypeInfo
	DECLARE_PROPPAGEIDS(CMFCSimpleCtrl)     // Property page IDs
	DECLARE_OLECTLTYPE(CMFCSimpleCtrl)		// Type name and misc status

// Message maps
	//{{AFX_MSG(CMFCSimpleCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

// Dispatch maps
	//{{AFX_DISPATCH(CMFCSimpleCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()

// Event maps
	//{{AFX_EVENT(CMFCSimpleCtrl)
		// NOTE - ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT
	DECLARE_EVENT_MAP()

// Dispatch and event IDs
public:
	enum {
	//{{AFX_DISP_ID(CMFCSimpleCtrl)
		// NOTE: ClassWizard will add and remove enumeration elements here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISP_ID
	};
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MFCSIMPLECTL_H__2B94DA32_EAF5_48B7_8B2F_E8AB7412BD7E__INCLUDED)
