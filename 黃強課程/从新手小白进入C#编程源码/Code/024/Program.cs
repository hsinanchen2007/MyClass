using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _024
{
    //多态是发生在继承关系上的
    public  class Animal
    {
        public  virtual  void Walk()  //C++ 也是加上virtual 虚函数实现多态的
        {
            Console.WriteLine("动物走路！");
        }
    }

    //鸭子
    public class Duck:Animal
    {
        public  override void Walk()
        {
            Console.WriteLine("鸭子两条腿大摇大摆的走！");
        }
    }

    //猫
    public class Cat : Animal
    {
        public override  void Walk()
        {
            Console.WriteLine("猫四条腿悄无声息的走！");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {

            //多态性，就是  基类的引用指向派生类的对象，
            //调用基类的方法时，会调用实际派生类重写的方法
            Animal ani = null;

            ani = new Duck();
            ani.Walk(); //应该是鸭子走路

            ani = new Cat();
            ani.Walk(); //应该是猫走路

            //同样的调用指的的是ani.Walk(); 展现不同的结果，叫多态

        }
    }
}
