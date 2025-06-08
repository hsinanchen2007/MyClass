/*   祘Α嘿 : ch6_9.c                   */
/*   ―皚程                         */
#include <stdio.h>
#include <stdlib.h>
int minimum(var)
int var[5];
{
    int min,i;

    min = var[0]; /* 既﹚皚材じ琌程 */ 
    for ( i = 0; i <= 4; i++ )
       if ( var[i] < min )  /* 璝ゑ程   */ 
          min = var[i];     /* 砞﹚穝程 */ 
    return min;             /* 肚程     */ 
}
int main()
{
    int array[5];
    int minimum_value;
    int i;

    for ( i = 0; i < 5; i++ )  /* 弄皚 */ 
    {
       printf("叫块计 %d ==> ",i+1);
       scanf("%d",&array[i]);
    }
    minimum_value = minimum(array);
    printf("程琌 %d \n",minimum_value);
    system("pause");
    return 0;
}
