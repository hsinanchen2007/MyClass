using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _036
{
    //定义委托类型
    public delegate void MyDelegate(int a);//这个委托类型名称为 MyDelegate，
                                                                       //它可以赋值任何  void  XXX(int  a); 

    class  A
    {
        public  void Fun1(int a)
        {
            Console.WriteLine("Fun1 "+a);
        }
        public void Fun2(int a)
        {
            Console.WriteLine("Fun2 " + a);
        }
        public static  void Fun3(int a)
        {
            Console.WriteLine("Fun3 " +a);
        }
    }

    class Program
    {
        static void Main(string[] args)
        {

            A a = new A();

            //定义委托变量
            MyDelegate d1 = a.Fun1;
            //通过委托调用方法
            d1(100);


            //定义委托变量
            MyDelegate d2 = new MyDelegate (a.Fun2);
            //通过委托调用方法
            d2(200);

            Console.WriteLine("-------------------------------------------");

            //委托一次可以添加多个方法
            MyDelegate d3 =  d2;
            d3 += A.Fun3; //+=在添加一个方法   -=减少一个方法
            d3(300); //同时会调用所有添加进来的方法

            Console.WriteLine("-------------------------------------------");

            d2(400);



        }
    }
}
