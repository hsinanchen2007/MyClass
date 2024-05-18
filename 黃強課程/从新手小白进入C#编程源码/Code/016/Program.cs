using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _016
{
    //定义人类
    public class Human
    {
        //成员变量(属性)
        public string name;//姓名
        public byte age;//年龄
        public string ID;//身份证号

        //成员方法(行为)
        public  void  School()//上学
        {
            Console.WriteLine(name + "去上学!");
        }
        public void Sleep()//睡觉
        {
            Console.WriteLine(name + "去睡觉!");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            //创建对象（类的一个实例）
            Human m = new Human();//new可以创建实例

            //为对象的成员变量赋值
            m.name = "小红";
            m.age = 18;
            m.ID = "4000000000001";

            //调用对象的成员方法
            m.School();
            m.Sleep();


            //创建第二个对象（类的一个实例）
            Human m2 = new Human();//new可以创建实例

            //为对象的成员变量赋值
            m2.name = "小华";
            m2.age =36;
            m2.ID = "4000000000002";

            //调用对象的成员方法
            m2.School();
            m2.Sleep();

        }
    }
}
