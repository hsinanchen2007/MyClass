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

 
	try {

		//构造连接字符串
		string ConnStr = "Provider=SQLOLEDB.1;Data Source=192.168.0.199;Persist Security Info=False;User ID=sa;Password=Sa123;Initial Catalog=test";

		//连接数据库
		HRESULT  hr = pConn->Open(ConnStr.data(), "", "", adConnectUnspecified);
		if (SUCCEEDED(hr)) {
			cout << "数据库连接成功！" << endl;
		}
		///////////////////////////////////////////////////////////////////////////////////////////

		 
		//使用Connection对象的Execute方法执行,返回查询的记录集
		string strSql = "DELETE  FROM   Student  WHERE  id = 1000";
		VARIANT   recordsAffected = {0};
		 pConn->Execute(_bstr_t(strSql.c_str()), &recordsAffected, adExecuteNoRecords);
		 cout << "删除"<<recordsAffected.intVal <<"行数据成功！" << endl;

		//关闭连接
		hr = pConn->Close();
		if (SUCCEEDED(hr)) {
			cout << "关闭数据库连接！" << endl;
		} 
		
		////////////////////////////////////////////////////////////////////////////////////////////
		//释放对象 
		pConn.Release(); 
	}
	catch (_com_error & e) {
		cout << e.Description() << endl;
	} 

	//释放com库
	CoUninitialize();

}