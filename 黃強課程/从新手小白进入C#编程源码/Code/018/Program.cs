using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _018
{

    public  class  Human
    {
            private int age;//如果定义为public，则 对象就可以随意赋非法值，
                                //所以设计为private，符合面向对象的封装性 


            //需要提供public 方法给对象去操作
            public void  SetAge(int _age)
            {
                if(_age < 0 || _age > 150)//保证代码安全性
                {
                    Console.WriteLine("年龄值非法!");
                    return;
                }

                age = _age;
            }

            //获取年龄
            public int  GetAge( )
            {
                return age;
            }
        }



    public class Human2
    {
        private int age;//如果定义为public，则 对象就可以随意赋非法值，
                        //所以设计为private，符合面向对象的封装性 

       //使用属性
        public  int   Age
        {
            get //用来获取年龄
            {
                return age;
            }
            set  //用来设置年龄的
            {
                // 系统会自动将值放到value中
                if (value < 0 || value > 150)//保证代码安全性
                {
                    Console.WriteLine("年龄值非法!"); 
                }
                else
                {
                    age = value;
                }
           
            }

        }



        //使用属性
        public String Name //可以不用定义私有变量name
        {
            get;
            set;
        }

        //使用属性
        public String ID //可以不用定义私有变量name
        {
            get;
        } = "420000006"; //还可以赋初始值

    }


    class Program
    {
        static void Main(string[] args)
        {
            //new 了人类的一个实例
            Human m = new Human();
            m.SetAge(1000000);//可以控制非法赋值
            m.SetAge(100);
            Console.WriteLine("年龄是" + m.GetAge());



            //new 了人类的一个实例
            Human2 m2 = new Human2();
            m2.Age = 100000;  //调用set代码块
            m2.Age = 100; //调用set代码块
            Console.WriteLine("年龄是" + m2.Age); //会调用get代码块


            m2.Name = "小红"; //调用set代码块
            Console.WriteLine("姓名是" + m2.Name); //会调用get代码块

            //m2.ID = "4200000001"; //无set代码块，所以不能设置
            Console.WriteLine("身份证是" + m2.ID); //会调用get代码块

        }
    }
}
