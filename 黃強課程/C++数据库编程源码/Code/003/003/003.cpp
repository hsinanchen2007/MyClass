// 003.cpp : 定义控制台应用程序的入口点。
//


//包含头文件
#include<Windows.h>
#include <sql.h> 
#include <sqlext.h> 
#include<sqltypes.h>
#include <tchar.h>

#include <iostream>
using namespace std;


int main()
{
	//设置为中文  
	_wsetlocale(LC_ALL, L"chs");


	SQLRETURN  ret = SQL_ERROR;


	//分配ODBC环境句柄
	SQLHENV     hEnv = NULL; 
	ret = SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv); 
	if (SQL_SUCCESS == ret)
	{
		wcout << _T("环境句柄分配成功!") << endl; 
	}
	else
	{
		return -1;
	}

	//设定ODBC的版本
	ret = SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, 	(SQLPOINTER)SQL_OV_ODBC3, 0);

	//分配数据库连接句柄
	SQLHDBC     hDbc = NULL;
	ret = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);

	//根据DSN ，连接数据库
	ret = SQLConnect(hDbc, (SQLTCHAR*)_T("SQLServerODBC"), SQL_NTS, (SQLTCHAR*)_T("sa"), SQL_NTS, (SQLTCHAR*)_T("Sa123"), SQL_NTS);
    if ((ret == SQL_SUCCESS) || (ret == SQL_SUCCESS_WITH_INFO))
	{
		wcout << _T("数据库连接成功!")<<endl;
	}
	else if (ret == SQL_ERROR)
	{
		SQLTCHAR   state[128] = { 0 };
		SQLTCHAR   msg[128] = { 0 };
		//获取错误信息
		ret = SQLError(hEnv, hDbc, NULL, state, NULL, msg, sizeof(msg), NULL);
		wcout << state <<"   "<<  msg << endl;
	}


	//关闭数据库连接
	ret = SQLDisconnect(hDbc);
	if (ret == SQL_SUCCESS)
	{
		wcout << _T("关闭数据库连接成功!") << endl;
	}

    //释放连接句柄
	if (hDbc)
	{ 
		ret = SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
	}
	//释放环境句柄
	if (hEnv)
	{
		ret = SQLFreeHandle(SQL_HANDLE_ENV, hEnv);
	}
	 
    return 0;
}

