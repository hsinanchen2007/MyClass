/*

Introduction
0/1 Knapsack pattern is based on the famous problem with the same name which is efficiently 
solved using Dynamic Programming (DP).

In this pattern, we will go through a set of problems to develop an understanding of DP. 
We will always start with a brute-force recursive solution to see the overlapping subproblems, 
i.e., realizing that we are solving the same problems repeatedly.

After the recursive solution, we will modify our algorithm to apply advanced techniques of 
Memoization and Bottom-Up Dynamic Programming to develop a complete understanding of this pattern.

Let’s jump onto our first problem.

https://www.educative.io/courses/grokking-the-coding-interview/gkZNLjV2kBk

Given the weights and profits of ‘N’ items, we are asked to put these items in a knapsack with 
a capacity ‘C.’ The goal is to get the maximum profit out of the knapsack items. Each item can 
only be selected once, as we don’t have multiple quantities of any item.

Let’s take Merry’s example, who wants to carry some fruits in the knapsack to get maximum profit. 
Here are the weights and profits of the fruits:

Items: { Apple, Orange, Banana, Melon }
Weights: { 2, 3, 1, 4 }
Profits: { 4, 5, 3, 7 }
Knapsack capacity: 5

Let’s try to put various combinations of fruits in the knapsack, such that their total weight is 
not more than 5:

Apple + Orange (total weight 5) => 9 profit
Apple + Banana (total weight 3) => 7 profit
Orange + Banana (total weight 4) => 8 profit
Banana + Melon (total weight 5) => 10 profit

This shows that Banana + Melon is the best combination as it gives us the maximum profit, and the 
total weight does not exceed the capacity.

Problem Statement
Given two integer arrays to represent weights and profits of ‘N’ items, we need to find a subset 
of these items which will give us maximum profit such that their cumulative weight is not more than 
a given number ‘C.’ Each item can only be selected once, which means either we put an item in the 
knapsack or we skip it.

*/

