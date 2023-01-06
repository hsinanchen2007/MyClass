/*

https://www.educative.io/module/lesson/cpp-standard-library/JYVJ7Xpj31v

String Streams
The string stream family lets us store and manipulate strings.

We'll cover the following

Streams
String Streams
Streams
A stream is an infinite data stream on which you can push or pull data. String streams and file streams 
enable strings and files to interact with the stream directly.

String Streams
String streams need the header <sstream>. They are not connected to an input or output stream and store 
their data in a string.

Whether you use a string stream for input or output or with the character type char or wchar_t there are 
various string stream classes:

Class	Use
std::istringstream and std::wistringstream	String stream for the input of data of type char and wchar_t.
std::ostringstream and std::wostringstream	String stream for the output of data of type char and wchar_t.
std::stringstream and std::wstringstream	String stream for the input or output of data of type char and wchar_t
Typical operations on a string stream are:

Write data in a string stream:
123
std::stringstream os;
os << "New String";
os.str("Another new String");
Read data from a string stream:
1234
std::stringstream os;
std::string str;
os >> str;
str= os.str();
Clear a string stream:
12
std::stringstream os;
os.str("");
String streams are often used for the type safe conversion between strings and numeric values:

*/

#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>
 
template < class T > 
T StringTo ( const std::string& source ){
 
  std::istringstream iss(source);
  T ret;
  iss >> ret;
 
  return ret;
 
}
 
template< class T > 
std::string ToString(const T& n){
 
  std::ostringstream tmp ;
  tmp << n;
  return tmp.str();
 
}
 
int main(){
   
  std::cout << std::endl;
 
  std::cout << "5 = "  << std::string("5") << std::endl;
  std::cout << "5 = " <<  StringTo<int>("5") << std::endl;
  std::cout << "5 + 6 = " << StringTo<int>("5") + 6 << std::endl;
   
  std::string erg(ToString(StringTo<int> ("5") + 6 ) ); 
  std::cout << "5 + 6 = " << erg  << std::endl;
   
  std::cout << "5e10: " << std::fixed << StringTo<double>("5e10")  << std::endl;
   
  std::cout << std::endl;
   
}

// 
// 5 = 5
// 5 = 5
// 5 + 6 = 11
// 5 + 6 = 11
// 5e10: 50000000000.000000
