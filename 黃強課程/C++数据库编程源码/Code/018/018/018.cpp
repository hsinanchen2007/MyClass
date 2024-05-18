#include<iostream>
#include <C:\Program Files\Microsoft SQL Server\100\SDK\Include\sqlncli.h>

using namespace std;

//�����ֽ�����������4�ı���
#define ROUNDUP(x) ROUND(x,4)
#define ROUND(x,y) (((x)+(y-1))&~(y-1))


int main()
{
	//�ÿ���̨�������WCHAR
	setlocale(LC_ALL, "");

	//��ʼ��COM��
	CoInitialize(NULL);

	IDBInitialize*   pIDBInitialize = NULL;
	HRESULT          hr;

	//����COM����
	hr = CoCreateInstance(CLSID_SQLNCLI10, NULL, CLSCTX_INPROC_SERVER,
		IID_IDBInitialize, (void**)&pIDBInitialize);

	if (FAILED(hr))
	{
		return -1;
	}

	//��ʼ�����ݿ�����
	DBPROP InitProperties[4] = { 0 };

	//ָ�����ݿ�ʵ����
	InitProperties[0].dwPropertyID = DBPROP_INIT_DATASOURCE;
	InitProperties[0].vValue.vt = VT_BSTR;
	InitProperties[0].vValue.bstrVal = SysAllocString(L"192.168.0.199");

	//ָ�����ݿ���
	InitProperties[1].dwPropertyID = DBPROP_INIT_CATALOG;
	InitProperties[1].vValue.vt = VT_BSTR;
	InitProperties[1].vValue.bstrVal = SysAllocString(L"test");

	//ָ����¼�û���
	InitProperties[2].dwPropertyID = DBPROP_AUTH_USERID;
	InitProperties[2].vValue.vt = VT_BSTR;
	InitProperties[2].vValue.bstrVal = SysAllocString(L"sa");

	//ָ����¼����
	InitProperties[3].dwPropertyID = DBPROP_AUTH_PASSWORD;
	InitProperties[3].vValue.vt = VT_BSTR;
	InitProperties[3].vValue.bstrVal = SysAllocString(L"Sa123");

	//�������Լ��ϣ���ʼ������ʱ��Ҫ�������
	DBPROPSET rgInitPropSet[1] = { 0 };
	rgInitPropSet[0].guidPropertySet = DBPROPSET_DBINIT;
	rgInitPropSet[0].cProperties = 4;
	rgInitPropSet[0].rgProperties = InitProperties;

	//��ȡ �������ݿ�����   �Ľӿ�
	IDBProperties* pIDBProperties = NULL;
	hr = pIDBInitialize->QueryInterface(IID_IDBProperties, (void **)&pIDBProperties);
	if (FAILED(hr))
	{
		return -1;
	}

	//���ýӿ����� ��ʼ������
	hr = pIDBProperties->SetProperties(1, rgInitPropSet);
	if (FAILED(hr))
	{
		return -1;
	}

	//���ӵ����ݿ�
	hr = pIDBInitialize->Initialize();
	if (SUCCEEDED(hr)) {
		wcout << L"���ݿ����ӳɹ���" << endl;
	}


	//��ȡ�Ự�ӿ�
	IDBCreateSession* pIDBCreateSession = NULL;
	hr = pIDBInitialize->QueryInterface(IID_IDBCreateSession, (void**)& pIDBCreateSession);
	if (FAILED(hr))
	{
		return -1;
	}

	//����CreateSession�����Ự���󣬲����´����ĻỰ�Ϸ��ش�������ӿ�
	IDBCreateCommand* pIDBCreateCommand = NULL;
	hr = pIDBCreateSession->CreateSession(NULL, IID_IDBCreateCommand, (IUnknown**)&pIDBCreateCommand);
	if (FAILED(hr))
	{
		return -1;
	}


	//����Command����ͬʱ��ȡICommandText�ӿ�
	ICommandText* pICommandText = NULL;
	hr = pIDBCreateCommand->CreateCommand(NULL, IID_ICommandText, (IUnknown**)&pICommandText);
	if (FAILED(hr))
	{
		return -1;
	}

	//sql���
	LPCOLESTR pSQL = (LPCOLESTR)L"SELECT * FROM Student";

	//��������sql
	hr = pICommandText->SetCommandText(DBGUID_DEFAULT, (LPCOLESTR)pSQL);
	if (FAILED(hr))
	{
		return -1;
	}

	//ִ�������ȡIRowset�ӿ�
	IRowset* pIRowset = NULL;
	hr = pICommandText->Execute(NULL, IID_IRowset, NULL, NULL, (IUnknown**)&pIRowset);
	if (FAILED(hr))
	{
		return -1;
	}

	//��ȡIColumnsInfo�ӿ�
	IColumnsInfo *pIColumnsInfo = NULL;
	hr = pIRowset->QueryInterface(IID_IColumnsInfo, (void**)&pIColumnsInfo);
	if (FAILED(hr))
	{
		return -1;
	}

	//��ȡ��������е���ϸ��Ϣ���������дDBBINDING��
	ULONG            cColumns;//����
	DBCOLUMNINFO  *   rgColumnInfo = NULL;//ÿ�е���Ϣ
	OLECHAR *pStringBuffer;
	hr = pIColumnsInfo->GetColumnInfo(&cColumns, &rgColumnInfo, &pStringBuffer);

	//��������Ϣ���������󶨣�Ϊÿ���з���DBBINDING�ڴ�ռ�
	DBBINDING *     rgBindings = (DBBINDING*)CoTaskMemAlloc(cColumns * sizeof(DBBINDING));
	memset(rgBindings, 0, cColumns * sizeof(DBBINDING));

	ULONG                 dwOffset = 0;

	for (int iCol = 0; iCol < cColumns; iCol++)
	{
		rgBindings[iCol].iOrdinal = rgColumnInfo[iCol].iOrdinal;
		//״̬+����+ֵ
		rgBindings[iCol].dwPart = DBPART_STATUS | DBPART_LENGTH | DBPART_VALUE;


		rgBindings[iCol].obStatus = dwOffset; // ״̬��ƫ��
		rgBindings[iCol].obLength = dwOffset + sizeof(DBSTATUS);// ���ȵ�ƫ��
		rgBindings[iCol].obValue = dwOffset + sizeof(DBSTATUS) + sizeof(ULONG);//ֵ��ƫ��

		rgBindings[iCol].dwMemOwner = DBMEMOWNER_CLIENTOWNED;
		rgBindings[iCol].eParamIO = DBPARAMIO_NOTPARAM;
		rgBindings[iCol].bPrecision = rgColumnInfo[iCol].bPrecision;
		rgBindings[iCol].bScale = rgColumnInfo[iCol].bScale;
		rgBindings[iCol].wType = rgColumnInfo[iCol].wType;

		switch (rgColumnInfo[iCol].wType)
		{
		case DBTYPE_I2://���ֽڴ��������� 
		case DBTYPE_I4://���ֽڴ���������  
			rgBindings[iCol].cbMaxLen = rgColumnInfo[iCol].ulColumnSize;
			break;

		case DBTYPE_WSTR:
			//���ֽ�
			rgBindings[iCol].cbMaxLen = rgColumnInfo[iCol].ulColumnSize * sizeof(WCHAR);
			break;
		}

		//�����ۼ�
		dwOffset = rgBindings[iCol].obValue + rgBindings[iCol].cbMaxLen;
		//4�ֽڶ���ƫ����
		dwOffset = ROUNDUP(dwOffset);
	}

	//�������ˣ��ͷ�����Ϣ����Ŀռ�
	CoTaskMemFree(rgColumnInfo);
	CoTaskMemFree(pStringBuffer);
	pIColumnsInfo->Release();


	//��ȡ�������Ľӿ�
	IAccessor *   pIAccessor = NULL;
	hr = pIRowset->QueryInterface(IID_IAccessor, (void**)&pIAccessor);

	//����������
	HACCESSOR hAccessor;
	hr = pIAccessor->CreateAccessor(DBACCESSOR_ROWDATA, cColumns, rgBindings, 0, &hAccessor, NULL);
	if (FAILED(hr))
	{
		return -1;
	}

	//����1�����ݵĻ�������dwOffsetΪһ������������ռ�
	void *     buf = HeapAlloc(GetProcessHeap(), HEAP_ZERO_MEMORY, dwOffset);

	//ѭ����ȡ���ݣ�ÿ�ζ�ȡ1�У�ʵ�ʶ�ȡ��cRowsObtained�� 
	ULONG                   cRowsObtained;
	HROW *                  hRows = NULL;
	while (S_OK == pIRowset->GetNextRows(DB_NULL_HCHAPTER, 0, 1/*һ�λ�ȡһ������*/, &cRowsObtained, &hRows))
	{
		//��������е�һ�����ݰ������������ȡ��buf��
		pIRowset->GetData(hRows[0], hAccessor, buf); //��Ϊֻ��һ�У�hRows[0]�Ϳ�����

		//��ȡid�����status����0�ű�ʾ������ȡ��ֵ
		DBSTATUS status0 = *(DBSTATUS*)((PBYTE)buf + rgBindings[0].obStatus);
		ULONG uSize0 = *(ULONG*)((PBYTE)buf + rgBindings[0].obLength);
		int offset0 = rgBindings[0].obValue;
		int  id = 0;
		id = *((int *)((char *)buf + offset0));

		//��ȡname�����status����0�ű�ʾ������ȡ��ֵ
		DBSTATUS status1 = *(DBSTATUS*)((PBYTE)buf + rgBindings[1].obStatus);
		ULONG uSize1 = *(ULONG*)((PBYTE)buf + rgBindings[1].obLength);
		int len1 = rgBindings[1].cbMaxLen;
		int offset1 = rgBindings[1].obValue;
		WCHAR  name[64] = { 0 };
		memcpy((char *)name, (char*)buf + offset1, len1);

		//��ȡage�����status����0�ű�ʾ������ȡ��ֵ
		DBSTATUS status2 = *(DBSTATUS*)((PBYTE)buf + rgBindings[2].obStatus);
		ULONG uSize2 = *(ULONG*)((PBYTE)buf + rgBindings[2].obLength);
		int offset2 = rgBindings[2].obValue;
		short  age = 0;
		age = *((short *)((char*)buf + offset2));

		//���
		wcout << id << "   " << name << "   " << age << endl;

		//�ͷ��о������
		pIRowset->ReleaseRows(cRowsObtained, hRows, NULL, NULL, NULL);
		//�ͷŸ����ڴ�
		CoTaskMemFree(hRows);
		hRows = NULL;
	}

	//�ͷŻ�����
	HeapFree(GetProcessHeap(), 0, buf);


	//�ͷŽӿ�
	if (pIRowset != NULL) {
		pIRowset->Release();
		pIRowset = NULL;
	}

	//�ͷŽӿ�
	if (pIAccessor != NULL) {
		pIAccessor->Release();
		pIAccessor = NULL;
	}


	//�ͷŽӿ�
	if (pIDBCreateSession != NULL) {
		pIDBCreateSession->Release();
		pIDBCreateSession = NULL;
	}

	//�ͷŽӿ�
	if (pICommandText != NULL) {
		pICommandText->Release();
		pICommandText = NULL;
	}

	//�ͷŽӿ�
	if (pIDBCreateCommand != NULL) {
		pIDBCreateCommand->Release();
		pIDBCreateCommand = NULL;
	}


	//������Դ���󷵻�δ��ʼ��״̬��
	hr = pIDBInitialize->Uninitialize();
	if (SUCCEEDED(hr)) {
		wcout << L"�ر����ݿ����ӣ�" << endl;
	}

	//�ͷŽӿ�
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

