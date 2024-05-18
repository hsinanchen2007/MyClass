#include<iostream>
#include <fstream>  

using namespace  std;

 
int  main()
{
	//ofstream输出流写文件
	/*ofstream  o;
	o.open("1.txt", ios::out);//每一次，都将删除上一次的文件，新建文件
	o << "hello";
	o.write("world!", strlen("world!"));
	o.close();


	//ifstream输入流读文件
	ifstream  i;
	i.open("1.txt", ios::in);

	char buf[100] = {0};
	//i.read(buf, 100);
	i >> buf;
	cout << "实际读取：" << i.gcount() << endl;
	cout << buf << endl;
	
	i.close();
	*/

	//fstream 输入输出流，可以读或者写
	fstream  f;
	f.open("2.txt", ios::out | ios::in | ios::trunc);

	//写入
	f << "hello";
	f << 100;
	f << 1.234;

    //此刻，文件指针在末尾，如果要读，什么都读不到
	//所以，我们需要把文件指针移到开头，然后再读取
	f.seekg(0, ios::beg); // 定位到文件开头


	char buf[100] = {0};
	//读取
	f >> buf;   
	cout << buf << endl;
	  
	f.close();


	return 0;
}