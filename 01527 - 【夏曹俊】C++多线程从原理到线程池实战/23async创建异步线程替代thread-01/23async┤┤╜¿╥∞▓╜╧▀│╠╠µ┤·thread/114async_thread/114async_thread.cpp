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
#include <future>
#include <string>
using namespace std;

string TestAsync(int index)
{
    cout << index<<" begin in TestAsync " << this_thread::get_id() << endl;
    this_thread::sleep_for(2s);
    return "TestAsync string return";
}
int main(int argc, char* argv[])
{
   //�����첽�߳�
    
    cout << "main thread id " << this_thread::get_id() << endl;
    //�������߳������첽����
    auto future = async(launch::deferred, TestAsync,100);
    this_thread::sleep_for(100ms);
    cout << "begin future get " << endl;
    cout << "future.get() = " << future.get() << endl;
    cout << "end future get" << endl;

    //�����첽�߳�
    cout << "=====�����첽�߳�====" << endl;
    auto future2 = async(TestAsync, 101);
    this_thread::sleep_for(100ms);
    cout << "begin future2 get " << endl;
    cout << "future2.get() = " << future2.get() << endl;
    cout << "end future2 get" << endl;


    getchar();
    return 0;
}