
// MainFrm.cpp : CMainFrame Ŭ������ ����
//

#include "stdafx.h"
#include "MFCBasic.h"

#include "MainFrm.h"
#include "WorkerThreadDlg.h"
#include "UIThread.h"
#include "KeyboardDlg.h"
#include "EditContorl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	ON_WM_CREATE()
	ON_COMMAND(ID_Menu_WorkerThread, &CMainFrame::OnMenuWorkerThread)
	ON_COMMAND(ID_Menu_UIThread, &CMainFrame::OnMenuUithread)
	ON_COMMAND(ID_Menu_ResumeThread, &CMainFrame::OnMenuResumethread)
	ON_COMMAND(ID_Menu_SuspendThread, &CMainFrame::OnMenuSuspendthread)
	ON_COMMAND(ID_Menu_ExitThread, &CMainFrame::OnMenuExitthread)
	ON_COMMAND(ID_Menu_Keyboard, &CMainFrame::OnMenuKeyboard)
	ON_COMMAND(ID_Menu_EditControl, &CMainFrame::OnMenuEditcontrol)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ���� �� ǥ�ñ�
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/�Ҹ�

CMainFrame::CMainFrame()
{
	// TODO: ���⿡ ��� �ʱ�ȭ �ڵ带 �߰��մϴ�.
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("���� ǥ������ ������ ���߽��ϴ�.\n");
		return -1;      // ������ ���߽��ϴ�.
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));

	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return TRUE;
}

// CMainFrame ����

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame �޽��� ó����


// worker thread
void CMainFrame::OnMenuWorkerThread()
{
	CWorkerThreadDlg threadExDlg;
	threadExDlg.DoModal();
}

// ui thread
void CMainFrame::OnMenuUithread()
{
	if(g_pUIThread != NULL)
	{
		AfxMessageBox("����� �������̽� �����尡 �������Դϴ�.");
		return;
	}
	g_pUIThread = AfxBeginThread(RUNTIME_CLASS(CUIThread));
}

void CMainFrame::OnMenuResumethread()
{
	if(g_pUIThread != NULL)
		g_pUIThread->ResumeThread();
}

void CMainFrame::OnMenuSuspendthread()
{
	if(g_pUIThread != NULL)
		g_pUIThread->SuspendThread();
}

void CMainFrame::OnMenuExitthread()
{
	if(g_pUIThread != NULL)
		g_pUIThread->PostThreadMessage(WM_QUIT, NULL, NULL);
}

void CMainFrame::OnMenuKeyboard()
{
	CKeyboardDlg keyboardDlg;
	keyboardDlg.DoModal();
}

void CMainFrame::OnMenuEditcontrol()
{
	CEditContorl editControlDlg;
	editControlDlg.DoModal();
}