#include <stdio.h>

int main()
{
    char buf[10] = {0};
    char src[] = "hello %s";
    
    // snprintf 函数本身是可变参数函数，原型如下：
    // int snprintf( char* buffer, int buf_size, const char* fomart, ... )
    // 当函数只有 3 个参数时，如果第三个参数没有包含格式化信息，函数调用没有问题；
    // 相反，如果第三个参数包含了格式化信息，但缺少后续对应参数，则程序行为不确定。
    // 格式化信息必须与变参个数相匹配。
    snprintf(buf, sizeof(buf), src);    // 未指定参数，会导致缓冲区溢出
    
    printf("buf = %s\n", buf);          // 输出结果不确定
    
    return 0;
}
