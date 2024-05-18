#include<iostream>
#include <C:\Program Files\Microsoft SQL Server\100\SDK\Include\sqlncli.h>

using namespace std;

//对齐字节数，让其是4的倍数
#define ROUNDUP(x) ROUND(x,4)
#define ROUND(x,y) (((x)+(y-1))&~(y-1))


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
	LPCOLESTR pSQL = (LPCOLESTR)L"SELECT * FROM Student";

	//设置命令sql
	hr = pICommandText->SetCommandText(DBGUID_DEFAULT, (LPCOLESTR)pSQL);
	if (FAILED(hr))
	{
		return -1;
	}

	//执行命令并获取IRowset接口
	IRowset* pIRowset = NULL;
	hr = pICommandText->Execute(NULL, IID_IRowset, NULL, NULL, (IUnknown**)&pIRowset);
	if (FAILED(hr))
	{
		return -1;
	}

	//获取IColumnsInfo接口
	IColumnsInfo *pIColumnsInfo = NULL;
	hr = pIRowset->QueryInterface(IID_IColumnsInfo, (void**)&pIColumnsInfo);
	if (FAILED(hr))
	{
		return -1;
	}

	//获取结果集的列的详细信息，方便后面写DBBINDING绑定
	ULONG            cColumns;//列数
	DBCOLUMNINFO  *   rgColumnInfo = NULL;//每列的信息
	OLECHAR *pStringBuffer;
	hr = pIColumnsInfo->GetColumnInfo(&cColumns, &rgColumnInfo, &pStringBuffer);

	//有了列信息，方便做绑定，为每个列分配DBBINDING内存空间
	DBBINDING *     rgBindings = (DBBINDING*)CoTaskMemAlloc(cColumns * sizeof(DBBINDING));
	memset(rgBindings, 0, cColumns * sizeof(DBBINDING));

	ULONG                 dwOffset = 0;

	for (int iCol = 0; iCol < cColumns; iCol++)
	{
		rgBindings[iCol].iOrdinal = rgColumnInfo[iCol].iOrdinal;
		//状态+长度+值
		rgBindings[iCol].dwPart = DBPART_STATUS | DBPART_LENGTH | DBPART_VALUE;


		rgBindings[iCol].obStatus = dwOffset; // 状态的偏移
		rgBindings[iCol].obLength = dwOffset + sizeof(DBSTATUS);// 长度的偏移
		rgBindings[iCol].obValue = dwOffset + sizeof(DBSTATUS) + sizeof(ULONG);//值的偏移

		rgBindings[iCol].dwMemOwner = DBMEMOWNER_CLIENTOWNED;
		rgBindings[iCol].eParamIO = DBPARAMIO_NOTPARAM;
		rgBindings[iCol].bPrecision = rgColumnInfo[iCol].bPrecision;
		rgBindings[iCol].bScale = rgColumnInfo[iCol].bScale;
		rgBindings[iCol].wType = rgColumnInfo[iCol].wType;

		switch (rgColumnInfo[iCol].wType)
		{
		case DBTYPE_I2://两字节带符号整数 
		case DBTYPE_I4://四字节带符号整数  
			rgBindings[iCol].cbMaxLen = rgColumnInfo[iCol].ulColumnSize;
			break;

		case DBTYPE_WSTR:
			//宽字节
			rgBindings[iCol].cbMaxLen = rgColumnInfo[iCol].ulColumnSize * sizeof(WCHAR);
			break;
		}

		//依次累加
		dwOffset = rgBindings[iCol].obValue + rgBindings[iCol].cbMaxLen;
		//4字节对齐偏移量
		dwOffset = ROUNDUP(dwOffset);
	}

	//绑定做好了，释放列信息分配的空间
	CoTaskMemFree(rgColumnInfo);
	CoTaskMemFree(pStringBuffer);
	pIColumnsInfo->Release();


	//获取访问器的接口
	IAccessor *   pIAccessor = NULL;
	hr = pIRowset->QueryInterface(IID_IAccessor, (void**)&pIAccessor);

	//创建访问器
	HACCESSOR hAccessor;
	hr = pIAccessor->CreateAccessor(DBACCESSOR_ROWDATA, cColumns, rgBindings, 0, &hAccessor, NULL);
	if (FAILED(hr))
	{
		return -1;
	}

	//分配1行数据的缓冲区，dwOffset为一行所有列所需空间
	void *     buf = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwOffset);

	//循环读取数据，每次读取1行，实际读取到cRowsObtained行 
	ULONG                   cRowsObtained;
	HROW *                  hRows = NULL;
	while (S_OK == pIRowset->GetNextRows(DB_NULL_HCHAPTER, 0, 1/*一次获取一行数据*/, &cRowsObtained, &hRows))
	{
		//将结果集中的一行内容按访问器规则获取到buf中
		pIRowset->GetData(hRows[0], hAccessor, buf); //因为只有一行，hRows[0]就可以了

		//读取id，如果status等于0才表示正常读取了值
		DBSTATUS status0 = *(DBSTATUS*)((PBYTE)buf + rgBindings[0].obStatus);
		ULONG uSize0 = *(ULONG*)((PBYTE)buf + rgBindings[0].obLength);
		int offset0 = rgBindings[0].obValue;
		int  id = 0;
		id = *((int *)((char *)buf + offset0));

		//读取name，如果status等于0才表示正常读取了值
		DBSTATUS status1 = *(DBSTATUS*)((PBYTE)buf + rgBindings[1].obStatus);
		ULONG uSize1 = *(ULONG*)((PBYTE)buf + rgBindings[1].obLength);
		int len1 = rgBindings[1].cbMaxLen;
		int offset1 = rgBindings[1].obValue;
		WCHAR  name[64] = { 0 };
		memcpy((char *)name, (char*)buf + offset1, len1);

		//读取age，如果status等于0才表示正常读取了值
		DBSTATUS status2 = *(DBSTATUS*)((PBYTE)buf + rgBindings[2].obStatus);
		ULONG uSize2 = *(ULONG*)((PBYTE)buf + rgBindings[2].obLength);
		int offset2 = rgBindings[2].obValue;
		short  age = 0;
		age = *((short *)((char*)buf + offset2));

		//输出
		wcout << id << "   " << name << "   " << age << endl;

		//释放行句柄数组
		pIRowset->ReleaseRows(cRowsObtained, hRows, NULL, NULL, NULL);
		//释放该行内存
		CoTaskMemFree(hRows);
		hRows = NULL;
	}

	//释放缓冲区
	HeapFree(GetProcessHeap(), 0, buf);


	//释放接口
	if (pIRowset != NULL) {
		pIRowset->Release();
		pIRowset = NULL;
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

