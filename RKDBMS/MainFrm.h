﻿
// MainFrm.h: CMainFrame 类的接口
//

#pragma once


#include "MyListView1.h"
#include "MyTreeView.h"

class CMainFrame : public CFrameWndEx
{
	
protected: // 仅从序列化创建
	CMainFrame() noexcept;
	DECLARE_DYNCREATE(CMainFrame)

// 特性
public:

// 操作
public:

// 重写
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual BOOL LoadFrame(UINT nIDResource, DWORD dwDefaultStyle = WS_OVERLAPPEDWINDOW | FWS_ADDTOTITLE, CWnd* pParentWnd = nullptr, CCreateContext* pContext = nullptr);

// 实现
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // 控件条嵌入成员
	CMFCMenuBar       m_wndMenuBar;
	CMFCStatusBar     m_wndStatusBar;
	CMFCToolBarImages m_UserImages;


// 生成的消息映射函数
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnViewCustomize();
	afx_msg LRESULT OnToolbarCreateNew(WPARAM wp, LPARAM lp);
	afx_msg void OnApplicationLook(UINT id);
	afx_msg void OnUpdateApplicationLook(CCmdUI* pCmdUI);
	afx_msg void OnSystemExit();
	afx_msg void OnCreateDatabase();
	afx_msg void OnOpenDatabase();
	afx_msg void OnCreateTable();
	afx_msg void OnAlterTable();
	afx_msg void OnDropTable();
	afx_msg void OnAddField();
	afx_msg void OnModifyField();
	afx_msg void OnDropField();
	afx_msg void OnInsertRecord();
	afx_msg void OnUpdateRecord();
	afx_msg void OnSelectRecord();
	afx_msg void OnDeleteRecord();
	afx_msg void OnSettingChange(UINT uFlags, LPCTSTR lpszSection);
	DECLARE_MESSAGE_MAP()

	BOOL CreateDockingWindows();
	void SetDockingWindowIcons(BOOL bHiColorIcons);
private:
	CSplitterWnd	m_wndSplitter;
	CMyTreeView* m_pMyTreeView;
	CMyListView1* m_pCMyListView1;
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
};


