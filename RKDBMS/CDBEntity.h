#pragma once
#include <cstring>
#include <iostream>
#include <atlstr.h>
class CDBEntity
{
private:
	CString m_strName;		//���ݿ���
	bool m_Type;			//
	CString m_strFilepath;	//�ļ�·��
	SYSTEMTIME m_tCtTime;	//

public:
	//CDBEntity(DatabaseBlock& db);
};

