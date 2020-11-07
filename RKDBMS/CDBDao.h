#pragma once
#include "CDBEntity.h"

class CDBDao
{
public:
	bool Create(CString, CDBEntity, bool);
	bool GetDatabase(CString, CDBEntity&);
};

