#include<iostream>
# include <memory> 
# include <string> 
using namespace  std;
 
template  <class T>
class SmartPointer
{
public :
	SmartPointer(T  *p)
	{
		ptr = p; 
	}

	~SmartPointer()
	{
		delete ptr;//�Զ�ɾ���ڴ棬��ֹй¶
		ptr = NULL; //�Զ��ÿգ���ֹҰָ��
	}

	//����*�����
	T & operator *()
	{
		return  *ptr;
	}

	//����->�����
	 T *  operator ->()
	{
		return  ptr;
	} 


private:
	T  *  ptr;
};

void main()
{  /*
   //�Լ�ʵ�ֵ�����ָ��
	SmartPointer<int>  sp(new int(333));
    
	//��ȡָ�������
	int  a = *sp; 
	cout << a << endl;
 
   
	SmartPointer<string>  sp2( new string("hello"));
	cout<<sp2->at(1)<<endl;


	//autoָ�룬�Ѿ�����
	int  *p = new int(4);
	auto_ptr<int>  ap(p);
	cout << *ap << endl;

	auto_ptr<int>  ap2(p);
	cout << *ap2 << endl;
	 

	//����������ָ��
	unique_ptr<int[]>  p(new int[5]{ 1, 2, 3, 4, 5 });
	cout << p[2] << endl;

	unique_ptr<int[]>  p2 =move(p);//�޷���������ֵ����Ϊ�Ƕ���ģ�ֻ��move
	cout << p2[4] << "   " << (p == nullptr) << endl;//���ת������Ȩ����ô�Լ���ɿ�
	*/


	//����������ָ��
	shared_ptr<int> sp(new int(10));
	cout << sp.use_count() << endl;  //���ü���
	 
	weak_ptr <int>  wp = sp;//���shared_ptr�Ĺ���
	cout << sp.use_count() << endl;//weak_ptr��ռ����Դ



	shared_ptr<int> sp2 = sp;  //�ڶ���shared_ptr,�������캯��    
	cout << (sp == sp2) << "    " << wp.use_count() << endl;

	*sp2 = 100; //ʹ�ý����ò������޸ı�ָ����    
	cout << *sp << endl; //��һ��shared_ptrҲͬʱ���޸�  

	sp.reset();//�ͷ�
	cout << (sp == nullptr) << "    " << wp.use_count() << endl;

}
