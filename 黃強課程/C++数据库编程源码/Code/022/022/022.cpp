#include<Windows.h>
//导入ADO的库
#import "msado15.dll" no_namespace rename("EOF","adoEOF")

#include<iostream>
using namespace std;


int  main()
{
	//初始化com库
	CoInitialize(NULL);

	//定义ADO Connection对象的智能指针，__uuidof获取一个UUID
	_ConnectionPtr  pConn(__uuidof(Connection));

	//定义ADO Command对象的智能指针 
	_CommandPtr  pCmd(__uuidof(Command));

	try {

		//构造连接字符串
		string ConnStr = "Provider=SQLOLEDB.1;Data Source=192.168.0.199;Persist Security Info=False;User ID=sa;Password=Sa123;Initial Catalog=test";

		//连接数据库
		HRESULT  hr = pConn->Open(ConnStr.data(), "", "", adConnectUnspecified);
		if (SUCCEEDED(hr)) {
			cout << "数据库连接成功！" << endl;
		}
		///////////////////////////////////////////////////////////////////////////////////////////

		 
		//设置Command的属性，并构造执行的SQL语句
		string strSql = "INSERT INTO Student  VALUES(?,?,?)";
		pCmd->ActiveConnection = pConn;
		pCmd->CommandText = _bstr_t(strSql.data());
		//adCmdText表示是sql文本，adCmdStoredProc表示存储过程名称
		pCmd->CommandType = adCmdText;

		//为Command传入参数
		//创建参数，ADO比OLEDB的  绑定，访问器  方便太多了
		_ParameterPtr  p1 = pCmd->CreateParameter("id", adInteger, adParamInput, sizeof(int), 1000);

		_ParameterPtr  p2 = pCmd->CreateParameter("name", adVarWChar, adParamInput, (long)11, L"天天");

		_ParameterPtr   p3 = pCmd->CreateParameter("age", adSmallInt, adParamInput, sizeof(short), 12);

		//把3个参数设置进去
		pCmd->Parameters->Append(p1);
		pCmd->Parameters->Append(p2);
		pCmd->Parameters->Append(p3);

		//adExecuteNoRecords参数表示无需返回结果集
		VARIANT recordsAffected = { 0 };//受影响的行数
		hr = pCmd->Execute(&recordsAffected, NULL, adExecuteNoRecords);
		if (recordsAffected.intVal == 1) {
			cout << "插入数据成功！" << endl;
		}

		//关闭连接
		hr = pConn->Close();
		if (SUCCEEDED(hr)) {
			cout << "关闭数据库连接！" << endl;
		}


		
		////////////////////////////////////////////////////////////////////////////////////////////
		//释放对象
		pCmd.Release();
		pConn.Release(); 
	}
	catch (_com_error & e) {
		cout << e.Description() << endl;
	} 

	//释放com库
	CoUninitialize();

}