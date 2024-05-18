#include<iostream>
#include <C:\Program Files\Microsoft SQL Server\100\SDK\Include\sqlncli.h>

using namespace std;



int main()
{
	//让控制台可以输出WCHAR
	setlocale(LC_ALL, "");

	//初始化COM库
	CoInitialize(NULL);

	IDBInitialize*   pIDBInitialize = NULL;
	HRESULT          hr;

	//创建数据源对象，同时获取IDBInitialize接口
	hr = CoCreateInstance(CLSID_SQLNCLI10, NULL, CLSCTX_INPROC_SERVER,
		IID_IDBInitialize, (void**)&pIDBInitialize);

	if (FAILED(hr))
	{
		return -1;
	}

	//初始化数据库属性
	DBPROP InitProperties[4] = { 0 };

	//指定数据库实例名
	InitProperties[0].dwPropertyID = DBPROP_INIT_DATASOURCE;
	InitProperties[0].vValue.vt = VT_BSTR;
	InitProperties[0].vValue.bstrVal = SysAllocString(L"192.168.0.199");

	//指定数据库名
	InitProperties[1].dwPropertyID = DBPROP_INIT_CATALOG;
	InitProperties[1].vValue.vt = VT_BSTR;
	InitProperties[1].vValue.bstrVal = SysAllocString(L"test");

	//指定登录用户名
	InitProperties[2].dwPropertyID = DBPROP_AUTH_USERID;
	InitProperties[2].vValue.vt = VT_BSTR;
	InitProperties[2].vValue.bstrVal = SysAllocString(L"sa");

	//指定登录密码
	InitProperties[3].dwPropertyID = DBPROP_AUTH_PASSWORD;
	InitProperties[3].vValue.vt = VT_BSTR;
	InitProperties[3].vValue.bstrVal = SysAllocString(L"Sa123");

	//创建属性集合，初始化连接时需要这个集合
	DBPROPSET rgInitPropSet[1] = { 0 };
	rgInitPropSet[0].guidPropertySet = DBPROPSET_DBINIT;
	rgInitPropSet[0].cProperties = 4;
	rgInitPropSet[0].rgProperties = InitProperties;

	//获取 设置数据库属性   的接口
	IDBProperties* pIDBProperties = NULL;
	hr = pIDBInitialize->QueryInterface(IID_IDBProperties, (void **)&pIDBProperties);
	if (FAILED(hr))
	{
		return -1;
	}

	//利用接口设置 初始化属性
	hr = pIDBProperties->SetProperties(1, rgInitPropSet);
	if (FAILED(hr))
	{
		return -1;
	}

	//连接到数据库
	hr = pIDBInitialize->Initialize();
	if (SUCCEEDED(hr)) {
		wcout << L"数据库连接成功！" << endl;
	}


	//获取会话接口
	IDBCreateSession* pIDBCreateSession = NULL;
	hr = pIDBInitialize->QueryInterface(IID_IDBCreateSession, (void**)& pIDBCreateSession);
	if (FAILED(hr))
	{
		return -1;
	}

	//利用CreateSession创建会话对象，同时获取创建命令接口
	IDBCreateCommand* pIDBCreateCommand = NULL;
	hr = pIDBCreateSession->CreateSession(NULL, IID_IDBCreateCommand, (IUnknown**)&pIDBCreateCommand);
	if (FAILED(hr))
	{
		return -1;
	}


	//创建Command对象，同时获取ICommandText接口
	ICommandText* pICommandText = NULL;
	hr = pIDBCreateCommand->CreateCommand(NULL, IID_ICommandText, (IUnknown**)&pICommandText);
	if (FAILED(hr))
	{
		return -1;
	}



	//sql语句
	LPCOLESTR pSQL = (LPCOLESTR)L"INSERT  INTO  Student VALUES( 3000,'张三',10);";

	//设置命令的SQL语句
	hr = pICommandText->SetCommandText(DBGUID_DEFAULT, (LPCOLESTR)pSQL);
	if (FAILED(hr))
	{
		return -1;
	}


	DBROWCOUNT row = 0;
	//执行命令
	hr = pICommandText->Execute(NULL, IID_NULL, NULL, &row, NULL);
	if (SUCCEEDED(hr))
	{
		wcout << L"数据插入成功,影响行数" << row << endl;
	}
	else
	{
		IErrorInfo *pIErrorInfo = NULL;
		GetErrorInfo(0, &pIErrorInfo);
		//获取错误信息
		BSTR  pBstrDescription = NULL;
		pIErrorInfo->GetDescription(&pBstrDescription);
		wcout << L"数据插入失败 " << pBstrDescription << endl;
	}




	//释放接口
	if (pIDBCreateSession != NULL) {
		pIDBCreateSession->Release();
		pIDBCreateSession = NULL;
	}

	//释放接口
	if (pICommandText != NULL) {
		pICommandText->Release();
		pICommandText = NULL;
	}

	//释放接口
	if (pIDBCreateCommand != NULL) {
		pIDBCreateCommand->Release();
		pIDBCreateCommand = NULL;
	}


	//将数据源对象返回未初始化状态。
	hr = pIDBInitialize->Uninitialize();
	if (SUCCEEDED(hr)) {
		wcout << L"关闭数据库连接！" << endl;
	}

	//释放接口
	if (pIDBProperties != NULL) {
		pIDBProperties->Release();
		pIDBProperties = NULL;
	}

	if (pIDBInitialize != NULL) {
		pIDBInitialize->Release();
		pIDBInitialize = NULL;
	}

	CoUninitialize();

	system("pause");

	return 0;
}

