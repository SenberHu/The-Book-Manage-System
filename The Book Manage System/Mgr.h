#pragma once
#import "c:\program files\common files\system\ado\msado15.dll" 
class CMgr
{
public:
	CMgr(void);
	~CMgr(void);
	bool OpenDatabase(LPCTSTR lpszConnect, long nOptions = adConnectUnspecified);
	bool CloseDatabase();
	bool OpenRecordset(LPCTSTR lpszSource, long nCursorType = adOpenDynamic,
		long nLockType = adLockOptimistic, long nOptions = adCmdText);
	bool CloseRecordset();
	void Read(CString* str, int* type, int num);
	CString ToString(const _variant_t& var);
	_ConnectionPtr m_pConnection;
	_RecordsetPtr m_pRecordset;
	CListCtrl* m_pListCtrl;
	//	_CommandPtr m_pCommand;
	bool AutoOpen(void);
	CString Return_x_y(int x, int y);
	bool IsEmpty(void);
	bool Excute(CString strCommand);
	CString ReturnFindName(CString strName);
};

