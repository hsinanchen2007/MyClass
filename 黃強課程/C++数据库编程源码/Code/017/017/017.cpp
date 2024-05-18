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

	//创建COM对象
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

	//利用CreateSession创建会话对象，并在新创建的会话上返回创建命令接口
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
	//LPCOLESTR pSQL = (LPCOLESTR)L"UPDATE Student  SET name='李四' , age =20 ;";
	LPCOLESTR pSQL = (LPCOLESTR)L"UPDATE Student  SET name=? , age =? ;";

	//设置命令的SQL语句
	hr = pICommandText->SetCommandText(DBGUID_DEFAULT, (LPCOLESTR)pSQL);
	if (FAILED(hr))
	{
		return -1;
	}


	//绑定结构
	DBBINDING Bindings[2] = { 0 };  //2个参数，所以数组长度为2

	Bindings[0].iOrdinal = 1;//序数从1开始 
	Bindings[0].obValue = 0; //缓冲区中到  值部分 的字节偏移量,  dwPart 设置 DBPART_VALUE 才生效
	Bindings[0].obLength = 0;//缓冲区中到 长度部分 的字节偏移量, dwPart 设置DBPART_LENGTH才生效
	Bindings[0].obStatus = 0;//缓冲区中到 状态部分 的字节偏移量, dwPart 设置DBPART_STATUS才生效
	Bindings[0].pTypeInfo = NULL;//保留字段
	Bindings[0].pObject = NULL;//指向DBOBJECT结构的指针,可容纳BLOB或COM对象的列或参数
	Bindings[0].pBindExt = NULL;//保留字段 
	Bindings[0].dwPart = DBPART_VALUE; //将哪些缓冲区部分绑定到列或参数,是DBPART_VALUE DBPART_LENGTH DBPART_STATUS值的组合 
	Bindings[0].dwMemOwner = DBMEMOWNER_CLIENTOWNED; //使用者拥有内存并负责释放它
	Bindings[0].eParamIO = DBPARAMIO_INPUT;//指定与绑定关联的参数是输入、输出参数
	Bindings[0].cbMaxLen = 10 * sizeof(WCHAR);//可变长数据结构的字节长度，固定长度的则忽略此字段
	Bindings[0].dwFlags = 0;//指定有关如何格式化返回数据的信息
	Bindings[0].wType = DBTYPE_WSTR;// 值部分的数据类型 
	Bindings[0].bPrecision = 0;//精度
	Bindings[0].bScale = 0;//规模


	Bindings[1].iOrdinal = 2;
	Bindings[1].obValue = Bindings[0].cbMaxLen;
	Bindings[1].obLength = 0;
	Bindings[1].obStatus = 0;
	Bindings[1].pTypeInfo = NULL;
	Bindings[1].pObject = NULL;
	Bindings[1].pBindExt = NULL;
	Bindings[1].dwPart = DBPART_VALUE;
	Bindings[1].dwMemOwner = DBMEMOWNER_CLIENTOWNED;
	Bindings[1].eParamIO = DBPARAMIO_INPUT;
	Bindings[1].cbMaxLen = 0;
	Bindings[1].dwFlags = 0;
	Bindings[1].wType = DBTYPE_I2;
	Bindings[1].bPrecision = 0;
	Bindings[1].bScale = 0;


	//获取访问器接口
	IAccessor* pIAccessor = NULL;
	pICommandText->QueryInterface(IID_IAccessor, (void**)&pIAccessor);

	//创建访问器
	HACCESSOR hAccessor = NULL;
	hr = pIAccessor->CreateAccessor(
		DBACCESSOR_PARAMETERDATA, //访问器是参数访问器，并在命令文本中描述对参数的绑定。
		2, // 访问器中的绑定几个参数
		Bindings, //  DBBINDING数组
		10 * sizeof(WCHAR) + sizeof(short), // 存放参数值的缓冲区的大小   姓名 （10长度的Unicode字符串) 年龄 短整型
		&hAccessor, // 返回访问器句柄
		NULL // 返回每个绑定的状态
		);


	DBPARAMS params = { 0 };
	params.cParamSets = 1;

	//我存放2个参数的内存缓冲区
	char *pData = new char[22];
	memset(pData, 0, 22);

	WCHAR name[10] = L"齐天大圣";
	short age = 66;
	memcpy(pData, name, 20);
	memcpy(pData + 20, &age, 2);

	params.pData = pData;
	params.hAccessor = hAccessor;

	//执行命令
	DBROWCOUNT row = 0;
	hr = pICommandText->Execute(NULL, IID_NULL, &params, &row, NULL);
	if (SUCCEEDED(hr))
	{
		wcout << L"修改成功,影响行数" << row << endl;
	}
	else
	{
		IErrorInfo *pIErrorInfo = NULL;
		GetErrorInfo(0, &pIErrorInfo);
		//获取错误信息
		BSTR  pBstrDescription = NULL;
		pIErrorInfo->GetDescription(&pBstrDescription);
		wcout << L"数据修改失败 " << pBstrDescription << endl;
	}


	//释放接口
	if (pIAccessor != NULL) {
		pIAccessor->Release();
		pIAccessor = NULL;
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

