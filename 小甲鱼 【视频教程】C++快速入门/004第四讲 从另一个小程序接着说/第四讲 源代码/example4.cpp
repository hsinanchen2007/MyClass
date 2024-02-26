#include <fstream>
#include <iostream>

using namespace std;

int main()
{
      fstream fp("test.txt", ios::in | ios::out );
      if( !fp )
      {
            cerr << "打开文件失败!" << endl;
            return 0;
      }

      fp << "IloveFishc.com!";

      static char str[100]; 

      fp.seekg(ios::beg);  // 使得文件指针指向文件头 ios::end 则是文件尾。
      fp >> str;
      cout << str << endl;

      fp.close();

      return 0;
}