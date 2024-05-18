using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _011
{
    class Program
    {
        static void Main(string[] args)
        {
            //将一个字节变量（占8位bit）
            byte a = 4;
            //二进制显示
            Console.WriteLine( "十进制4的二进制表示  "+Convert.ToString(a, 2).PadLeft(8, '0'));


            //将一个字节变量（占8位bit）
            byte b = 2;
            //二进制显示
            Console.WriteLine("十进制2的二进制表示  " + Convert.ToString(b, 2).PadLeft(8, '0'));

            //位运算，  二进制之间对应位上的运算

            //位与   & ，两个都为1，则结果为1，否则结果为0
            //   4      00000100
            //   2      00000010
            //           00000000            
            Console.WriteLine(" 4  & 2 = " + Convert.ToString(  a  & b   , 2).PadLeft(8, '0'));


            //位或   | ，至少有一个为1，则结果为1，否则结果为0
            //   4      00000100
            //   2      00000010
            //           00000110            
            Console.WriteLine(" 4  | 2 = " + Convert.ToString(a | b, 2).PadLeft(8, '0'));

            //异或   | ，不同为1，相同为0
            //   4      00000100
            //   2      00000010
            //           00000110            
            Console.WriteLine(" 4  ^ 2 = " + Convert.ToString(a ^ b, 2).PadLeft(8, '0'));

            //取反  ~ ，0为1，1为0
            //   4      00000100
            //           11111011      
            Console.WriteLine(" ~4   = " + Convert.ToString((byte)~a  , 2).PadLeft(8, '0'));


            //左移  <<N  
            //   4      00000100
            //           00010000    
            Console.WriteLine(" 4<<2   = " + Convert.ToString( a <<2 , 2).PadLeft(8, '0'));


            //右移  >>N  
            //   4      00000100
            //           00000001    
            Console.WriteLine(" 4>>2   = " + Convert.ToString(a >> 2, 2).PadLeft(8, '0'));


        }
    }
}
