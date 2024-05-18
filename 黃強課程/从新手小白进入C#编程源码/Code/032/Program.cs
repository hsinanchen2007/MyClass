using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _032
{

    struct Human
    {
        public string name;//成员变量
        public int age;//成员变量

        public Human(String name,int age) //结构体不能定义无参构造函数
        {
            this.name = name; //在里面必须给成员赋值
            this.age = age;
            Console.WriteLine("结构体的有参构造函数！");
        }

        public void School()
        {
            Console.WriteLine(name+"去上学！");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {

            Human m;//结构是值类型，可以不用new
            m.name = "小红";
            m.age = 12;
            m.School();

            Human m2 = m; //值类型，各自互相独立
            m2.name = "小华";

            m.School();

            Human m3 = new Human(); //系统默认的无参构造函数
            m3.name = "小明";
            m3.School();

            Human m4= new Human("天天",18); //调用有参构造函数 
            m4.School();

        }
    }
}
