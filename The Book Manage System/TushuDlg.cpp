// TushuDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "The Book Manage System.h"
#include "TushuDlg.h"
#include "afxdialogex.h"
#include "Mgr.h"


// CTushuDlg �Ի���
extern CMgr* mgr;
IMPLEMENT_DYNAMIC(CTushuDlg, CDialogEx)

CTushuDlg::CTushuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TUSHU, pParent)
{

}

CTushuDlg::~CTushuDlg()
{
}

void CTushuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit);
}


BEGIN_MESSAGE_MAP(CTushuDlg, CDialogEx)
	ON_BN_CLICKED(IDC_ChaXun, &CTushuDlg::OnBnClickedChaxun)
END_MESSAGE_MAP()


// CTushuDlg ��Ϣ�������

BOOL CTushuDlg::OnInitDialog()
{
	CDialog::OnInitDialog();
	/*	CListCtrl* pListCtrl=(CListCtrl*)GetDlgItem(IDC_LIST);
	m_ListCtrl.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	m_ListCtrl.InsertColumn(0,_T("���"),LVCFMT_CENTER,80);
	m_ListCtrl.InsertColumn(1,_T("����"),LVCFMT_CENTER,100);
	m_ListCtrl.InsertColumn(2,_T("����"),LVCFMT_CENTER,100);*/
	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_edit.SetFocus();
	m_edit.SetSel(0, -1);
	//((CEdit*)GetDlgItem(IDC_EDIT1))->SetFocus();
	//((CEdit*)GetDlgItem(IDC_EDIT1))->SetSel(0,-1);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}

void CTushuDlg::OnBnClickedChaxun()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strName;
	GetDlgItemText(IDC_EDIT1, strName);
	CString strSource = _T("");
	if (strName == "*")
		strSource = _T("select * from ͼ����Ϣ");


	else
		strSource.Format(_T("select * from ͼ����Ϣ where �鼮����='%s'"), strName);
	mgr->OpenRecordset(strSource);


	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	mgr->m_pListCtrl = pListCtrl;
	if (!mgr->AutoOpen())
		AfxMessageBox(_T("��������ȷ������!"));
}
