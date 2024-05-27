#include <stdio.h>

int main()
{
    // initialize int pointer as value 1
    int* pi = new int(1);

    // initialize int pointers in array with values
    int* pa = new int[10] {1,2,3,4,5,6,7,8,9,10};

    // initialize flow pointer as value 2.0f
    float* pf = new float(2.0f);

    // initialize char pointer as value "c"
    char* pc = new char('c');

    printf("*pi = %d\n", *pi);
    printf("*pf = %f\n", *pf);
    printf("*pc = %c\n", *pc);
    for (int i = 0; i < 10; i++) {
        printf("%d\n", pa[i]);
    }

    delete pi;
    delete pf;
    delete pc;
    delete[] pa;

    return 0;
}