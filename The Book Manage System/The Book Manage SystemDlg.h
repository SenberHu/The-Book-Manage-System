
// The Book Manage SystemDlg.h : 头文件
//

#pragma once
#include "afxwin.h"
#include "MyButton.h"


// CTheBookManageSystemDlg 对话框
class CTheBookManageSystemDlg : public CDialogEx
{
// 构造
public:
	CTheBookManageSystemDlg(CWnd* pParent = NULL);	// 标准构造函数
	CImage m_bkImage;
// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_THEBOOKMANAGESYSTEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedXiugai();
	afx_msg void OnBnClickedBanli();
	afx_msg void OnBnClickedJiehuanshu();
	afx_msg void OnBnClickedTushuchaxun();
	afx_msg void OnBnClickedJieshudan();
	afx_msg void OnBnClickedBaocun();
	CMyButton m_XiuGai;
	CMyButton m_BanLi;
	CMyButton m_JieHuanShu;
	CMyButton m_ChaXun;
	CMyButton m_JieShu;
	CMyButton m_BaoCun;
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
};
