using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _027
{
    //C#不支持类的多继承，但是支持 接口的多继承
    interface  IWalk
    {
        void Walk();
    }


    interface ISay
    {
        void Say();
    }


    //一个接口可以多继承多个接口
    interface   IWalkSayEat: IWalk, ISay
    {
        void Eat();
    }


    //人类可以实现IWalkSayEat接口

    class Human : IWalkSayEat
    {
        public void Eat()
        {
            Console.WriteLine("人类吃美食！");
        }

        public void Say()
        {
            Console.WriteLine("人类说你好！");
        }

        public void Walk()
        {
            Console.WriteLine("人类走路！");
        }
    }





    class Program
    {
        static void Main(string[] args)
        {

            Human m = new Human();

            IWalk w = m;
            w.Walk();//可走路

            IWalkSayEat wse = m;
            wse.Walk();
            wse.Eat();
            wse.Say();



        }
    }
}
