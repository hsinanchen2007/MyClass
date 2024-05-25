
struct Test
{
    int a;
    int b;
};

extern int g_var;   // 声明全局变量时，不需要给出初始值
extern int f_var;

int add(int a, int b);
int mul(int, int);   // 进行函数声明的时候，可以省略参数名

extern void test();
