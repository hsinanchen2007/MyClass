/*   程式名稱 : ch6_10.c                  */
/*   傳遞二維陣列                         */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int num[3][4] = {
                     { 88, 79, 91, 0 },
                     { 86, 84, 90, 0 },
                     { 77, 65, 70, 0 } };
    void average();
    int i,j;

    average(num,3);
    for ( i = 0; i < 3; i++ )   /* 列印新的陣列 */ 
    {
       for ( j = 0; j < 4; j++ )
          printf("%5d",num[i][j]);
       printf("\n");
    }
    system("pause");
    return 0;   
}
void average(var,length)
int var[][4],length;
{
    int sum,i,j;

    for ( i = 0; i < length; i++ )
    {
       sum = 0;
       for ( j = 0; j < 4; j++ )
          sum += var[i][j];
       var[i][3] = sum / 3;   /* 平均值放入各列最右 */ 
    }
}
