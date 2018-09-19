// MFCSimpleCtl.cpp : Implementation of the CMFCSimpleCtrl ActiveX Control class.

#include "stdafx.h"
#include "MFCSimple.h"
#include "MFCSimpleCtl.h"
#include "MFCSimplePpg.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CMFCSimpleCtrl, COleControl)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CMFCSimpleCtrl, COleControl)
	//{{AFX_MSG_MAP(CMFCSimpleCtrl)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
	ON_OLEVERB(AFX_IDS_VERB_PROPERTIES, OnProperties)
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Dispatch map

BEGIN_DISPATCH_MAP(CMFCSimpleCtrl, COleControl)
	//{{AFX_DISPATCH_MAP(CMFCSimpleCtrl)
	// NOTE - ClassWizard will add and remove dispatch map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()


/////////////////////////////////////////////////////////////////////////////
// Event map

BEGIN_EVENT_MAP(CMFCSimpleCtrl, COleControl)
	//{{AFX_EVENT_MAP(CMFCSimpleCtrl)
	// NOTE - ClassWizard will add and remove event map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_EVENT_MAP
END_EVENT_MAP()


/////////////////////////////////////////////////////////////////////////////
// Property pages

// TODO: Add more property pages as needed.  Remember to increase the count!
BEGIN_PROPPAGEIDS(CMFCSimpleCtrl, 1)
	PROPPAGEID(CMFCSimplePropPage::guid)
END_PROPPAGEIDS(CMFCSimpleCtrl)


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CMFCSimpleCtrl, "MFCSIMPLE.MFCSimpleCtrl.1",
	0x3ca01ed3, 0xd9d2, 0x4ffa, 0x91, 0x2a, 0xfa, 0xe6, 0xca, 0xc5, 0xc4, 0xaf)


/////////////////////////////////////////////////////////////////////////////
// Type library ID and version

IMPLEMENT_OLETYPELIB(CMFCSimpleCtrl, _tlid, _wVerMajor, _wVerMinor)


/////////////////////////////////////////////////////////////////////////////
// Interface IDs

const IID BASED_CODE IID_DMFCSimple =
		{ 0xeab1b76c, 0x400d, 0x48e7, { 0x8c, 0xbc, 0x42, 0xb8, 0x99, 0xb7, 0xb8, 0x48 } };
const IID BASED_CODE IID_DMFCSimpleEvents =
		{ 0x40421655, 0xe832, 0x449b, { 0x8c, 0xea, 0x61, 0x8b, 0x9c, 0x1f, 0xc1, 0x85 } };


/////////////////////////////////////////////////////////////////////////////
// Control type information

static const DWORD BASED_CODE _dwMFCSimpleOleMisc =
	OLEMISC_ACTIVATEWHENVISIBLE |
	OLEMISC_SETCLIENTSITEFIRST |
	OLEMISC_INSIDEOUT |
	OLEMISC_CANTLINKINSIDE |
	OLEMISC_RECOMPOSEONRESIZE;

IMPLEMENT_OLECTLTYPE(CMFCSimpleCtrl, IDS_MFCSIMPLE, _dwMFCSimpleOleMisc)


/////////////////////////////////////////////////////////////////////////////
// CMFCSimpleCtrl::CMFCSimpleCtrlFactory::UpdateRegistry -
// Adds or removes system registry entries for CMFCSimpleCtrl

BOOL CMFCSimpleCtrl::CMFCSimpleCtrlFactory::UpdateRegistry(BOOL bRegister)
{
	// TODO: Verify that your control follows apartment-model threading rules.
	// Refer to MFC TechNote 64 for more information.
	// If your control does not conform to the apartment-model rules, then
	// you must modify the code below, changing the 6th parameter from
	// afxRegApartmentThreading to 0.

	if (bRegister)
		return AfxOleRegisterControlClass(
			AfxGetInstanceHandle(),
			m_clsid,
			m_lpszProgID,
			IDS_MFCSIMPLE,
			IDB_MFCSIMPLE,
			afxRegApartmentThreading,
			_dwMFCSimpleOleMisc,
			_tlid,
			_wVerMajor,
			_wVerMinor);
	else
		return AfxOleUnregisterClass(m_clsid, m_lpszProgID);
}


/////////////////////////////////////////////////////////////////////////////
// CMFCSimpleCtrl::CMFCSimpleCtrl - Constructor

CMFCSimpleCtrl::CMFCSimpleCtrl()
{
	InitializeIIDs(&IID_DMFCSimple, &IID_DMFCSimpleEvents);

	// TODO: Initialize your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CMFCSimpleCtrl::~CMFCSimpleCtrl - Destructor

CMFCSimpleCtrl::~CMFCSimpleCtrl()
{
	// TODO: Cleanup your control's instance data here.
}


/////////////////////////////////////////////////////////////////////////////
// CMFCSimpleCtrl::OnDraw - Drawing function

void CMFCSimpleCtrl::OnDraw(
			CDC* pdc, const CRect& rcBounds, const CRect& rcInvalid)
{
	// TODO: Replace the following code with your own drawing code.
	pdc->FillRect(rcBounds, CBrush::FromHandle((HBRUSH)GetStockObject(WHITE_BRUSH)));
	pdc->Ellipse(rcBounds);
}


/////////////////////////////////////////////////////////////////////////////
// CMFCSimpleCtrl::DoPropExchange - Persistence support

void CMFCSimpleCtrl::DoPropExchange(CPropExchange* pPX)
{
	ExchangeVersion(pPX, MAKELONG(_wVerMinor, _wVerMajor));
	COleControl::DoPropExchange(pPX);

	// TODO: Call PX_ functions for each persistent custom property.

}


/////////////////////////////////////////////////////////////////////////////
// CMFCSimpleCtrl::OnResetState - Reset control to default state

void CMFCSimpleCtrl::OnResetState()
{
	COleControl::OnResetState();  // Resets defaults found in DoPropExchange

	// TODO: Reset any other control state here.
}


/////////////////////////////////////////////////////////////////////////////
// CMFCSimpleCtrl message handlers
