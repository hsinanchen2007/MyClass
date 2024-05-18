using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _008
{
    class Program
    {
        static void Main(string[] args)
        {
            {
                //前加
                int a = 10;
                int b = ++a; //a增加1，并且直接返回增加后的值
                Console.WriteLine("前加   a  {0}   b  {1}", a, b); 
            }

            {
                //后加
                int a = 10;
                int b = a++; //先返回a原来的值，然后a增加1
                Console.WriteLine("后加   a  {0}   b  {1}", a, b);
            }

            {
                //前减
                int a = 10;
                int b = --a; //a减少1，并且直接返回减少后的值
                Console.WriteLine("前减   a  {0}   b  {1}", a, b);
            }

            {
                //后减
                int a = 10;
                int b = a--; //先返回a原来的值，然后a减少1
                Console.WriteLine("后减   a  {0}   b  {1}", a, b);
            }



        }
    }
}
