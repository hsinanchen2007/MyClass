/*

https://www.educative.io/module/lesson/cpp-standard-library/NEnvZ6vyGNK

Permutations
We can see the different permutations in a range using C++.

std::prev_permutation and std::next_permutation return the previous smaller or next bigger permutation 
of the newly ordered range. If a smaller or bigger permutation is not available, the algorithms return 
false. Both algorithms need bidirectional iterators. Per default the predefined sorting criterion std::less 
is used. If you use your sorting criterion, it has to obey the strict weak ordering. If not, the program 
is undefined.

Applies the previous permutation to the range:

12
bool prev_permutation(BiIt first, BiIt last)
bool prev_permutation(BiIt first, BiIt last, BiPred pre))
Applies the next permutation to the range:

12
bool next_permutation(BiIt first, BiIt last)
bool next_permutation(BiIt first, BiIt last, BiPred pre)
You can easily generate with both algorithms all permutations of the range.

*/

#include <algorithm>
#include <iostream>
#include <vector>
 
int main(){
 
  std::cout << std::endl;
 
  std::vector<int> myInts{1, 2, 3};
 
  std::cout << "All 3! permutions" << "\n\n";
  std::cout << "forwards" << std::endl;  
  do{
    for (auto i: myInts) std::cout << i << " ";
    std::cout << std::endl;
  } while(std::next_permutation(myInts.begin(), myInts.end()));
   
  std::cout << std::endl;
   
  std::reverse(myInts.begin(), myInts.end());
   
  std::cout << "backwards" << std::endl;
   
  do{
    for (auto i: myInts) std::cout << i << " ";
    std::cout << std::endl;
  } while(std::prev_permutation(myInts.begin(), myInts.end()));
   
  std::cout << std::endl;
 
}

//
// All 3! permutions
//
// forwards
// 1 2 3 
// 1 3 2 
// 2 1 3 
// 2 3 1 
// 3 1 2 
// 3 2 1 
//
// backwards
// 3 2 1 
// 3 1 2 
// 2 3 1 
// 2 1 3 
// 1 3 2 
// 1 2 3 
