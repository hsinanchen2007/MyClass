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
#include <mutex>
#include <list>
#include <string>
#include <sstream>
using namespace std;
list<string> msgs_;
mutex mux;
condition_variable cv;
void ThreadWrite()
{
    for (int i = 0;;i++)
    {
        stringstream ss;
        ss << "Write msg " << i;
        unique_lock<mutex> lock(mux);
        msgs_.push_back(ss.str());
        lock.unlock();
        cv.notify_one(); //�����ź�
        //cv.notify_all();
        this_thread::sleep_for(3s);
    }
}
void ThreadRead(int i)
{
    for (;;)
    {
        cout << "read msg" << endl;
        unique_lock<mutex> lock(mux);
        //cv.wait(lock);//�����������ȴ��ź�
        cv.wait(lock, [i] 
            {
                cout << i << " wait" << endl;
                return !msgs_.empty(); 
            });
        //��ȡ�źź�����
        while (!msgs_.empty())
        {
            cout << i << " read " << msgs_.front() << endl;
            msgs_.pop_front();
        }

    }
}
int main(int argc, char* argv[])
{
    thread th(ThreadWrite);
    th.detach();
    for (int i = 0; i < 3; i++)
    {
        thread th(ThreadRead, i + 1);
        th.detach();
    }
    getchar();
    return 0;
}