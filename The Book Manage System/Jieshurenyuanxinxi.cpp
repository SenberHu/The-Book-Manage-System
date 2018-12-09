// Jieshurenyuanxinxi.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "The Book Manage System.h"
#include "Jieshurenyuanxinxi.h"
#include "afxdialogex.h"
#include "JieshudanDlg.h"
#include "Mgr.h"


// CJieshurenyuanxinxi �Ի���

IMPLEMENT_DYNAMIC(CJieshurenyuanxinxi, CDialogEx)
extern CMgr* mgr;
CJieshurenyuanxinxi::CJieshurenyuanxinxi(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_Jieshurenyuanxinxi, pParent)
{

}

CJieshurenyuanxinxi::~CJieshurenyuanxinxi()
{
}

void CJieshurenyuanxinxi::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CJieshurenyuanxinxi, CDialogEx)

	ON_BN_CLICKED(IDC_Add, &CJieshurenyuanxinxi::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_Delete, &CJieshurenyuanxinxi::OnBnClickedDelete)
END_MESSAGE_MAP()


// CJieshurenyuanxinxi ��Ϣ�������

BOOL CJieshurenyuanxinxi::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	CString strSource = _T("select ���鿨��,��������,�����Ա�,����ѧԺ,����רҵ from ���鿨��Ϣ ");
	mgr->OpenRecordset(strSource);
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	mgr->m_pListCtrl = pListCtrl;
	mgr->AutoOpen();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CJieshurenyuanxinxi::OnBnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CJieshudanDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		CString strSource = _T("");
		strSource.Format(_T("INSERT INTO ���鿨��Ϣ values (%s,'%s','%s','%s','%s')"), dlg.m_[0], dlg.m_[1], dlg.m_[2], dlg.m_[3], dlg.m_[4]);
		if (mgr->Excute(strSource))
		{
			AfxMessageBox(_T("��ӳɹ���"));			
		}
		else
		{
			AfxMessageBox(_T("��������ȷ�Ľ�����Ա��Ϣ��"));
		}
		OnInitDialog();
	}
}


void CJieshurenyuanxinxi::OnBnClickedDelete()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	POSITION pos = pListCtrl->GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		AfxMessageBox(_T("����ѡ�м�¼"));
		return;
	}
	if (AfxMessageBox(_T("ȷ��ɾ����"), MB_YESNO) != IDYES)
		return;
	int nItem = pListCtrl->GetNextSelectedItem(pos);
	CString strBook = pListCtrl->GetItemText(nItem, 0);
	CString strSource = _T("");
	strSource.Format(_T("delete from ���鿨��Ϣ where ���鿨��=%s"), strBook);
	if (mgr->Excute(strSource))
		AfxMessageBox(_T("ɾ���ɹ���"));

	OnInitDialog();
}
