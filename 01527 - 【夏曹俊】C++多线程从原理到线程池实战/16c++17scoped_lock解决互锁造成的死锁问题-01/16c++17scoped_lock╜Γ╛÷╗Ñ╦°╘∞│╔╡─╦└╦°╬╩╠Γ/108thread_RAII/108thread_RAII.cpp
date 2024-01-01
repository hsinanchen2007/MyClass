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
        //已经拥有锁，不lock
        lock_guard<mutex> lock(gmutex,adopt_lock);
        //结束释放锁
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
    //模拟死锁 停100ms等另一个线程锁mux2
    this_thread::sleep_for(100ms); 
    cout <<this_thread::get_id()<< " begin mux1 lock" << endl;
    //mux1.lock();
    cout << this_thread::get_id() << " begin mux2 lock" << endl;
    //mux2.lock(); //死锁
    //c++11
    // lock(mux1, mux2);
    //c++17 
    scoped_lock lock(mux1, mux2); // 解决死锁
    
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
    mux1.lock();//死锁
    cout << "TestScope2" << endl;
    this_thread::sleep_for(1500ms);
    mux1.unlock();
    mux2.unlock();
}

int main(int argc, char* argv[])
{
    {
    //演示死锁情况
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
        //共享锁
        static shared_timed_mutex  tmux;
        //读取锁 共享锁
        {
            //调用共享锁 
            shared_lock<shared_timed_mutex> lock(tmux);
            cout << "read data" << endl;
            //退出栈区 释放共享锁
        }
        //写入锁 互斥锁
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
            //临时释放锁
            lock.lock();
        }

        {
            //已经拥有锁 不锁定，退出栈区解锁
            mux.lock();
            unique_lock<mutex> lock(mux, adopt_lock);
        }
        {
            //延后加锁 不拥有 退出栈区不解锁
            unique_lock<mutex> lock(mux, defer_lock);
            //加锁 退出栈区解锁
            lock.lock();
        }
        {
            //mux.lock();
            //尝试加锁 不阻塞 失败不拥有锁
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