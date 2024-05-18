#include<iostream>



//这里必须是dllimport 导入函数
extern "C"  _declspec(dllimport)     int   sum(int  a, int b);

//这里的.lib文件并不是静态库，而是动态库的符号文件
//方法一:  #pragma  comment (lib,"../Debug/003.lib")
//方法二:  右键-》属性-》配置属性-》链接器-》输入-》附加依赖项

//发布的时候，还需要发布.dll文件
int  main()
{
	std::cout << sum(123, 456) << std::endl;
}