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

#include "xthread_pool.h"
#include <iostream>
using namespace std;
class MyTask :public XTask
{
public:
    int Run()
    {
        cout << "================================================" << endl;
        cout << this_thread::get_id()<<" Mytask " << name << endl;
        cout << "================================================" << endl;
        for (int i = 0; i < 10; i++)
        {
            if (is_exit())break;
            cout << "." << flush;
            this_thread::sleep_for(500ms);
        }
        return 0;
    }
    std::string name = "";
};
int main(int argc, char* argv[])
{
  
    XThreadPool pool;
    pool.Init(16);
    pool.Start();

    MyTask task1;
    task1.name = "test name 001";
    pool.AddTask(&task1);

    MyTask task2;
    task2.name = "test name 002";
    pool.AddTask(&task2);
    this_thread::sleep_for(100ms);
    cout << "task run  count = " << pool.task_run_count() << endl;


    this_thread::sleep_for(1s);
    pool.Stop();
    cout << "task run  count = " << pool.task_run_count() << endl;

    getchar();
    return 0;
}