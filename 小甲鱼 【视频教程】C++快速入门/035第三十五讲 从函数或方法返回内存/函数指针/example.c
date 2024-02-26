#include <stdio.h>

int fun(int x, int y);

int main()
{
        int i,a,b;
        int (*p)();    /* 声明函数指针 */

        scanf("%d",&a);
        p = fun;            /* 给函数指针p赋值,使它指向函数f */

        printf("请输入是个数字: \n");
        for(i=0; i < 10; i++)
        {
                scanf("%d", &b);
                a = (*p)(a, b);    /* 通过指针p调用函数f */
        }

        printf("The Max Number is:%d", a);

        return 0;
}

fun(int x, int y)
{
    int z;

    z = (x > y) ? x : y;

    return(z);
}
