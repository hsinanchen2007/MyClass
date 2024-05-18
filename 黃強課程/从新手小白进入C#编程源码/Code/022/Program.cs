using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _022
{

    public  class Father
    {
        public         string house = "房子"; //公有成员
        protected   string car = "车子"; //公有成员
        private        string money = "存款"; //公有成员
    }


    //儿子类继承自父亲类，  Father 是基类或者父类， Son是派生类或者 子类
    public  class  Son : Father
    {
        //成员方法测试，在子类中，可访问父类的public成员，
        // 可访问protected成员，不可访问private成员
        public void  CanUse()
        {
            Console.WriteLine("儿子可以继承父亲的" + house); //house是父类的public成员
            Console.WriteLine("儿子可以继承父亲的" + car); //car是父类的protected成员
            //Console.WriteLine("儿子可以继承父亲的" + money); //money是父类的private成员
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            Son s = new Son();
            s.CanUse();

            //下面测试子类的对象能访问哪些
            Console.WriteLine(s.house);//子类对象可以访问父类的public成员
            //Console.WriteLine(s.car);//子类对象不可以访问父类的protected成员
            //Console.WriteLine(s.money);//子类对象不可以访问父类的private成员
        }
    }
}
