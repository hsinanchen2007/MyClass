#include <fstream>
#include <cstdlib>

using namespace std;

void print_error( const char*, const char* = "" );

int main( int argc, char* argv[] )
{
      if( argc != 3 )
      {
            print_error( "������ʽ: copyFile Դ�ļ��� Ŀ���ļ��� \n" );
      }

      ifstream in( argv[1], ios::binary );

      if( !in )
      {

      }

      return 0;
}