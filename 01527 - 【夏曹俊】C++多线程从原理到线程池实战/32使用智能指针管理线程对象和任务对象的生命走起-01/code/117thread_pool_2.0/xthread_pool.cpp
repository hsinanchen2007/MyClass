//////////////////////////////////  @版权说明  //////////////////////////////////////////////////
///						Jiedi(China nanjing)Ltd.                                    
/// @版权说明 代码和课程版权有夏曹俊所拥有并已经申请著作权，此代码可用作为学习参考并可在项目中使用，
/// 课程中涉及到的其他开源软件，请遵守其相应的授权
/// 课程源码不可以直接转载到公开的博客，或者其他共享平台，不可以用以制作在线课程。
/// 课程中涉及到的其他开源软件，请遵守其相应的授权  @@              
/////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////  源码说明  //////////////////////////////////////////////////
/// 项目名称      : C++11 14 17 20 多线程从原理到线程池实战
/// Contact       : xiacaojun@qq.com
///  博客   :				http://blog.csdn.net/jiedichina
///	视频课程 : 网易云课堂	http://study.163.com/u/xiacaojun		
///			   腾讯课堂		https://jiedi.ke.qq.com/				
///			   csdn学院		http://edu.csdn.net/lecturer/lecturer_detail?lecturer_id=961	
///           51cto学院		https://edu.51cto.com/sd/d3b6d
///			   老夏课堂		http://www.laoxiaketang.com 
/// 更多资料请在此网页下载  http://ffmpeg.club
/// ！！！请加入课程qq群 【970032028】与同学交流和下载资料 
/// 微信公众号: jiedi2007
/// 头条号	 : xiacaojun
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////// 课程交流qq群970032028  //////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////// COMMENT ///////////////////////////////////////////////

#include "xthread_pool.h"
#include <iostream>
using namespace std;

//////////////////////////////////////////////
/// 初始化线程池
/// @para num 线程数量
void XThreadPool::Init(int num)
{
    unique_lock<mutex> lock(mux_);
    this->thread_num_ = num;
    cout << "Thread pool Init " << num << endl;
}

//////////////////////////////////////////////
/// 启动所有线程，必须先调用Init
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
    //启动线程
    for (int i = 0; i < thread_num_; i++)
    {
        //auto th = new thread(&XThreadPool::Run, this);
        auto th = make_shared<thread>(&XThreadPool::Run, this);
        threads_.push_back(th);
    }
}
//////////////////////////////////////////////
/// 线程池退出
void XThreadPool::Stop()
{
    is_exit_ = true;
    cv_.notify_all();
    for (auto& th : threads_)
    {
        th->join();
    }
    unique_lock<mutex> lock(mux_);
    threads_.clear();
}
//线程池线程的入口函数
void XThreadPool::Run()
{
    cout << "begin XThreadPool Run " << this_thread::get_id() << endl;
    while (!is_exit())
    {
        auto task = GetTask();
        if (!task)continue;
        ++task_run_count_;
        try
        {
            task->Run();
        }
        catch (...)
        {

        }
        --task_run_count_;
    }

    cout << "end XThreadPool Run " << this_thread::get_id() << endl;
}

void XThreadPool::AddTask(std::shared_ptr<XTask> task)
{
    unique_lock<mutex> lock(mux_);
    tasks_.push_back(task);
    task->is_exit = [this] {return is_exit(); };
    lock.unlock();
    cv_.notify_one();
}

std::shared_ptr<XTask> XThreadPool::GetTask()
{
    unique_lock<mutex> lock(mux_);
    if (tasks_.empty())
    {
        cv_.wait(lock);
    }
    if (is_exit())
        return nullptr;
    if (tasks_.empty())
        return nullptr;
    auto task = tasks_.front();
    tasks_.pop_front();
    return task;
}