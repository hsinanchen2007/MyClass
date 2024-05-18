using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _004
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("bool     类型范围:{0}~{1}", true, false);
            Console.WriteLine("byte     类型范围:{0}~{1}", byte.MinValue, byte.MaxValue);
            Console.WriteLine("sbyte    类型范围:{0}~{1}", sbyte.MinValue, sbyte.MaxValue);
            Console.WriteLine("char     类型范围:{0}~{1}", (int)char.MinValue, (int)(char.MaxValue));
            Console.WriteLine("ushort   类型范围:{0}~{1}", ushort.MinValue, ushort.MaxValue);
            Console.WriteLine("uint     类型范围:{0}~{1}", uint.MinValue, uint.MaxValue);
            Console.WriteLine("short    类型范围:{0}~{1}", short.MinValue, short.MaxValue);
            Console.WriteLine("uint     类型范围:{0}~{1}", uint.MinValue, uint.MaxValue);
            Console.WriteLine("int      类型范围:{0}~{1}", int.MinValue, int.MaxValue);

            Console.WriteLine("ulong    类型范围:{0}~{1}", ulong.MinValue, ulong.MaxValue);
            Console.WriteLine("long     类型范围:{0}~{1}", long.MinValue, long.MaxValue);
            Console.WriteLine("float    类型范围:{0}~{1}", float.MinValue, float.MaxValue);
            Console.WriteLine("double   类型范围:{0}~{1}", double.MinValue, double.MaxValue);
            Console.WriteLine("decimal  类型范围:{0}~{1}", decimal.MinValue, decimal.MaxValue);

            Console.WriteLine("------------------------------------------------------------");


            Console.WriteLine("bool     占字节数: {0}", sizeof(bool));
            Console.WriteLine("byte     占字节数: {0}", sizeof(byte));
            Console.WriteLine("sbyte    占字节数: {0}", sizeof(sbyte));
            Console.WriteLine("char     占字节数: {0}", sizeof(char));
            Console.WriteLine("ushort   占字节数: {0}", sizeof(ushort));
            Console.WriteLine("short    占字节数: {0}", sizeof(short));
            Console.WriteLine("uint     占字节数: {0}", sizeof(uint));
            Console.WriteLine("int      占字节数: {0}", sizeof(int));

            Console.WriteLine("ulong    占字节数: {0}", sizeof(ulong));
            Console.WriteLine("long     占字节数: {0}", sizeof(long));
            Console.WriteLine("float    占字节数: {0}", sizeof(float));
            Console.WriteLine("double   占字节数: {0}", sizeof(double));
            Console.WriteLine("decimal  占字节数: {0}", sizeof(decimal));


            //小数数字后缀
            double a = 0.123;//不报错， 0.123默认是double
            float b = 0.123f;  //加个f表示0.123是float类型
            float c = 0.123F;  //加个F也可以表示0.123是float类型

            decimal d = 0.123M; // m，M表示0.123是decimal类型

            //整数数字后缀
            int f = 100;//默认是int型
            long e = 100L; //l,L表示100是long类型
            uint g = 100U;//u,U表示100是无符号的

        }
    }
}
