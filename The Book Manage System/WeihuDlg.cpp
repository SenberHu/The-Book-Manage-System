// WeihuDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "The Book Manage System.h"
#include "WeihuDlg.h"
#include "afxdialogex.h"
#include "Mgr.h"
#include "BookDlg.h"


// CWeihuDlg 对话框

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


// CWeihuDlg 消息处理程序



void CWeihuDlg::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码	
	CBookDlg dlg;
	if (dlg.DoModal() == IDOK)
	{
		CString strSource = _T("");
		strSource.Format(_T("INSERT INTO 图书信息 values (%s,'%s','%s','%s','%s','%s')"), dlg.m_[0],dlg.m_[1],dlg.m_[2],dlg.m_[3],dlg.m_[4],dlg.m_[5]);
		if (mgr->Excute(strSource))
		{
			AfxMessageBox(_T("添加成功！"));
			CString strSource = _T("");
			strSource.Format(_T("SELECT * FROM 图书信息 where 书籍名称='%s'"), dlg.m_[1]);
			mgr->OpenRecordset(strSource);
			CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
			mgr->m_pListCtrl = pListCtrl;
			mgr->AutoOpen();
		}
		else
		{
			AfxMessageBox(_T("请输入正确的图书信息！"));
		}
	}

}


void CWeihuDlg::OnBnClickedGai()
{
	// TODO: 在此添加控件通知处理程序代码
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	POSITION pos = pListCtrl->GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		AfxMessageBox(_T("请先选中记录"));
		return;
	}
	int nItem = pListCtrl->GetNextSelectedItem(pos);
	//CString strBook=pListCtrl->GetItemText(nItem,0);
	CBookDlg dlg;
	for (int i = 0; i<4; i++)
		dlg.m_[i] = pListCtrl->GetItemText(nItem, i);
	//dlg.SetDlgItemTextW(IDOK,_T("修改"));
	if (dlg.DoModal() == IDOK)
	{		
		

			CString strSource = _T("");
			strSource.Format(_T("update  图书信息 set 书籍编号=%s,书籍名称='%s',书籍类别='%s',书籍作者='%s',出版社名称='%s',是否借出='%s'\
							where 书籍编号=%s"), dlg.m_[0], dlg.m_[1], dlg.m_[2], dlg.m_[3], dlg.m_[4], dlg.m_[5], pListCtrl->GetItemText(nItem, 0));
			if (mgr->Excute(strSource))
			{
				AfxMessageBox(_T("修改成功！"));
				CString strSource = _T("");
				strSource.Format(_T("SELECT * FROM 图书信息 where 书籍名称='%s'"), dlg.m_[1]);
				mgr->OpenRecordset(strSource);
				CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
				mgr->m_pListCtrl = pListCtrl;
				mgr->AutoOpen();
			}
			else
			{
				AfxMessageBox(_T("请填入正确的图书信息！"));
			
			}
		}
		
}


void CWeihuDlg::OnBnClickedDelete()
{
	// TODO: 在此添加控件通知处理程序代码

	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	POSITION pos = pListCtrl->GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		AfxMessageBox(_T("请先选中记录"));
		return;
	}
	if (AfxMessageBox(_T("确定删除？"), MB_YESNO) != IDYES)
		return;
		CString str1("否");
		int nItem = pListCtrl->GetNextSelectedItem(pos);
		CString iItem = pListCtrl->GetItemText(nItem,5);
		CString strBook = pListCtrl->GetItemText(nItem, 0);
		CString strSource = _T("");
		strSource.Format(_T("delete from 图书信息 where 书籍编号=%s "), strBook);
		if(iItem == str1)
		{ 
		   if (mgr->Excute(strSource))
			AfxMessageBox(_T("删除成功！"));
		}
		else
	    {
		AfxMessageBox(_T("已被借出，无法删除！"));
	
	    }


	
	CListCtrl* pListCtr2 = (CListCtrl*)GetDlgItem(IDC_LIST1);
	OnBnClickedOk();
}


void CWeihuDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	CString strName;
	GetDlgItemText(IDC_EDIT1, strName);

	CString strSource = _T("");
	strSource.Format(_T("SELECT * FROM 图书信息 where 书籍名称='%s'"), strName);
	mgr->OpenRecordset(strSource);
	if (mgr->IsEmpty())
	{
		AfxMessageBox(_T("请输入正确的书名！"));
		return;
	}
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	mgr->m_pListCtrl = pListCtrl;
	mgr->AutoOpen();
}
