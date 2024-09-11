#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* p = malloc(4); // 从堆空间申请 4 个字节当作 int 类型的变量使用

    if( p != NULL )  // 如果申请失败 p 为 0 ，即：空值
    {
        *p = 100;

        printf("%d\n", *p);     // 100

        free(p);
    }

    p = malloc(4 * sizeof(int));

    if( p != NULL )
    {
        int i = 0;

        for(i=0; i<4; i++)
        {
            p[i] = i * 10;
        }

        // 0 10 20 30
        for(i=0; i<4; i++)
        {
            printf("%d\n", p[i]);
        }

        free(p);
    }

    return 0;
}
