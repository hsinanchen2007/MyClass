using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _035
{
    //索引器，就是把对象像数组一样，可以[index]访问，很有意思，类似于C++运算符重载[]
    class A
    {

        private String [] data= new string[100]; //底层实际保存数据

        //索引器
        public  string  this[int i]
        {
            get
            {
                return data[i];
            }
            set 
            {
                //系统自动把等号右边的值放入value
                Console.WriteLine("索引是：{0} ,设置的值是：{1}", i, value);

                if(i <  data.Length )
                {
                    data[i] = value;
                }
                else
                {
                    Console.WriteLine("错误，索引值越界！" );
                }
      
            }

        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            A a = new A();
            //因为A类定义了索引器，所以现在可以像数组一样玩

            a[10] = "你好"; //调用set
            a[9] = "大家好"; //调用set

            a[10000000] = "大家好"; //调用set

            Console.WriteLine(a[10]);
            Console.WriteLine(a[9]);


        }
    }
}
