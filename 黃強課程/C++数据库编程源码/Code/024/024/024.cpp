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

	//����ADO Recordset���������ָ�� 
	_RecordsetPtr  pRec = nullptr;

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
		string strSql = "SELECT  *  FROM   Student";
		VARIANT   recordsAffected = {0};
		pRec = pConn->Execute(_bstr_t(strSql.c_str()), &recordsAffected, adCmdText);
		//INSERT DELETE  UPDATE������Ӱ���������SELECT  ��-1
		cout << "��ѯ���ݳɹ�" << recordsAffected.intVal <<"����Ӱ��"<< endl;


	   //������¼���������ݴ�ӡ����
		while (!pRec->adoEOF)  //û���������ͼ���
		{

			_variant_t id= pRec->GetCollect("id");
			_variant_t name = pRec->GetCollect("name");
			_variant_t age = pRec->GetCollect("age");

			cout << id.intVal << " \t" << _bstr_t(name)<< "\t" << age.intVal << endl;

			pRec->MoveNext();
		}
	 

		//�ر�����
		hr = pConn->Close();
		if (SUCCEEDED(hr)) {
			cout << "�ر����ݿ����ӣ�" << endl;
		} 
		
		////////////////////////////////////////////////////////////////////////////////////////////
		//�ͷŶ���
		pRec.Release();
		pConn.Release(); 
	}
	catch (_com_error & e) {
		cout << e.Description() << endl;
	} 

	//�ͷ�com��
	CoUninitialize();

}