#include <stdio.h>

int main()
{
    int i = 0;
    int* pI;
    char* pC;
    float* pF;
    
    pI = &i;
    
    *pI = 10;
    
    printf("%p, %p, %d\n", pI, &i, i);                          // 0x7ffebc1f4c14, 0x7ffebc1f4c14, 10   
    printf("%d, %d, %p\n", sizeof(int*), sizeof(pI), &pI);      // 4, 4, 00F7FECC
    printf("%d, %d, %p\n", sizeof(char*), sizeof(pC), &pC);     // 4, 4, 00F7FEC8
    printf("%d, %d, %p\n", sizeof(float*), sizeof(pF), &pF);    // 4, 4, 00F7FEC4
    
    return 0;
}
