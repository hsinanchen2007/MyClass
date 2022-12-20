/*

Introduction
Any problem that asks us to find the top/smallest/frequent ‘K’ elements among a given set 
falls under this pattern.

The best data structure that comes to mind to keep track of ‘K’ elements is Heap. This pattern 
will make use of the Heap to solve multiple problems dealing with ‘K’ elements at a time from 
a set of given elements.

Let’s jump onto our first problem to develop an understanding of this pattern.

https://www.educative.io/courses/grokking-the-coding-interview/RM535yM9DW0

Given an unsorted array of numbers, find the ‘K’ largest numbers in it.

Note: For a detailed discussion about different approaches to solve this problem, take a look 
at Kth Smallest Number.

Example 1:

Input: [3, 1, 5, 12, 2, 11], K = 3
Output: [5, 12, 11]

Example 2:

Input: [5, 12, 11, -1, 12], K = 3
Output: [12, 11, 12]

*/
