using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;

namespace _007
{
    /// <summary>
    /// App.xaml 的交互逻辑
    /// </summary>
    public partial class App : Application
    {
        //观察Run方法被调用
        public new int Run()
        {
            int r = 0;
            Console.WriteLine("Run()方法开始...");
            r = base.Run(); //事件循环
            Console.WriteLine("Run()方法结束...");
            return r;
        }

        // 当应用程序启动Run时调用
        protected override void OnStartup(StartupEventArgs e)
        {
            Console.WriteLine("程序启动...");
        }

        // 当应用程序从非活动状态转换为活动状态时调用
        protected override void OnActivated(EventArgs e)
        {
            Console.WriteLine("程序活动状态...");
        }



        // 当应用程序从活动状态转换为非活动状态时调用
        protected override void OnDeactivated(EventArgs e)
        {
            Console.WriteLine("程序非活动状态...");
        }

        // 当应用程序退出时调用
        protected override void OnExit(ExitEventArgs e)
        {
            Console.WriteLine("程序退出...");
        }





    }
}
