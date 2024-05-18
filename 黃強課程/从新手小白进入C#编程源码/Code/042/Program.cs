using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _042
{
    //泛型编程，将 类型（int，float  变成参数）
    class MyMath
    {
        public  T   Sum<T>(T a,  T b)  // T是一个类型参数
        {
            dynamic _a = a; //动态判断类型
            dynamic _b = b;

            return  _a + _b;
        }
         
    }
     
  ///////////////////////////////////////////////////////////////////////////////// 
    class MyMath<H>
    {
        public H Sum(H a, H b)  // H是一个类型参数
        {
            dynamic _a = a; //动态判断类型
            dynamic _b = b;

            return _a + _b;
        }


        public T Mult<T>(T a, T b)  // T是一个类型参数
        {
            dynamic _a = a; //动态判断类型
            dynamic _b = b;

            return _a * _b;
        }
    }

    ///////////////////////////////////////////////////////////////////////////////// 

    class MyMath<A,B,C>
    {
        public C Sum(A a, B b)  // A,B ,C 是三个类型参数
        {
            dynamic _a = a; //动态判断类型
            dynamic _b = b;

            return _a + _b;
        } 
    }

    class Program
    {
        static void Main(string[] args)
        {
            MyMath m = new MyMath();

            //整数求和
            int r1=  m.Sum<int>(100, 200);
            Console.WriteLine(r1);

            //浮点数求和
            double   r2 = m.Sum(0.123, 0.345); //根据函数参数，自动匹配T的类型
            Console.WriteLine(r2);

            float r3 = m.Sum(0.12f, 0.34f);  
            Console.WriteLine(r3);

            //////////////////////////////////////////////////////
            MyMath<int> c = new MyMath<int>();
            int  r4=  c.Sum(100, 200);
            Console.WriteLine(r4);

            float r5 = c.Mult<float>(100, 200);
            Console.WriteLine(r5);

            /////////////////////////////////////////////////////////
            MyMath<int ,float ,double > d = new MyMath<int, float, double>();
            double  r6 = d.Sum(100, 200.023f);
            Console.WriteLine(r6);



        }
    }
}
