
// The Book Manage SystemDlg.cpp : ʵ���ļ�
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


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CTheBookManageSystemDlg �Ի���



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


// CTheBookManageSystemDlg ��Ϣ�������

BOOL CTheBookManageSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	m_bkImage.LoadFromResource(AfxGetInstanceHandle(), IDB_BACKGROUND);
	m_XiuGai.SetBkColor(0xFF0000);
	m_BanLi.SetBkColor(0x02F78E);
	m_JieHuanShu.SetBkColor(0x0080FF);
	m_ChaXun.SetBkColor(0xF9F900);
	m_JieShu.SetBkColor(0xFF8040);
	m_BaoCun.SetBkColor(0xAE57A4);

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CTheBookManageSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC   dc(this);
		CRect   rect;
		GetClientRect(&rect);                                 //��ȡ�Ի��򳤿�         
		CDC   dcBmp;                                           //���岢����һ���ڴ��豸����  
		dcBmp.CreateCompatibleDC(&dc);                         //����������DC  
		CBitmap   bmpBackground;
		bmpBackground.LoadBitmap(IDB_BACKGROUND);                 //������Դ�е�IDB_BITMAP1ͼƬ  
		BITMAP   m_bitmap;                                     //ͼƬ����                  
		bmpBackground.GetBitmap(&m_bitmap);                    //��ͼƬ����λͼ��  
		CBitmap   *pbmpOld = dcBmp.SelectObject(&bmpBackground); //��λͼѡ����ʱ�ڴ��豸����    
																 //���ú�����ʾͼƬ StretchBlt��ʾ��״�ɱ�  
		dc.StretchBlt(0, 0, rect.Width(), rect.Height(), &dcBmp, 0, 0,
			m_bitmap.bmWidth, m_bitmap.bmHeight, SRCCOPY);
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CTheBookManageSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




void CTheBookManageSystemDlg::OnBnClickedXiugai()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	CWeihuDlg dlg;
	dlg.DoModal();
}


void CTheBookManageSystemDlg::OnBnClickedBanli()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CJieshurenyuanxinxi dlg;
	dlg.DoModal();
}


void CTheBookManageSystemDlg::OnBnClickedJiehuanshu()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CJiehuanshuDlg dlg;
	dlg.DoModal();
}


void CTheBookManageSystemDlg::OnBnClickedTushuchaxun()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CTushuDlg dlg;
	dlg.DoModal();
}


void CTheBookManageSystemDlg::OnBnClickedJieshudan()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CJieshudan dlg;
	dlg.DoModal();
}


void CTheBookManageSystemDlg::OnBnClickedBaocun()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	bool b = CopyFile(TEXT("E:\\The Book Manage System\\The Book Manage System\\Library.mdb"),TEXT("C:\\Users\\Xenber\\Desktop\\new.mdb"), true);
	DWORD dw = GetLastError();
	AfxMessageBox(_T("���ݳɹ���"));


}


HBRUSH CTheBookManageSystemDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  �ڴ˸��� DC ���κ�����

	switch (pWnd->GetDlgCtrlID())
	{
	case IDC_STATIC:
		pDC->SetBkMode(TRANSPARENT);
		pDC->SetTextColor(RGB(0, 0, 0));
		return (HBRUSH)GetStockObject(HOLLOW_BRUSH);
	default:
		break;
	}
	// TODO:  ���Ĭ�ϵĲ������軭�ʣ��򷵻���һ������
	return hbr;
}
