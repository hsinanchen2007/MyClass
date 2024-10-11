#include <stdio.h>

// 定義數組類型
typedef int(AINT5)[5];
typedef float(AFLOAT10)[10];
typedef char(ACHAR9)[9];

int main()
{
    AINT5 a1;
    float fArray[10];
    AFLOAT10* pf = &fArray;
    ACHAR9 cArray;

    // 定義指向數組的指針
    char(*pc)[9] = &cArray;
    char(*pcw)[4] = cArray;
    
    int i = 0;
    
    printf("%d, %d\n", sizeof(AINT5), sizeof(a1));  // 20, 20
    
    for(i=0; i<10; i++)
    {
        (*pf)[i] = i;                               // 給數組賦值, 這裡的 pf 是指向 fArray 數組的指針
    }
    
    for(i=0; i<10; i++)
    {
        printf("%f\n", fArray[i]);
    }
    
    printf("%p, %p, %p\n", &cArray, pc+1, pcw+1);   // pc + 1 = (unsigned int)&cArray + 9 * sizeof(*pc) 
                                                    // pcw + 1 = (unsigned int)cArray + 4 * sizeof(*pcw)
                                                    // 0117FEDC, 0117FEE5, 0117FEE0

    printf("%p, %p\n", cArray, pc);                 // 0117FEDC, 0117FEDC
    printf("%p, %p\n", &cArray, &pc);               // 0117FEDC, 0117FEAC, pc 是指向 cArray 數組的指針, 所以 &pc 是指針pc的地址
    printf("%p, %p\n", (&cArray + 1), (pc + 1));    // 0117FEE5, 0117FEE5 
                                                    // cArray 是數組名, 所以 &cArray + 1 是 cArray 數組的下一個地址
                                                    // pc 是指向 cArray 數組的指針, 所以 pc + 1 是指向 cArray 數組的下一個地址

    return 0;
}

