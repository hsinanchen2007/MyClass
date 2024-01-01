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

//////////////////////////////////////////////
/// ��ʼ���̳߳�
/// @para num �߳�����
void XThreadPool::Init(int num)
{
    unique_lock<mutex> lock(mux_);
    this->thread_num_ = num;
    cout << "Thread pool Init " << num << endl;
}

//////////////////////////////////////////////
/// ���������̣߳������ȵ���Init
void XThreadPool::Start()
{
    unique_lock<mutex> lock(mux_);
    if (thread_num_ <= 0)
    {
        cerr << "Please Init XThreadPool" << endl;
        return;
    }
    if (!threads_.empty())
    {
        cerr << "Thread pool has start!" << endl;
        return;
    }
    //�����߳�
    for (int i = 0; i < thread_num_; i++)
    {
        auto th = new thread(&XThreadPool::Run, this);
        threads_.push_back(th);
    }
}

//�̳߳��̵߳���ں���
void XThreadPool::Run()
{
    cout << "begin XThreadPool Run " << this_thread::get_id() << endl;

    cout << "end XThreadPool Run " << this_thread::get_id() << endl;
}

