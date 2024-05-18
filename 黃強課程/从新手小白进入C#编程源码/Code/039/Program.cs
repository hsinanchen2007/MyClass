using System; 
using System.Reflection; 

namespace _039
{

    class A
    {
        public A( )
        {
            Console.WriteLine("调用无参构造函数!");
        }
        public  A(String name,int  age)
        {
            Console.WriteLine("调用有参构造函数   "+ name +"  "+age);
        }  

        public  void Fun()
        {
            Console.WriteLine("调用Fun!");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            // A a = new A();//这个不叫运行时的动态创建

            //运行时动态创建类的对象

            //获取类的Type对象
            Type t = Type.GetType("_039.A");

            //获取当前程序集
            Assembly assembly = Assembly.GetExecutingAssembly();
            //动态创建类的对象
            A  a = (A) assembly.CreateInstance(t.FullName);
            a.Fun();


            //调用有参构造函数构造 
            A a2 = (A)assembly.CreateInstance("_039.A", true,
                System.Reflection.BindingFlags.Default, null, new object[] { "小红",18  }, null, null);
            a2.Fun();
        }
    }
}
