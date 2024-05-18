
#include <stdio.h>

int main()
{
    //定义一个学生结构体类型
    struct Student
    {
        int id;//学号
        char name[20];//姓名
        int   age;//年龄
    };

    //定义结构体类型的变量,并且初始化
    struct Student  stu = { 1000,"张三",12 };

    printf("学号:%d   姓名:%s   年龄:%d  \n", stu.id, stu.name, stu.age);

    stu.age = 16;//给成员赋值

    printf("学号:%d   姓名:%s   年龄:%d  \n", stu.id, stu.name, stu.age);

    //结构体变量占得字节数 = 各个成员占字节数的和
    printf("字节数 %d\n", sizeof(struct Student)); // 4+20*1+4
 
     
}
