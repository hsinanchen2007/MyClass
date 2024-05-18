using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _005
{
    class Program
    {
        static void Main(string[] args)
        {

            //定义变量
            char a='A' ;//定义一个字符类型的变量，好比一个盒子，占用了2个字节的内存空间

            //同时定义多个变量
            int   i =1, j=2, k=3;// i,j,k 三个盒子， 分别占用4,4,4字节的空间

            //不赋值的变量使用的时候会报错
            Console.WriteLine("{0}   {1}   {2}     {3}",  a, i ,  j, k);


            //先定义变量 
            double d;
            //再赋值
            d = 0.123;//往这个箱子里放入0.123 ，你还可以放其它值，所以叫变量

            Console.WriteLine("{0} ", d);

        }
    }
}
