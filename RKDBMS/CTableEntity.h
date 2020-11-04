#pragma once

#include <iostream>
#include <atlstr.h>
#include "CFieldEntity.h"

class CTableEntity
{
private:
	CString m_strName;		//����	
	int m_nRecordNum;		//�м�����¼
	CString m_strTdfPath;
	CString m_strTrdPath;
	CString m_strTicPath;
	CString m_strTidPath;
	SYSTEMTIME m_tCrTime;
	SYSTEMTIME m_tMTime;
	CFieldEntity* m_arrFields;	//�����ֶ�

public:
	CTableEntity(CString strName);
	CTableEntity();
	~CTableEntity();

	CFieldEntity* AddField(CFieldEntity& fe);	//����ֶ�
	CFieldEntity* DeleteField(int index);		//ɾ���ֶ�
	CFieldEntity GetFieldAt(int nIndex);		//��ȡ�ֶ�
};

