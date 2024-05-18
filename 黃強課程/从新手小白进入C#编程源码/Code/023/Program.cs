using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _023
{

    class Father
    {
        //一旦程序员提供了有参构造函数，系统将不为此类提供无参构造函数，和C++一样
       public  Father(String name)
        {
            Console.WriteLine("Father的有参构造函数!" + name);
        }
    }

    class Son:Father
    {
        public  Son(String name):  base(name) //显示调用父类的有参构造函数
                                                                      //类似C++的初始化构造列表
        {
            Console.WriteLine("Son的有参构造函数!"+name);
        }


        public Son( ) : base("小明") //显示调用父类的有参构造函数
                                             //类似C++的初始化构造列表
        {
            Console.WriteLine("Son的无参构造函数!" );
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Son s = new Son("小红");//new Son类的一个对象

            Son s2 = new Son( );//new Son类的一个对象
        }
    }
}
