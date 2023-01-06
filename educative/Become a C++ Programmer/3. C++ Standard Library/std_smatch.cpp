/*

https://www.educative.io/module/lesson/cpp-standard-library/q2lzoBYq42p

The Search Result
Whenever we verify whether a piece of text satisfies our regular expression, we have to store the results somewhere. 
std::match_results allows us to do just that.

We'll cover the following

std::sub_match
The object of type std::match_results is the result of a std::regex_match or std::regex_search. std::match_results is 
a sequential container having at least one capture group of a std::sub_match object. The std::sub_match objects are 
sequences of characters.

?? What is a capture group?
Capture groups allow it to further analyse the search result in a regular expression. They are defined by a pair of 
parentheses (). The regular expression ((a+)(b+)(c+)) has four capture groups: ((a+)(b+)(c+)), (a+), (b+) and (c+) 
The total result is the 0th capture group.

C++ has four types of synonyms of type std::match_results:

1234
typedef match_results<const char*> cmatch;typedef match_results<const wchar_t*> wcmatch;typedef match_results<string::const_iterator> 
smatch;typedef match_results<wstring::const_iterator> wsmatch;
typedef match_results<const char*> cmatch;
typedef match_results<const wchar_t*> wcmatch;
typedef match_results<string::const_iterator> smatch;
typedef match_results<wstring::const_iterator> wsmatch;
The search result std::smatch smatch has a powerful interface.

Some methods of the std::smatch interface:

Method	Description
smatch.size()	Returns the number of capture groups.
smatch.empty()	Returns if the search result has a capture group.
smatch[i]	Returns the ith capture group.
smatch.length(i)	Returns the length of the ith capture group.
smatch.position(i)	Returns the position of the ith capture group.
smatch.str(i)	Returns the ith capture group as string.
smatch.prefix() and smatch.suffix()	Returns the string before and after the capture group.
smatch.begin() and smatch.end()	Returns the begin and end iterator for the capture groups.
smatch.format(...)	Formats std::smatch objects for the output.
Interface of std::smatch

The following program shows the output of the first four capture groups for different regular expressions.

*/

#include <regex>
#include <iomanip>
#include <iostream>
#include <string>

void showCaptureGroups(const std::string& regEx, const std::string& text) {
    // regular expression holder
    std: :regex rgx(regkx);

    // result holder
    std: :smatch smatch;

    // result evaluation
    if (std::regex_search(text, smatch, rgx)) {
        std::cout << std::setw(10) << regEx << std::setw(308) << text << std::setw(38) << smatch[8] << std::setw(25) << smatch[1] << std::setw(28) << smatch[2] << std::setw(36) << smatch[3] << std::setw(30) << smatch[4] << std::endl;
    }
}

int main() {
    std::cout << std::endl;
    std::cout << std::setw(10) << "reg Expr" << std::setw(30) << "text" << std::setw(30) << "smatch[8]" << std::setw(30) << "smatch[1]" << std::setw(30) << "smatch[2]" << std::setw(36) << "smatch[3]" << std::setw(36) << "smatch[4]" << std::endl;
    showCaptureGroups("abc+", "abcccec");
    showCaptureGroups("(a+) (b+) (c+)", "aaabccc");
    showCaptureGroups("((a+) (b+) (c+))", "aaabccc");
    showCaptureGroups("(ab) (abc)+", "ababcabc");
    std::cout << std::endl;
}

//  reg Expr                          text                     smatch[0]                     smatch[1]                     smatch[2]                     smatch[3]                     smatch[4]
//      abc+                       abccccc                       abccccc                                                                                                                       
// (a+)(b+)(c+)                       aaabccc                       aaabccc                      aaa                           b                                 ccc                              
// ((a+)(b+)(c+))                       aaabccc                       aaabccc                  aaabccc                         aaa                                   b                           ccc
// (ab)(abc)+                      ababcabc                      ababcabc                       ab                         abc                                                                  
