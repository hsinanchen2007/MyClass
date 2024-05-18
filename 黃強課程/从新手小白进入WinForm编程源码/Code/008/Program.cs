using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _008
{
    static class Program
    {
        /// <summary>
        /// 应用程序的主入口点。
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);

            //打印应用程序的可执行文件的路径
            Debug.WriteLine("可执行文件的路径(包含文件名)    " + Application.ExecutablePath);
            Debug.WriteLine("可执行文件的路径(不包含文件名)    " + Application.StartupPath);
            Debug.WriteLine("应用程序数据的路径    " + Application.UserAppDataPath);

            //一旦Run结束，消息循环结束，Main函数就结束
            //Application.Run(new Form1()); 


            //下面模拟Application.Run方法
            Form1 f1 = new Form1();
            f1.Show();

            //简单模拟消息循环
            while (true)
            {
                //需要在这个里面进行相应的消息处理
            }

            Debug.WriteLine("Main方法结束！！！");
        }
    }
}
