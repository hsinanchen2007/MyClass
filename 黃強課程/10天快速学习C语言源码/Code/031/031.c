
#include <stdio.h>

int main()
{
    int a = 10;
    int b = 20;
    int c = 30;
    //需要三个指针值（地址）
   
    int* arr[3] = {  &a,&b,&c }  ;
    //指针数组，每个元素都是指针值

    for (int i = 0; i < 3; ++i)
    {
        printf("%p    %d \n", arr[i] , *arr[i]);
    }

}
