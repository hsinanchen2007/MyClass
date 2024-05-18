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
	ret = SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, 	(SQLPOINTER)SQL_OV_ODBC3, 0);

	//�������ݿ����Ӿ��
	SQLHDBC     hDbc = NULL;
	ret = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);

	//����DSN ���������ݿ�
	ret = SQLConnect(hDbc, (SQLTCHAR*)_T("SQLServerODBC"), SQL_NTS, (SQLTCHAR*)_T("sa"), SQL_NTS, (SQLTCHAR*)_T("Sa123"), SQL_NTS);
    if ((ret == SQL_SUCCESS) || (ret == SQL_SUCCESS_WITH_INFO))
	{
		wcout << _T("���ݿ����ӳɹ�!")<<endl;
	}
	else if (ret == SQL_ERROR)
	{
		SQLTCHAR   state[128] = { 0 };
		SQLTCHAR   msg[128] = { 0 };
		//��ȡ������Ϣ
		ret = SQLError(hEnv, hDbc, NULL, state, NULL, msg, sizeof(msg), NULL);
		wcout << state <<"   "<<  msg << endl;
	}


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

