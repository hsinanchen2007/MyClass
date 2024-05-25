#include <stdio.h>

int main()
{
    int i = 0;  // 局部变量

    while( i < 5 )
    {
        int j = 10;  // 局部变量

        j++;

        printf("j = %d\n", j);

        i++;
    }

    printf("i = %d\n", i);  // var = 10;

    return 0;
}
