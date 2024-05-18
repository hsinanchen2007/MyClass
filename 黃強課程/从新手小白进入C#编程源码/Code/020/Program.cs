using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _020
{

    public  class Human
    {

        private String name;
        private int age;

        //如果不提供构造函数，系统默认提供一个无参的构造函数

        //函数名与类名相同，没有返回值，做初始化工作
        public  Human()
        {
            //做一些初始化工作
            Console.WriteLine("调用无参构造函数!");
        }

        
        public Human(String  name,int  age,string ID)
        {
            //做一些初始化工作
            this.name = name;
            this.age = age;

            Console.WriteLine("调用"+name+"有参构造函数!");
        }



        //析构函数
        //函数名为 ~类名，  无参无返回值， 对象销毁的时候，系统自动调用，做清理的工作
         ~Human()
        {
            Console.WriteLine("调用" + name + "析构函数!");

            //做清理工作
            name = "";
            //释放资源
        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Main开始!");

            Human m = new Human();//调用无参构造函数

            Human m2 = new Human("小红",12,"4000000006");//调用有参构造函数


            Console.WriteLine("Main结束!");
        }
    }
}
