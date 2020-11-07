#pragma once
#include <atlstr.h>
#include <string>


class DataType
{

};


struct INTEGER
{
	int value;
};

struct DATETIME
{
	int year, month, day, hour, minute, second;

	CString value;

	DATETIME(int y, int mon, int d, int h, int min, int s)
	{
		year = y;
		month = mon;
		day = d;
		hour = h;
		minute = min;
		second = s;
		value.Format(_T("%d-%d-%d-%d-%d-%d"), y, mon, d, h, min, s);
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

struct DatabaseBlock
{
	VARCHAR name;		//数据库名
	bool type;			//数据库类型(false:系统数据库 true:用户数据库)
	VARCHAR fileName;	//数据库数据文件夹全路径
	DATETIME crtTime;	//创建日期
};

struct TableBlock
{
	VARCHAR name;		//表名
	INTEGER field_num;	//字段数
	INTEGER record_num;	//记录数
	VARCHAR tdf;		//表定义文件路径
	VARCHAR trd;		//表记录文件路径
	VARCHAR tic;		//表完整性约束文件路径(暂不使用)
	VARCHAR tid;		//表索引文件路径(暂不使用)
	DATETIME crtTime;	//表创建日期
	DATETIME mTime;		//表修改日期
};

struct FieldBlock
{
	INTEGER order;		
	VARCHAR name;
	INTEGER type;
	INTEGER param;
	DATETIME mTime;
	INTEGER integrities;
};