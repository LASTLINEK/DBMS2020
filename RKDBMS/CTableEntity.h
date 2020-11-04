#pragma once

#include <iostream>
#include <atlstr.h>
#include "CFieldEntity.h"

class CTableEntity
{
private:
	CString m_strName;		//表名	
	int m_nRecordNum;		//有几条记录
	CString m_strTdfPath;
	CString m_strTrdPath;
	CString m_strTicPath;
	CString m_strTidPath;
	SYSTEMTIME m_tCrTime;
	SYSTEMTIME m_tMTime;
	CFieldEntity* m_arrFields;	//所有字段

public:
	CTableEntity(CString strName);
	CTableEntity();
	~CTableEntity();

	CFieldEntity* AddField(CFieldEntity& fe);	//添加字段
	CFieldEntity* DeleteField(int index);		//删除字段
	CFieldEntity GetFieldAt(int nIndex);		//获取字段
};

