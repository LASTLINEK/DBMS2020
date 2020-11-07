#pragma once
#include "CDBEntity.h"

class CFileDao
{
public:
	CString GetDBFile();
	CString GetDBFolder();
	CString GetInfoFile();
	bool ProduceDBFile(CDBEntity&);

};

