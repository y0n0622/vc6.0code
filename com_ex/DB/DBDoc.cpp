// DBDoc.cpp : implementation of the CDBDoc class
//

#include "stdafx.h"
#include "DB.h"

#include "DBDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDBDoc

IMPLEMENT_DYNCREATE(CDBDoc, CDocument)

BEGIN_MESSAGE_MAP(CDBDoc, CDocument)
	//{{AFX_MSG_MAP(CDBDoc)
	ON_COMMAND(IDM_CREATETABLE, OnCreatetable)
	ON_COMMAND(IDM_READTABLE, OnReadtable)
	ON_COMMAND(IDM_WRITETABLE, OnWritetable)
	ON_UPDATE_COMMAND_UI(IDM_WRITETABLE, OnUpdateWritetable)
	ON_UPDATE_COMMAND_UI(IDM_READTABLE, OnUpdateReadtable)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDBDoc construction/destruction

CDBDoc::CDBDoc()
{
	// TODO: add one-time construction code here
    m_pDB = NULL;
}

CDBDoc::~CDBDoc()
{
	if(m_pDB)
	{
		delete m_pDB;
		m_pDB = NULL;
	}
}

BOOL CDBDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	m_pDB = new DBsrv;
	m_csData = "No data yet!";
	m_nCount = 0;
	m_nTable = 1;

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDBDoc serialization

void CDBDoc::Serialize(CArchive& ar)
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
// CDBDoc diagnostics

#ifdef _DEBUG
void CDBDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDBDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDBDoc commands

void CDBDoc::OnCreatetable() 
{
	// TODO: Add your command handler code here
	m_pDB->Create(m_nTable, _T("Testing"));
	m_nCount = 0;
}

void CDBDoc::OnReadtable() 
{
	// TODO: Add your command handler code here
	m_pDB->Read(m_nTable, 0, m_csData.GetBuffer(80));
	m_csData.ReleaseBuffer();
	UpdateAllViews(NULL);
}

void CDBDoc::OnWritetable() 
{
	// TODO: Add your command handler code here
	m_nCount++;
	CString csText;
	csText.Format(_T("Text data #%d in table %d, row 0!"), m_nCount, (int)m_nTable);
	m_pDB->Write(m_nTable, 0,(LPTSTR)csText);
}

void CDBDoc::OnUpdateWritetable(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_nTable >= 0);
}

void CDBDoc::OnUpdateReadtable(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(m_nCount > 0);
}
