/*

https://en.cppreference.com/w/cpp/utility/optional

std::optional
 C++ Utilities library std::optional 
Defined in header <optional>
template< class T >
class optional;
(since C++17)
The class template std::optional manages an optional contained value, i.e. a value that may or 
may not be present.

A common use case for optional is the return value of a function that may fail. As opposed to 
other approaches, such as std::pair<T,bool>, optional handles expensive-to-construct objects 
well and is more readable, as the intent is expressed explicitly.

Any instance of optional<T> at any given point in time either contains a value or does not contain 
a value.

If an optional<T> contains a value, the value is guaranteed to be allocated as part of the optional 
object footprint, i.e. no dynamic memory allocation ever takes place. Thus, an optional object models 
an object, not a pointer, even though operator*() and operator->() are defined.

When an object of type optional<T> is contextually converted to bool, the conversion returns true 
if the object contains a value and false if it does not contain a value.

The optional object contains a value in the following conditions:

The object is initialized with/assigned from a value of type T or another optional that contains a value.
The object does not contain a value in the following conditions:

The object is default-initialized.
The object is initialized with/assigned from a value of type std::nullopt_t or an optional object that 
does not contain a value.

The member function reset() is called.
There are no optional references; a program is ill-formed if it instantiates an optional with a reference 
type. Alternatively, an optional of a std::reference_wrapper of type T may be used to hold a reference. 
In addition, a program is ill-formed if it instantiates an optional with the (possibly cv-qualified) tag 
types std::nullopt_t or std::in_place_t.

Template parameters
T	-	the type of the value to manage initialization state for. The type must meet the requirements of 
Destructible (in particular, array and reference types are not allowed).
Member types
Member type	Definition
value_type	T
Member functions
(constructor)
 
constructs the optional object
(public member function)
(destructor)
 
destroys the contained value, if there is one
(public member function)
operator=
 
assigns contents
(public member function)
Observers
operator->
operator*
 
accesses the contained value
(public member function)
operator bool
has_value
 
checks whether the object contains a value
(public member function)
value
 
returns the contained value
(public member function)
value_or
 
returns the contained value if available, another value otherwise
(public member function)
Monadic operations
and_then
  
(C++23)
 
returns the result of the given function on the contained value if it exists, or an empty optional otherwise
(public member function)
transform
  
(C++23)
 
returns an optional containing the transformed contained value if it exists, or an empty optional otherwise
(public member function)
or_else
  
(C++23)
 
returns the optional itself if it contains a value, or the result of the given function otherwise
(public member function)
Modifiers
swap
 
exchanges the contents
(public member function)
reset
 
destroys any contained value
(public member function)
emplace
 
constructs the contained value in-place
(public member function)
Non-member functions
operator==
operator!=
operator<
operator<=
operator>
operator>=
operator<=>
  
(C++17)
(C++17)
(C++17)
(C++17)
(C++17)
(C++17)
(C++20)
 
compares optional objects
(function template)
make_optional
  
(C++17)
 
creates an optional object
(function template)
std::swap(std::optional)
  
(C++17)
 
specializes the std::swap algorithm
(function template)
Helper classes
std::hash<std::optional>
  
(C++17)
 
specializes the std::hash algorithm
(class template specialization)
nullopt_t
  
(C++17)
 
indicator of optional type with uninitialized state
(class)
bad_optional_access
  
(C++17)
 
exception indicating checked access to an optional that doesn't contain a value
(class)

*/

#include <string>
#include <functional>
#include <iostream>
#include <optional>
 
// optional can be used as the return type of a factory that may fail
std::optional<std::string> create(bool b) {
    if (b)
        return "Godzilla";
    return {};
}
 
// std::nullopt can be used to create any (empty) std::optional
auto create2(bool b) {
    return b ? std::optional<std::string>{"Godzilla"} : std::nullopt;
}
 
// std::reference_wrapper may be used to return a reference
auto create_ref(bool b) {
    static std::string value = "Godzilla";
    return b ? std::optional<std::reference_wrapper<std::string>>{value}
             : std::nullopt;
}
 
int main()
{
    std::cout << "create(false) returned "
              << create(false).value_or("empty") << '\n';
 
    // optional-returning factory functions are usable as conditions of while and if
    if (auto str = create2(true)) {
        std::cout << "create2(true) returned " << *str << '\n';
    }
 
    if (auto str = create_ref(true)) {
        // using get() to access the reference_wrapper's value
        std::cout << "create_ref(true) returned " << str->get() << '\n';
        str->get() = "Mothra";
        std::cout << "modifying it changed it to " << str->get() << '\n';
    }
}

// create(false) returned empty
// create2(true) returned Godzilla
// create_ref(true) returned Godzilla
// modifying it changed it to Mothra
