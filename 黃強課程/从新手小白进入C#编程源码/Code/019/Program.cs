using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _019
{

    class  Human
    {
        //成员变量
        private string name="小红";//姓名

         //成员函数(成员方法) 
        public   int   Eat(String food)
        {
            //成员方法可以随意访问成员变量
            Console.WriteLine( name+ "吃" + food);
            return 3;
        }


        //吃N个food, 函数重载
        public int Eat(int  n,  String food)
        {
            //成员方法可以随意访问成员变量
            Console.WriteLine(name + "吃" +n+"个"+ food);
            return 3;
        }


        //吃多重个food, 函数重载
        public int Eat(float kg, String food)
        {
            //成员方法可以随意访问成员变量
            Console.WriteLine(name + "吃" + kg + "kg重的" + food);
            return 3;
        }

    }



    class Program
    {
        static void Main(string[] args)
        {
            Human m = new Human();
            //调用成员方法
            m.Eat("苹果!");
            //调用成员方法
            m.Eat(3, "水蜜桃");
            //调用成员方法
            m.Eat(0.5f, "猪肉");

        }
    }
}
