#ifndef _INTARRAY_H_
#define _INTARRAY_H_

class IntArray
{
private:
    int m_length;
    int* m_pointer;
public:
    // constructor
    IntArray(int len);

    // copy constructor
    IntArray(const IntArray& obj);

    // public APIs for set/get/access
    int length();
    bool get(int index, int& value);
    bool set(int index ,int value);
    void free();
};

#endif
