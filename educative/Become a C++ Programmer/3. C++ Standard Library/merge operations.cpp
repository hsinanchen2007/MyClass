/*

https://www.educative.io/module/lesson/cpp-standard-library/7Az2lnnGDvj

Merge Operations
In this lesson, we'll learn different ways of combining ranges.

Merge operations empower you to merge sorted ranges in a new sorted range. The algorithm requires that 
the ranges and the algorithm use the same sorting criterion. If not, the program is undefined. Per default 
the predefined sorting criterion std::less is used. If you use your sorting criterion, it has to obey 
the strict weak ordering. If not, the program is undefined.

You can merge two sorted ranges with std::inplace_merge and std::merge. You can check with std::includes 
if one sorted range is in another sorted range. You can merge with std::set_difference, std::set_intersection, 
std::set_symmetric_difference and std::set_union two sorted ranges in a new sorted range.

Merges in place two sorted sub ranges [first, mid) and [mid, last):

12345
void inplace_merge(BiIt first, BiIt mid, BiIt last)
void inplace_merge(ExePol pol, BiIt first, BiIt mid, BiIt last)

void inplace_merge(BiIt first, BiIt mid, BiIt last, BiPre pre)
void inplace_merge(ExePol pol, BiIt first, BiIt mid, BiIt last, BiPre pre)
Merges two sorted ranges and copies the result to result:

12345
OutIt merge(InpIt first1, InpIt last1, InpIt first2, InpIt last2, OutIt result)
FwdIt3 merge(ExePol pol, FwdIt1 first1, FwdIt1 last1, FwdIt2 first2, FwdIt2 last2, FwdIt3 result)

OutIt merge(InpIt first1, InpIt last1, InpIt first2, InpIt last2, OutIt result, BiPre pre)
FwdIt3 merge(ExePol pol, FwdIt1 first1, FwdIt1 last1, FwdpIt2 first2, FwdIt2 last2, FwdIt3 result, BiPre pre)
Checks if all elements of the second range are in the first range:

12345
bool includes(InpIt first1, InpIt last1, InpIt1 first2, InpIt1 last2)
bool includes(ExePol pol, FwdIt first1, FwdIt last1, FwdIt1 first2, FwdIt1 last2)

bool includes(InpIt first1, InpIt last1, InpIt first2, InpIt last2, BinPre pre)
bool includes(ExePol pol, FwdIt first1, FwdIt last1, FwdIt1 first2, FwdIt1 last2, BinPre pre)
Copies these elements of the first range to result, being not in the second range:

12345
OutIt set_difference(InpIt first1, InpIt last1, InpIt1 first2, InpIt2 last2, OutIt result)
FwdIt2 set_difference(ExePol pol, FwdIt first1, FwdIt last1, FWdIt1 first2, FwdIt1 last2, FwdIt2 result)
             
OutIt set_difference(InpIt first1, InpIt last1, InpIt1 first2, InpIt2 last2, OutIt result, BiPre pre)
FwdIt2 set_difference(ExePol pol, FwdIt first1, FwdIt last1, FwdIt1 first2, FwdIt1 last2, FwdIt2 result, BiPre pre)
Determines the intersection of the first with the second range and copies the result to result:

12345
OutIt set_intersection(InpIt first1, InpIt last1, InpIt1 first2, InpIt2 last2, OutIt result)
FwdIt2 set_intersection(ExePol pol, FwdIt first1, FwdIt last1, FWdIt1 first2, FwdIt1 last2, FwdIt2 result)
             
OutIt set_intersection(InpIt first1, InpIt last1, InpIt1 first2, InpIt2 last2, OutIt result, BiPre pre)
FwdIt2 set_intersection(ExePol pol, FwdIt first1, FwdIt last1, FwdIt1 first2, FwdIt1 last2, FwdIt2 result, BiPre pre)
Determines the symmetric difference of the first with the second range and copies the result to result:

12345
OutIt set_symmetric_difference(InpIt first1, InpIt last1, InpIt1 first2, InpIt2 last2, OutIt result)
FwdIt2 set_symmetric_difference(ExePol pol, FwdIt first1, FwdIt last1, FWdIt1 first2, FwdIt1 last2, FwdIt2 result)
             
OutIt set_symmetric_difference(InpIt first1, InpIt last1, InpIt1 first2, InpIt2 last2, OutIt result, BiPre pre)
FwdIt2 set_symmetric_difference(ExePol pol, FwdIt first1, FwdIt last1, FwdIt1 first2, FwdIt1 last2, FwdIt2 result, BiPre pre)
Determines the union of the first with the second range and copies the result to result:

12345
OutIt set_union(InpIt first1, InpIt last1, InpIt1 first2, InpIt2 last2, OutIt result)
FwdIt2 set_union(ExePol pol, FwdIt first1, FwdIt last1, FWdIt1 first2, FwdIt1 last2, FwdIt2 result)
             
OutIt set_union(InpIt first1, InpIt last1, InpIt1 first2, InpIt2 last2, OutIt result, BiPre pre)
FwdIt2 set_union(ExePol pol, FwdIt first1, FwdIt last1, FwdIt1 first2, FwdIt1 last2, FwdIt2 result, BiPre pre)
The returned iterator is an end iterator for the destination range. The destination range of std::set_difference 
has all the elements in the first, but not the second range. On the contrary, the destination range of 
std::symmetric_difference has only the elements that are elements of one range, but not both. std::union determines 
the union of both sorted ranges.

*/

#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>
 
int main(){
 
  std::cout << std::boolalpha;
 
  std::vector<int> vec1{1, 1, 4, 3, 5, 8, 6, 7, 9, 2};
  std::vector<int> vec2{1, 2, 3};
  
  std::cout << "vec1:\t\t\t\t\t";
  for (auto v: vec1) std::cout << v << " ";
  std::cout << std::endl;
  //vec1:	1 1 4 3 5 8 6 7 9 2 
  std::cout << "vec2:\t\t\t\t\t";
  for (auto v: vec2) std::cout << v << " ";
  std::cout << std::endl;
  //vec2:	1 2 3 
  
  std::sort(vec1.begin(), vec1.end());
  std::vector<int> vec(vec1);
  
  std::cout << std::endl;
  std::cout << "vec1 includes vec2: " << std::includes(vec1.begin(), vec1.end(), vec2.begin(), vec2.end()) << std::endl;
  //vec1 includes vec2: true
  std::cout << std::endl;
  
  vec1.reserve(vec1.size() + vec2.size());
  vec1.insert(vec1.end(), vec2.begin(), vec2.end());
  
  std::cout << "vec1:\t\t\t\t\t";
  for (auto v: vec1) std::cout << v << " "; 
  std::cout << std::endl;
   
  std::inplace_merge(vec1.begin(), vec1.end() - vec2.size(), vec1.end());  
  std::cout << "vec1:\t\t\t\t\t";
  for ( auto v: vec1 ) std::cout << v << " ";
   
  std::cout << "\n\n";
   
  vec2.push_back(10);
   
  std::cout << "vec:\t\t\t\t\t\t";
  for (auto v: vec) std::cout <<  v << " ";
  std::cout << std::endl;
  std::cout << "vec2:\t\t\t\t\t";
  for (auto v: vec2) std::cout << v << " ";
   
  std::vector<int> res;
  std::set_union(vec.begin(), vec.end(), vec2.begin(), vec2.end(),
         std::back_inserter(res));
  std::cout << "\n" << "set_union:\t\t\t\t";
  for (auto v : res) std::cout << v << " ";
   
  res={};
  std::set_intersection(vec.begin(), vec.end(), vec2.begin(), vec2.end(),
         std::back_inserter(res));
  std::cout << "\n" << "set_intersection:\t\t\t";
  for (auto v : res) std::cout << v << " ";

   
  res={};
  std::set_difference(vec.begin(), vec.end(), vec2.begin(), vec2.end(),
         std::back_inserter(res));
  std::cout << "\n" << "set_difference:\t\t\t";
  for (auto v : res) std::cout << v << " ";
   
  res={};
  std::set_symmetric_difference(vec.begin(), vec.end(), vec2.begin(), vec2.end(),
         std::back_inserter(res));
  std::cout << "\n" << "set_symmetric_difference:\t";
  for (auto v : res) std::cout << v << " ";
   
 
  std::cout << "\n\n";
 
}

// vec1:					1 1 4 3 5 8 6 7 9 2 
// vec2:					1 2 3 
//
// vec1 includes vec2: true
//
// vec1:					1 1 2 3 4 5 6 7 8 9 1 2 3 
// vec1:					1 1 1 2 2 3 3 4 5 6 7 8 9 
//
// vec:						1 1 2 3 4 5 6 7 8 9 
// vec2:					1 2 3 10 
// set_union:				1 1 2 3 4 5 6 7 8 9 10 
// set_intersection:			1 2 3 
// set_difference:			1 4 5 6 7 8 9 
// set_symmetric_difference:	1 4 5 6 7 8 9 10 
