#include <stdio.h>

int main()
{
    int a[] = {1, 2, 3, 4, 5};
    int* p = a;
    int i = 0;

    // a[i] <==> *(a+i) <==> *(p+i) <==> p[i]

    for(i=0; i<5; i++)
    {
        printf("%d, %d\n", a[i], *(a + i));
    }

    for(i=0; i<5; i++)
    {
        printf("%d, %d\n", a[i], p[i]);
    }

    for(i=0; i<5; i++)
    {
        printf("%d, %d\n", p[i], *(p + i));
    }

    printf("a = %p, p = %p\n", a, p);       // a = 00D8FBE0, p = 00D8FBE0, 
                                            // a and p are pointers, and they pointed to same address

    printf("&a = %p, &p = %p\n", &a, &p);   // &a = 00D8FBE0, &p = 00D8FBD8, 
                                            // a and p are different variables, so their addresses will be different

    return 0;
}
