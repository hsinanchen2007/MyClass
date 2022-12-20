/*

https://www.educative.io/module/lesson/oop-in-cpp/JEk9Dj37mA9

Challenge 4: Implement Derived Class to Calculate Min/Max/Mean
In this exercise, you have to implement a derived class that will calculate the min, max and 
the mean of the data set given in the dynamic array.

We'll cover the following

Problem Statement
Input
Sample Input
Expected Output
Coding Exercise
Solution Review
Problem Statement
In this challenge, you are given a class called DynamicArray which implements a dynamic array 
of integers that can grow in size.

This class has the following functions:

void append(int value): Adds a new value at the end of the array.
int get(int index): Returns the value at the given index.
int length(): Returns the current size of the array.
void resize(): Resizes the array when the maximum capacity is reached. The growth factor is 
two, therefore, it will each time double the capacity of the array.
Your task is to write a derived class called DynamicArrayWithStats which will implement the 
following functions:

int max(): Returns the maximum element in the dynamic array.
int min(): Returns the minimum element present in the dynamic array.
int mean(): Finds the mean value from the elements in the array and returns it.
Input
The input will be an integer and it will be given using the append() function. The get() function 
will be used to print the values in the dynamic array. Then, all functions of the DynamicArrayWithStats 
class will be called.

Sample Input
We want to execute the following instructions:

    DynamicArrayWithStats arr = DynamicArrayWithStats();
    arr.append(2);
    arr.append(6);
    arr.append(4);
    arr.append(1);
    arr.append(3);

    cout << "Array: ";
    for(int i = 0; i < arr.length(); i++){
        cout << arr.get(i) << " ";
    }
    cout << endl;
    
    cout << "Max: " << arr.max() << endl;
    cout << "Min: " << arr.min() << endl;
    cout << "Mean: " << arr.mean() << endl;
Expected Output
The following is the correct output:

Array: 2 6 4 1 3 
Max: 6
Min: 1
Mean: 3
Coding Exercise
Implement the code in the problem tab.

Good Luck!

Solution Review
We have implemented a class called DynamicArrayWithStats and inherited it publicly from the 
DynamicArray class.
The DynamicArrayWithStats class has a public function called max() that finds the maximum 
element of the array. It uses get() function of DynamicArray to search through all elements 
of the array by index.
The min() function in DynamicArrayWithStats class finds the minimum element of the array. 
It also uses get() function of DynamicArray class.
The mean() function makes first calculates the sum of all elements and then calls length() to 
find the size of the array. The sum is divided by the size to find the mean value.

*/

#include <iostream>
#include <assert.h>
using namespace std;


class DynamicArray {

    int *array;
    int capacity = 2;
    int size;

public:
    DynamicArray() {
        array = new int[capacity];
        size = 0;
    }

    void append(int element) {
        insertAt(element, size);
    }

    int length() {
        return size;
    }

    int get(int pos) {
        return array[pos];
    }

    ~DynamicArray() {
        delete[] array;
    }

private:
    void insertAt(int element, int pos) {
        assert(0 <= pos && pos <= size);
        if(size == capacity) {
            resize();
        }
        for(int i = size; i > pos; i--) {
            array[i] = array[i-1];
        }
        size++;
        array[pos] = element;
    }

    void resize() {
        capacity *= 2;
        int *temp = new int[capacity];
        copy(array, array + size, temp);
        delete [] array;
        array = temp;
    }

};

class DynamicArrayWithStats : public DynamicArray {
public:
    int max(){
        int max = get(0);
        for (int i = 1; i < length(); i++){
            if (get(i) > max)
                max = get(i);
        }
        return max;
    }
    int min(){
        int min = get(0);
        for (int i = 1; i < length(); i++){
            if (get(i) < min)
                min = get(i);
        }
        return min;
    }
    int mean(){
        int sum = 0;
        for (int i = 0; i < length(); i++){
            sum += get(i);
        }
        int mean = sum/length();
        return mean;
    }
};

int main() {
    
    DynamicArrayWithStats arr = DynamicArrayWithStats();
    arr.append(2);
    arr.append(6);
    arr.append(4);
    arr.append(1);
    arr.append(3);

    cout << "Array: ";
    for(int i = 0; i < arr.length(); i++){
        cout << arr.get(i) << " ";
    }
    cout << endl;
    
    cout << "Max: " << arr.max() << endl;
    cout << "Min: " << arr.min() << endl;
    cout << "Mean: " << arr.mean() << endl;
    return 0;
}

// Array: 2 6 4 1 3 
// Max: 6
// Min: 1
// Mean: 3
