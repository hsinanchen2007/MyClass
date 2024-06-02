#include <iostream>
#include <string>

/*
    Leetcode 1427 - Perform String Shifts

    Description
    You are given a string s containing lowercase English letters, 
    and a matrix shift, where shift[i] = [directioni, amounti]:

    directioni can be 0 (for left shift) or 1 (for right shift).
    amounti is the amount by which string s is to be shifted.
    A left shift by 1 means remove the first character of s and 
    append it to the end. Similarly, a right shift by 1 means remove 
    the last character of s and add it to the beginning. Return the 
    final string after all operations.

    Example 1:

    Input: s = "abc", shift = [[0,1],[1,2]]
    Output: "cab"
    Explanation:
    [0,1] means shift to left by 1. "abc" -> "bca"
    [1,2] means shift to right by 2. "bca" -> "cab"
    Example 2:

    Input: s = "abcdefg", shift = [[1,1],[1,1],[0,2],[1,3]]
    Output: "efgabcd"
    Explanation:
    [1,1] means shift to right by 1. "abcdefg" -> "gabcdef"
    [1,1] means shift to right by 1. "gabcdef" -> "fgabcde"
    [0,2] means shift to left by 2. "fgabcde" -> "abcdefg"
    [1,3] means shift to right by 3. "abcdefg" -> "efgabcd"

    Constraints:

    1 <= s.length <= 100
    s only contains lower case English letters.
    1 <= shift.length <= 100
    shift[i].length == 2
    directioni is either 0 or 1.
    0 <= amounti <= 100

    class Solution {
        public:
            string stringShift(string s, vector<vector<int>>& shift) {
                int x = 0;
                for (auto& e : shift) {
                    if (e[0] == 0) {
                        e[1] = -e[1];
                    }
                    x += e[1];
                }
                int n = s.size();
                x = (x % n + n) % n;
                return s.substr(n - x, x) + s.substr(0, n - x);
            }
    };
*/

using namespace std;

// For string with 3 characters
// abc ---> cab (shift 1)
// abc ---> cab (shift 4)

// For string with 8 characters
// abcdefgh ---> habcdefg (shift 1)
// abcdefgh ---> habcdefg (shift 9)

string operator >> (const string& s, unsigned int n)
{
    string ret = "";
    unsigned int pos = 0;

    n = n % s.length();
    pos = s.length() - n;
    ret = s.substr(pos);
    ret += s.substr(0, pos);

    return ret;
}

int main()
{
    string s = "abcdefg";
    string r = (s >> 3);

    cout << r << endl;

    return 0;
}
