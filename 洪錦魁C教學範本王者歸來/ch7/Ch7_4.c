/*   祘Α嘿 : ch7_4.c                   */
/*   ―皚程ㄧ计                     */
#include <stdio.h>
#include <stdlib.h>
int maximum( int var[], int number )
{
    int max, i;
    max = var[0];           /* 既﹚皚材程 */ 
    for ( i = 0; i < number; i++ )
    {
       if ( var[i] > max )  /* 狦皚既﹚程 */ 
          max = var[i];     /* 砞﹚穝程 */ 
    }
    return max;
}
int main()
{
    static int array1[5] = { 134, 211, 122, 333, 237 };
    static int array2[4] = { 132, 123, 37, 98 };

    printf("皚 array1 程琌 %d \n",maximum(array1,5));
    printf("皚 array2 程琌 %d \n",maximum(array2,4));
    system("pause");
    return 0;
}
