#pragma once


// CJieshudanDlg 对话框

class CJieshudanDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CJieshudanDlg)

public:
	CJieshudanDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CJieshudanDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Jieshuka };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString m_[5];
	afx_msg void OnBnClickedidok();
};
