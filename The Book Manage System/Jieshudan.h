#pragma once


// CJieshudan �Ի���

class CJieshudan : public CDialogEx
{
	DECLARE_DYNAMIC(CJieshudan)

public:
	CJieshudan(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CJieshudan();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_JIESHUDAN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedChaxun();
	virtual BOOL OnInitDialog();
};
