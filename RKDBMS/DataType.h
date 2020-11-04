#pragma once
#include <atlstr.h>
#include <string>
class DataType
{
public:
	struct INTEGER
	{
		int value;
	};

	struct DATE
	{
		int year, month, day;

		CString value;

		DATE(int y, int m, int d)
		{
			year = y;
			month = m;
			day = d;
			value.Format(_T("%d-%d-%d"), y, m, d);
		}
	};

	struct VARCHAR
	{
		char* value;
		int num;

		VARCHAR(int n)
		{
			num = n;
			value = (char*)calloc(n, sizeof(char));
		}
	};

	struct BOOL
	{
		bool value;
	};
};

