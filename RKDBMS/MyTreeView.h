
#pragma once

#include <afxcview.h>
// CMyTreeView ��ͼ
//View1
#define  VIEW1_ROOT			0x10
#define  VIEW1_SUB			0x11
//View2
#define  VIEW2_ROOT			0x20
#define  VIEW2_SUB			0x21

class CMyTreeView : public CTreeView
{
	DECLARE_DYNCREATE(CMyTreeView)

protected:
	CMyTreeView();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CMyTreeView();

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
	HTREEITEM m_TreeItem1;
	HTREEITEM m_TreeItem2;

	virtual void OnInitialUpdate();
	void UpdateTree(void);
	void UpdateTree1(void);
	void UpdateTree2(void);
	afx_msg void OnNMClick(NMHDR* pNMHDR, LRESULT* pResult);
	void ShowView(HTREEITEM select_item);
};