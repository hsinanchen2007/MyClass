using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _043
{
    class Program
    {
        static void Main(string[] args)
        {

            //动态数组 
            ArrayList al = new ArrayList();
            al.Add(111);
            al.Add("Hello");
            al.Add(0.123);
            al.Add(new object());

            Console.WriteLine(al[0]);//直接用下标索引访问，使用了索引器

            foreach(object o  in  al)
            {
                Console.WriteLine(o);
            }

            Console.WriteLine();


            //哈希表,key-value键值对， 哈希算法，通过键查找值速度比较快
            Hashtable ht = new Hashtable();
            ht.Add(111, "hello111");
            ht.Add("good", 1.234);
            ht.Add(0.657, "小数值");

            Console.WriteLine( ht[0.657]); //通过 键 查找 值

            ICollection keys = ht.Keys; //获取哈希表所有的键值
            foreach( object k  in keys)
            {
                Console.WriteLine(k + "->"+ ht[k]); //通过 键 查找 值
            }

            Console.WriteLine();

            //排序列表  key-value键值对 ,自动通过键排序
            SortedList sl = new SortedList();
            sl.Add(1, "Hello");
            sl.Add(4, "Are");
            sl.Add(3, 0.456);
            sl.Add(2, new object());

            ICollection kes = sl.Keys; //获取哈希表所有的键值
            foreach (object k in kes)
            {
                Console.WriteLine(k + "->" + sl[k]); //通过 键 查找 值
            }

            Console.WriteLine();

            //栈， 先进后出 FILO  
            Stack s = new Stack();
            s.Push('A');//入栈
            s.Push('B');//入栈
            s.Push('C');//入栈

            //出栈
            while( s.Count>0)
            {
                Console.WriteLine(s.Pop());  //出栈，会自动删除元素
            }

            Console.WriteLine();

          //队列，FIFO 先进先出
           Queue q = new Queue();
            q.Enqueue('A');//入队
            q.Enqueue('B');//入队
            q.Enqueue('C');//入队

            //出队
            while (q.Count > 0)
            {
                Console.WriteLine(q.Dequeue());  //出队列，会自动删除元素
            }



        }
    }
}
