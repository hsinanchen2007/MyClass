using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _013
{
    class Program
    {
        static void Main(string[] args)
        {

            //for循环    
            for(  int  i=1;   i<=10 ;  ++i )
            {
                Console.WriteLine("第"+i+"次播放Jay的《Mojitou》");
            }


            //foreach 不关心次数，循环次数取决于 集合的元素个数
            int [] arr= new  int [] { 1,2,3,4,5,6,7,8,9,10};
            foreach(int  i   in   arr)
            {
                Console.WriteLine("第" + i + "次播放Jay的《青花瓷》");
            }


            //while 也不是很关心次数 
            int k = 1;
            while(k<=10)
            {
                Console.WriteLine("第" + k+ "次播放Jay的《回到过去》");
                k++;
            }

            //do while ,保证循环至少执行一次
            int m = 1;
            do
            {
                Console.WriteLine("第" + m + "次播放Jay的《蒲公英的约定》");
            }
            while ( ++m <=10 );




        }
    }
}
