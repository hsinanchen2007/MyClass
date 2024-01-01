//////////////////////////////////  @��Ȩ˵��  //////////////////////////////////////////////////
///						Jiedi(China nanjing)Ltd.                                    
/// @��Ȩ˵�� ����Ϳγ̰�Ȩ���Ĳܿ���ӵ�в��Ѿ���������Ȩ���˴��������Ϊѧϰ�ο���������Ŀ��ʹ�ã�
/// �γ����漰����������Դ���������������Ӧ����Ȩ
/// �γ�Դ�벻����ֱ��ת�ص������Ĳ��ͣ�������������ƽ̨�������������������߿γ̡�
/// �γ����漰����������Դ���������������Ӧ����Ȩ  @@              
/////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////  Դ��˵��  //////////////////////////////////////////////////
/// ��Ŀ����      : C++11 14 17 20 ���̴߳�ԭ���̳߳�ʵս
/// Contact       : xiacaojun@qq.com
///  ����   :				http://blog.csdn.net/jiedichina
///	��Ƶ�γ� : �����ƿ���	http://study.163.com/u/xiacaojun		
///			   ��Ѷ����		https://jiedi.ke.qq.com/				
///			   csdnѧԺ		http://edu.csdn.net/lecturer/lecturer_detail?lecturer_id=961	
///           51ctoѧԺ		https://edu.51cto.com/sd/d3b6d
///			   ���Ŀ���		http://www.laoxiaketang.com 
/// �����������ڴ���ҳ����  http://ffmpeg.club
/// �����������γ�qqȺ ��970032028����ͬѧ�������������� 
/// ΢�Ź��ں�: jiedi2007
/// ͷ����	 : xiacaojun
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// �γ̽���qqȺ970032028  //////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////// COMMENT ///////////////////////////////////////////////

#include <thread>
#include <iostream>
#include <string>
//Linux -lpthread
using namespace std;
class Para
{
public:
    Para() { cout << "Create Para" << endl; }
    Para(const Para& p) { cout << "Copy Para" << endl; }
    ~Para() { cout << "Drop Para" << endl; }
    string name;
};

void ThreadMain(int p1, float p2, string str, Para p4)
{
    this_thread::sleep_for(100ms);
    cout << "ThreadMain " << p1 << " " << p2 << " " << str <<" "<<p4.name<< endl;
}

void ThreadMainPtr(Para* p)
{
    this_thread::sleep_for(100ms);
    cout << "ThreadMainPtr name = " << p->name << endl;
}

void ThreadMainRef(Para& p)
{
    this_thread::sleep_for(100ms);
    cout << "ThreadMainPtr name = " << p.name << endl;
}
int main(int argc, char* argv[])
{
    {
       //��������
        Para p;
        p.name = "test ref";
        thread th(ThreadMainRef, ref(p));
        th.join();
    }
    getchar();

    {
        //�����߳�ָ��
        Para p;
        p.name = "test ThreadMainPtr name";
        thread th(ThreadMainPtr, &p); //���� ���̷߳��ʵ�p�ռ����ǰ�ͷ�
        th.detach();
    }
    // Para �ͷ�
    getchar();
    {
        //�����߳�ָ��
        Para p;
        p.name = "test ThreadMainPtr name";
        thread th(ThreadMainPtr, &p);
        th.join();
        getchar();
    }


    thread th;
    {
    float f1 = 12.1f;
    Para p;
    p.name = "test Para class";
    //���еĲ���������
    th =  thread(ThreadMain, 101, f1, "test string para",p);
    }
    th.join();
    return 0;
}