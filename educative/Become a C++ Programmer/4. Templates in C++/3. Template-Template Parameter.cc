/*

https://www.educative.io/module/lesson/templates-in-cpp/mEZyOPn3BMG

We have declared a Matrix class which contains a function, i.e., getSize, and an explicit constructor that prints 
all entries of the passed parameter. Cont in line 8 is a template, which takes two arguments. There��s no need for 
us to name the template parameters in the template declaration. We have to specify them in the instantiation of the 
template (line 19). The template used in the template parameter has exactly the signature of the sequence containers. 
The result is, that we can instantiate a matrix with an std::vector, or an std::list. Of course std::deque and 
std::forward_list would also be possible. In the end, you have a Matrix, which stores its elements in a vector or 
in a list.

If you want to study more examples for template-template parameter, you can check container adaptors.

*/

// templateTemplateTemplatesParameter.cpp

#include <initializer_list>
#include <iostream>
#include <list>
#include <vector>

template <typename T, template <typename, typename> class Cont >
class Matrix{
public:
  explicit Matrix(std::initializer_list<T> inList): data(inList){
    for (auto d: data) std::cout << d << " ";
  }
  int getSize() const{
    return data.size();
  }

private:
  Cont<T, std::allocator<T>> data;

};

int main(){

  std::cout << std::endl;

  Matrix<int,std::vector> myIntVec{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  std::cout << std::endl;
  std::cout << "myIntVec.getSize(): " << myIntVec.getSize() << std::endl;

  std::cout << std::endl;

  Matrix<double,std::vector> myDoubleVec{1.1, 2.2, 3.3, 4.4, 5.5};
  std::cout << std::endl;
  std::cout << "myDoubleVec.getSize(): "  << myDoubleVec.getSize() << std::endl;

  std::cout << std::endl;

  Matrix<std::string,std::list> myStringList{"one", "two", "three", "four"};
  std::cout << std::endl;
  std::cout << "myStringList.getSize(): " << myStringList.getSize() << std::endl;

  std::cout << std::endl;
}

// 1 2 3 4 5 6 7 8 9 10 
// myIntVec.getSize(): 10
//
// 1.1 2.2 3.3 4.4 5.5 
// myDoubleVec.getSize(): 5
//
// one two three four 
// myStringList.getSize(): 4
