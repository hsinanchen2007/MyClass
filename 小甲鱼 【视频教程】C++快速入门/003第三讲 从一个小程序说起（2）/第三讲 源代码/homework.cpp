#include <iostream>

using namespace std;

int main()
{
      int sum = 0;
      int i;

      cout << "������һ��������������Ŀ�Ŀո�:";

      
      while( cin >> i )
      {
            sum += i;
            while( cin.peek() == ' ' )
            {
                  cin.get();
            }
            if( cin.peek() == '\n' )
            {
                  break;
            }
      }

      cout << "�����: " << sum << endl;

      return 0;
}