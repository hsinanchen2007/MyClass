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

	//��������Դ����ͬʱ��ȡIDBInitialize�ӿ�
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


	//�ͷ�COM����
	CoUninitialize();

	system("pause");

	return 0;
}

