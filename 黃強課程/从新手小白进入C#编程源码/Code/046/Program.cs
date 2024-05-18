#define  Hello    //不能像C，C++一样宏定义
#undef   Hello   //删除定义的符号
#define  GOOD    


using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _046
{
    class Program
    {
        static void Main(string[] args)
        {
#if Hello
            Console.WriteLine("定义了Hello这个符号！");
#else
          Console.WriteLine("没定义了Hello这个符号！");
#endif


#if GOOD
 Console.WriteLine("定义了GOOD这个符号！");
#elif HIGH
 Console.WriteLine("定义了HIGH这个符号！");
#elif STUDY
 Console.WriteLine("定义了STUDY这个符号！");
#else
            Console.WriteLine("没定义这些符号！");
#endif








        }
    }
}
