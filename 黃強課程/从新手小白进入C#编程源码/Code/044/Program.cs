using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _044
{
    class Program
    {

        public static  unsafe void  Fun() //整个函数写非安全代码
        {
            int a = 100;
            int* pA = &a;//使用指针
            Console.WriteLine(  (int) pA );
        }

        static void Main(string[] args)
        {
            unsafe
            {
                int a = 100;
                int* pA = &a; //使用指针
                *pA = 200;
                Console.WriteLine(a); 
                int** ppA = &pA;//使用指针的指针
                **ppA = 400;
                Console.WriteLine(a);
            }


            Fun();
        }
    }
}
