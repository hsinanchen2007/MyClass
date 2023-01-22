/*

https://www.algoexpert.io/questions/two-number-sum

Two Number Sum

Write a function that takes in a non-empty array of distinct integers and an integer representing a target sum. 
If any two numbers in the input array sum up to the target sum, the function should return them in an array, in 
any order. If no two numbers sum up to the target sum, the function should return an empty array. Note that the 
target sum has to be obtained by summing two different integers in the array; you can't add a single integer to 
itself in order to obtain the target sum. You can assume that there will be at most one pair of numbers summing 
up to the target sum.

*/


// Copyright © 2022 AlgoExpert LLC. All rights reserved.
#include <vector>
using namespace std;

// 0(n^2) time | 0(1) space
vector<int> twoNumberSum(vector<int> array, int targetSum) {
    for (int i = 0; i < array.size() - 1; i++) {
        int firstNum = array[i];
        for (int j = 1 + 1; j < array.size(); j++) {
            int secondNum = array[j];
            if (firstNum + secondNum == targetSum) {
                return vector<int>{firstNum, secondNum};
            }
        }   
    }
    return {};
}


// Copyright © 2022 AlgoExpert LLC. All rights reserved.
#include <vector>
#include <unordered_set>

// O(n) time | O(n) space
vector<int> twoNumberSum(vector<int> array, int targetSum) {
    unordered_set<int> nums;
    for (int num : array) {
        int potentialMatch = targetSum - num;
        if (nums.find(potentialMatch) != nums.end()) {
            return vector<int>{potentialMatch, num};
        } else {
            nums.insert(num);
        }
    }
    return {};
}


// Copyright © 2022 AlgoExpert LLC. All rights reserved
#include <vector>
#include <algorithm>
using namespace std;

// 0(nlog(n)) | 0(1) space
vector<int> twoNumberSum(vector<int> array, int targetSum) {
    sort(array.begin(), array.end());
    int left = 0;
    int right = array.size() - 1;
    while (left < right) {
        int currentSum = array[left] + array[right];
        if (currentSum == targetSum) {
            return {array[left], array[right]};
        } else if (currentSum < targetSum) {
            left++;
        } else if (currentSum > targetSum) {
            right--;
        }
    }
    return {};
}