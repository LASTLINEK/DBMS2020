#pragma once
#include "CDBEntity.h"

class CDBLogic
{
public:
	static bool CreateDatabase(CDBEntity& e);
	bool GetDatabase(CDBEntity& e);
};

