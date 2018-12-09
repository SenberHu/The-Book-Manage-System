// Jieshudan.cpp : 实现文件
//

#include "stdafx.h"
#include "The Book Manage System.h"
#include "Jieshudan.h"
#include "afxdialogex.h"
#include "Mgr.h"

// CJieshudan 对话框

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


// CJieshudan 消息处理程序


void CJieshudan::OnBnClickedChaxun()
{
	// TODO: 在此添加控件通知处理程序代码

	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	POSITION pos = pListCtrl->GetFirstSelectedItemPosition();
	if (pos == NULL)
	{
		AfxMessageBox(_T("未选中记录"));
		return;
	}
	int nItem = pListCtrl->GetNextSelectedItem(pos);
	

}

BOOL CJieshudan::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	CString strSource = _T("select 借书卡号,书籍编号,借书时间,还书时间 from 借书信息 ");
	mgr->OpenRecordset(strSource);
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	mgr->m_pListCtrl = pListCtrl;
	mgr->AutoOpen();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 异常: OCX 属性页应返回 FALSE
}