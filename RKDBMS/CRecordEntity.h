#pragma once
#include <atlstr.h>
#include "DataType.h"

class CRecordEntity
{
private:
	//CMapStringToString m_mapData;

public:
	CRecordEntity(CRecordEntity& e);
	CRecordEntity();
	~CRecordEntity();

	void Put(CString strKey, VARCHAR strValue);
	void Put(CString strKey, INTEGER nValue);
	void Put(CString strKey, BOOL bValue);
	void Put(CString strKey, DATETIME strValue);
	CString Get(CString strKey);
};

