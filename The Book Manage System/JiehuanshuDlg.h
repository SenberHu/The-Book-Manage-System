#pragma once


// CJiehuanshuDlg 对话框

class CJiehuanshuDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CJiehuanshuDlg)

public:
	CJiehuanshuDlg(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CJiehuanshuDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_JIEHUANSHU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedJieshu();
	afx_msg void OnBnClickedHuanshu();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();

};
