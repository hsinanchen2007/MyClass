using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _029
{
    //定义一个类
    class  Human
    {
        public int age;
    }


    class Program
    {
        static void Main(string[] args)
        {
            //值类型
            int a = 100;
            int a2 = a;
            Console.WriteLine("值类型改变前 a：{0}         a2：{1}", a, a2);
             a2 = 200;
            Console.WriteLine("值类型改变后 a：{0}         a2：{1}", a, a2);
            //说明两块内存是彼此独立的

            Console.WriteLine(object.ReferenceEquals(a, a2));

            //引用类型
            Human h = new Human();
            h.age = 100;
            Human h2 = h;
            Console.WriteLine("引用类型改变前 a：{0}         a2：{1}", h.age, h2.age);
            h2.age= 200;
            Console.WriteLine("引用类型改变后 a：{0}         a2：{1}", h.age, h2.age);
            //说明两个引用指向同一块内存

            Console.WriteLine(object.ReferenceEquals(h, h2));

        }
    }
}
