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
#include <mutex>
#include <shared_mutex>
//Linux -lpthread
using namespace std;
//c++17  ������
//shared_mutex smux;

//c++14 
shared_timed_mutex stmux;

void ThreadRead(int i)
{
    for (;;)
    {
        stmux.lock_shared();
        cout << i << " Read" << endl;
        this_thread::sleep_for(500ms);
        stmux.unlock_shared();
        this_thread::sleep_for(1ms);
    }
}
void ThreadWrite(int i)
{
    for (;;)
    {
        stmux.lock_shared();
        //��ȡ����
        stmux.unlock_shared();
        stmux.lock(); //������ д��
        cout << i << " Write" << endl;
        this_thread::sleep_for(300ms);
        stmux.unlock();
        this_thread::sleep_for(1ms);
    }
}
int main(int argc, char* argv[])
{
    for (int i = 0; i < 3; i++)
    {
        thread th(ThreadWrite, i + 1);
        th.detach();
    }
    for (int i = 0; i < 3; i++)
    {
        thread th(ThreadRead, i + 1);
        th.detach();
    }
    getchar();
    return 0;
}