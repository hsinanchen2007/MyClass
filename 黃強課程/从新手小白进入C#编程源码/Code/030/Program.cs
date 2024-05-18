using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _030
{
    class Program
    {
        //打印一维数组
        static void PrintArray(int [] a)
        {
            foreach (int e in a)
            {
                Console.Write("    " + e);
            }

            Console.WriteLine();
        }

        //打印二维数组
        static void PrintArray(int[ ,] b)
        {
            Console.WriteLine();

            for (int i = 0; i < b.GetLength(0); ++i)
            {
                for (int j = 0; j < b.GetLength(1); ++j)
                {
                    Console.Write("    " + b[i,j]); //获取第i行第j列的元素
                }
                Console.WriteLine();
            }

            Console.WriteLine();
           
        }


        static void Main(string[] args)
        {
            //一位数组 ，内存空间连续，并且每个元素类型相同
            int[] a1 = new int[5]; //new数组，元素值初始化都为0
            PrintArray(a1);
             

            int[] a2 = { 1, 2, 3, 4, 5,6,7,8 }; //根据后面的元素个数确定数组长度
            PrintArray(a2);

            int[] a3 = new int [] { 1, 2, 3, 4, 5, 6, 7, 8,9,10 }; //类似a2
            PrintArray(a3);

            int[] a4 = new int[5] { 1, 2, 3,4,5}; //花括号中的元素必须与数组长度个数一致
            PrintArray(a4);


            int[] a5 = a4;
            a5[0] = 111; //改a5的时候，a4页也变化了，说明是引用类型
            PrintArray(a4);

            //------------------------二维数组-----------------------------------------

            int[,] b = new  int [2,3];//产生2行3列的数组，元素值初始化都为0
            PrintArray(b);

            int[,] b2 = { { 1, 2, 3 }, { 4, 5, 6 } }; //利用初始值来确定几行几列
            PrintArray(b2);

            int[,] b3 =new int[,] { { 1, 2, 3,4,5 }, { 6,7,8,9,10 }, { 11, 12, 13, 14, 15 } }; // 类似b2
            PrintArray(b3);

            int[,] b4 = new int[3,2] { { 1, 2  }, { 3, 4  }, { 5, 6 } }; // 必须和行数列数严格相等
            PrintArray(b4);

            //------------------------三维数组-----------------------------------------

            int[,,] c = new int[2, 3, 4]; 
        }
    }
}
