#pragma once


// CJieshurenyuanxinxi �Ի���

class CJieshurenyuanxinxi : public CDialogEx
{
	DECLARE_DYNAMIC(CJieshurenyuanxinxi)

public:
	CJieshurenyuanxinxi(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CJieshurenyuanxinxi();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Jieshurenyuanxinxi };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedDelete();
	virtual BOOL OnInitDialog();
};
