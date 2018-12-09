#pragma once


// CJieshurenyuanxinxi 对话框

class CJieshurenyuanxinxi : public CDialogEx
{
	DECLARE_DYNAMIC(CJieshurenyuanxinxi)

public:
	CJieshurenyuanxinxi(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CJieshurenyuanxinxi();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Jieshurenyuanxinxi };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDelete();
	virtual BOOL OnInitDialog();
};
