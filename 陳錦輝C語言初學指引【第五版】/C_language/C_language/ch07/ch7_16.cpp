/*    檔名:ch7_16.cpp    功能:傳參考呼叫     */

#include <stdio.h>
#include <stdlib.h>

void func1(int &a,int b)
{
 a=a+10;
 b=b+100;
 printf("func1()的a=%d\n",a);
 printf("func1()的a記憶體位址=%X\n",&a);
 printf("func1()的b=%d\n", b);
}

int main(void)
{
 int m=1,n=1;
 func1(m,n);
 printf("main( )的m=%d\n",m);
 printf("main( )的m記憶體位址=%X\n",&m);
 printf("main( )的n=%d\n",n);
 /*  system("pause");  */
 return 0;
}
