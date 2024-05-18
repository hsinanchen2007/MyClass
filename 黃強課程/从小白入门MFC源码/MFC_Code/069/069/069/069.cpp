#include<afx.h>
#include<iostream>
using namespace std;


//֧�����л�
class CPerson:public CObject
{
	DECLARE_SERIAL(CPerson)


private:
	CString name;
	int age;
	char sex;
public:

	CPerson() {}
	CPerson(CString _name, int _age, char _sex):name(_name), age(_age), sex(_sex)
	{}
	void print()
	{
		wcout.imbue(locale("chs"));//�����ַ���
		wcout << name.GetString() << "," << age << "," << sex << "," << endl;//�����cout������ʾ�ַ�������ʾ����һ����ַ
	
	}
	virtual void Serialize(CArchive &ar)
	{
		if (ar.IsLoading())//��ʾ���ļ�����
		{
			ar >> name >> age >> sex;

		}
		else 
		{
			ar << name << age << sex;


		}
	
	
	}


};

IMPLEMENT_SERIAL(CPerson,CObject,1)

int main()
{
	
	/*CPerson  person(L"����", 23, 'M');


	//�����л�����
	CArchive ar(&file, CArchive::store);
	ar.WriteObject(&person);
	ar.Close();
		
	file.SeekToBegin();//���ļ�ָ���Ƶ��ļ���ͷ�ٶ�ȡ*/
	//�����л��ļ�
	CFile file(L"person.t", CFile::modeReadWrite);
	CArchive ar2(&file, CArchive::load);
	CPerson *P= (CPerson *)ar2.ReadObject(RUNTIME_CLASS(CPerson));
	P->print();
	ar2.Close();




	//Person.print();


	return 0;
}