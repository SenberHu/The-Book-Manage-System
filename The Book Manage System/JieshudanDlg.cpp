// JieshudanDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "The Book Manage System.h"
#include "JieshudanDlg.h"
#include "afxdialogex.h"
#include "Mgr.h"


// CJieshudanDlg �Ի���

IMPLEMENT_DYNAMIC(CJieshudanDlg, CDialogEx)
extern CMgr* mgr;
CJieshudanDlg::CJieshudanDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Jieshuka, pParent)
{
	for(int i = 0; i<5; i++)
		m_[i] = _T("");

}

CJieshudanDlg::~CJieshudanDlg()
{
}

void CJieshudanDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_[0]);
	DDX_Text(pDX, IDC_EDIT2, m_[1]);
	DDX_Text(pDX, IDC_EDIT3, m_[2]);
	DDX_Text(pDX, IDC_EDIT4, m_[3]);
	DDX_Text(pDX, IDC_EDIT5, m_[4]);
}


BEGIN_MESSAGE_MAP(CJieshudanDlg, CDialogEx)
	ON_BN_CLICKED(IDC_idOk, &CJieshudanDlg::OnBnClickedidok)
END_MESSAGE_MAP()


// CJieshudanDlg ��Ϣ�������


void CJieshudanDlg::OnBnClickedidok()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CDialog::OnOK();

}

