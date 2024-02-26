#include <fstream>
#include <cstdlib>

using namespace std;

void print_error( const char*, const char* = "" );

int main( int argc, char* argv[] )
{
      if( argc != 3 )
      {
            print_error( "输入形式: copyFile 源文件名 目标文件名 \n" );
      }

      ifstream in( argv[1], ios::binary );

      if( !in )
      {

      }

      return 0;
}