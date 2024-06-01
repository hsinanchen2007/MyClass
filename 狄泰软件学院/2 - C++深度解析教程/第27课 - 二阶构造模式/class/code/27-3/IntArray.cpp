#include "IntArray.h"

// For 2 levels constructor
// 1. Have constructor and only initialize 
//    some data members which won't have any 
//    problem in general, like m_length
// 2. Have a seperate function to initialize
//    data members which may fail, like call
//    "new" or create/access outside data.
//    Both (1) and (2) are in private
// 3. From outside, like main(), call the
//    static member function to get the
//    return status. This one is public
//    API


// constructor here can only initialize
// members, not guarantee that this class
// object will be created properly or not
IntArray::IntArray(int len)
{
    m_length = len;
}

// main API to create and initialize the
// data member m_pointer, which may fail
// when memory is not enough
bool IntArray::construct()
{
    bool ret = true;
    
    // How to prevent fatal or issue below with "new"?
    // 1. By try {} catch {}
    // 2. By new (std::nothrow)
    // 3. Check its return pointer
    m_pointer = new int[m_length];
    
    if( m_pointer )
    {
        for(int i=0; i<m_length; i++)
        {
            m_pointer[i] = 0;
        }
    }
    else
    {
        ret = false;
    }
    
    return ret;
}

// The public API that can create and chceck
// whether the class object is created properly
// or not, by checking its return value
IntArray* IntArray::NewInstance(int length) 
{
    IntArray* ret = new IntArray(length);
    
    if( !(ret && ret->construct()) ) 
    {
        delete ret;
        ret = 0;
    }
        
    return ret;
}

int IntArray::length()
{
    return m_length;
}

bool IntArray::get(int index, int& value)
{
    bool ret = (0 <= index) && (index < length());
    
    if( ret )
    {
        value = m_pointer[index];
    }
    
    return ret;
}

bool IntArray::set(int index, int value)
{
    bool ret = (0 <= index) && (index < length());
    
    if( ret )
    {
        m_pointer[index] = value;
    }
    
    return ret;
}

IntArray::~IntArray()
{
    delete[]m_pointer;
}
