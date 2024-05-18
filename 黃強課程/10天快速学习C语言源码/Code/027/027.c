
#include <stdio.h>

int main()
{
    int  arr[5] = { 1,2,3,4,5 };//定义一个一维数组，并且初始化

    int* p = arr;//不需要 & ，数组名就是数组的首地址 

    //指针变量p指向了数组的首地址
    //指针变量p可以当成数组名来使用
    for (int i = 0; i < 5; ++i)
    {
        printf("%d  ", p[i]);
    }

    printf("\n");

    //指针变量p+i  等价于  &arr[i]
    printf("%p   %p \n",  p+3 ,  &arr[3]);


    //使用++p  或者 --p可以移动指针，每次移动一个元素所占字节的大小
    // int *p ,那么++p移动 4个字节，   char * p  那么++p移动1个字节

    ++p;
    printf("%d  \n",  *p);

    ++p;
    printf("%d  \n", *p);

    --p;
    printf("%d  \n", *p);

   // ++arr; //数组名是一个存放首地址的常量，不允许改变的， 而++arr 的意思是  arr =arr+1，会改变值


}