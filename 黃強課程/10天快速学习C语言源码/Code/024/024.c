 
#include <stdio.h>

int main()
{
    //测试指针类型占的字节数 ，凡是指针类型，一律占4字节
    printf("字符指针类型 char * 占 %d 字节\n", sizeof(char*));
    printf("短整型指针类型 short * 占 %d 字节\n", sizeof(short*));
    printf("整型指针类型 int  * 占 %d 字节\n", sizeof(int *));
    printf("长整型指针类型 long * 占 %d 字节\n", sizeof(long*));
    printf("单精度浮点型指针类型 float * 占 %d 字节\n", sizeof(float*));
    printf("双精度浮点型指针类型 double * 占 %d 字节\n", sizeof(double*));

}
 