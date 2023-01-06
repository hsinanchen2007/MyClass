/*

https://www.educative.io/module/lesson/cpp-standard-library/7A1NANOGlWO

A word consists of a least one character (\w+). This regular expression is used to define the begin 
iterator wordItBegin and the end iterator wordItEnd. The iteration through the matches happens in 
the for loop. Each word increments the counter: ++allWords[wordItBegin]->str()]. A word with counter 
equals to 1 is created if it is not already in allWords.

std::regex_token_iterator
C++ defines the following four type synonyms for std::regex_token_iterator.

1234
typedef cregex_iterator     regex_iterator<const char*>
typedef wcregex_iterator    regex_iterator<const wchar_t*>
typedef sregex_iterator     regex_iterator<std::string::const_iterator>
typedef wsregex_iterator    regex_iterator<std::wstring::const_iterator>
std::regex_token_iterator enables you by using indexes to specify which capture groups you are interested 
in explicitly. If you don¡¦t specify the index, you will get all capture groups, but you can also request 
specific capture groups using its respective index. The -1 index is special: You can use -1 to address the 
text between the matches:

*/

#include <regex>
 
#include <iostream>
#include <string>
#include <vector>
 
int main(){
 
  std::cout << std::endl;
 
  // a few books
  std::string text{"Pete Becker, The C++ Standard Library Extensions, 2006:Nicolai Josuttis, The C++ Standard Library, 1999:Andrei Alexandrescu, Modern C++ Design, 2001"};
 
  // regular expression for a book
  std::regex regBook(R"((\w+)\s(\w+), ([\w\s\+]*), (\d{4}))");
 
  // get all books from text
  std::sregex_token_iterator bookItBegin(text.begin(), text.end(), regBook);
  const std::sregex_token_iterator bookItEnd;
 
  std::cout << "##### std::match_results ######" << "\n\n";
  while ( bookItBegin != bookItEnd){
    std::cout << *bookItBegin++ << std::endl;
  }
 
  std::cout << "\n\n" << "##### last name,  date of publication ######" << "\n\n";
 
  // get all last name and date of publication for the entries
  std::sregex_token_iterator bookItNameIssueBegin(text.begin(), text.end(), regBook, {{2, 4}});
  const std::sregex_token_iterator bookItNameIssueEnd;
  while ( bookItNameIssueBegin != bookItNameIssueEnd){
      std::cout << *bookItNameIssueBegin++ << ", ";
      std::cout << *bookItNameIssueBegin++ << std::endl;
  }
 
  // regular expression for a book, using negativ search
  std::regex regBookNeg(":");
 
  std::cout << "\n\n" << "##### get each entry, using negativ search  ######" << "\n\n";
 
  // get all entries, only using ":" as regular expression
  std::sregex_token_iterator bookItNegBegin(text.begin(), text.end(), regBookNeg, -1);
  const std::sregex_token_iterator bookItNegEnd;
   while ( bookItNegBegin != bookItNegEnd){
       std::cout << *bookItNegBegin++ << std::endl;
   }
 
 
  std::cout << std::endl;
 
}

//
// ##### std::match_results ######
//
// Pete Becker, The C++ Standard Library Extensions, 2006
// Nicolai Josuttis, The C++ Standard Library, 1999
// Andrei Alexandrescu, Modern C++ Design, 2001
//
//
// ##### last name,  date of publication ######
//
// Becker, 2006
// Josuttis, 1999
// Alexandrescu, 2001
//
//
// ##### get each entry, using negativ search  ######
// 
// Pete Becker, The C++ Standard Library Extensions, 2006
// Nicolai Josuttis, The C++ Standard Library, 1999
// Andrei Alexandrescu, Modern C++ Design, 2001
