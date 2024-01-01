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
        //阻塞等待 set_value
        return p_.get_future().get();
    }
    void SetValue(int v)
    {
        p_.set_value(v);
    }
private:
    //用来接收返回值
    std::promise<int> p_;
};

class XThreadPool
{
public:
    //////////////////////////////////////////////
    /// 初始化线程池
    /// @para num 线程数量
    void Init(int num);

    //////////////////////////////////////////////
    /// 启动所有线程，必须先调用Init
    void Start();

    //////////////////////////////////////////////
    /// 线程池退出
    void Stop();

    //void AddTask(XTask* task);
    void AddTask(std::shared_ptr<XTask> task);

    std::shared_ptr<XTask> GetTask();

    //线程池是否退出
    bool is_exit() { return is_exit_; }

    int task_run_count() { return task_run_count_; }
private:
    //线程池线程的入口函数
    void Run() ;
    int thread_num_ = 0;//线程数量
    std::mutex mux_;
    //std::vector<std::thread*> threads_;
    //线程列表 指针指针版本
    std::vector< std::shared_ptr<std::thread> > threads_;

    //std::list<XTask*> tasks_;
    std::list<std::shared_ptr<XTask> > tasks_;
    
    std::condition_variable cv_;
    bool is_exit_ = false; //线程池退出

    //正在运行的任务数量,线程安全
    std::atomic<int> task_run_count_ = {0};
};

