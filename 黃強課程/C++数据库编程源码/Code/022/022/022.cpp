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

	//����ADO Command���������ָ�� 
	_CommandPtr  pCmd(__uuidof(Command));

	try {

		//���������ַ���
		string ConnStr = "Provider=SQLOLEDB.1;Data Source=192.168.0.199;Persist Security Info=False;User ID=sa;Password=Sa123;Initial Catalog=test";

		//�������ݿ�
		HRESULT  hr = pConn->Open(ConnStr.data(), "", "", adConnectUnspecified);
		if (SUCCEEDED(hr)) {
			cout << "���ݿ����ӳɹ���" << endl;
		}
		///////////////////////////////////////////////////////////////////////////////////////////

		 
		//����Command�����ԣ�������ִ�е�SQL���
		string strSql = "INSERT INTO Student  VALUES(?,?,?)";
		pCmd->ActiveConnection = pConn;
		pCmd->CommandText = _bstr_t(strSql.data());
		//adCmdText��ʾ��sql�ı���adCmdStoredProc��ʾ�洢��������
		pCmd->CommandType = adCmdText;

		//ΪCommand�������
		//����������ADO��OLEDB��  �󶨣�������  ����̫����
		_ParameterPtr  p1 = pCmd->CreateParameter("id", adInteger, adParamInput, sizeof(int), 1000);

		_ParameterPtr  p2 = pCmd->CreateParameter("name", adVarWChar, adParamInput, (long)11, L"����");

		_ParameterPtr   p3 = pCmd->CreateParameter("age", adSmallInt, adParamInput, sizeof(short), 12);

		//��3���������ý�ȥ
		pCmd->Parameters->Append(p1);
		pCmd->Parameters->Append(p2);
		pCmd->Parameters->Append(p3);

		//adExecuteNoRecords������ʾ���践�ؽ����
		VARIANT recordsAffected = { 0 };//��Ӱ�������
		hr = pCmd->Execute(&recordsAffected, NULL, adExecuteNoRecords);
		if (recordsAffected.intVal == 1) {
			cout << "�������ݳɹ���" << endl;
		}

		//�ر�����
		hr = pConn->Close();
		if (SUCCEEDED(hr)) {
			cout << "�ر����ݿ����ӣ�" << endl;
		}


		
		////////////////////////////////////////////////////////////////////////////////////////////
		//�ͷŶ���
		pCmd.Release();
		pConn.Release(); 
	}
	catch (_com_error & e) {
		cout << e.Description() << endl;
	} 

	//�ͷ�com��
	CoUninitialize();

}