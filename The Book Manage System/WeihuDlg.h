#pragma once
#include "afxwin.h"


// CWeihuDlg �Ի���

class CWeihuDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CWeihuDlg)

public:
	CWeihuDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CWeihuDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_WeiHu };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:

	
	afx_msg void OnBnClickedAdd();
	afx_msg void OnBnClickedGai();
	afx_msg void OnBnClickedDelete();
	afx_msg void OnBnClickedOk();
	
};

