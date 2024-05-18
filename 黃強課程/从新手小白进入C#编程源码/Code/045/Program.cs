using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _045
{
    //为我们的业务，定制一个异常， 买票业务，出票失败的异常
    class  TicketsOutException :Exception
    {
        public TicketsOutException(String msg) : base(msg) 
        {

        }
    }

    class Program
    {
        static void Main(string[] args)
        {

            //异常捕获和处理
            try
            {
                //假设出票失败了，现在主动抛出异常
                throw new TicketsOutException("出票失败了！！！");

                String s = null;
                s.ToString();//产生空指针异常


                //可能有异常的代码
                int a = 0;
                int b = 3 / a;//产生一个除0的异常，系统抛出来,导致下面的代码无法执行
                Console.WriteLine("b的结果是" + b); 

            }
            catch (TicketsOutException  e) //异常的基类
            {
                Console.WriteLine("捕捉到了异常:  " + e.Message);
                Console.WriteLine("进行处理异常的工作！");
            }
            catch (Exception  e) //异常的基类
            {
                Console.WriteLine("捕捉到了异常:  " + e.Message);
            } 
            finally
            {
                Console.WriteLine("finally不论是否发生异常，都会执行！ " );
            }
        }
    }
}
