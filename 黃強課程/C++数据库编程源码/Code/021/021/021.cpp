#include<Windows.h>
//����ADO�Ŀ�
#import "msado15.dll" no_namespace rename("EOF","adoEOF")

#include<iostream>
using namespace std;


int  main()
{
	//��ʼ��com��
	CoInitialize(NULL);

	//����ADO Connection���������ָ�룬��ȡһ��UUID
	_ConnectionPtr  pConn(__uuidof(Connection));

	try {

		//���������ַ���
		string ConnStr = "Provider=SQLOLEDB.1;Data Source=192.168.0.199;Persist Security Info=False;User ID=sa;Password=Sa123;Initial Catalog=test";
		 
		//�������ݿ�
		HRESULT  hr = pConn->Open(ConnStr.data(), "", "", adConnectUnspecified);
		if (SUCCEEDED(hr)) {
			cout << "���ݿ����ӳɹ���" << endl;
		}


		//�ͷŶ���
		pConn.Release();


	}
	catch (_com_error & e) {
		cout << e.Description()<< endl;
	}


	//�ͷ�com��
	CoUninitialize();

}