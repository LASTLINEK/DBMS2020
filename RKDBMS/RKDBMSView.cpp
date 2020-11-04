
// RKDBMSView.cpp: CRKDBMSView 类的实现
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "RKDBMS.h"
#endif

#include "RKDBMSDoc.h"
#include "RKDBMSView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CRKDBMSView

IMPLEMENT_DYNCREATE(CRKDBMSView, CView)

BEGIN_MESSAGE_MAP(CRKDBMSView, CView)
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CRKDBMSView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
END_MESSAGE_MAP()

// CRKDBMSView 构造/析构

CRKDBMSView::CRKDBMSView() noexcept
{
	// TODO: 在此处添加构造代码

}

CRKDBMSView::~CRKDBMSView()
{
}

BOOL CRKDBMSView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CRKDBMSView 绘图

void CRKDBMSView::OnDraw(CDC* /*pDC*/)
{
	CRKDBMSDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
}


// CRKDBMSView 打印


void CRKDBMSView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CRKDBMSView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void CRKDBMSView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加额外的打印前进行的初始化过程
}

void CRKDBMSView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: 添加打印后进行的清理过程
}

void CRKDBMSView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CRKDBMSView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CRKDBMSView 诊断

#ifdef _DEBUG
void CRKDBMSView::AssertValid() const
{
	CView::AssertValid();
}

void CRKDBMSView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRKDBMSDoc* CRKDBMSView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRKDBMSDoc)));
	return (CRKDBMSDoc*)m_pDocument;
}
#endif //_DEBUG


// CRKDBMSView 消息处理程序
