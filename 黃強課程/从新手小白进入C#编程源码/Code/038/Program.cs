using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;

namespace _038
{
    class A
    {
        //成员变量
        private int           a;
        protected String b;
        public  double    c;

        //属性
        public String B
        {
            get;set;
        }
        //有参构造函数
        public A(int a)
        {
            Console.WriteLine("有参构造函数");
        }

        //成员方法
        private void      Fun1(int a)
        {
            Console.WriteLine("Fun1  " + a);
        }
        protected void Fun2(String a)
        {
            Console.WriteLine("Fun2  " + a);
        }
        public void Fun3(String a)
       {
            Console.WriteLine("Fun3  " + a);
        }
       public static void Fun4(String a)
       {
            Console.WriteLine("Fun4  " + a);
        }
}



    class Program
    {
        static void Main(string[] args)
        {
            //首先获取Type类的对象
            Type t = typeof(A);

            //获取A类的所有成员信息
            MemberInfo [] ms=   t.GetMembers();
            foreach(MemberInfo  m in ms )
            {
                Console.WriteLine(m);
            }


            //获取类的方法
            MethodInfo  mi=  t.GetMethod("Fun3");

            A a = new A(123);

            //运行时调用类的方法
            mi.Invoke(a, new Object[] { "666" });

        }
    }
}
