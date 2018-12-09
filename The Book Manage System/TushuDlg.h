#pragma once
#include "afxwin.h"


// CTushuDlg 对话框

class CTushuDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTushuDlg)

public:
	bool OpenRecordset(LPCTSTR lpszSource, long nCursorType, long nLockType, long nOptions);
	CTushuDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CTushuDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUSHU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedChaxun();
	CEdit m_edit;
};
