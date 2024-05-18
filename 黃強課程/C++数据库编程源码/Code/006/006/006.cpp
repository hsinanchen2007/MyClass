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
	//SQLTCHAR sql[] = _T("DELETE FROM  Student WHERE  id = 1000");//�򵥰汾
	SQLTCHAR sql[] = _T("DELETE FROM  Student WHERE  id = ?");//���Ӱ汾

	//׼��SQL���
	ret = SQLPrepare(hStmt,sql, SQL_NTS);//SQL_NTS�Զ�����sql���ĳ���

	//���Ӱ汾��SQL���Ĳ��� 
	int id = 1000;
	ret = SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, &id , 0 , NULL);


	//ִ��SQL���
	ret = SQLExecute(hStmt ); 
	if ((ret == SQL_SUCCESS) || (ret == SQL_SUCCESS_WITH_INFO)|| (ret == SQL_NO_DATA))
	{  
		SQLLEN n = 0;
		ret = SQLRowCount(hStmt, &n);//��ѯ��Ӱ���������������SELECT ,INSERT,UPDATE,DELETE������
		if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
		{
			_tprintf(_T("ɾ��%d�����ݳɹ�!\n"), n);
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

