/*   �{���W�� : ch5_14.c                  */
/*   �������Ъ�²������                   */
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int *p, **ptr;
    int n = 10; 
    int m = 20;             

    p = &n;
    ptr = &p;
    printf("n=%d   n��}=%d \n",n,&n);
    printf("*p=%d  p���e=%d   p��}=%d\n",*p,p,&p);
    printf("**ptr=%d ptr���e=%d ptr��}=%d\n",**ptr,ptr,&ptr);
    **ptr = m;     /* �����]�w�������Ъ��� */ 
    printf("m=%d  **ptr=%d\n",m,**ptr); 
    system("pause");
    return 0;    
}
