#pragma once

#include <iostream>
#include <atlstr.h>

class CFieldEntity
{
private:
	CString m_strName;		//字段名
	int m_nType;			//类型
	int m_nParam;			//(可理解为varchar的长度?)
	SYSTEMTIME m_tMTime;
	int m_nIntegrities;		//完整性

public:
	CFieldEntity(CFieldEntity &field);
	CFieldEntity(CString, int, int, int);
	CFieldEntity();
	~CFieldEntity();


};

