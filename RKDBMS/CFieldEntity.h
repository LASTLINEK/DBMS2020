#pragma once

#include <iostream>
#include <atlstr.h>

class CFieldEntity
{
private:
	CString m_strName;		//�ֶ���
	int m_nType;			//����
	int m_nParam;			//(�����Ϊvarchar�ĳ���?)
	SYSTEMTIME m_tMTime;
	int m_nIntegrities;		//������

public:
	CFieldEntity(CFieldEntity &field);
	CFieldEntity(CString, int, int, int);
	CFieldEntity();
	~CFieldEntity();


};

