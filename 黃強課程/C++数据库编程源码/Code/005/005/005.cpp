// 003.cpp : �������̨Ӧ�ó������ڵ㡣
//


//����ͷ�ļ�
#include<Windows.h>
#include <sql.h> 
#include <sqlext.h> 
#include<sqltypes.h>
#include <tchar.h>

#include <iostream>
using namespace std;


int main()
{
	//����Ϊ����  
	_wsetlocale(LC_ALL, L"chs");


	SQLRETURN  ret = SQL_ERROR;


	//����ODBC�������
	SQLHENV     hEnv = NULL;
	ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
	if (SQL_SUCCESS == ret)
	{
		wcout << _T("�����������ɹ�!") << endl;
	}
	else
	{
		return -1;
	}

	//�趨ODBC�İ汾
	ret = SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);

	//�������ݿ����Ӿ��
	SQLHDBC     hDbc = NULL;
	ret = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);

	//����DSN ���������ݿ�
	ret = SQLConnect(hDbc, (SQLTCHAR*)_T("SQLServerODBC"), SQL_NTS, (SQLTCHAR*)_T("sa"), SQL_NTS, (SQLTCHAR*)_T("Sa123"), SQL_NTS);
	if ((ret == SQL_SUCCESS) || (ret == SQL_SUCCESS_WITH_INFO))
	{
		wcout << _T("���ݿ����ӳɹ�!") << endl;
	}
	else if (ret == SQL_ERROR)
	{
		SQLTCHAR   state[128] = { 0 };
		SQLTCHAR   msg[128] = { 0 };
		//��ȡ������Ϣ
		ret = SQLError(hEnv, hDbc, NULL, state, NULL, msg, sizeof(msg), NULL);
		wcout << state << "   " << msg << endl;
	}

	/////////////////////////////////////////////////////////////////////////////////////////////
	//��������

	//���������
	SQLHSTMT  hStmt = NULL;
	ret = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);

	//SQL��ѯ��� 
	SQLTCHAR sql[] = _T("SELECT  * FROM  Student ");
 
	//ִ��SQL���
	ret = SQLExecDirect(hStmt,sql,SQL_NTS); //SQL_NTS�Զ�����sql���ĳ���
	if ((ret == SQL_SUCCESS) || (ret == SQL_SUCCESS_WITH_INFO))
	{
		//��ѯ֮���������ݷŵ���һ�黺������������Ҫ�����������
		int id = 0;
		TCHAR name[32] = { 0 };
		short age = 0;

		//���ֶ�
		SQLLEN len = SQL_NTS;
		SQLBindCol(hStmt, 1, SQL_C_LONG, &id, sizeof(id), 0);
		SQLBindCol(hStmt, 2, /*SQL_C_CHAR*/SQL_C_WCHAR, name, sizeof(name), &len);
		SQLBindCol(hStmt, 3, SQL_C_SHORT, &age, sizeof(age), 0);

		//���б�������ȡ����
		ret = SQLFetch(hStmt);
		while (ret != SQL_NO_DATA)
		{
			wcout << id << "\t" << name << "\t" << age << endl;

			//ÿ�����һ�����еľ�����,��֤�´λ�ȡ�����ݸɾ�
			id = 0;
			ZeroMemory(name, sizeof(name));
			age = 0;

			//��ȡ��һ�л�������������䵽id,name,age
			ret = SQLFetch(hStmt);
		} 


		SQLLEN n = 0;
		ret = SQLRowCount(hStmt, &n);//��ѯ��Ӱ���������������SELECT ,INSERT,UPDATE,DELETE������
		if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
		{
			_tprintf(_T("��ѯ%d�����ݳɹ�!\n"), n);
		}

	}
	else if (ret == SQL_ERROR)
	{
		SQLTCHAR   state[128] = { 0 };
		SQLTCHAR   msg[128] = { 0 };
		//��ȡ������Ϣ��ע����д�����
		ret = SQLError(hEnv, hDbc, hStmt, state, NULL, msg, sizeof(msg), NULL);
		wcout << state << "   " << msg << endl;
	}
	 
	 
	//�ͷ������
	if (hStmt)
	{
		ret = SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	}

	//////////////////////////////////////////////////////////////////////////////////////////////

	//�ر����ݿ�����
	ret = SQLDisconnect(hDbc);
	if (ret == SQL_SUCCESS)
	{
		wcout << _T("�ر����ݿ����ӳɹ�!") << endl;
	}

	//�ͷ����Ӿ��
	if (hDbc)
	{
		ret = SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
	}

	//�ͷŻ������
	if (hEnv)
	{
		ret = SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
	}

	return 0;
}

