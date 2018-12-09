#pragma once


// CJieshudan 对话框

class CJieshudan : public CDialogEx
{
	DECLARE_DYNAMIC(CJieshudan)

public:
	CJieshudan(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CJieshudan();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_JIESHUDAN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedChaxun();
	virtual BOOL OnInitDialog();
};
