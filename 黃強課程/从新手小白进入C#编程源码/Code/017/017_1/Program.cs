using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _017_1
{
    //公有的，不仅可以在本项目中使用，也可以在其他项目中使用
    public  class A
    {
        internal int a1; // 和public一样
        public int a2; //类的内部，和对象都可以访问
        protected int a3; //只能在类的内部或派生类的内部访问，对象无法访问
        private int a4; //只能在类的内部访问，对象无法访问
        int a5; //不写也是private

        public  void Fun()
        {
            //类的内部全部都可以访问
             a1 = 1;
             a2 = 2;
             a3 = 3;
             a4 = 3;
             a5 = 4;
        }

    }

    //内部的，只能在本项目中使用,
    internal class B  //不写也是internal
    { }

    class Program
    {
        static void Main(string[] args)
        {
            //在本项目中，public，internal都可以使用
            A a = new A();


            a.a1 = 1;//internal可以使用对象访问
            a.a2 = 2;//public可以使用对象访问
           //a.a3 = 3;//protected不可以使用对象访问
           //a.a4 = 3;//private不可以使用对象访问
           // a.a5 = 4;//private不可以使用对象访问


            B b = new B();
        }
    }
}
