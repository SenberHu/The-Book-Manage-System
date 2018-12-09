// Jieshurenyuanxinxi.cpp : 实现文件
//

#include "stdafx.h"
#include "The Book Manage System.h"
#include "Jieshurenyuanxinxi.h"
#include "afxdialogex.h"
#include "JieshudanDlg.h"
#include "Mgr.h"


// CJieshurenyuanxinxi 对话框

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


// CJieshurenyuanxinxi 消息处理程序

BOOL CJieshurenyuanxinxi::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString strSource = _T("select 借书卡号,读者姓名,读者性别,读者学院,读者专业 from 借书卡信息 ");
	mgr->OpenRecordset(strSource);
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	mgr->m_pListCtrl = pListCtrl;
	mgr->AutoOpen();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}


void CJieshurenyuanxinxi::OnBnClickedAdd()
{
	// TODO: 在此添加控件通知处理程序代码
	CJieshudanDlg dlg;

	if (dlg.DoModal() == IDOK)
	{
		CString strSource = _T("");
		strSource.Format(_T("INSERT INTO 借书卡信息 values (%s,'%s','%s','%s','%s')"), dlg.m_[0], dlg.m_[1], dlg.m_[2], dlg.m_[3], dlg.m_[4]);
		if (mgr->Excute(strSource))
		{
			AfxMessageBox(_T("添加成功！"));			
		}
		else
		{
			AfxMessageBox(_T("请输入正确的借书人员信息！"));
		}
		OnInitDialog();
	}
}


void CJieshurenyuanxinxi::OnBnClickedDelete()
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
	int nItem = pListCtrl->GetNextSelectedItem(pos);
	CString strBook = pListCtrl->GetItemText(nItem, 0);
	CString strSource = _T("");
	strSource.Format(_T("delete from 借书卡信息 where 借书卡号=%s"), strBook);
	if (mgr->Excute(strSource))
		AfxMessageBox(_T("删除成功！"));

	OnInitDialog();
}
