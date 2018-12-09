#include "StdAfx.h"
#include "Mgr.h"

CMgr *mgr = new CMgr();
CMgr::CMgr(void)
{
	if (!SUCCEEDED(CoInitialize(NULL)))
	{
		::AfxMessageBox(_T("初始化COM库失败!"));
		return;
	}
	if (!SUCCEEDED(m_pConnection.CreateInstance(__uuidof(Connection))))
	{
		m_pConnection = NULL;
		TRACE(_T("Database createInstance failed!"));
	}
	if (!SUCCEEDED(m_pRecordset.CreateInstance(__uuidof(Recordset))))
	{
		m_pRecordset = NULL;
		TRACE(_T("Recordset createInstance failed!"));
	}
	if (m_pConnection->State & adStateOpen)
	{
		AfxMessageBox(_T("数据库已经打开!"));
		return;
	}							
	CString strConnect = _T("Provider = Microsoft.Jet.OLEDB.4.0; Data Source = E:\\The Book Manage System\\The Book Manage System\\Library.mdb");
	if (!OpenDatabase(strConnect))
	{
		AfxMessageBox(_T("数据库打开失败!"));
		return;
	}

}


CMgr::~CMgr(void)
{
	CloseRecordset();
	CloseDatabase();
}

bool CMgr::OpenDatabase(LPCTSTR lpszConnect, long nOptions)
{
	ASSERT(m_pConnection != NULL);
	ASSERT(lpszConnect != NULL);
	ASSERT(AfxIsValidString(lpszConnect));

	try
	{
		return SUCCEEDED(m_pConnection->Open(_bstr_t(lpszConnect), _T(""), _T(""), nOptions));
	}
	catch (_com_error& e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return false;
	}
	//m_pConnection->Execute(
}

bool CMgr::OpenRecordset(LPCTSTR lpszSource, long nCursorType, long nLockType, long nOptions)
{
	ASSERT(m_pConnection != NULL);
	ASSERT(m_pRecordset != NULL);
	ASSERT(lpszSource != NULL);
	ASSERT(AfxIsValidString(lpszSource));

	try
	{
		return SUCCEEDED(m_pRecordset->Open(_variant_t(lpszSource), m_pConnection.GetInterfacePtr(),
			(CursorTypeEnum)nCursorType, (LockTypeEnum)nLockType, nOptions));
	}
	catch (_com_error& e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return false;
	}
}

bool CMgr::CloseDatabase()
{
	ASSERT(m_pConnection != NULL);
	try
	{
		if (m_pConnection->State&adStateOpen)
		{
			return SUCCEEDED(m_pConnection->Close());
		}
		else
		{
			return false;
		}
	}
	catch (_com_error& e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return false;
	}
}
bool CMgr::CloseRecordset()
{
	ASSERT(m_pRecordset != NULL);
	try
	{
		if (m_pRecordset->State&adStateOpen)
		{
			return SUCCEEDED(m_pRecordset->Close());
		}
		else
		{
			return true;
		}
	}
	catch (_com_error& e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		return false;
	}
}
void CMgr::Read(CString* str, int* type, int num)
{
	// TODO: 在此添加控件通知处理程序代码
	if (!(m_pRecordset->State & adStateOpen))
	{
		AfxMessageBox(_T("记录集未打开!"));
		return;
	}
	m_pListCtrl->DeleteAllItems();
	if (m_pRecordset->BOF&&m_pRecordset->adoEOF)
	{
		CloseRecordset();
		return;
	}
	m_pRecordset->MoveFirst();
	int n = 0;
	while (!m_pRecordset->adoEOF)
	{
		_variant_t varValue;
		CString strText = _T("");

		FieldsPtr   fds = m_pRecordset->GetFields();
		//printf( "printf   field   name   of   the   table\n "); 
		for (int i = 0; i <fds->GetCount(); i++)
		{
			FieldPtr   fd = fds->GetItem(_variant_t(short(i)));
			CString strTemp = (LPCTSTR)m_pRecordset->GetFields()->GetItem((long)i)->GetName();
			_variant_t     vValue = m_pRecordset->GetFields()->GetItem((long)i)->GetValue();
			const char*   aa = new char(90);
			aa = (LPCSTR)_bstr_t(vValue);
		}

		switch (type[0])
		{
		case 0://CString
			   //CString strTemp=_T("");
			varValue = m_pRecordset->GetCollect(_variant_t(str[0]));
			if (varValue.vt != VT_NULL)
			{
				strText = varValue.bstrVal;
			}
			else
			{
				strText = _T("");
			}
			m_pListCtrl->InsertItem(n, strText);
			break;
		case 1://int
			int nTemp = 0;
			varValue = m_pRecordset->GetCollect(_variant_t(str[0]));
			if (varValue.vt != VT_NULL)
			{
				nTemp = varValue.intVal;
			}
			else
			{
				nTemp = 0;
			}
			//CString strText=_T("");
			strText.Format(_T("%d"), nTemp);
			m_pListCtrl->InsertItem(n, strText);
			break;
		}
		for (int i = 1; i<num; i++)
		{
			switch (type[i])
			{
			case 0://CString
				   //CString strTemp=_T("");
				varValue = m_pRecordset->GetCollect(_variant_t(str[i]));
				if (varValue.vt != VT_NULL)
				{
					strText = varValue.bstrVal;
				}
				else
				{
					strText = _T("");
				}
				m_pListCtrl->SetItemText(n, i, strText);
				break;
			case 1://int
				int nTemp = 0;
				varValue = m_pRecordset->GetCollect(_variant_t(str[i]));
				if (varValue.vt != VT_NULL)
				{
					nTemp = varValue.intVal;
				}
				else
				{
					nTemp = 0;
				}
				//CString strText=_T("");
				strText.Format(_T("%d"), nTemp);
				m_pListCtrl->SetItemText(n, i, strText);
				break;
			}
		}
		n++;
		m_pRecordset->MoveNext();
	}
	CloseRecordset();
}

bool CMgr::AutoOpen(void)
{
	if (!(m_pRecordset->State & adStateOpen))
	{
		AfxMessageBox(_T("记录集未打开!"));
		return false;
	}
	while (m_pListCtrl->DeleteColumn(0));;
	m_pListCtrl->DeleteAllItems();
	if (m_pRecordset->BOF&&m_pRecordset->adoEOF)
	{
		//AfxMessageBox(_T("满足条件的记录为空!"));
		CloseRecordset();
		return false;
	}
	m_pRecordset->MoveFirst();
	int n = 0;
	_variant_t varValue;
	CString strText = _T("");

	m_pListCtrl->SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
	FieldsPtr   fds = m_pRecordset->GetFields();
	for (int i = 0; i <fds->GetCount(); i++)
	{
		FieldPtr   fd = fds->GetItem(_variant_t(short(i)));
		CString strTemp = (LPCTSTR)fd->GetName();
		//_variant_t     vValue=m_pRecordset-> GetFields()-> GetItem((long)i)-> GetValue(); 
		//const char*   aa=new char(90);
		//aa=   (LPCSTR)_bstr_t(vValue);
		m_pListCtrl->InsertColumn(i, strTemp, LVCFMT_CENTER, 80);
	}

	while (!m_pRecordset->adoEOF)
	{

		FieldPtr   fd = fds->GetItem(_variant_t(short(0)));
		//CString strTemp=(LPCTSTR)fd-> GetName();
		varValue = fd->GetValue();
		strText = ToString(varValue);
		m_pListCtrl->InsertItem(n, strText);


		for (int i = 1; i<fds->GetCount(); i++)
		{
			FieldPtr   fd = fds->GetItem(_variant_t(short(i)));
			CString strTemp = (LPCTSTR)fd->GetName();
			varValue = fd->GetValue();
			strText = ToString(varValue);
			m_pListCtrl->SetItemText(n, i, strText);
		}
		n++;
		m_pRecordset->MoveNext();
	}
	CloseRecordset();
	return true;
}
CString CMgr::ToString(const _variant_t& var)
{
	CString strValue;
	switch (var.vt)
	{
	case VT_BSTR: //字符串   
	case VT_LPSTR:
	case VT_LPWSTR:
		strValue = (LPCTSTR)(_bstr_t)var;
		break;
	case VT_I1:   //无符号字符   
	case VT_UI1:
		strValue.Format(_T("%d"), var.bVal);
		break;
	case VT_I2:   //短整型   
		strValue.Format(_T("%d"), var.iVal);
		break;
	case VT_UI2:   //无符号短整型   
		strValue.Format(_T("%u"), var.uiVal);
		break;
	case VT_INT: //整型   
		strValue.Format(_T("%d"), var.intVal);
		break;
	case VT_I4:   //整型   
	case VT_I8:   //长整型   
		strValue.Format(_T("%d"), var.lVal);
		break;
	case VT_UINT:   //无符号整型   
		strValue.Format(_T("%d"), var.uintVal);
		break;
	case VT_UI4:    //无符号整型   
	case VT_UI8:    //无符号长整型   
		strValue.Format(_T("%d"), var.ulVal);
		break;
	case VT_VOID:
		strValue.Format(_T("%08x"), var.byref);
		break;
	case VT_R4:   //浮点型   
		strValue.Format(_T("%f"), var.fltVal);
		break;
	case VT_R8:   //双精度型   
		strValue.Format(_T("%f"), var.dblVal);
		break;
	case VT_DECIMAL: //小数   
		strValue.Format(_T("%f"), (double)var);
		break;
	case VT_CY:
	{
		COleCurrency cy = var.cyVal;
		strValue = cy.Format();
	}
	break;
	case VT_BLOB:
	case VT_BLOB_OBJECT:
	case 0x2011:
		strValue = _T("[BLOB]");
		break;
	case VT_BOOL:   //布尔型     
		strValue = var.boolVal ? _T("TRUE") : _T("FALSE");
		break;
	case VT_DATE: //日期型   
	{
		DATE dt = var.date;
		COleDateTime da = COleDateTime(dt);
		//strValue = da.Format(_T("%Y-%m-%d %H:%M:%S"));   
		strValue = da.Format(_T("%Y-%m-%d"));
	}
	break;
	case VT_NULL://NULL值   
	case VT_EMPTY:   //空   
		strValue = _T("");
		break;
	case VT_UNKNOWN:   //未知类型   
	default:
		strValue = _T("VT_UNKNOW");
		break;
	}

	return strValue;
}

CString CMgr::Return_x_y(int x, int y)
{
	if (!(m_pRecordset->State & adStateOpen))
	{
		//AfxMessageBox(_T("记录集未打开!"));
		return NULL;
	}
	if (m_pRecordset->BOF&&m_pRecordset->adoEOF)
	{
		//AfxMessageBox(_T("满足条件的记录为空!"));
		CloseRecordset();
		return NULL;
	}
	CString strText = _T("");
	try
	{
		m_pRecordset->MoveFirst();
		m_pRecordset->Move((long)y);
		_variant_t varValue;
		FieldsPtr   fds = m_pRecordset->GetFields();
		FieldPtr   fd = fds->GetItem(_variant_t(short(x)));
		varValue = fd->GetValue();
		strText = ToString(varValue);
	}
	catch (_com_error& e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		//AfxMessageBox(_T("行列数不满足条件！"));
		CloseRecordset();
		return NULL;
	}
	CloseRecordset();
	return strText;
}

bool CMgr::IsEmpty()
{
	if (m_pRecordset->BOF&&m_pRecordset->adoEOF)
	{
		//AfxMessageBox(_T("满足条件的记录为空!"));
		CloseRecordset();
		return true;
	}
	return false;
}


bool CMgr::Excute(CString strCommand)
{
	try
	{
		m_pConnection->Execute((_bstr_t)strCommand, NULL, adCmdText);
	}
	catch (_com_error& e)
	{
		TRACE(_T("%s\n"), e.ErrorMessage());
		//AfxMessageBox(_T("命令执行失败！"));
		//CloseRecordset();
		return false;
	}
	return true;
}

CString CMgr::ReturnFindName(CString strName)
{
	_variant_t var;
	if (!(m_pRecordset->State & adStateOpen))
	{
		//AfxMessageBox(_T("记录集未打开!"));
		return NULL;
	}
	if (m_pRecordset->BOF&&m_pRecordset->adoEOF)
	{
		//AfxMessageBox(_T("满足条件的记录为空!"));
		CloseRecordset();
		return NULL;
	}
	CString strText = _T("");
	var = m_pRecordset->GetCollect("strName");

	strText = ToString(var);
	return strText;

}










