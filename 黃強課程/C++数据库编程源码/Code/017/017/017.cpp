#include<iostream>
#include <C:\Program Files\Microsoft SQL Server\100\SDK\Include\sqlncli.h>

using namespace std;


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
	//LPCOLESTR pSQL = (LPCOLESTR)L"UPDATE Student  SET name='����' , age =20 ;";
	LPCOLESTR pSQL = (LPCOLESTR)L"UPDATE Student  SET name=? , age =? ;";

	//���������SQL���
	hr = pICommandText->SetCommandText(DBGUID_DEFAULT, (LPCOLESTR)pSQL);
	if (FAILED(hr))
	{
		return -1;
	}


	//�󶨽ṹ
	DBBINDING Bindings[2] = { 0 };  //2���������������鳤��Ϊ2

	Bindings[0].iOrdinal = 1;//������1��ʼ 
	Bindings[0].obValue = 0; //�������е�  ֵ���� ���ֽ�ƫ����,  dwPart ���� DBPART_VALUE ����Ч
	Bindings[0].obLength = 0;//�������е� ���Ȳ��� ���ֽ�ƫ����, dwPart ����DBPART_LENGTH����Ч
	Bindings[0].obStatus = 0;//�������е� ״̬���� ���ֽ�ƫ����, dwPart ����DBPART_STATUS����Ч
	Bindings[0].pTypeInfo = NULL;//�����ֶ�
	Bindings[0].pObject = NULL;//ָ��DBOBJECT�ṹ��ָ��,������BLOB��COM������л����
	Bindings[0].pBindExt = NULL;//�����ֶ� 
	Bindings[0].dwPart = DBPART_VALUE; //����Щ���������ְ󶨵��л����,��DBPART_VALUE DBPART_LENGTH DBPART_STATUSֵ����� 
	Bindings[0].dwMemOwner = DBMEMOWNER_CLIENTOWNED; //ʹ����ӵ���ڴ沢�����ͷ���
	Bindings[0].eParamIO = DBPARAMIO_INPUT;//ָ����󶨹����Ĳ��������롢�������
	Bindings[0].cbMaxLen = 10 * sizeof(WCHAR);//�ɱ䳤���ݽṹ���ֽڳ��ȣ��̶����ȵ�����Դ��ֶ�
	Bindings[0].dwFlags = 0;//ָ���й���θ�ʽ���������ݵ���Ϣ
	Bindings[0].wType = DBTYPE_WSTR;// ֵ���ֵ��������� 
	Bindings[0].bPrecision = 0;//����
	Bindings[0].bScale = 0;//��ģ


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


	//��ȡ�������ӿ�
	IAccessor* pIAccessor = NULL;
	pICommandText->QueryInterface(IID_IAccessor, (void**)&pIAccessor);

	//����������
	HACCESSOR hAccessor = NULL;
	hr = pIAccessor->CreateAccessor(
		DBACCESSOR_PARAMETERDATA, //�������ǲ��������������������ı��������Բ����İ󶨡�
		2, // �������еİ󶨼�������
		Bindings, //  DBBINDING����
		10 * sizeof(WCHAR) + sizeof(short), // ��Ų���ֵ�Ļ������Ĵ�С   ���� ��10���ȵ�Unicode�ַ���) ���� ������
		&hAccessor, // ���ط��������
		NULL // ����ÿ���󶨵�״̬
		);


	DBPARAMS params = { 0 };
	params.cParamSets = 1;

	//�Ҵ��2���������ڴ滺����
	char *pData = new char[22];
	memset(pData, 0, 22);

	WCHAR name[10] = L"�����ʥ";
	short age = 66;
	memcpy(pData, name, 20);
	memcpy(pData + 20, &age, 2);

	params.pData = pData;
	params.hAccessor = hAccessor;

	//ִ������
	DBROWCOUNT row = 0;
	hr = pICommandText->Execute(NULL, IID_NULL, &params, &row, NULL);
	if (SUCCEEDED(hr))
	{
		wcout << L"�޸ĳɹ�,Ӱ������" << row << endl;
	}
	else
	{
		IErrorInfo *pIErrorInfo = NULL;
		GetErrorInfo(0, &pIErrorInfo);
		//��ȡ������Ϣ
		BSTR  pBstrDescription = NULL;
		pIErrorInfo->GetDescription(&pBstrDescription);
		wcout << L"�����޸�ʧ�� " << pBstrDescription << endl;
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

