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
	ret = SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0);

	//分配数据库连接句柄
	SQLHDBC     hDbc = NULL;
	ret = SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);

	//根据DSN ，连接数据库
	ret = SQLConnect(hDbc, (SQLTCHAR*)_T("SQLServerODBC"), SQL_NTS, (SQLTCHAR*)_T("sa"), SQL_NTS, (SQLTCHAR*)_T("Sa123"), SQL_NTS);
	if ((ret == SQL_SUCCESS) || (ret == SQL_SUCCESS_WITH_INFO))
	{
		wcout << _T("数据库连接成功!") << endl;
	}
	else if (ret == SQL_ERROR)
	{
		SQLTCHAR   state[128] = { 0 };
		SQLTCHAR   msg[128] = { 0 };
		//获取错误信息
		ret = SQLError(hEnv, hDbc, NULL, state, NULL, msg, sizeof(msg), NULL);
		wcout << state << "   " << msg << endl;
	}

    /////////////////////////////////////////////////////////////////////////////////////////////
	//插入数据

	//分配语句句柄
	SQLHSTMT  hStmt = NULL;
    ret = SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);

	//准备SQL语句
	//SQLTCHAR sql[] = _T("INSERT  INTO  Student  VALUES('1001' ,'小白',23) ");//没 “?”简单版本
	SQLTCHAR sql[] = _T("INSERT  INTO  Student  VALUES(? , ? , ?) ");//复杂版本
	ret = SQLPrepare(hStmt, sql, SQL_NTS);


	//复杂版本下的参数传递到SQL语句中
	//三个参数
	SQLINTEGER id = 1000;
	SQLTCHAR name[32] = _T("张三");
	SQLSMALLINT age = 10;

	//绑定SQL语句的参数
	ret = SQLBindParameter(hStmt, 1, SQL_PARAM_INPUT, SQL_C_LONG, SQL_INTEGER, 0, 0, (SQLPOINTER)&id, 0, NULL);
	//因为数据库设计的是nvarchar，所以这里是SQL_WVARCHAR ，需要对应
	ret = SQLBindParameter(hStmt, 2, SQL_PARAM_INPUT, /*SQL_C_CHAR*/ SQL_C_WCHAR, /*SQL_VARCHAR*/SQL_WVARCHAR, 3, 0, (SQLPOINTER)name, 0, NULL);

	ret = SQLBindParameter(hStmt, 3, SQL_PARAM_INPUT, SQL_C_SHORT, SQL_SMALLINT, 0, 0, (SQLPOINTER)&age, 0, NULL);


	//执行SQL语句
	ret=SQLExecute(hStmt);
	if ((ret == SQL_SUCCESS) || (ret == SQL_SUCCESS_WITH_INFO))
	{
		SQLLEN n = 0;
		ret = SQLRowCount(hStmt, &n);//查询被影响的行数
		if (ret == SQL_SUCCESS || ret == SQL_SUCCESS_WITH_INFO)
		{
			_tprintf(_T("插入%d行数据成功!\n"), n);
		}

	}
	else if (ret == SQL_ERROR)
	{
		SQLTCHAR   state[128] = { 0 };
		SQLTCHAR   msg[128] = { 0 };
		//获取错误信息，注意填写语句句柄
		ret = SQLError(hEnv, hDbc, hStmt, state, NULL, msg, sizeof(msg), NULL);
		wcout << state << "   " << msg << endl;
	}


	//释放语句句柄
	if (hStmt)
	{
		ret = SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	}

	//////////////////////////////////////////////////////////////////////////////////////////////
	 
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

