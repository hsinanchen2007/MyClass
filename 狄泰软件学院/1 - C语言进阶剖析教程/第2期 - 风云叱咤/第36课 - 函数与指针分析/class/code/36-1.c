#include <stdio.h>

typedef int(FUNC)(int);

int test(int i)
{
    return i * i;
}

void f()
{
    printf("Call f()...\n");
}

int main()
{
    // 經由函數定義去定義函數指針, test本身就是函數指針
    FUNC* pt = test;

    // 直接定義函數指針, 也可以這樣寫
    void(*pf)() = &f;
    
    printf("pf = %p\n", pf);            // pf = 009B3E4F
    printf("f = %p\n", f);              // f = 009B3E4F
    printf("&f = %p\n", &f);            // &f = 009B3E4F
    
    pf();                               // Call f()...
    
    (*pf)();                            // Call f()...
    
    printf("Function pointer call: %d\n", pt(2));   // Function pointer call: 4
    
    return 0;
}

