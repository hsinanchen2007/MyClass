using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _014
{
    class Program
    {
        static void Main(string[] args)
        {
            //分支语句

            string day = "星期三";
            switch(day)
            {
                case "星期一":
                    Console.WriteLine("Monday");
                    break;
                case "星期二":
                    Console.WriteLine("Tuesday");
                    break;
                case "星期三":
                    Console.WriteLine("Wednesday");
                    break;
                case "星期四":
                    Console.WriteLine("Thursday");
                    break;
                case "星期五":
                    Console.WriteLine("Friday");
                    break;
                case "星期六":
                    Console.WriteLine("Saturday");
                    break;
                case "星期日":
                    Console.WriteLine("Sunday");
                    break;

                default:
                    Console.WriteLine("输入有误!");
                    break;
            }


        }
    }
}
