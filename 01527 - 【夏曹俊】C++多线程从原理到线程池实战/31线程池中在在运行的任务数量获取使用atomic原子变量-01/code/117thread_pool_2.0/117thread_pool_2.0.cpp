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
class MyTask :public XTask
{
public:
    int Run()
    {
        cout << "================================================" << endl;
        cout << this_thread::get_id()<<" Mytask " << name << endl;
        cout << "================================================" << endl;
        for (int i = 0; i < 10; i++)
        {
            if (is_exit())break;
            cout << "." << flush;
            this_thread::sleep_for(500ms);
        }
        return 0;
    }
    std::string name = "";
};
int main(int argc, char* argv[])
{
  
    XThreadPool pool;
    pool.Init(16);
    pool.Start();

    MyTask task1;
    task1.name = "test name 001";
    pool.AddTask(&task1);

    MyTask task2;
    task2.name = "test name 002";
    pool.AddTask(&task2);
    this_thread::sleep_for(100ms);
    cout << "task run  count = " << pool.task_run_count() << endl;


    this_thread::sleep_for(1s);
    pool.Stop();
    cout << "task run  count = " << pool.task_run_count() << endl;

    getchar();
    return 0;
}