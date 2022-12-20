/*

https://www.educative.io/module/lesson/oop-in-cpp/q2W2k05LxmG

Override and Final
In this lesson, we'll discuss override and final in detail.

We'll cover the following

override
override
final
override 
The override keyword in a method declaration expresses that the method should override a virtual 
method of a base class. The compiler checks this assertion. It checks the parameter of the method, 
the return type of the method, and qualifiers like const and volatile. Of course, the compiler 
notices if the overridden method is not virtual.

The compiler verifies if the override annotated method actually overrides a virtual method of a 
base class.

The compiler checks for
The parameters and the return type.
The constness of the method.
The virtuality of the method.
The compiler ensures that the programmer obeys the contract.

By using the context-sensitive keywords override and final, we can explicitly manage the overriding 
of virtual functions. In particular, the keyword override solves a common bug present in object 
hierarchies: methods that should override methods of base classes but do not. The result is a syntactically 
but not semantically correct program. The program performs the wrong actions in the right way.

override 
To override a method, the signature of the overridden method of the base class has to match exactly. 
Although this sounds easy in theory, it is often not in practice. If the signature of the method does 
not match exactly, the program will compile but have the wrong behavior… A different method than intended 
will be invoked.

final 
final supports two use cases. First, we can declare a method that cannot be overridden; second, we can 
define a class that cannot be derived from. The compiler uses the same rules to determine if a method 
of child class overrides a method of a base class. Of course, the strategy is inverted because the final 
specifier should disallow the overriding of a method. Therefore, the compiler checks the parameters of 
the method, its return type, and any const/volatile qualifiers.

A virtual method declared final must not be overridden.

The compiler checks for
The parameter.
The return type.
The constness of the method.
Methods and classes declared as final are an optimization opportunity for the compiler.
Both variants are equivalent:
void func() final;
virtual void func() final override;
The compiler ensures that the programmer obeys the contract.

To learn more about override, click here.

To learn more about final, click here.


https://en.cppreference.com/w/cpp/language/override

override specifier (since C++11)
 C++ C++ language Classes 
Specifies that a virtual function overrides another virtual function.

Syntax
The identifier override, if used, appears immediately after the declarator in the syntax of a member function 
declaration or a member function definition inside a class definition.

declarator virt-specifier-seq(optional) pure-specifier(optional)	(1)	
declarator virt-specifier-seq(optional) function-body	(2)	
1) In a member function declaration, override may appear in virt-specifier-seq immediately after the declarator, 
and before the pure-specifier, if used.
2) In a member function definition inside a class definition, override may appear in virt-specifier-seq immediately 
after the declarator and just before function-body.
In both cases, virt-specifier-seq, if used, is either override or final, or final override or override final.

Explanation
In a member function declaration or definition, override specifier ensures that the function is virtual and is 
overriding a virtual function from a base class. The program is ill-formed (a compile-time error is generated) 
if this is not true.

override is an identifier with a special meaning when used after member function declarators: it's not a reserved 
keyword otherwise.

*/

#include <iostream>
 
struct A
{
    virtual void foo();
    void bar();
    virtual ~A();
};
 
// member functions definitions of struct A:
void A::foo() { std::cout << "A::foo();\n"; }
A::~A() { std::cout << "A::~A();\n"; }
 
struct B : A
{
//  void foo() const override; // Error: B::foo does not override A::foo
                               // (signature mismatch)
    void foo() override; // OK: B::foo overrides A::foo
//  void bar() override; // Error: A::bar is not virtual
    ~B() override; // OK: `override` can also be applied to virtual
                   // special member functions, e.g. destructors
    void override(); // OK, member function name, not a reserved keyword
};
 
// member functions definitions of struct B:
void B::foo() { std::cout << "B::foo();\n"; }
B::~B() { std::cout << "B::~B();\n"; }
void B::override() { std::cout << "B::override();\n"; }
 
int main() {
    B b;
    b.foo();
    b.override(); // OK, invokes the member function `override()`
    int override{42}; // OK, defines an integer variable
    std::cout << "override: " << override << '\n';
}

// B::foo();
// B::override();
// override: 42
// B::~B();
// A::~A();
