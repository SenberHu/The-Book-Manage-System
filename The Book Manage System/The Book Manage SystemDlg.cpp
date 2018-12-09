
// The Book Manage SystemDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "The Book Manage System.h"
#include "The Book Manage SystemDlg.h"
#include "afxdialogex.h"
#include "JiehuanshuDlg.h"
#include "WeihuDlg.h"
#include "TushuDlg.h"
#include "Jieshudan.h"
#include "Jieshurenyuanxinxi.h"
#include "iostream"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CTheBookManageSystemDlg 对话框



CTheBookManageSystemDlg::CTheBookManageSystemDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_THEBOOKMANAGESYSTEM_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CTheBookManageSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_XiuGai, m_XiuGai);
	DDX_Control(pDX, IDC_BanLi, m_BanLi);
	DDX_Control(pDX, IDC_JieHuanShu, m_JieHuanShu);
	DDX_Control(pDX, IDC_TuShuChaXun, m_ChaXun);
	DDX_Control(pDX, IDC_JieShuDan, m_JieShu);
	DDX_Control(pDX, IDC_BaoCun, m_BaoCun);
}

BEGIN_MESSAGE_MAP(CTheBookManageSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_XiuGai, &CTheBookManageSystemDlg::OnBnClickedXiugai)
	ON_BN_CLICKED(IDC_BanLi, &CTheBookManageSystemDlg::OnBnClickedBanli)
	ON_BN_CLICKED(IDC_JieHuanShu, &CTheBookManageSystemDlg::OnBnClickedJiehuanshu)
	ON_BN_CLICKED(IDC_TuShuChaXun, &CTheBookManageSystemDlg::OnBnClickedTushuchaxun)
	ON_BN_CLICKED(IDC_JieShuDan, &CTheBookManageSystemDlg::OnBnClickedJieshudan)
	ON_BN_CLICKED(IDC_BaoCun, &CTheBookManageSystemDlg::OnBnClickedBaocun)
	ON_WM_CTLCOLOR()
END_MESSAGE_MAP()


// CTheBookManageSystemDlg 消息处理程序

BOOL CTheBookManageSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_bkImage.LoadFromResource(AfxGetInstanceHandle(), IDB_BACKGROUND);
	m_XiuGai.SetBkColor(0xFF0000);
	m_BanLi.SetBkColor(0x02F78E);
	m_JieHuanShu.SetBkColor(0x0080FF);
	m_ChaXun.SetBkColor(0xF9F900);
	m_JieShu.SetBkColor(0xFF8040);
	m_BaoCun.SetBkColor(0xAE57A4);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CTheBookManageSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CTheBookManageSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC   dc(this);
		CRect   rect;
		GetClientRect(&rect);                                 //获取对话框长宽         
		CDC   dcBmp;                                           //定义并创建一个内存设备环境  
		dcBmp.CreateCompatibleDC(&dc);                         //创建兼容性DC  
		CBitmap   bmpBackground;
		bmpBackground.LoadBitmap(IDB_BACKGROUND);                 //载入资源中的IDB_BITMAP1图片  
		BITMAP   m_bitmap;                                     //图片变量                  
		bmpBackground.GetBitmap(&m_bitmap);                    //将图片载入位图中  
		CBitmap   *pbmpOld = dcBmp.SelectObject(&bmpBackground); //将位图选入临时内存设备环境    
																 //调用函数显示图片 StretchBlt显示形状可变  
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0,
			m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CTheBookManageSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CTheBookManageSystemDlg::OnBnClickedXiugai()
{
	// TODO: 在此添加控件通知处理程序代码
	
	CWeihuDlg dlg;
	dlg.DoModal();
}


void CTheBookManageSystemDlg::OnBnClickedBanli()
{
	// TODO: 在此添加控件通知处理程序代码
	CJieshurenyuanxinxi dlg;
	dlg.DoModal();
}


void CTheBookManageSystemDlg::OnBnClickedJiehuanshu()
{
	// TODO: 在此添加控件通知处理程序代码
	CJiehuanshuDlg dlg;
	dlg.DoModal();
}


void CTheBookManageSystemDlg::OnBnClickedTushuchaxun()
{
	// TODO: 在此添加控件通知处理程序代码
	CTushuDlg dlg;
	dlg.DoModal();
}


void CTheBookManageSystemDlg::OnBnClickedJieshudan()
{
	// TODO: 在此添加控件通知处理程序代码
	CJieshudan dlg;
	dlg.DoModal();
}


void CTheBookManageSystemDlg::OnBnClickedBaocun()
{
	// TODO: 在此添加控件通知处理程序代码
	bool b = CopyFile(TEXT("E:\\The Book Manage System\\The Book Manage System\\Library.mdb"),TEXT("C:\\Users\\Xenber\\Desktop\\new.mdb"), true);
	DWORD dw = GetLastError();
	AfxMessageBox(_T("备份成功！"));


}


HBRUSH CTheBookManageSystemDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性

	switch (pWnd->GetDlgCtrlID())
	{
	case IDC_STATIC:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0, 0, 0));
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	default:
		break;
	}
	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}
