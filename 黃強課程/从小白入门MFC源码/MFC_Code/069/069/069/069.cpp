#include<afx.h>
#include<iostream>
using namespace std;


//支持序列化
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
		wcout.imbue(locale("chs"));//设置字符集
		wcout << name.GetString() << "," << age << "," << sex << "," << endl;//如果用cout，不显示字符串，显示的是一个地址
	
	}
	virtual void Serialize(CArchive &ar)
	{
		if (ar.IsLoading())//表示从文件加载
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
	
	/*CPerson  person(L"张三", 23, 'M');


	//先序列化对象
	CArchive ar(&file, CArchive::store);
	ar.WriteObject(&person);
	ar.Close();
		
	file.SeekToBegin();//把文件指针移到文件开头再读取*/
	//反序列化文件
	CFile file(L"person.t", CFile::modeReadWrite);
	CArchive ar2(&file, CArchive::load);
	CPerson *P= (CPerson *)ar2.ReadObject(RUNTIME_CLASS(CPerson));
	P->print();
	ar2.Close();




	//Person.print();


	return 0;
}