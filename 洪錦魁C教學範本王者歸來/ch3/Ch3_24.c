/*   程式名稱 : ch3_24.c                  */
/*   特殊運算子運算                       */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a,b,c,d,e;

    a = b = c = d = e = 0;
    a += 2;
    printf("a = %d\n",a);

    b -= 2;
    printf("b = %d\n",b);

    c *= c = 2;
    printf("c = %d\n",c);

    d %= d = 3;
    printf("d = %d\n",d);

    e /= e = 4;
    printf("e = %d\n",e);
    system("pause");
    return 0;
}
