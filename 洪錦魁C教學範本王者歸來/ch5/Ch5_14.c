/*   程式名稱 : ch5_14.c                  */
/*   雙重指標的簡單應用                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p, **ptr;
    int n = 10; 
    int m = 20;             

    p = &n;
    ptr = &p;
    printf("n=%d   n位址=%d \n",n,&n);
    printf("*p=%d  p內容=%d   p位址=%d\n",*p,p,&p);
    printf("**ptr=%d ptr內容=%d ptr位址=%d\n",**ptr,ptr,&ptr);
    **ptr = m;     /* 直接設定雙重指標的值 */ 
    printf("m=%d  **ptr=%d\n",m,**ptr); 
    system("pause");
    return 0;    
}
