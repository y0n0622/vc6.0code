// DBsrv.cpp: implementation of the DBsrv class.
//
//////////////////////////////////////////////////////////////////////

#include "DBsrv.h"


//#define new DEBUG_NEW

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

DBsrv::DBsrv()
{
	short nNumTables;
	for(GetNumTables(nNumTables); nNumTables > 0; GetNumTables(nNumTables))
	{
		Delete(nNumTables - 1);
	}
}

DBsrv::~DBsrv()
{

}

//Database object
HRESULT DBsrv::Read(short nTable, short nRow, LPTSTR lpszData)
{
	CStringArray* pTable;
	pTable = (CStringArray*)m_arrTables[nTable];
	lstrcpy(lpszData, (*pTable)[nRow]);
	return NO_ERROR;
}
HRESULT DBsrv::Write(short nTable, short nRow, LPTSTR lpszData)
{
	CStringArray* pTable;
	pTable = (CStringArray*)m_arrTables[nTable];
	pTable->SetAtGrow(nRow, lpszData);
	return NO_ERROR;
}
//Interface for database management
HRESULT DBsrv::Create(short &nTable, LPCTSTR  lpszName)
{
	CStringArray* pTable = new CStringArray;
	nTable = m_arrTables.Add(pTable);
	m_arrNames.SetAtGrow(nTable, lpszName);
	return NO_ERROR;
}
HRESULT DBsrv::Delete(short nTable)
{
	CStringArray* pTable;
	pTable = (CStringArray*)m_arrTables[nTable];
	delete pTable;
	m_arrTables[nTable] = NULL;
	m_arrTables[nTable] = "";
	if(nTable == m_arrTables.GetSize() - 1)
	{
		m_arrTables.RemoveAt(nTable);
		m_arrNames.RemoveAt(nTable);
	}
	return NO_ERROR;
}
//Interface for database information
HRESULT DBsrv::GetNumTables(short &nNumTables)
{
	nNumTables = m_arrTables.GetSize();
	return NO_ERROR;
}
HRESULT DBsrv::GetTableName(short nTable, LPTSTR lpszName)
{
	lstrcpy(lpszName, m_arrNames[nTable]);
	return NO_ERROR;
}
HRESULT DBsrv::GetNumRows(short nTable, short &nRows)
{
	CStringArray* pTable;
	pTable = (CStringArray*)m_arrTables[nTable];
	return pTable->GetSize();
}