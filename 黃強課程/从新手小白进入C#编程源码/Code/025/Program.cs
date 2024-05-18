using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _025
{
    //定义一个抽象类，不能实例化，不能产生对象，因为产生的对象没有什么意义
    abstract class  Animal
    {
      public   abstract void Walk();//抽象方法，可以不用实现

        void Eat() //抽象类也可以有非抽象方法
        {

        }
    }

    class  Duck:  Animal
    {
        public  override  void Walk() //非抽象类必须实现父类的抽象方法
        {
            Console.WriteLine("鸭子两条腿大摇大摆的走路!");
        } 
    }
    class Cat : Animal
    {
        public override void Walk() //非抽象类必须实现父类的抽象方法
        {
            Console.WriteLine("猫四条腿悄无声息的走路!");
        }
    }


    abstract  class BigAnimal : Animal
    {
        //抽象类可以不实现父抽象类的抽象方法
    }


    class  A
    {
      //public   abstract void Fun();  //普通类不能包含抽象方法
    }

    class Program
    {
        static void Main(string[] args)
        { 
            //Animal a = new Animal();//抽象类不能创建实例
             
            //呈现多态
            Animal ani = null;

            ani = new Duck();
            ani.Walk();

            ani = new Cat();
            ani.Walk(); 
        }
    }
}
