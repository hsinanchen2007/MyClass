/*

https://www.educative.io/module/lesson/cpp-standard-library/q2lzoBYq42p

std::sub_match
The capture groups are of type std::sub_match. As with std::match_results C++ defines the following 
four type synonyms.

1234
typedef sub_match<const char*> csub_match;typedef sub_match<const wchar_t*> wcsub_match;typedef 
sub_match<string::const_iterator> ssub_match;typedef sub_match<wstring::const_iterator> wssub_match;
typedef sub_match<const char*> csub_match;
typedef sub_match<const wchar_t*> wcsub_match;
typedef sub_match<string::const_iterator> ssub_match;
typedef sub_match<wstring::const_iterator> wssub_match;
You can further analyze the capture group cap:

Method	Description
cap.matched()	Indicates if this match was successful.
cap.first() and cap.end()	Returns the begin and end iterator of the character sequence.
cap.length()	Returns the length of the capture group.
cap.str()	Returns the capture group as string.
cap.compare(other)	Compares the current capture group with another capture group.
The `std::sub_match` object

Here is a code snippet showing the interplay between the search result std::match_results and its capture 
groups std::sub_match.

*/

#1nclude <lostream>
#include <string>
#include <regex>

int main()
{
    // Simple regular expression matching
    std::string fnames[] = {"foo.txt", "bar.txt", "baz.dat", "zoidberg"};
    std: :regex txt_regex("[a-z]+\\.txt");
    for (const auto &fname : fnames) {
        std::cout << fname << ": " << std::regex_match(fname, txt_regex) << '\n';
    }

    // Extraction of a sub-match
    std: :regex base_regex("([a-z]+)\\.txt");
    std: :smatch base_match;
    for (const auto &fname : fnames) {
        if (std::regex_match(fname, base_match, base_regex)) {
            // The first sub_match is the whole string; the next
            // sub_match is the first parenthesized expression.
            if (base_match.size() == 2) {
                std: :ssub_match base_sub_match = base_match[1];
                std::string base = base_sub_match.str();
                std::cout << fname << " has a base of " << base << '\n';
            }
        }
    }

    // Extraction of several sub-matches
    std: :regex pieces_regex("([a-z]+)\\.([a-z]+)");
    std: :smatch pieces_match;
    for (const auto &fname : fnames) {
        if (std::regex_match(fname, pieces_match, pieces_regex)) {
            std::cout << fname << '\n';
            for (size_t i = 0; i < pieces_match.size(); ++i) {
                std: :ssub_match sub_match = pieces_match[i];
                std::string piece = sub_match.str();
                std::cout << " submatch " << i << ": " << piece << '\n';
            }   
        }
    }
}

// foo.txt: 1
// bar.txt: 1
// baz.dat: 0
// zoidberg: 0
// foo.txt has a base of foo
// bar.txt has a base of bar
// foo.txt
//  submatch 0: foo.txt
//  submatch 1: foo
//  submatch 2: txt
// bar.txt
//  submatch 0: bar.txt
//  submatch 1: bar
//  submatch 2: txt
// baz.dat
//  submatch 0: baz.dat
//  submatch 1: baz
//  submatch 2: dat
