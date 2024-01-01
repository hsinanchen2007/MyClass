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
class MyThread
{
public:
    //����̺߳���
    void Main()
    {
        cout << "MyThread Main " << name << ":" << age;
    }
    string name;
    int age = 100;
};
class XThread
{
public:
    virtual void Start()
    {
        is_exit_ = false;
        th_ = std::thread(&XThread::Main, this);
    }
    virtual void Stop()
    {
        is_exit_ = true;
        Wait();
    }
    virtual void Wait()
    {
        if (th_.joinable())
            th_.join();
    }
    bool is_exit() { return is_exit_; }
private:
    virtual void Main() = 0;
    std::thread th_;
    bool is_exit_ = false;
};
class TestXThread :public XThread
{
public:
    void Main() override
    {
        cout << "TestXThread Main begin" << endl;
        while (!is_exit())
        {
            this_thread::sleep_for(100ms);
            cout << "." << flush;
        }
        cout << "TestXThread Main end" << endl;
    }
    string name;
};
int main(int argc, char* argv[])
{
    TestXThread testth;
    testth.name = "TestXThread name ";
    testth.Start();
    this_thread::sleep_for(3s);
    testth.Stop();

    testth.Wait();
    getchar();

    MyThread myth;
    myth.name = "Test name 001";
    myth.age = 20;
    thread th(&MyThread::Main, &myth);
    th.join();

    return 0;
}