using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _026
{
    //接口，指定一些方法标准，不允许自己实现，必须留给派生类去实现
    interface  IWalkSay
    {
        void Walk();   //和抽象方法很像，只不过少了abstract
        void Say();
    }

    //符合这个接口的一些类
    class Duck : IWalkSay
    {
        public void Say()
        {
            Console.WriteLine("鸭子嘎嘎");
        }

        public void Walk()
        {
            Console.WriteLine("鸭子大摇大摆的走路");
        }
    }

    class Robot : IWalkSay
    {
        public void Say()
        {
            Console.WriteLine("机器人说你好");
        }

        public void Walk()
        {
            Console.WriteLine("机器人利用轮子走路");
        }
    }


    class Program
    {
        static void Main(string[] args)
        {

            //体现出多态的味道
            IWalkSay ws = null;

            ws = new Duck();
            ws.Walk();
            ws.Say();

            ws = new Robot();
            ws.Walk();
            ws.Say();
        }
    }
}
