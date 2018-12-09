// BookDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "The Book Manage System.h"
#include "BookDlg.h"
#include "afxdialogex.h"


// CBookDlg 对话框

IMPLEMENT_DYNAMIC(CBookDlg, CDialogEx)

CBookDlg::CBookDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_BOOK, pParent)
	
{
	for (int i = 0; i<6; i++)
		m_[i] = _T("");
}

CBookDlg::~CBookDlg()
{
}

void CBookDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);




	DDX_Text(pDX, IDC_EDIT1, m_[0]);
	DDX_Text(pDX, IDC_EDIT2, m_[1]);
	DDX_Text(pDX, IDC_EDIT3, m_[2]);
	DDX_Text(pDX, IDC_EDIT4, m_[3]);
	DDX_Text(pDX, IDC_EDIT5, m_[4]);
	DDX_Text(pDX, IDC_EDIT6, m_[5]);
}


BEGIN_MESSAGE_MAP(CBookDlg, CDialogEx)
	
END_MESSAGE_MAP()


// CBookDlg 消息处理程序

