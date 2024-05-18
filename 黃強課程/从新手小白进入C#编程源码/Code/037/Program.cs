using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _037
{
     //就个人理解，event只是一种标识符而已，没有具体含义，真正起作用的是委托
    class  MyOS
    {
        //定义委托类型
        public delegate void MouseClickDelegate(int x, int y);

        //定义一个事件(本质上定义了一个委托变量)
        public event  MouseClickDelegate mouseClick;

        //当用户点击的时候，模拟系统自动处理
        public  void  SysFunWhenMouseClick()
        {
            mouseClick(100, 200);//这样就能调用你自己放到委托上的函数
        }

    }

    class Program
    {
       //程序员自己处理的代码
        public   static  void MyMouseClickFun(int x,int y)
        {
            Console.WriteLine("操作系统告诉我，用户点击了鼠标{0}  {1}  ", x, y);
        }

        static void Main(string[] args)
        {

            MyOS os = new MyOS();

            os.mouseClick += Program.MyMouseClickFun;

            //模拟用户在我的操作系统上突然点击鼠标
            os.SysFunWhenMouseClick();
        }
    }
}
