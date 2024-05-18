using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _031
{
    class Program
    {
        static void Main(string[] args)
        {
            //构造字符串对象
            String s1 = "Hello  World!";//常量字符串
            Console.WriteLine(s1);

            //new的方法
            string s2 = new string(new char[] { 'G', 'o', 'o', 'd' });
            Console.WriteLine(s2);

            //String的静态成员函数
            String s3 = String.Format("{0} is {1}", "Time", 1234);
            Console.WriteLine(s3);

            //String是引用类型
            String s4 = s3;
            Console.WriteLine( object.ReferenceEquals(s3,s4 ));

            ////////////////////////////常用的字符串操作////////////////////////////////////////////////
            String s5 = "hello,我是程序员,I  Love Code,hello";
            bool b= s5.Contains("ove");
            Console.WriteLine("是否包含某个字符串" + b);

           int b2= String.Compare("aaaaaa", "bb"); //大于返回1， 等于返回0，小于返回-1
            Console.WriteLine("字符串比较大小" + b2);

            int index1 = s5.IndexOf("ell"); //从左往右找找到第一个
            int index2 = s5.LastIndexOf("ell");//从右往左找到第一个
            Console.WriteLine("查找子串的索引位置 {0}   {1}" ,index1,index2  );

            String  s6= s5.Replace("hello", "你好");
            Console.WriteLine("替换字符串    "+ s6);
            Console.WriteLine("原来字符串不变    " + s5);

            String s7 = s5.Substring(6, 5);
            Console.WriteLine("截取字符串    " + s7);
            Console.WriteLine("原来字符串不变    " + s5);

            Console.WriteLine();

            string [] s8 =  s5.Split(new char[] { ',' });
            Console.WriteLine("分割字符串    " );
            foreach(string e in s8)
            {
                Console.WriteLine( e );
            }
            Console.WriteLine("原来字符串不变    " + s5);


        }
    }
}
