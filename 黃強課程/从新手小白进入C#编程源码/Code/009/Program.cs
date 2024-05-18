using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _009
{
    class Program
    {
        static void Main(string[] args)
        {
            //关系运算符

            //等于
            bool ret =  ( 2 == 3 );
            Console.WriteLine(" 2 == 3  结果为  "+  ret );
            //小于
            bool ret2 = (2  < 3);
            Console.WriteLine(" 2 < 3  结果为  " + ret2);
            //大于
            bool ret3 = (2 > 3);
            Console.WriteLine(" 2 > 3  结果为  " + ret3);
            //小于等于
            bool ret4 = (2 <= 3);
            Console.WriteLine(" 2 <= 3  结果为  " + ret4);
            //大于等于
            bool ret5 = (2 >= 3);
            Console.WriteLine(" 2 >= 3  结果为  " + ret5);
            //不等于
            bool ret6 = (2 != 3);
            Console.WriteLine(" 2 != 3  结果为  " + ret6);

        }
    }
}
