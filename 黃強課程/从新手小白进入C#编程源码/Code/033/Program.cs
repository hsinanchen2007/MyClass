using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _033
{
    //你可以枚举出来的常量值
    enum  Color
    {
        Red=1,
        Green = 2,
        Blue =100,
        Black , //前面的值自动+1     101
        White //102
    }


    class Program
    {
        static void Main(string[] args)
        {
            //定义枚举变量
            Color c = Color.White;

            Console.WriteLine("颜色是 " + c + "    "+ (int)c);

        }
    }
}
