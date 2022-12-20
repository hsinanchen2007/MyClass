/*

https://www.educative.io/module/lesson/oop-in-cpp/JPoj43YPKxl

Explanation
We have implemented two classes named Sort and QuickSort.

We have created three private virtual methods and a public virtual method processData 
in the Sort class which calls the three private methods.

The QuickSort class publicly inherits from the Sort class.

We have overridden the methods of the Sort class in QuickSort.

By using a pointer to the Base class, we can access the overridden methods of the derived 
class.

*/

#include <iostream>

class Sort{
public:
  virtual void processData(){
    readData();
    sortData();
    writeData();
  }
private:
  virtual void readData(){}
  virtual void sortData() = 0;
  virtual void writeData(){}
};


class QuickSort: public Sort{
private:
  void readData(){
    std::cout << "readData" << std::endl;
  }
  void sortData(){
    std::cout <<  "sortData" << std::endl;
  }
  void writeData(){
    std::cout << "writeData" << std::endl;
  }
};


int main(){

  std::cout << std::endl;

  Sort* sort = new QuickSort;
  sort->processData();

  std::cout << std::endl;

}

// readData
// sortData
// writeData
