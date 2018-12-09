
// The Book Manage SystemDlg.h : ͷ�ļ�
//

#pragma once
#include "afxwin.h"
#include "MyButton.h"


// CTheBookManageSystemDlg �Ի���
class CTheBookManageSystemDlg : public CDialogEx
{
// ����
public:
	CTheBookManageSystemDlg(CWnd* pParent = NULL);	// ��׼���캯��
	CImage m_bkImage;
// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_THEBOOKMANAGESYSTEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
