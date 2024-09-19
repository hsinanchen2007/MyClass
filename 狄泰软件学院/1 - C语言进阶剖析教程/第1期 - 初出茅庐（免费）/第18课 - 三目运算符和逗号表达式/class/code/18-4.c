#include <stdio.h>
#include <assert.h>

int strlen(const char* s)
{  
    // below statement is equivalent to:
    // if(s == NULL)
    // {
    //     assert(s);
    // }
    // return (*s ? strlen(s + 1) + 1 : 0);

    return assert(s), (*s ? strlen(s + 1) + 1 : 0);
}

int main()
{   
    printf("len = %d\n", strlen("Delphi")); // len = 6
    printf("len = %d\n", strlen(NULL));     // Assertion failed: s, file D:\git\MyClass\狄泰软件学院\1 - C语言进阶剖析教程\第1期 - 初出茅庐（免费）\第18课 - 三目运算符和逗号表达式\class\code\18-4.c, line 6
    
    return 0;
}
