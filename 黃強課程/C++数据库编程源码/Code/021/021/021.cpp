#include<Windows.h>
//导入ADO的库
#import "msado15.dll" no_namespace rename("EOF","adoEOF")

#include<iostream>
using namespace std;


int  main()
{
	//初始化com库
	CoInitialize(NULL);

	//定义ADO Connection对象的智能指针，获取一个UUID
	_ConnectionPtr  pConn(__uuidof(Connection));

	try {

		//构造连接字符串
		string ConnStr = "Provider=SQLOLEDB.1;Data Source=192.168.0.199;Persist Security Info=False;User ID=sa;Password=Sa123;Initial Catalog=test";
		 
		//连接数据库
		HRESULT  hr = pConn->Open(ConnStr.data(), "", "", adConnectUnspecified);
		if (SUCCEEDED(hr)) {
			cout << "数据库连接成功！" << endl;
		}


		//释放对象
		pConn.Release();


	}
	catch (_com_error & e) {
		cout << e.Description()<< endl;
	}


	//释放com库
	CoUninitialize();

}