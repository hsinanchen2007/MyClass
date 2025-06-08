/*   程式名稱 : ch7_3.c                   */
/*   static 靜態變數宣告應用              */
#include <stdio.h>
#include <stdlib.h>
void varfunction()
{
    int var = 0;
    static int static_var = 0;

    printf("var = %d \n",var);
    printf("靜態 static static_var = %d \n",static_var);
    printf("\n");
    var++;
    static_var++;
}
int main()
{
    int  i;

    for ( i = 0; i < 3; i++ )
       varfunction();
    system("pause");
    return 0;
}
