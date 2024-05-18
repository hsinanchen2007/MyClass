#include <mysql/jdbc.h>
#pragma comment(lib, "mysqlcppconn.lib")


#include<iostream>
using namespace std;

int main()
{
	//�����ַ���
	const char* host = "tcp://192.168.0.199:3306/test";

	const char* user = "root";//�û���
	const char* passwd = "root";//����

	try
	{
		//��ȡ����ʵ��
		sql::mysql::MySQL_Driver* driver = sql::mysql::get_mysql_driver_instance();

		//connect�������ݿ⣬����Connection����ָ��
		sql::Connection* conn = driver->connect(host, user, passwd);

		if (conn != nullptr && conn->isClosed() == 0) {
			cout << "���ݿ����ӳɹ���" << endl;
		}
		 
		//���ÿͻ��˵����ӱ����ʽΪGBK
		sql::Statement *stmt = conn->createStatement();
		stmt->execute("SET character set gbk");

		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//��������
		if(true)
		{
		    //����PreparedStatement׼��sql���
			const sql::SQLString  sql = "INSERT  INTO Student VALUES(?,?,?);";
			sql::PreparedStatement  * pstmt = conn->prepareStatement(sql);
		
			//��䣿����
			pstmt->setInt(1, 1000);
			pstmt->setString(2, "ѧϰ");
			pstmt->setInt(3, 22);

			//ִ��sql���
			int ret= pstmt->executeUpdate(); // executeUpdate������UPDATE  INSERT  DELETE����
			if (ret == 1) {
				cout<<"�������ݳɹ���"<<endl;
			}
			//�ر����
			pstmt->close();

		}
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//��ѯ����
		if(true)
		{
			const sql::SQLString  sql = "SELECT  *  FROM   Student ;";
			sql::ResultSet * rs=    stmt->executeQuery(sql);// executeQuery������ SELECT

			while (rs != nullptr && rs->next()) {

				int id= rs->getInt("id");//�� ������ȡ����
				sql::SQLString  name=  rs->getString(2);//����ŷ�ʽ��ȡ������
				int age = rs->getInt(3);

				cout << id << "\t" << name.c_str() << "\t" << age << endl;
			}
			 
			//�رս����
			rs->close();
		} 
		/////////////////////////////////////////////////////////////////////////////////////////////////////////////
		//�޸�����
		if (true)
		{
			const sql::SQLString  sql = "UPDATE  Student  SET  name='��������'  WHERE id =1000;";
			int  effectRows= stmt->executeUpdate(sql);// executeUpdate������ UPDATE INSERT  DELETE
			cout << "�޸����ݳɹ�" << effectRows << "����Ӱ�죡" << endl; 
		}

		//////////////////////////////////////////////////////////////////////////////////
		//ɾ������
		if (true)
		{
			/*д��һ
			const sql::SQLString  sql = "DELETE  FROM Student WHERE id =1000;";
			int  effectRows = stmt->executeUpdate(sql);// executeUpdate������ UPDATE INSERT  DELETE
			cout << "ɾ�����ݳɹ�" << effectRows << "����Ӱ�죡" << endl;
			*/


			const sql::SQLString  sql = "DELETE  FROM Student WHERE id =1000;";
			// const sql::SQLString  sql = "SELECT  * FROM Student WHERE id =1000;";
			 bool  ret= stmt->execute(sql);// execute������ UPDATE INSERT  DELETE  SELECT
			 if (ret)
			 {//������SELECT ���������Ի�ȡ�����
				 sql::ResultSet * rs = stmt->getResultSet();
				 cout << "��ѯ���������������ݼ�" << rs << endl;
			 }
			 else 
			 {//������UPDATE INSERT  DELETE���������Ի�ȡ��Ӱ�������
				 int  effectRows = stmt->getUpdateCount();
				  cout << "ɾ�����ݳɹ�" << effectRows << "����Ӱ�죡" << endl;
			 }

		}
		//////////////////////////////////////////////////////////////////////////////////


		//�ر����
		stmt->close();

		//�ر����ݿ�����
		conn->close();
		cout << "�ر����ݿ����ӳɹ���" << endl;

		delete conn;
	}
	catch (sql::SQLException& e) {
		std::cout << "����: " << e.getErrorCode() << "  " << e.what();
	}



}

