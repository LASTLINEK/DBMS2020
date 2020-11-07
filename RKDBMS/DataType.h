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
	VARCHAR name;		//���ݿ���
	bool type;			//���ݿ�����(false:ϵͳ���ݿ� true:�û����ݿ�)
	VARCHAR fileName;	//���ݿ������ļ���ȫ·��
	DATETIME crtTime;	//��������
};

struct TableBlock
{
	VARCHAR name;		//����
	INTEGER field_num;	//�ֶ���
	INTEGER record_num;	//��¼��
	VARCHAR tdf;		//�����ļ�·��
	VARCHAR trd;		//���¼�ļ�·��
	VARCHAR tic;		//��������Լ���ļ�·��(�ݲ�ʹ��)
	VARCHAR tid;		//�������ļ�·��(�ݲ�ʹ��)
	DATETIME crtTime;	//��������
	DATETIME mTime;		//���޸�����
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