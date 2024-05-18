using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _021
{

    public  class Human
    {
       // public  int n=0;//类的普通成员
       public static int n=0;//类的静态成员,属于类和对象的

        public Human()
        {
            ++n;  //每构造一个对象，就让n加一
            Console.WriteLine("产生第" + n + "个对象!");
        }


        public static void  Show()
        {
            Console.WriteLine("类的静态成员函数!");
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            //类的静态成员，可以不产生对象，就可以访问
            Console.WriteLine("目前有" + Human.n + "个对象!");

            Human.Show();

            Human m1= new Human(); //产生第1个对象
            Human m2 = new Human(); //产生第2个对象
            Human m3= new Human(); //产生第3个对象

            //必须用类名访问类的静态成员 （与C++不同，C++中对象.静态成员是允许的）
            Console.WriteLine("目前有" + Human.n + "个对象!");

            Global.LEN = 200;//像全局变量的一样使用
        }
    }
}
