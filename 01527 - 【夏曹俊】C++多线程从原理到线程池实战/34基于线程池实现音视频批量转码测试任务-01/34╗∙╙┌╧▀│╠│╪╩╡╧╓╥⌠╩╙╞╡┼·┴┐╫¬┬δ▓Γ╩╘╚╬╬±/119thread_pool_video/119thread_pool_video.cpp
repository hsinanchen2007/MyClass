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
#include "xvideo_task.h"
#include <iostream>
using namespace std;
/// 命令行视频转码工具
/// ffmpeg工具
/// 用户输入 视频源 输出视频尺寸
/// 在线程池中执行转码任务
/// 转码任务调用ffmpeg
/// ffmpeg -y -i test.mp4 -s 400x300 400.mp4 >log.txt 2>&1

int main(int argc, char* argv[])
{
    XThreadPool pool;
    pool.Init(16);
    pool.Start();
    auto vtask1 = make_shared<XVideoTask>();
    vtask1->in_path = "test.mp4";
    vtask1->out_path = "640.mp4";
    vtask1->width = 640;
    vtask1->height = 480;
    pool.AddTask(vtask1);

    vtask1->GetReturn();
    
    return 0;
}