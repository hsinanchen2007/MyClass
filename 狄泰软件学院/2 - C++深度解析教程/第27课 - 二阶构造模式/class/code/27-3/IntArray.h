#ifndef _INTARRAY_H_
#define _INTARRAY_H_

class IntArray
{
private:
    int m_length;
    int* m_pointer;
    
    // Note that the constructors are private
    // not public, so we will rely on the public
    // static member function "NewInstance()" 
    // to create the class object and check if 
    // the given class object is created successfully
    // or not
    IntArray(int len);
    IntArray(const IntArray& obj);

    bool construct();
public:
    // public API to create and check the 
    // class object is being created properly
    // or not
    static IntArray* NewInstance(int length); 

    int length();
    bool get(int index, int& value);
    bool set(int index ,int value);
    ~IntArray();
};

#endif
