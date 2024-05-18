using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _041
{
    class A  //默认就是object的子类
    {
        public override String ToString()
        {
            return "这是一个A类对象";
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            int aa = 100; //本质是struct  Int32 ，它的父类是Object
            aa.ToString();//老师，为什么这里基本数据类型竟然有成员方法？
            aa.GetType();


            //定义object类的对象
            object o = new object();
            object o2 = new object();
            //调用静态成员方法
            Console.WriteLine(object.Equals(o, o2));
            Console.WriteLine(object.ReferenceEquals(o, o2));
            //调用成员方法,可以被派生类重写(virtual)
            Console.WriteLine(o.Equals( o ));
            Console.WriteLine(o.GetHashCode());
            Console.WriteLine(o2.GetHashCode()); //不同的对象，hashCode不同，用于快速判断两个对象是否相同
            Console.WriteLine(o.ToString());
            //调用成员方法
            Console.WriteLine(o.GetType());

            Console.WriteLine();

            int i = 100;
            int i2 = 100;
            Console.WriteLine(object.Equals(i, i2));
            Console.WriteLine(object.ReferenceEquals(i, i2)); 
            Console.WriteLine(i.Equals(i2));
            Console.WriteLine(i.GetHashCode());
            Console.WriteLine(i2.GetHashCode()); 
            Console.WriteLine(i.ToString());

            Console.WriteLine();


            A a = new A();
            A a2 = new A();
            Console.WriteLine(object.Equals(a, a2));
            Console.WriteLine(object.ReferenceEquals(a, a2));
            Console.WriteLine(a.Equals(a2));
            Console.WriteLine(a.GetHashCode());
            Console.WriteLine(a2.GetHashCode());
            Console.WriteLine(a.ToString());




        }
    }
}
