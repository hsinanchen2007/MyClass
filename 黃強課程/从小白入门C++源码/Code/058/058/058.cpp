#include<iostream>
#include <fstream>  

using namespace  std;

 
int  main()
{
	//ofstream�����д�ļ�
	/*ofstream  o;
	o.open("1.txt", ios::out);//ÿһ�Σ�����ɾ����һ�ε��ļ����½��ļ�
	o << "hello";
	o.write("world!", strlen("world!"));
	o.close();


	//ifstream���������ļ�
	ifstream  i;
	i.open("1.txt", ios::in);

	char buf[100] = {0};
	//i.read(buf, 100);
	i >> buf;
	cout << "ʵ�ʶ�ȡ��" << i.gcount() << endl;
	cout << buf << endl;
	
	i.close();
	*/

	//fstream ��������������Զ�����д
	fstream  f;
	f.open("2.txt", ios::out | ios::in | ios::trunc);

	//д��
	f << "hello";
	f << 100;
	f << 1.234;

    //�˿̣��ļ�ָ����ĩβ�����Ҫ����ʲô��������
	//���ԣ�������Ҫ���ļ�ָ���Ƶ���ͷ��Ȼ���ٶ�ȡ
	f.seekg(0, ios::beg); // ��λ���ļ���ͷ


	char buf[100] = {0};
	//��ȡ
	f >> buf;   
	cout << buf << endl;
	  
	f.close();


	return 0;
}