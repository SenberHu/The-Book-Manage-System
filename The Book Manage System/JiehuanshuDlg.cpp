// JiehuanshuDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "The Book Manage System.h"
#include "JiehuanshuDlg.h"
#include "afxdialogex.h"
#include "Mgr.h"

int i = 0;
// CJiehuanshuDlg �Ի���

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


// CJiehuanshuDlg ��Ϣ�������


void CJiehuanshuDlg::OnBnClickedJieshu()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CString strBook;
	GetDlgItemText(IDC_EDIT1, strBook);
	CString strSource = _T("");
	strSource.Format(_T("SELECT count(*) from ͼ����Ϣ where �鼮���=%s"), strBook);
	mgr->OpenRecordset(strSource);
	CString strNum = mgr->Return_x_y(0, 0);
	if (strNum != "1")
	{
		AfxMessageBox(_T("����δ¼�����ݿ⣡"));
		return;
	}
	strSource = _T("");
	strSource.Format(_T("SELECT count(*) from ������Ϣ where �鼮���=%s"), strBook);
	mgr->OpenRecordset(strSource);
	strNum = mgr->Return_x_y(0, 0);
	if (strNum == "1")
	{
		AfxMessageBox(_T("�����ѽ����"));
		return;
	}
	CString strId;
	GetDlgItemText(IDC_EDIT2, strId);
	strSource = _T("");
	strSource.Format(_T("select count(*) from ������Ϣ where ���鿨��=%s"), strId);
	if (!mgr->OpenRecordset(strSource))
	{
		AfxMessageBox(_T("��������ȷ�Ľ���֤�ţ�"));
		return;
	}
	strNum = mgr->Return_x_y(0, 0);
	int nNum = _wtoi(strNum);
	if (nNum >= 30)
	{
		AfxMessageBox(_T("�ѽ�����"));
		return;
	}
	//
	COleDateTime  Date;         //��ȡ��ǰʱ��
	Date = COleDateTime::GetCurrentTime();
	Date -= COleDateTimeSpan(60);
	//Date.SetDate(Date.GetYear(),Date.GetMonth()-1,Date.GetDay());
	CString strTime = Date.Format(_T("%Y-%m-%d"));
	strSource.Format(_T("select count(*) from ������Ϣ where ���鿨��=%s AND ����ʱ��<=#%s#"), strId, strTime);
	mgr->OpenRecordset(strSource);
	strNum = mgr->Return_x_y(0, 0);
	if (strNum != "0")
	{
		AfxMessageBox(_T("��δ�����飡"));
		return;
	}

	Date = COleDateTime::GetCurrentTime();
	strTime = Date.Format(_T("%Y-%m-%d"));

	COleDateTime strTimeLast = COleDateTime::GetCurrentTime();
	strTimeLast += COleDateTimeSpan(30);
	CString strTime1 = strTimeLast.Format(_T("%Y-%m-%d"));
	strSource.Format(_T("INSERT INTO ������Ϣ VALUES ( %s, %s, #%s#, #%s# )"), strId, strBook, strTime, strTime1);

	if (mgr->Excute(strSource))
		AfxMessageBox(_T("����ɹ�!"));
	else
		AfxMessageBox(_T("�����ѽ����"));
}


void CJiehuanshuDlg::OnBnClickedHuanshu()
{
	
	CString strBook;
	GetDlgItemText(IDC_EDIT2, strBook);
	CString strSource = _T("");
	strSource.Format(_T("delete * from ������Ϣ where ���鿨��=%s"), strBook);
	if (mgr->Excute(strSource)&i == 0)
	{
		AfxMessageBox(_T("����ɹ�!"));
		i++;
	}
	else
	{
		AfxMessageBox(_T("�����ѻ�"));// TODO: �ڴ���ӿؼ�֪ͨ����������
		i--;
	}

}


void CJiehuanshuDlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	CString strBook;
	GetDlgItemText(IDC_EDIT1, strBook);
	CString strSource = _T("");
	strSource.Format(_T("select * from ͼ����Ϣ where �鼮���=%s"), strBook);
	mgr->OpenRecordset(strSource);
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST2);
	mgr->m_pListCtrl = pListCtrl;
	mgr->AutoOpen();
}


void CJiehuanshuDlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	CString strId;
	GetDlgItemText(IDC_EDIT2, strId);
	CString strSource = _T("");
	strSource.Format(_T("select * from ���鿨��Ϣ where ���鿨��=%s"), strId);
	mgr->OpenRecordset(strSource);
	CListCtrl* pListCtrl = (CListCtrl*)GetDlgItem(IDC_LIST1);
	mgr->m_pListCtrl = pListCtrl;
	mgr->AutoOpen();
}



