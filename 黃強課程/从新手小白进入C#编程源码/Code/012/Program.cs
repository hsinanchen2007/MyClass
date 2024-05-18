using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _012
{
    class Program
    {
        static void Main(string[] args)
        {

            //条件判断语句

            //最简单的if ,true就执行，否则不执行
            int score = 100;
            if(score >= 90)
            {
                Console.WriteLine("优秀！");
            }

            //if -else ， true 执行if的语句，false执行else的语句
            score = 80;
            if (score >= 90)
            {
                Console.WriteLine("优秀！");
            }
            else
            {
                Console.WriteLine("不是优秀！");
            }

            // if  -else if - else
            score = 59;
            if (score >= 90)
            {
                Console.WriteLine("优秀！");
            }
            else if (score >= 80)
            {
                Console.WriteLine("良好！");
            }
            else if (score >= 60)
            {
                Console.WriteLine("及格！");
            }
            else
            {
                Console.WriteLine("不及格！");
            }

        }
    }
}
