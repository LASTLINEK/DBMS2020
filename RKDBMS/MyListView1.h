#pragma once


// CMyListView1 ��ͼ
#include <afxcview.h>

class CMyListView1 : public CListView
{
	DECLARE_DYNCREATE(CMyListView1)

protected:
	CMyListView1();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMyListView1();

public:
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual void OnInitialUpdate();
	void UpdateList(void);
};