#pragma once
#include "afxwin.h"


// CBookDlg 对话框

class CBookDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBookDlg)

public:
	CBookDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CBookDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BOOK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_[6];
	


};
