using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _028
{
    class A { }
    class B { }
    // class C : A, B { } //错误， C#类不支持继承多个类


    //但是，C#可以支持，继承一个类，（实现）多个接口
    interface IWalk
    {
        void Walk();
    }

    interface ISay
    {
        void Say();
    }


    class Human
    {
        public string name;
        public Human(String name)
        {
            this.name = name;
        }
        public  void Study()
        {
            Console.WriteLine(name+"学习！");
        }
    }

    //C#支持 继承自一个类，多个接口
    class XiaoMing : Human, IWalk, ISay
    {
        public XiaoMing() : base("小明")
        {

        }
        public void Say()
        {
            Console.WriteLine(name + "说你好！");
        }

        public void Walk()
        {
            Console.WriteLine(name + "走路！");
        }
    }


    class Program
    {
        static void Main(string[] args)
        {

            XiaoMing xm = new XiaoMing();
            xm.Walk();
            xm.Say();
            xm.Study();

        }
    }
}
