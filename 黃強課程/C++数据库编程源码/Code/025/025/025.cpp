#include<Windows.h>
//����ADO�Ŀ�
#import "msado15.dll" no_namespace rename("EOF","adoEOF")

#include<iostream>
using namespace std;


int  main()
{
	//��ʼ��com��
	CoInitialize(NULL);

	//����ADO Connection���������ָ�룬__uuidof��ȡһ��UUID
	_ConnectionPtr  pConn(__uuidof(Connection));

 
	try {

		//���������ַ���
		string ConnStr = "Provider=SQLOLEDB.1;Data Source=192.168.0.199;Persist Security Info=False;User ID=sa;Password=Sa123;Initial Catalog=test";

		//�������ݿ�
		HRESULT  hr = pConn->Open(ConnStr.data(), "", "", adConnectUnspecified);
		if (SUCCEEDED(hr)) {
			cout << "���ݿ����ӳɹ���" << endl;
		}
		///////////////////////////////////////////////////////////////////////////////////////////

		 
		//ʹ��Connection�����Execute����ִ��,���ز�ѯ�ļ�¼��
		string strSql = "DELETE  FROM   Student  WHERE  id = 1000";
		VARIANT   recordsAffected = {0};
		 pConn->Execute(_bstr_t(strSql.c_str()), &recordsAffected, adExecuteNoRecords);
		 cout << "ɾ��"<<recordsAffected.intVal <<"�����ݳɹ���" << endl;

		//�ر�����
		hr = pConn->Close();
		if (SUCCEEDED(hr)) {
			cout << "�ر����ݿ����ӣ�" << endl;
		} 
		
		////////////////////////////////////////////////////////////////////////////////////////////
		//�ͷŶ��� 
		pConn.Release(); 
	}
	catch (_com_error & e) {
		cout << e.Description() << endl;
	} 

	//�ͷ�com��
	CoUninitialize();

}