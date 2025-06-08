/*   祘Α嘿 : ch11_8.c                  */
/*   ~ ( 1 干计 ) 笲衡                  */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int  a, b;

    a = 234;
    b = ~a;
    printf("a  1 干计 ( 10 秈) = %d \n",b);
    a = ~a;
    printf("a  1 干计 ( 16 秈) = %x \n",a);
    system("pause");
    return 0;
}
