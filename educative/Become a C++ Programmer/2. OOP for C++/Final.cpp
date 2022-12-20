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


https://en.cppreference.com/w/cpp/language/final

final specifier (since C++11)
 C++ C++ language Classes 
Specifies that a virtual function cannot be overridden in a derived class or that a class cannot be 
derived from.

Syntax
When applied to a member function, the identifier final appears immediately after the declarator in 
the syntax of a member function declaration or a member function definition inside a class definition.

When applied to a class, the identifier final appears at the beginning of the class definition, 
immediately after the name of the class.

declarator virt-specifier-seq(optional) pure-specifier(optional)	(1)	
declarator virt-specifier-seq(optional) function-body	(2)	
class-key attr(optional) class-head-name class-virt-specifier(optional) base-clause(optional)	(3)	
1) In a member function declaration, final may appear in virt-specifier-seq immediately after the 
declarator, and before the pure-specifier, if used.
2) In a member function definition inside a class definition, final may appear in virt-specifier-seq 
immediately after the declarator and just before function-body.
3) In a class definition, final may appear as class-virt-specifier immediately after the name of the 
class, just before the colon that begins the base-clause, if used.
In the cases (1,2), virt-specifier-seq, if used, is either override or final, or final override or 
override final. In the case (3), the only allowed value of class-virt-specifier, if used, is final

Explanation
When used in a virtual function declaration or definition, final specifier ensures that the function 
is virtual and specifies that it may not be overridden by derived classes. The program is ill-formed 
(a compile-time error is generated) otherwise.

When used in a class definition, final specifies that this class may not appear in the base-specifier-list 
of another class definition (in other words, cannot be derived from). The program is ill-formed otherwise 
(a compile-time error is generated). final can also be used with a union definition, in which case 
it has no effect (other than on the outcome of std::is_final) (since C++14), since unions cannot be 
derived from.

final is an identifier with a special meaning when used in a member function declaration or class head. 
In other contexts, it is not reserved and may be used to name objects and functions.

Note
In a sequence of the following tokens:

one of class, struct and union;
a possibly qualified identifier;
final;
one of : and {,
the third token final in the sequence is always considered as a specifier instead of an identifier:

*/

struct A;
struct A final {}; // OK, definition of struct A,
                   // not value-initialization of variable final
 
struct X
{
    struct C { constexpr operator int() { return 5; } };
    struct B final : C{}; // OK, definition of nested class B,
                          // not declaration of a bit-field member final
};
 
// Abnormal final usage.
 
struct final final // OK, definition of a struct named `final` from which
{                  // you cannot inherit
};
 
// struct final final {}; // Error: redefinition of `struct final`, NOT a
                          // definition of a variable `final` using an elaborated
                          // type specifier `struct final` followed by an
                          // aggregate initialization
 
// struct override : final {}; // Error: cannot derive from final base type;
                               // `override` in given context is a normal name
void foo()
{
    [[maybe_unused]]
    final final; // OK, declaration of a variable named `final` of type
                 // `struct final` 
}
 
struct final final; // OK, declaration of a variable named `final` of type
                    // `struct final` using an elaborated type specifier
int main()
{
}

/*
    struct Base
    {
        virtual void foo();
    };
    
    struct A : Base
    {
        void foo() final; // Base::foo is overridden and A::foo is the final override
        void bar() final; // Error: bar cannot be final as it is non-virtual
    };
    
    struct B final : A // struct B is final
    {
        void foo() override; // Error: foo cannot be overridden as it is final in A
    };
    
    struct C : B {}; // Error: B is final


    Possible output:

    main.cpp:9:10: error: 'void A::bar()' marked 'final', but is not virtual
        9 |     void bar() final; // Error: bar cannot be final as it is non-virtual
        |          ^~~
    main.cpp:14:10: error: virtual function 'virtual void B::foo()' overriding final function
    14 |     void foo() override; // Error: foo cannot be overridden as it is final in A
        |          ^~~
    main.cpp:8:10: note: overridden function is 'virtual void A::foo()'
        8 |     void foo() final; // Base::foo is overridden and A::foo is the final override
        |          ^~~
    main.cpp:17:8: error: cannot derive from 'final' base 'B' in derived type 'C'
    17 | struct C : B // Error: B is final
        |
*/

