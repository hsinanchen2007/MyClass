#include <stdio.h>

int main()
{
    /*
     * 接收用户输入的三个整数，排序后输出
     *
     * 5, 3, 2 按照升序排序
     */
    // 1.提示用户输入三个整数
    printf("请输入三个整数, 以逗号隔开, 以回车结束\n");
    // 2.定义三个变量保存用户输入的数据
    int a, b, c;
    // 3.接收用户输入的数据
    scanf("%i,%i,%i", &a, &b, &c);

    printf("a = %i, b = %i, c = %i\n", a, b, c);

    // 4.1用a和b进行比较, 如果a>b就交换a和b保存的数据
    if(a > b){
        int temp = a;
        a = b;
        b = temp;
    }
    // 4.2用b和c进行比较, 如果b>c就交换b和c保存的数据
    if(b > c){
        int temp = b;
        b = c;
        c = temp;
    }
    // 4.3用a和b进行比较, 如果a>b就交换a和b保存的数据
    if(a > b){
        int temp = a;
        a = b;
        b = temp;
    }
    printf("a = %i, b = %i, c = %i\n", a, b, c);
    return 0;
}
