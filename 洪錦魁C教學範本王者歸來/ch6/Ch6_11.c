/*   程式名稱 : ch6_11.c                  */
/*   資料對調函數設計                     */
#include <stdio.h>
#include <stdlib.h>
void swap(x,y)
int *x,*y;
{
    int tmp;

    tmp = *x;
    *x = *y;
    *y = tmp;
}
int main()
{
    int i,j;

    i = 5;
    j = 6;
    printf("呼叫 swap 前\n");
    printf("i = %d,    j = %d \n",i,j);
    swap(&i,&j);
    printf("呼叫 swap 後\n");
    printf("i = %d,    j = %d \n",i,j);
    system("pause");
    return 0;
}
