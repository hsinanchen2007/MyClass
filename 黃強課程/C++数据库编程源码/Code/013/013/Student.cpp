// Student.h : CStudent ���ʵ��



// CStudent ʵ��

// ���������� 2020��5��9��, 20:13

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
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString CStudent::GetDefaultConnect()
{
	return _T("DSN=SQLServerODBC;UID=sa;PWD=Sa123;APP=Microsoft\x00ae Visual Studio\x00ae 2015;WSID=DESKTOP-1KEAFF9;DATABASE=test");

	//���������л�Mysql���ݿ�
	//return _T("DSN=MySqlODBC;UID=root;PWD=root;APP=Microsoft\x00ae Visual Studio\x00ae 2015;WSID=DESKTOP-1KEAFF9;DATABASE=test");

}

CString CStudent::GetDefaultSQL()
{
	return _T("[dbo].[Student]");
}

void CStudent::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[id]"), m_id);
	RFX_Text(pFX, _T("[name]"), m_name);
	RFX_Int(pFX, _T("[age]"), m_age);

}
/////////////////////////////////////////////////////////////////////////////
// CStudent ���

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


