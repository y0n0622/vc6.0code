// MFCSimplePpg.cpp : Implementation of the CMFCSimplePropPage property page class.

#include "stdafx.h"
#include "MFCSimple.h"
#include "MFCSimplePpg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


IMPLEMENT_DYNCREATE(CMFCSimplePropPage, COlePropertyPage)


/////////////////////////////////////////////////////////////////////////////
// Message map

BEGIN_MESSAGE_MAP(CMFCSimplePropPage, COlePropertyPage)
	//{{AFX_MSG_MAP(CMFCSimplePropPage)
	// NOTE - ClassWizard will add and remove message map entries
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()


/////////////////////////////////////////////////////////////////////////////
// Initialize class factory and guid

IMPLEMENT_OLECREATE_EX(CMFCSimplePropPage, "MFCSIMPLE.MFCSimplePropPage.1",
	0x1fd2a0b2, 0xa0a3, 0x4b76, 0x9c, 0x81, 0xde, 0x30, 0xea, 0xcf, 0x8f, 0xec)


/////////////////////////////////////////////////////////////////////////////
// CMFCSimplePropPage::CMFCSimplePropPageFactory::UpdateRegistry -
// Adds or removes system registry entries for CMFCSimplePropPage

BOOL CMFCSimplePropPage::CMFCSimplePropPageFactory::UpdateRegistry(BOOL bRegister)
{
	if (bRegister)
		return AfxOleRegisterPropertyPageClass(AfxGetInstanceHandle(),
			m_clsid, IDS_MFCSIMPLE_PPG);
	else
		return AfxOleUnregisterClass(m_clsid, NULL);
}


/////////////////////////////////////////////////////////////////////////////
// CMFCSimplePropPage::CMFCSimplePropPage - Constructor

CMFCSimplePropPage::CMFCSimplePropPage() :
	COlePropertyPage(IDD, IDS_MFCSIMPLE_PPG_CAPTION)
{
	//{{AFX_DATA_INIT(CMFCSimplePropPage)
	// NOTE: ClassWizard will add member initialization here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_INIT
}


/////////////////////////////////////////////////////////////////////////////
// CMFCSimplePropPage::DoDataExchange - Moves data between page and properties

void CMFCSimplePropPage::DoDataExchange(CDataExchange* pDX)
{
	//{{AFX_DATA_MAP(CMFCSimplePropPage)
	// NOTE: ClassWizard will add DDP, DDX, and DDV calls here
	//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DATA_MAP
	DDP_PostProcessing(pDX);
}


/////////////////////////////////////////////////////////////////////////////
// CMFCSimplePropPage message handlers
