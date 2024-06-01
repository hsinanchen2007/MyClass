#include <stdio.h>
#include "IntArray.h"

int main()
{
    // when the value is too big, it will cause error
    // IntArray* a = IntArray::NewInstance(50000000000000);

    // when the value is small, it will be OK and work
    // as expected. Below code, we should still check the
    // returned a and see if it is NULL
    IntArray* a = IntArray::NewInstance(5);

    printf("a.length = %d\n", a->length());

    a->set(0, 1);

    for (int i = 0; i < a->length(); i++)
    {
        int v = 0;

        a->get(i, v);

        printf("a[%d] = %d\n", i, v);
    }

    delete a;

    return 0;
}
