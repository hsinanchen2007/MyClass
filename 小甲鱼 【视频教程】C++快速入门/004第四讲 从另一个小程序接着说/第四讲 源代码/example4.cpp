#include <fstream>
#include <iostream>

using namespace std;

int main()
{
      fstream fp("test.txt", ios::in | ios::out );
      if( !fp )
      {
            cerr << "���ļ�ʧ��!" << endl;
            return 0;
      }

      fp << "IloveFishc.com!";

      static char str[100]; 

      fp.seekg(ios::beg);  // ʹ���ļ�ָ��ָ���ļ�ͷ ios::end �����ļ�β��
      fp >> str;
      cout << str << endl;

      fp.close();

      return 0;
}