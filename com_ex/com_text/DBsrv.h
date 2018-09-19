// DBsrv.h: interface for the DBsrv class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_DBSRV_H__D90A58EC_CB87_41AF_A3C2_74F07F17BC06__INCLUDED_)
#define AFX_DBSRV_H__D90A58EC_CB87_41AF_A3C2_74F07F17BC06__INCLUDED_

#if _MSC_VER > 1000
#pragma once

#endif // _MSC_VER > 1000
//#include "windows.h"
#include "afxcoll.h"
#ifndef _DBSERVER_INCLUDE
#define _DBSERVER_INCLUDE
#endif
typedef long HRESULT;

class DBsrv  
{
	//Interfaces
public:
	//Interface for data access
	HRESULT Read(short nTable, short nRow, LPTSTR lpszData);
	HRESULT Write(short nTable, short nRow, LPTSTR lpszData);
	//Interface for database management
	HRESULT Create(short &nTable, LPCTSTR  lpszName);
	HRESULT Delete(short nTable);
	//Interface for database information
	HRESULT GetNumTables(short &nNumTables);
	HRESULT GetTableName(short nTable, LPTSTR lpszName);
	HRESULT GetNumRows(short nTable, short &nRows);
	//inplementation
private:
	CPtrArray m_arrTables;
	CStringArray m_arrNames;
public:
	DBsrv();
	virtual ~DBsrv();

};

#endif // !defined(AFX_DBSRV_H__D90A58EC_CB87_41AF_A3C2_74F07F17BC06__INCLUDED_)
