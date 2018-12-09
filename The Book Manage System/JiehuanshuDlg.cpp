// JiehuanshuDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "The Book Manage System.h"
#include "JiehuanshuDlg.h"
#include "afxdialogex.h"
#include "Mgr.h"

int i = 0;
// CJiehuanshuDlg 对话框

IMPLEMENT_DYNAMIC(CJiehuanshuDlg, CDialogEx)
extern CMgr* mgr;
CJiehuanshuDlg::CJiehuanshuDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_JIEHUANSHU, pParent)
{

}

CJiehuanshuDlg::~CJiehuanshuDlg()
{
}

void CJiehuanshuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CJiehuanshuDlg, CDialogEx)
	ON_BN_CLICKED(IDC_JieShu, &CJiehuanshuDlg::OnBnClickedJieshu)
	ON_BN_CLICKED(IDC_HuanShu, &CJiehuanshuDlg::OnBnClickedHuanshu)
	ON_EN_CHANGE(IDC_EDIT1, &CJiehuanshuDlg::OnEnChangeEdit1)
	ON_EN_CHANGE(IDC_EDIT2, &CJiehuanshuDlg::OnEnChangeEdit2)
	
END_MESSAGE_MAP()


// CJiehuanshuDlg 消息处理程序


void CJiehuanshuDlg::OnBnClickedJieshu()
{
	// TODO: 在此添加控件通知处理程序代码

	CString strBook;
	GetDlgItemText(IDC_EDIT1, strBook);
	CString strSource = _T("");
	strSource.Format(_T("SELECT count(*) from 图书信息 where 书籍编号=%s"), strBook);
	mgr->OpenRecordset(strSource);
	CString strNum = mgr->Return_x_y(0, 0);
	if (strNum != "1")
	{
		AfxMessageBox(_T("此书未录入数据库！"));
		return;
	}
	strSource = _T("");
	strSource.Format(_T("SELECT count(*) from 借书信息 where 书籍编号=%s"), strBook);
	mgr->OpenRecordset(strSource);
	strNum = mgr->Return_x_y(0, 0);
	if (strNum == "1")
	{
		AfxMessageBox(_T("此书已借出！"));
		return;
	}
	CString strId;
	GetDlgItemText(IDC_EDIT2, strId);
	strSource = _T("");
	strSource.Format(_T("select count(*) from 借书信息 where 借书卡号=%s"), strId);
	if (!mgr->OpenRecordset(strSource))
	{
		AfxMessageBox(_T("请填入正确的借书证号！"));
		return;
	}
	strNum = mgr->Return_x_y(0, 0);
	int nNum = _wtoi(strNum);
	if (nNum >= 30)
	{
		AfxMessageBox(_T("已借满！"));
		return;
	}
	//
	COleDateTime  Date;         //获取当前时间
	Date = COleDateTime::GetCurrentTime();
	Date -= COleDateTimeSpan(60);
	//Date.SetDate(Date.GetYear(),Date.GetMonth()-1,Date.GetDay());
	CString strTime = Date.Format(_T("%Y-%m-%d"));
	strSource.Format(_T("select count(*) from 借书信息 where 借书卡号=%s AND 借书时间<=#%s#"), strId, strTime);
	mgr->OpenRecordset(strSource);
	strNum = mgr->Return_x_y(0, 0);
	if (strNum != "0")
	{
		AfxMessageBox(_T("有未还的书！"));
		return;
	}

	Date = COleDateTime::GetCurrentTime();
	strTime = Date.Format(_T("%Y-%m-%d"));

	COleDateTime strTimeLast = COleDateTime::GetCurrentTime();
	strTimeLast += COleDateTimeSpan(30);
	CString strTime1 = strTimeLast.Format(_T("%Y-%m-%d"));
	strSource.Format(_T("INSERT INTO 借书信息 VALUES ( %s, %s, #%s#, #%s# )"), strId, strBook, strTime, strTime1);

	if (mgr->Excute(strSource))
		AfxMessageBox(_T("借书成功!"));
	else
		AfxMessageBox(_T("此书已借出！"));
}


void CJiehuanshuDlg::OnBnClickedHuanshu()
{
	
	CString strBook;
	GetDlgItemText(IDC_EDIT2, strBook);
	CString strSource = _T("");
	strSource.Format(_T("delete * from 借书信息 where 借书卡号=%s"), strBook);
	if (mgr->Excute(strSource)&i == 0)
	{
		AfxMessageBox(_T("还书成功!"));
		i++;
	}
	else
	{
		AfxMessageBox(_T("此书已还"));// TODO: 在此添加控件通知处理程序代码
		i--;
	}

}


void CJiehuanshuDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	CString strBook;
	GetDlgItemText(IDC_EDIT1, strBook);
	CString strSource = _T("");
	strSource.Format(_T("select * from 图书信息 where 书籍编号=%s"), strBook);
	mgr->OpenRecordset(strSource);
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST2);
	mgr->m_pListCtrl = pListCtrl;
	mgr->AutoOpen();
}


void CJiehuanshuDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码

	CString strId;
	GetDlgItemText(IDC_EDIT2, strId);
	CString strSource = _T("");
	strSource.Format(_T("select * from 借书卡信息 where 借书卡号=%s"), strId);
	mgr->OpenRecordset(strSource);
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	mgr->m_pListCtrl = pListCtrl;
	mgr->AutoOpen();
}



