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
//Linux -lpthread
using namespace std;
bool is_exit = false;
void ThreadMain()
{
    cout << "begin sub thread main " << this_thread::get_id() << endl;
    for (int i = 0; i < 10; i++)
    {
        if (!is_exit) break;
        cout << "in thread " << i << endl;
        this_thread::sleep_for(chrono::seconds(1));//1000ms
    }
    cout << "end sub thread main " << this_thread::get_id() << endl;
}
int main(int argc, char* argv[])
{
    {
        //thread th(ThreadMain); //出错，thread对象被销毁 子线程还在运行
    }
    {
        thread th(ThreadMain);
        th.detach(); //子线程与主线程分离 守护线程
        //坑 ：主线程退出后 子线程不一定退出
    }

    {
        thread th(ThreadMain);
        this_thread::sleep_for(chrono::seconds(1));//1000ms
        is_exit = true; //通知子线程退出
        cout << "主线程阻塞，等待子线程退出" << endl;
        th.join(); //主线程阻塞，等待子线程退出
        cout << "子线程已经退出！" << endl;
    }
    getchar();

    return 0;
}