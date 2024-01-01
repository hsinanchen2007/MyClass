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
// RAII
class XMutex
{
public:
    XMutex(mutex& mux):mux_(mux)
    {
        cout << "Lock" << endl;
        mux.lock();
    }
    ~XMutex()
    {
        cout << "Unlock" << endl;
        mux_.unlock();
    }
private:
    mutex& mux_;
};
static mutex mux;
void TestMutex(int status)
{
    XMutex lock(mux);
    if (status == 1)
    {
        cout << "=1" << endl;
        return;
    }
    else
    {
        cout << "!=1" << endl;
        return;
    }
}

static mutex gmutex;
void TestLockGuard(int i)
{
    gmutex.lock();
    {
        //�Ѿ�ӵ��������lock
        lock_guard<mutex> lock(gmutex,adopt_lock);
        //�����ͷ���
    }
    {
        lock_guard<mutex> lock(gmutex);
        cout << "begin thread " << i << endl;
    }
    for (;;)
    {
        {
            lock_guard<mutex> lock(gmutex);
            cout << "In " << i << endl;
        }
        this_thread::sleep_for(500ms);
    }
}

static mutex mux1;
static mutex mux2;

void TestScope1()
{
    //ģ������ ͣ100ms����һ���߳���mux2
    this_thread::sleep_for(100ms); 
    cout <<this_thread::get_id()<< " begin mux1 lock" << endl;
    //mux1.lock();
    cout << this_thread::get_id() << " begin mux2 lock" << endl;
    //mux2.lock(); //����
    //c++11
    // lock(mux1, mux2);
    //c++17 
    scoped_lock lock(mux1, mux2); // �������
    
    cout << "TestScope1" << endl;
    this_thread::sleep_for(1000ms);
    
    //mux1.unlock();
    //mux2.unlock();
}
void TestScope2()
{
    cout << this_thread::get_id() << " begin mux2 lock" << endl;
    mux2.lock();
    this_thread::sleep_for(500ms);
    cout << this_thread::get_id() << " begin mux1 lock" << endl;
    mux1.lock();//����
    cout << "TestScope2" << endl;
    this_thread::sleep_for(1500ms);
    mux1.unlock();
    mux2.unlock();
}

int main(int argc, char* argv[])
{
    {
    //��ʾ�������
        {
            thread th(TestScope1);
            th.detach();
        }
        {
            thread th(TestScope2);
            th.detach();
        }
    }
    getchar();

    {
        //������
        static shared_timed_mutex  tmux;
        //��ȡ�� ������
        {
            //���ù����� 
            shared_lock<shared_timed_mutex> lock(tmux);
            cout << "read data" << endl;
            //�˳�ջ�� �ͷŹ�����
        }
        //д���� ������
        {
            unique_lock<shared_timed_mutex> lock(tmux);
            cout << "write data" << endl;
        }

    }


    {
        static mutex mux;
        {
            unique_lock<mutex> lock(mux);
            lock.unlock();
            //��ʱ�ͷ���
            lock.lock();
        }

        {
            //�Ѿ�ӵ���� ���������˳�ջ������
            mux.lock();
            unique_lock<mutex> lock(mux, adopt_lock);
        }
        {
            //�Ӻ���� ��ӵ�� �˳�ջ��������
            unique_lock<mutex> lock(mux, defer_lock);
            //���� �˳�ջ������
            lock.lock();
        }
        {
            //mux.lock();
            //���Լ��� ������ ʧ�ܲ�ӵ����
            unique_lock<mutex> lock(mux, try_to_lock);

            if (lock.owns_lock())
            {
                cout << "owns_lock" << endl;
            }
            else
            {
                cout << "not owns_lock" << endl;
            }
        }

    }

    for (int i = 0; i < 3; i++)
    {
        thread th(TestLockGuard, i + 1);
        th.detach();
    }
    TestMutex(1);
    TestMutex(2);

    getchar();
    return 0;
}