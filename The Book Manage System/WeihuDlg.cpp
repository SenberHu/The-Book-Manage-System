// WeihuDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "The Book Manage System.h"
#include "WeihuDlg.h"
#include "afxdialogex.h"
#include "Mgr.h"
#include "BookDlg.h"


// CWeihuDlg �Ի���

IMPLEMENT_DYNAMIC(CWeihuDlg, CDialogEx)
extern CMgr* mgr;
CWeihuDlg::CWeihuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_WeiHu, pParent)
{

}

CWeihuDlg::~CWeihuDlg()
{
}

void CWeihuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	
}


BEGIN_MESSAGE_MAP(CWeihuDlg, CDialogEx)
	ON_BN_CLICKED(IDC_Add, &CWeihuDlg::OnBnClickedAdd)
	ON_BN_CLICKED(IDC_Gai, &CWeihuDlg::OnBnClickedGai)
	ON_BN_CLICKED(IDC_Delete, &CWeihuDlg::OnBnClickedDelete)
	ON_BN_CLICKED(IDC_OK, &CWeihuDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CWeihuDlg ��Ϣ�������



void CWeihuDlg::OnBnClickedAdd()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������	
	CBookDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CString strSource = _T("");
		strSource.Format(_T("INSERT INTO ͼ����Ϣ values (%s,'%s','%s','%s','%s','%s')"), dlg.m_[0],dlg.m_[1],dlg.m_[2],dlg.m_[3],dlg.m_[4],dlg.m_[5]);
		if (mgr->Excute(strSource))
		{
			AfxMessageBox(_T("��ӳɹ���"));
			CString strSource = _T("");
			strSource.Format(_T("SELECT * FROM ͼ����Ϣ where �鼮����='%s'"), dlg.m_[1]);
			mgr->OpenRecordset(strSource);
			CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
			mgr->m_pListCtrl = pListCtrl;
			mgr->AutoOpen();
		}
		else
		{
			AfxMessageBox(_T("��������ȷ��ͼ����Ϣ��"));
		}
	}

}


void CWeihuDlg::OnBnClickedGai()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	POSITION pos = pListCtrl->GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		AfxMessageBox(_T("����ѡ�м�¼"));
		return;
	}
	int nItem = pListCtrl->GetNextSelectedItem(pos);
	//CString strBook=pListCtrl->GetItemText(nItem,0);
	CBookDlg dlg;
	for (int i = 0; i<4; i++)
		dlg.m_[i] = pListCtrl->GetItemText(nItem, i);
	//dlg.SetDlgItemTextW(IDOK,_T("�޸�"));
	if (dlg.DoModal() == IDOK)
	{		
		

			CString strSource = _T("");
			strSource.Format(_T("update  ͼ����Ϣ set �鼮���=%s,�鼮����='%s',�鼮���='%s',�鼮����='%s',����������='%s',�Ƿ���='%s'\
							where �鼮���=%s"), dlg.m_[0], dlg.m_[1], dlg.m_[2], dlg.m_[3], dlg.m_[4], dlg.m_[5], pListCtrl->GetItemText(nItem, 0));
			if (mgr->Excute(strSource))
			{
				AfxMessageBox(_T("�޸ĳɹ���"));
				CString strSource = _T("");
				strSource.Format(_T("SELECT * FROM ͼ����Ϣ where �鼮����='%s'"), dlg.m_[1]);
				mgr->OpenRecordset(strSource);
				CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
				mgr->m_pListCtrl = pListCtrl;
				mgr->AutoOpen();
			}
			else
			{
				AfxMessageBox(_T("��������ȷ��ͼ����Ϣ��"));
			
			}
		}
		
}


void CWeihuDlg::OnBnClickedDelete()
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
		CString str1("��");
		int nItem = pListCtrl->GetNextSelectedItem(pos);
		CString iItem = pListCtrl->GetItemText(nItem,5);
		CString strBook = pListCtrl->GetItemText(nItem, 0);
		CString strSource = _T("");
		strSource.Format(_T("delete from ͼ����Ϣ where �鼮���=%s "), strBook);
		if(iItem == str1)
		{ 
		   if (mgr->Excute(strSource))
			AfxMessageBox(_T("ɾ���ɹ���"));
		}
		else
	    {
		AfxMessageBox(_T("�ѱ�������޷�ɾ����"));
	
	    }


	
	CListCtrl* pListCtr2 = (CListCtrl*)GetDlgItem(IDC_LIST1);
	OnBnClickedOk();
}


void CWeihuDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString strName;
	GetDlgItemText(IDC_EDIT1, strName);

	CString strSource = _T("");
	strSource.Format(_T("SELECT * FROM ͼ����Ϣ where �鼮����='%s'"), strName);
	mgr->OpenRecordset(strSource);
	if (mgr->IsEmpty())
	{
		AfxMessageBox(_T("��������ȷ��������"));
		return;
	}
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	mgr->m_pListCtrl = pListCtrl;
	mgr->AutoOpen();
}
