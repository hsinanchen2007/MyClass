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
#include <vector>
#include <chrono>
using namespace std;
using namespace chrono;
static const char base16[] = "0123456789abcdef";
void Base16Encode(const unsigned char* data, int size, unsigned char* out)
{
    for (int i = 0; i < size; i++)
    {
        unsigned char d = data[i];
        // 0000 0000
        // 1234 5678 >>4 0000 1234
        // 1234 5678 & 0000 1111   0000 5678
        char a = base16[d >> 4];
        char b = base16[d & 0x0F];
        out[i * 2] = a;
        out[i * 2 + 1] = b;
    }
}
//C++11 多核base16编码
void Base16EncodeThread(const vector<unsigned char>&data,vector<unsigned char>&out)
{
    int size = data.size();
    int th_count = thread::hardware_concurrency(); //系统支持的线程核心数
    //切片数据
    int slice_count = size / th_count; //余数丢弃
    if (size < th_count) //只切一片
    {
        th_count = 1;
        slice_count = size;
    }

    //准备好线程
    vector<thread> ths;
    ths.resize(th_count);

    //任务分配到各个线程    
    for (int i = 0; i < th_count; i++)
    {
        //1234 5678 9abc defg hi 
        int offset = i * slice_count;
        int count = slice_count;

        //最后一个线程
        if (th_count > 1 && i == th_count - 1)
        {
            count = slice_count + size % th_count;
        }
        //cout << offset << ":" << count << endl;
        ths[i] = thread(Base16Encode, data.data() + offset, count, out.data());
    }
    //等待所有线程处理结束
    for (auto& th : ths)
    {
        th.join();
    }
}

int main(int argc, char* argv[])
{
    string test_data = "测试base16编码";
    unsigned char out[1024] = { 0 };
    Base16Encode((unsigned char*)test_data.data(), test_data.size(), out);
    cout << "base16:" << out << endl;


    //初始化测试数据
    vector<unsigned char> in_data;
    in_data.resize(1024 * 1024 * 20); //20M
    //in_data.data();
    for (int i = 0; i < in_data.size(); i++)
    {
        in_data[i] = i % 256;
    }
    vector<unsigned char > out_data;
    out_data.resize(in_data.size() * 2);


    //测试单线程base16编码效率
    {
        cout << "单线程base16开始计算" << endl;
        auto start = system_clock::now();
        Base16Encode(in_data.data(), in_data.size(), out_data.data());
        auto end = system_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << "编码：" << in_data.size() << "字节数据花费" 
            <<double( duration.count() )<< "毫秒" << endl;
        //cout << out_data.data() << endl;
    }

    //测试c++11 多线程Base16编码
    {
        cout << "c++11 多线程Base16编码 开始计算" << endl;
        auto start = system_clock::now();
        Base16EncodeThread(in_data,  out_data);
        auto end = system_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << "编码：" << in_data.size() << "字节数据花费"
            << double(duration.count()) << "毫秒" << endl;
        //cout << out_data.data() << endl;
    }

    getchar();
    return 0;
}