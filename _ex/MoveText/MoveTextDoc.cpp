// MoveTextDoc.cpp : implementation of the CMoveTextDoc class
//

#include "stdafx.h"
#include "MoveText.h"

#include "MoveTextDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMoveTextDoc

IMPLEMENT_DYNCREATE(CMoveTextDoc, CDocument)

BEGIN_MESSAGE_MAP(CMoveTextDoc, CDocument)
	//{{AFX_MSG_MAP(CMoveTextDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMoveTextDoc construction/destruction

CMoveTextDoc::CMoveTextDoc()
{
	// TODO: add one-time construction code here

}

CMoveTextDoc::~CMoveTextDoc()
{
}

BOOL CMoveTextDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CMoveTextDoc serialization

void CMoveTextDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CMoveTextDoc diagnostics

#ifdef _DEBUG
void CMoveTextDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CMoveTextDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMoveTextDoc commands
