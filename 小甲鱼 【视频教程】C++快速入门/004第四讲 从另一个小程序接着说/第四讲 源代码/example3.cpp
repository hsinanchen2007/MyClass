#include <fstream>
#include <iostream>

using namespace std;

int main()
{
      ofstream out( "test.txt", ios::app );

      if( !out )
      {
            cerr << "文件打开失败!" << endl;
            return 0;
      }

      for( int i=10; i > 0; i-- )
      {
            out << i;
      }

      out << endl;
      out.close();

      return 0;
}