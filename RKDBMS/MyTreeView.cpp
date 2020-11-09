#include "pch.h"
#include "MyTreeView.h"
// MyTreeView.cpp : 实现文件
//

#include "MyTreeView.h"
#include "MainFrm.h"

// CMyTreeView

IMPLEMENT_DYNCREATE(CMyTreeView, CTreeView)

CMyTreeView::CMyTreeView()
{

}

CMyTreeView::~CMyTreeView()
{
}

BEGIN_MESSAGE_MAP(CMyTreeView, CTreeView)
	ON_NOTIFY_REFLECT(NM_CLICK, &CMyTreeView::OnNMClick)
END_MESSAGE_MAP()


// CMyTreeView 诊断

#ifdef _DEBUG
void CMyTreeView::AssertValid() const
{
	CTreeView::AssertValid();
}

#ifndef _WIN32_WCE
void CMyTreeView::Dump(CDumpContext& dc) const
{
	CTreeView::Dump(dc);
}
#endif
#endif //_DEBUG


// CMyTreeView 消息处理程序

void CMyTreeView::OnInitialUpdate()
{
	CTreeView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//属性
	CTreeCtrl& tree = GetTreeCtrl();
	DWORD dwStyle = GetWindowLong(tree, GWL_STYLE);
	dwStyle |= TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT | TVS_SHOWSELALWAYS;
	SetWindowLong(tree, GWL_STYLE, dwStyle);

	CFont font;
	font.CreateFont(
		20,
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
	tree.SetFont(&font);

	UpdateTree();
}

void CMyTreeView::UpdateTree(void)
{
	CTreeCtrl& tree = GetTreeCtrl();
	tree.DeleteAllItems();

	UpdateTree1();
	UpdateTree2();
}

void CMyTreeView::UpdateTree1(void)
{
	CTreeCtrl& tree = GetTreeCtrl();
	CString str = _T("");
	int i = 0, cnt = 0;
	HTREEITEM root, sub;

	str = _T("DB1");
	root = tree.InsertItem(str, 0, 0, TVI_ROOT);
	tree.SetItemData(root, VIEW1_ROOT);
	m_TreeItem1 = root;

	cnt = 2;
	for (i = 0; i < cnt; i++)
	{
		str.Format(_T("DB1 TABLE%d"), i);
		sub = tree.InsertItem(str, 1, 1, m_TreeItem1);
		tree.SetItemData(sub, VIEW1_SUB);
	}
	tree.Expand(m_TreeItem1, TVE_EXPAND);
}

void CMyTreeView::UpdateTree2(void)
{
	CTreeCtrl& tree = GetTreeCtrl();
	CString str = _T("");
	int i = 0, cnt = 0;
	HTREEITEM root, sub;

	str = _T("DB2");
	root = tree.InsertItem(str, 0, 0, TVI_ROOT);
	tree.SetItemData(root, VIEW2_ROOT);
	m_TreeItem2 = root;

	cnt = 3;
	for (i = 0; i < cnt; i++)
	{
		str.Format(_T("DB2 TABLE%d"), i);
		sub = tree.InsertItem(str, 1, 1, m_TreeItem2);
		tree.SetItemData(sub, VIEW2_SUB);
	}
	tree.Expand(m_TreeItem2, TVE_EXPAND);
}

void CMyTreeView::OnNMClick(NMHDR* pNMHDR, LRESULT* pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	CTreeCtrl& tree = GetTreeCtrl();
	CPoint CursorPoint;
	if (!GetCursorPos(&CursorPoint))
	{
		return;
	}
	tree.ScreenToClient(&CursorPoint);
	UINT uFlag = 0;
	HTREEITEM select_item = tree.HitTest(CursorPoint, &uFlag);
	if ((NULL != select_item) && (TVHT_ONITEM & uFlag))
	{
		tree.Select(select_item, TVGN_CARET);
	}
	else
	{
		return;
	}

	ShowView(select_item);

	*pResult = 0;
}

void CMyTreeView::ShowView(HTREEITEM select_item)
{
	CTreeCtrl& tree = GetTreeCtrl();
	DWORD dwData = tree.GetItemData(select_item);
	CString sText = tree.GetItemText(select_item);

	//switch (dwData)
	//{
	//case VIEW1_ROOT:
	//	((CMainFrame*)(GetParent()->GetParent()))->ShowListView1();
	//	break;
	//case VIEW1_SUB:
	//	((CMainFrame*)(GetParent()->GetParent()))->ShowListView1();
	//	break;
	//case VIEW2_ROOT:
	//	((CMainFrame*)(GetParent()->GetParent()))->ShowListView2();
	//	break;
	//case VIEW2_SUB:
	//	((CMainFrame*)(GetParent()->GetParent()))->ShowListView2();
	//	break;
	//default:
	//	break;
	//}
}