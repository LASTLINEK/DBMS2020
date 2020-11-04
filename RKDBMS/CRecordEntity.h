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

	void Put(CString strKey, DataType::VARCHAR strValue);
	void Put(CString strKey, DataType::INTEGER nValue);
	void Put(CString strKey, DataType::BOOL bValue);
	void Put(CString strKey, DataType::DATE strValue);
	CString Get(CString strKey);
};

