// Student.h : CStudent 类的实现



// CStudent 实现

// 代码生成在 2020年5月9日, 20:13

#include "stdafx.h"
#include "Student.h"
IMPLEMENT_DYNAMIC(CStudent, CRecordset)

CStudent::CStudent(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_id = 0;
	m_name = L"";
	m_age = 0;
	m_nFields = 3;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString CStudent::GetDefaultConnect()
{
	return _T("DSN=SQLServerODBC;UID=sa;PWD=Sa123;APP=Microsoft\x00ae Visual Studio\x00ae 2015;WSID=DESKTOP-1KEAFF9;DATABASE=test");

	//改下立即切换Mysql数据库
	//return _T("DSN=MySqlODBC;UID=root;PWD=root;APP=Microsoft\x00ae Visual Studio\x00ae 2015;WSID=DESKTOP-1KEAFF9;DATABASE=test");

}

CString CStudent::GetDefaultSQL()
{
	return _T("[dbo].[Student]");
}

void CStudent::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[id]"), m_id);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Int(pFX, _T("[age]"), m_age);

}
/////////////////////////////////////////////////////////////////////////////
// CStudent 诊断

#ifdef _DEBUG
void CStudent::AssertValid() const
{
	CRecordset::AssertValid();
}

void CStudent::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


