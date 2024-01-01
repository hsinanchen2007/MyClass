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

#pragma once
#include <thread>
#include <mutex>
#include <vector>
#include <list>
#include <functional>
#include <atomic>
#include <future>
class XTask
{
public:
    virtual int Run() = 0;
    std::function<bool()> is_exit = nullptr;
    auto GetReturn()
    {
        //�����ȴ� set_value
        return p_.get_future().get();
    }
    void SetValue(int v)
    {
        p_.set_value(v);
    }
private:
    //�������շ���ֵ
    std::promise<int> p_;
};

class XThreadPool
{
public:
    //////////////////////////////////////////////
    /// ��ʼ���̳߳�
    /// @para num �߳�����
    void Init(int num);

    //////////////////////////////////////////////
    /// ���������̣߳������ȵ���Init
    void Start();

    //////////////////////////////////////////////
    /// �̳߳��˳�
    void Stop();

    //void AddTask(XTask* task);
    void AddTask(std::shared_ptr<XTask> task);

    std::shared_ptr<XTask> GetTask();

    //�̳߳��Ƿ��˳�
    bool is_exit() { return is_exit_; }

    int task_run_count() { return task_run_count_; }
private:
    //�̳߳��̵߳���ں���
    void Run() ;
    int thread_num_ = 0;//�߳�����
    std::mutex mux_;
    //std::vector<std::thread*> threads_;
    //�߳��б� ָ��ָ��汾
    std::vector< std::shared_ptr<std::thread> > threads_;

    //std::list<XTask*> tasks_;
    std::list<std::shared_ptr<XTask> > tasks_;
    
    std::condition_variable cv_;
    bool is_exit_ = false; //�̳߳��˳�

    //�������е���������,�̰߳�ȫ
    std::atomic<int> task_run_count_ = {0};
};

