using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _010
{
    class Program
    {
        static void Main(string[] args)
        {
            //逻辑运算符

            //且&&  ， 两者全部为真，结果才是真，否则结果为假
            {
                bool ret = true && true;
                Console.WriteLine("true && true 结果为 " + ret);

                bool ret2 = true && false;
                Console.WriteLine("true && false 结果为 " + ret2);

                bool ret3 = false && false;
                Console.WriteLine("false && false 结果为 " + ret3);
            }

            //或 ||   ， 两者至少一个真，结果为真， 否则结果为假
            {
                bool ret = true || true;
                Console.WriteLine("true || true 结果为 " + ret);

                bool ret2 = true || false;
                Console.WriteLine("true || false 结果为 " + ret2);

                bool ret3 = false || false;
                Console.WriteLine("false || false 结果为 " + ret3);
            }

            //非 ! ， 为真则结果是假， 为假则结果是真
            {
                bool ret =! true ;
                Console.WriteLine("!true 结果为 " + ret);

                bool ret2 = !false;
                Console.WriteLine("!false 结果为 " + ret2); 
            }


            //小细节
            {
                //对于&& 而言，如果第一个条件就为false，那么结果已经确实是false，第二个条件就忽略检测
                int k = 10;
                bool ret = false && (++k == 0);
                Console.WriteLine("第二个条件是否执行 {0}", k); //打印出来还是10
            }

            {
                //对于|| 而言，如果第一个条件就为true，那么结果已经确实是true，第二个条件就忽略检测
                int k = 10;
                bool ret = true ||  (++k == 0);
                Console.WriteLine("第二个条件是否执行 {0}", k);
            }

        }
    }
}
