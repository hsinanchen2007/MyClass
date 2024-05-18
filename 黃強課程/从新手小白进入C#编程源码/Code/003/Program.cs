using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _003
{
    class Program
    {
        //有且仅有一个Main函数，因为是纯面向对象的，不能有全局函数，所以只能是类的静态函数
        //args 是程序运行的时候命令行用户传入的参数
        static void Main(string[] args)
        {
            //打印系统传给我们的参数args
            for(int i=0;i<args.Length;++i)
            {
                Console.WriteLine("第"+(i+1)+"个参数:  "+ args[i]);
            } 
        }
    }

    class Test
    {
/*        static void Main(string[] args)
        {
        }*/
    }
}
