/*    檔名:ch14_02.cpp    功能:cin物件的練習    */

#include <iostream>

using namespace std;

int main()
{
  int   a1,a2;
  float b;
  char s[100];
  int* p;
  
  p=&a2;                 // p指向a2
  cout << "請輸入a1,a2:";
  cin >> a1 >> *p;
  cout << "請輸入b:";
  cin >> b;
  cout << "請輸入s字串:";
  cin >> s;
  cout << "a1=" << a1 << "\ta2=" << a2 << "\tb=" << b << "\ts=" << s << endl;
  return 0;
}
