#pragma once
#include "MFCBasic.h"

// CKeyboardDlg 대화 상자입니다.

class CKeyboardDlg : public CDialog
{
	DECLARE_DYNAMIC(CKeyboardDlg)

public:
	CKeyboardDlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CKeyboardDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_KEYBOARDDLG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
};
