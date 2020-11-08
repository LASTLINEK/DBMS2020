#pragma once
#include <cstring>
#include <iostream>
#include <atlstr.h>
class CDBEntity
{
private:
	CString m_strName;		//数据库名
	bool m_Type;			//
	CString m_strFilepath;	//文件路径
	SYSTEMTIME m_tCtTime;	//

public:
	//CDBEntity(DatabaseBlock& db);
};

