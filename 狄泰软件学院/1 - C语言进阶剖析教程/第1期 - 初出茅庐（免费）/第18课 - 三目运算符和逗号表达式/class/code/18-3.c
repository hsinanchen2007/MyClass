#include <stdio.h>

void hello()
{
    printf("Hello!\n");
}

int main()
{   
    // 逗号表达式, ()中的表达式从左到右依次执行，
    // 整个表达式的值是最后一个表达式的值
    // so it becomes (2, 5, 8, 0, 0, 0, 0, 0, 0)
    int a[3][3] = {
        (0, 1, 2),
        (3, 4, 5),
        (6, 7, 8)
    };
    
    int i = 0;
    int j = 0;
    
    while( i < 5 )
        printf("i = %d\n", i),
        
    hello(),
    
    i++;
        
    for(i=0; i<3; i++)
    {
        for(j=0; j<3; j++)
        {
            printf("a[%d][%d] = %d\n", i, j, a[i][j]);
        }
    }

    return 0;
}

/*
    i = 0
    Hello!
    i = 1
    Hello!
    i = 2
    Hello!
    i = 3
    Hello!
    i = 4
    Hello!
    a[0][0] = 2
    a[0][1] = 5
    a[0][2] = 8
    a[1][0] = 0
    a[1][1] = 0
    a[1][2] = 0
    a[2][0] = 0
    a[2][1] = 0
    a[2][2] = 0
*/

