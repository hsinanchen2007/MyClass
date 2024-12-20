/*
    在没有传递任何参数的情况下，成功地在print() 函数中打印出了main() 函数中arr 数组
    内的每个元素。现在来看看上面代码的实现方法，在print() 函数中定义了一个_ebp 无符号
    整型变量，通过VC++ 6.0 内嵌汇编把ebp 的值保持到_ebp 中，按照上面的分析，可以将在
    函数print() 中通过这条内嵌汇编语句得到的ebp 看成一个指针，指针所指向的单元存放的就
    是print() 函数的上一个函数的栈底，在此是main() 函数的栈底。知道了_ebp 的作用后，我
    们来分析下代码，通过(int*)_ebp 将_ebp 转换为一个整型指针，然后通过*(int*)_ebp 即可
    得到main() 函数的栈底地址。由于栈的压栈操作是从上到下、从右到左的，所以main() 函
    数中的变量a 先压栈，然后是b、c，最后是arr 数组，数组的压栈顺序是从右到左。通过“int
    *p=(int *)(*(int *)_ebp-4-4-4-7*4);”即可得到数组元素的首地址。接下来，根据首地址就可
    以取出数组中的每个元素了。有的读者可能会有一个疑惑，main() 函数中有一个字符型变
    量，是不是在求数组元素的首地址时应该把其中的减4 改为减1 呢？因为它只占用了一个字
    节！即将“int *p=(int *)(*(int *)_ebp-4-4-4-7*4);”修改为“int *p=(int *)(*(int *)_ebp-4-4-1-
    7*4)”。我们暂且不说其对与错，先来看看修改后的运行结果：
    3072 3328 3584 3840 4096 4352 -859021056
    我们发现这样的运行结果是错误的，为什么呢？细心的读者可能发现了本章一开始回顾的
    知识点中有一点是很重要的，那就是压栈操作为4 字节对齐。所以这里必须减4，而不是减1。
*/

#include <stdio.h>

void print()
{
    unsigned int _ebp;
    
    __asm {
        mov _ebp,ebp
    }

    // original code
    // int *p=(int *)(*(int *)_ebp-4-4-4-7*4);

    // works on my laptop, maybe due to 64bit compiler?
    int *p=(int *)(*(int *)_ebp-4-4-4-7*4+8);

    for(int i=0;i<7;i++)
        printf("%d\t",p[i]);
}

int main()
{
    int a=1;
    int b=2;
    char c='a';
    int arr[]={11,12,13,14,15,16,17};

    print();

    return 0;
}