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
#include <future>
#include <string>
using namespace std;

string TestPack(int index)
{
    cout << "begin Test Pack " << index << endl;
    this_thread::sleep_for(2s);
    return "Test Pack return";
}
int main(int argc, char* argv[])
{
    packaged_task< string(int) > task(TestPack);
    auto result = task.get_future();
    //task(100);
    thread th(move(task),101);
    
    cout << "begin result get" << endl;

    //测试是否超时
    for (int i = 0; i < 30; i++)
    {
        if (result.wait_for(100ms) != future_status::ready)
        {
            continue;
        }
    }
    if (result.wait_for(100ms) == future_status::timeout)
    {
        cout << "wait result timeout" << endl;
    }
    else
        cout << "result get " << result.get() << endl;
    th.join();
    getchar();
    return 0;
}