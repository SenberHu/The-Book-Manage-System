#pragma once


// CJieshudanDlg �Ի���

class CJieshudanDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CJieshudanDlg)

public:
	CJieshudanDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CJieshudanDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_Jieshuka };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_[5];
	afx_msg void OnBnClickedidok();
};
