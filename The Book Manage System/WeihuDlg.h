#pragma once
#include "afxwin.h"


// CWeihuDlg 对话框

class CWeihuDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CWeihuDlg)

public:
	CWeihuDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CWeihuDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WeiHu };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:

	
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedGai();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedOk();
	
};

