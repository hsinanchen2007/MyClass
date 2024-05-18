using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _007
{
    class Program
    {
        static void Main(string[] args)
        {
            //定义三个整型变量
            int a = 2;
            int b = 3;
            int c = 0;//结果

            //加法      
            c = a + b;
            Console.WriteLine("{0} + {1} = {2}   ", a , b, c);
            //减法      
            c = a - b;
            Console.WriteLine("{0} -  {1} = {2}   ", a, b, c);
            //乘法 *     
            c = a * b;
            Console.WriteLine("{0} *  {1} = {2}   ", a, b, c);
            //除法 /     ,整数的除法，结果是整数
            c = a / b;
            Console.WriteLine("{0} /  {1} = {2}   ", a, b, c);

            double a1 = 2.0;
            double b1 = 3.0;
            double c1 = 0;
            //除法 /     ,小数的除法，结果是小数
            c1 = a1 / b1;
            Console.WriteLine("{0} /  {1} = {2}   ", a1, b1, c1);


            //取余
            c = a % b;
            Console.WriteLine("{0} % {1} = {2}   ", a, b, c);


        }
    }
}
