/*

https://www.educative.io/courses/grokking-the-coding-interview/xVlKmyX542P

Solution
This problem follows the Subsets pattern and can be mapped to Permutations.

Let’s take Example-2 mentioned above to generate all the permutations. Following a 
BFS approach, we will consider one character at a time. Since we need to preserve the 
character sequence, we can start with the actual string and process each character 
(i.e., make it upper-case or lower-case) one by one:

Starting with the actual string: "ab7c"
Processing the first character (‘a’), we will get two permutations: "ab7c", "Ab7c"
Processing the second character (‘b’), we will get four permutations: "ab7c", "Ab7c", 
"aB7c", "AB7c"
Since the third character is a digit, we can skip it.
Processing the fourth character (‘c’), we will get a total of eight permutations: 
"ab7c", "Ab7c", "aB7c", "AB7c", "ab7C", "Ab7C", "aB7C", "AB7C"

Let’s analyze the permutations in the 3rd and the 5th step. How can we generate the 
permutations in the 5th step from the permutations in the 3rd step?

If we look closely, we will realize that in the 5th step, when we processed the new 
character (‘c’), we took all the permutations of the previous step (3rd) and changed 
the case of the letter (‘c’) in them to create four new permutations.

Here is the visual representation of this algorithm:

    []   
    [1]   
    [5]   
    [1,5]   
    [3]   
    [1,3]   
    [5,3]   
    [1,5,3]   
    ab7c   
    [ab7c]   
    [Ab7c]   
    [ab7c]   
    [Ab7c]   
    [aB7c]   
    [AB7c]   
    [ab7c]   
    [Ab7c]   
    [aB7c]   
    [AB7c]   
    [ab7C]   
    Ab7C]   
    aB7C]   
    [AB7C]   
 Given string: "ab7c"  

Time complexity
Since we can have 2^N permutations at the most and while processing each permutation 
we convert it into a character array, the overall time complexity of the algorithm will 
be O(N*2^N)

Space complexity
All the additional space used by our algorithm is for the output list. Since we can have 
a total of O(2^N) permutations, the space complexity of our algorithm is O(N*2^N)

*/

using namespace std;

#include <iostream>
#include <string>
#include <vector>

class LetterCaseStringPermutation {
 public:
  static vector<string> findLetterCaseStringPermutations(const string& str) {
    vector<string> permutations;
    if (str == "") {
      return permutations;
    }

    permutations.push_back(str);
    // process every character of the string one by one
    for (int i = 0; i < str.length(); i++) {
      if (isalpha(str[i])) {  // only process characters, skip digits
        // we will take all existing permutations and change the letter case appropriately
        int n = permutations.size();
        for (int j = 0; j < n; j++) {
          vector<char> chs(permutations[j].begin(), permutations[j].end());
          // if the current character is in upper case change it to lower case or vice versa
          if (isupper(chs[i])) {
            chs[i] = tolower(chs[i]);
          } else {
            chs[i] = toupper(chs[i]);
          }
          permutations.push_back(string(chs.begin(), chs.end()));
        }
      }
    }
    return permutations;
  }
};

int main(int argc, char* argv[]) {
  vector<string> result = LetterCaseStringPermutation::findLetterCaseStringPermutations("ad52");
  cout << "String permutations are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;

  result = LetterCaseStringPermutation::findLetterCaseStringPermutations("ab7c");
  cout << "String permutations are: ";
  for (auto str : result) {
    cout << str << " ";
  }
  cout << endl;
}
