using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

using _017_1;

namespace _017_2
{
    class Program
    {
        static void Main(string[] args)
        {
            //访问其他项目中的类
            A a = new A();

           // a.a1 = 1;//不可以在其他项目访问，因为是internal
            a.a2 = 2;//可以访问，因为是public

           //B b = new B(); //不能在其他项目中使用
        }
    }
}
