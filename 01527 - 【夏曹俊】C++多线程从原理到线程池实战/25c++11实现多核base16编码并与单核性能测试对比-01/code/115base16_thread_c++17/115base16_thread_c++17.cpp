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
//C++11 ���base16����
void Base16EncodeThread(const vector<unsigned char>&data,vector<unsigned char>&out)
{
    int size = data.size();
    int th_count = thread::hardware_concurrency(); //ϵͳ֧�ֵ��̺߳�����
    //��Ƭ����
    int slice_count = size / th_count; //��������
    if (size < th_count) //ֻ��һƬ
    {
        th_count = 1;
        slice_count = size;
    }

    //׼�����߳�
    vector<thread> ths;
    ths.resize(th_count);

    //������䵽�����߳�    
    for (int i = 0; i < th_count; i++)
    {
        //1234 5678 9abc defg hi 
        int offset = i * slice_count;
        int count = slice_count;

        //���һ���߳�
        if (th_count > 1 && i == th_count - 1)
        {
            count = slice_count + size % th_count;
        }
        //cout << offset << ":" << count << endl;
        ths[i] = thread(Base16Encode, data.data() + offset, count, out.data());
    }
    //�ȴ������̴߳������
    for (auto& th : ths)
    {
        th.join();
    }
}

int main(int argc, char* argv[])
{
    string test_data = "����base16����";
    unsigned char out[1024] = { 0 };
    Base16Encode((unsigned char*)test_data.data(), test_data.size(), out);
    cout << "base16:" << out << endl;


    //��ʼ����������
    vector<unsigned char> in_data;
    in_data.resize(1024 * 1024 * 20); //20M
    //in_data.data();
    for (int i = 0; i < in_data.size(); i++)
    {
        in_data[i] = i % 256;
    }
    vector<unsigned char > out_data;
    out_data.resize(in_data.size() * 2);


    //���Ե��߳�base16����Ч��
    {
        cout << "���߳�base16��ʼ����" << endl;
        auto start = system_clock::now();
        Base16Encode(in_data.data(), in_data.size(), out_data.data());
        auto end = system_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << "���룺" << in_data.size() << "�ֽ����ݻ���" 
            <<double( duration.count() )<< "����" << endl;
        //cout << out_data.data() << endl;
    }

    //����c++11 ���߳�Base16����
    {
        cout << "c++11 ���߳�Base16���� ��ʼ����" << endl;
        auto start = system_clock::now();
        Base16EncodeThread(in_data,  out_data);
        auto end = system_clock::now();
        auto duration = duration_cast<milliseconds>(end - start);
        cout << "���룺" << in_data.size() << "�ֽ����ݻ���"
            << double(duration.count()) << "����" << endl;
        //cout << out_data.data() << endl;
    }

    getchar();
    return 0;
}