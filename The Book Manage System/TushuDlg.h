#pragma once
#include "afxwin.h"


// CTushuDlg �Ի���

class CTushuDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CTushuDlg)

public:
	bool OpenRecordset(LPCTSTR lpszSource, long nCursorType, long nLockType, long nOptions);
	CTushuDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CTushuDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TUSHU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedChaxun();
	CEdit m_edit;
};
