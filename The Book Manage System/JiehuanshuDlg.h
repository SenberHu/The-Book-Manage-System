#pragma once


// CJiehuanshuDlg �Ի���

class CJiehuanshuDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CJiehuanshuDlg)

public:
	CJiehuanshuDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CJiehuanshuDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_JIEHUANSHU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedJieshu();
	afx_msg void OnBnClickedHuanshu();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnEnChangeEdit2();

};
