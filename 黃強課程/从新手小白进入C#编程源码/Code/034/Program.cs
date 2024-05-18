using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;


//使用命名空间
using ns1;
 

namespace ns1
{
    class  A
    {
        public  A()
        {
            Console.WriteLine("命名空间ns1里面的A类");
        }
    }
}

namespace ns2
{
    class A
    {
        public A()
        {
            Console.WriteLine("命名空间ns2里面的A类");
        }
    }
}


namespace ns3
{
    class B
    {
        public B()
        {
            Console.WriteLine("命名空间ns3里面的B类");
        }
    }

    namespace ns4
    {
        class B
        {
            public B()
            {
                Console.WriteLine("命名空间ns3.ns4里面的B类");
            }
        }
    }
}



namespace _034
{
    class Program
    {
        static void Main(string[] args)
        { 
            A a = new A(); //因为前面自动using ns1;

            ns2.A a2 = new ns2.A(); //明确指出使用哪个命名空间中哪个类
             
            ns3.ns4.B b = new ns3.ns4.B();//使用了嵌套命名空间中B类
        }
    }
}
