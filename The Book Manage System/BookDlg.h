#pragma once
#include "afxwin.h"


// CBookDlg �Ի���

class CBookDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBookDlg)

public:
	CBookDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CBookDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BOOK };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CString m_[6];
	


};
