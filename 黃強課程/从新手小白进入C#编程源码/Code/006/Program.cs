using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _006
{
    class Program
    {
        static void Main(string[] args)
        {

            //定义一个常量
            const int a = 100; //常量一开始就必须有一个常量值

            //定义一个常量
            const int b = a;//用常量赋值常量

            //常量不能用变量赋值
            int d = 200; //变量
            //const int c = d;//用变量赋值是错误的

            //错误
            //b = 300;//常量一旦初始化，再也不能改变值了


        }
    }
}
