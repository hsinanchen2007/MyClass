/*

https://www.educative.io/module/lesson/cpp-standard-library/qVvyxwYv0jG

Introduction
To be honest, std::weak_ptr is not a classic smart pointer, since it supports no transparent access 
to the resource; it only borrows the resource from an std::shared_ptr.

Methods
The table provides an overview of the methods of std::weak_ptr.

Name	Description
    expired	Checks if the resource was deleted.
    lock	Creates a std::shared_ptr on the resource.
    reset	Resets the resource.
    swap	Swaps the resources.
    use_count	Returns the value of the reference counter.
Methods of std::weak_ptr

There is one main reason for the existence and use of std::weak_ptr. It breaks the cycle of std::shared_ptr. 
We will discuss these cyclic references in detail in the next lessons.

Explanation 
In line 11, we create an std::weak_ptr that borrows the resource from the std::shared_ptr.

The output of the program shows that the reference counter is 1 (line 13 and 14), meaning that std::weak 
does not increment the counter.

The call weakPtr.expired() checks if the resource was already deleted. That is equivalent to the expression 
weakPtr.use_count() == 0.

If the std::weak_ptr shared a resource, we could use weakPtr.lock() at line 17 to create an std::shared_ptr 
out of it.

The reference counter will now be increased to 2 (line 18). After resetting the weakPtr (line 25), the call 
weakPtr.lock() fails.

That was almost the whole story for the std::weak_ptr. Almost, because the std::weak_ptr has a special job: 
it helps to break the cyclic references of std::shared_ptr.

*/

// weakPtr.cpp

#include <iostream>
#include <memory>

int main(){

  std::cout << std::boolalpha << std::endl;

  auto sharedPtr=std::make_shared<int>(2011);
  std::weak_ptr<int> weakPtr(sharedPtr);
  
  std::cout << "weakPtr.use_count(): " << weakPtr.use_count() << std::endl;
  std::cout << "sharedPtr.use_count(): " << sharedPtr.use_count() << std::endl;
  std::cout << "weakPtr.expired(): " << weakPtr.expired() << std::endl;

  if( std::shared_ptr<int> sharedPtr1 = weakPtr.lock() ) {
    std::cout << "*sharedPtr: " << *sharedPtr << std::endl;
    std::cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << std::endl;
  }
  else{
    std::cout << "Don't get the resource!" << std::endl;
  }

  weakPtr.reset();
  if( std::shared_ptr<int> sharedPtr1 = weakPtr.lock() ) {
    std::cout << "*sharedPtr: " << *sharedPtr << std::endl;
    std::cout << "sharedPtr1.use_count(): " << sharedPtr1.use_count() << std::endl;
  }
  else{
    std::cout << "Don't get the resource!" << std::endl;
  }

  std::cout << std::endl;

}

// weakPtr.use_count(): 1
// sharedPtr.use_count(): 1
// weakPtr.expired(): false
// *sharedPtr: 2011
// sharedPtr1.use_count(): 2
// Don't get the resource!
