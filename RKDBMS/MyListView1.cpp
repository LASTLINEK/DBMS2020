#include "pch.h"
#include "MyListView1.h"
// MyListView1.cpp : 实现文件
//

#include "MyListView1.h"


// CMyListView1

IMPLEMENT_DYNCREATE(CMyListView1, CListView)

CMyListView1::CMyListView1()
{

}

CMyListView1::~CMyListView1()
{
}

BEGIN_MESSAGE_MAP(CMyListView1, CListView)
END_MESSAGE_MAP()


// CMyListView1 诊断

#ifdef _DEBUG
void CMyListView1::AssertValid() const
{
	CListView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyListView1::Dump(CDumpContext& dc) const
{
	CListView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyListView1 消息处理程序

void CMyListView1::OnInitialUpdate()
{
	CListView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//属性设置
	CListCtrl& list = GetListCtrl();
	list.ModifyStyle(LVS_TYPEMASK, LVS_REPORT & LVS_TYPEMASK | LVS_SINGLESEL);//important for show
	DWORD dwStyle = list.GetExtendedStyle();
	list.SetExtendedStyle(dwStyle | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	CImageList image;
	image.Create(1, 20, ILC_COLOR24 | ILC_MASK, 4, 0);
	list.SetImageList(&image, LVSIL_SMALL);

	CFont font;
	font.CreateFont(
		16,
		0,
		0,
		0,
		FW_NORMAL,
		FALSE,
		FALSE,
		0,
		ANSI_CHARSET,
		OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS,
		_T("宋体"));
	list.SetFont(&font);
	list.GetHeaderCtrl()->SetFont(&font);

	//标题栏
	list.InsertColumn(0, _T("字段1"), LVCFMT_LEFT, 200, 0);
	list.InsertColumn(1, _T("字段2"), LVCFMT_LEFT, 100, 0);
}

void CMyListView1::UpdateList(void)
{
	CListCtrl& list = GetListCtrl();
	list.DeleteAllItems();
	CString str = _T("");

	for (int i = 0; i < 2; i++)
	{
		str.Format(_T("字段 %d"), i);
		list.InsertItem(i, str);
	}
}