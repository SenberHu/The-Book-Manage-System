// Jieshudan.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "The Book Manage System.h"
#include "Jieshudan.h"
#include "afxdialogex.h"
#include "Mgr.h"

// CJieshudan �Ի���

IMPLEMENT_DYNAMIC(CJieshudan, CDialogEx)
extern CMgr* mgr;
CJieshudan::CJieshudan(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_JIESHUDAN, pParent)
{

}

CJieshudan::~CJieshudan()
{
}

void CJieshudan::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CJieshudan, CDialogEx)
	ON_BN_CLICKED(IDC_ChaXun, &CJieshudan::OnBnClickedChaxun)
END_MESSAGE_MAP()


// CJieshudan ��Ϣ�������


void CJieshudan::OnBnClickedChaxun()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	POSITION pos = pListCtrl->GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		AfxMessageBox(_T("δѡ�м�¼"));
		return;
	}
	int nItem = pListCtrl->GetNextSelectedItem(pos);
	

}

BOOL CJieshudan::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CString strSource = _T("select ���鿨��,�鼮���,����ʱ��,����ʱ�� from ������Ϣ ");
	mgr->OpenRecordset(strSource);
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	mgr->m_pListCtrl = pListCtrl;
	mgr->AutoOpen();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}