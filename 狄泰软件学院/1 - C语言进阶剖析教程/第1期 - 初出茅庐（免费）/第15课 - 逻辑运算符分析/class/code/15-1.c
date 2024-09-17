#include <stdio.h>

int main()
{
    int i = 0;
    int j = 0;
    int k = 0;
    
    // 逻辑或运算符的优先级低于逻辑与运算符
    // i = 0 || 1 && 0 || 0;
    ++i || ++j && ++k;

    // The code demonstrates the precedence and "short-circuit behavior" of logical operators in C. 
    // The expression ++i || ++j && ++k results in i being incremented to 1, while j and k remain 0 
    // because the right side of the || operator is not evaluated.
    printf("%d\n", i);  // 1
    printf("%d\n", j);  // 0
    printf("%d\n", k);  // 0
    
    return 0;
}
