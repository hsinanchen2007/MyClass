/*

https://www.educative.io/module/lesson/cpp-standard-library/7A1NANOGlWO

Repeated Search
We will now introduce the concept of iterators in regular expressions.

We'll cover the following

std::regex_iterator
std::regex_token_iterator
It¡¦s quite convenient to iterate with std::regex_iterator and std::regex_token_iterator over the matched texts. 
std::regex_iterator supports the matches and their capture groups. std::regex_token_iterator supports more. 
You can address the components of each capture and by using a negative index, your can access the text between 
the matches.

std::regex_iterator
C++ defines the following four type synonyms for std::regex_iterator.

1234
typedef cregex_iterator     regex_iterator<const char*>
typedef wcregex_iterator    regex_iterator<const wchar_t*>
typedef sregex_iterator     regex_iterator<std::string::const_iterator>
typedef wsregex_iterator    regex_iterator<std::wstring::const_iterator>
You can use std::regex_iterator to count the occurrences of the words in a text:

*/

#include <regex>
 
#include <iostream>
#include <string>
#include <unordered_map>
 
int main(){
 
  std::cout << std::endl;
 
  // Bjarne Stroustrup about C++0x on http://www2.research.att.com/~bs/C++0xFAQ.html
  std::string text{"That's a (to me) amazingly frequent question. It may be the most frequently asked question. Surprisingly, C++0x feels like a new language: The pieces just fit together better than they used to and I find a higher-level style of programming more natural than before and as efficient as ever."};
 
  // regular expression for a word
  std::regex wordReg(R"(\w+)");
 
  // get all words from text
  std::sregex_iterator wordItBegin(text.begin(), text.end(), wordReg);
  const std::sregex_iterator wordItEnd;
 
  // use unordered_map to count the wourds
  std::unordered_map<std::string, std::size_t> allWords;
 
  // count the words
  for (; wordItBegin != wordItEnd;++wordItBegin){
    ++allWords[wordItBegin->str()];
  }
 
  for ( auto wordIt: allWords) std::cout << wordIt.first << ": " << wordIt.second << "\n" ;
 
  std::cout << "\n\n";
 
}

// 
// as: 2
// of: 1
// level: 1
// find: 1
// ever: 1
// and: 2
// natural: 1
// higher: 1
// they: 1
// more: 1
// than: 2
// together: 1
// fit: 1
// just: 1
// pieces: 1
// be: 1
// a: 3
// That: 1
// C: 1
// used: 1
// It: 1
// better: 1
// question: 2
// to: 2
// efficient: 1
// frequent: 1
// programming: 1
// the: 1
// I: 1
// may: 1
// s: 1
// asked: 1
// like: 1
// before: 1
// style: 1
// language: 1
// me: 1
// frequently: 1
// Surprisingly: 1
// 0x: 1
// amazingly: 1
// most: 1
// feels: 1
// new: 1
// The: 1



