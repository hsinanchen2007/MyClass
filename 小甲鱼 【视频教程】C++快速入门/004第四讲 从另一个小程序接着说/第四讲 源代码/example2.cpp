#include <fstream>
#include <iostream>

using namespace std;

int main()
{
      ofstream out;

      out.open( "test.txt" );
      if( !out )
      {
            cerr << "���ļ�ʧ��!" << endl;
			return 0;
      }

      for( int i=0; i < 10; i++ )
      {
            out << i;
      }
      
      out << endl;
      out.close();

      return 0;
}