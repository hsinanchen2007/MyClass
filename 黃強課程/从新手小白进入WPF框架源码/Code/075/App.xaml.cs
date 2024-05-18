using System;
using System.Collections.Generic;
using System.Configuration;
using System.Data;
using System.Linq;
using System.Threading.Tasks;
using System.Windows;
using View;

namespace _075
{
    /// <summary>
    /// App.xaml 的交互逻辑
    /// </summary>
    public partial class App : Application
    {
        //重写方法
        protected override void OnStartup(StartupEventArgs e)
        {
            base.OnStartup(e);

           //先弹出登录窗口
            Login login = new Login();
            bool? ret=   login.ShowDialog();
            if (ret == true )
            {
                //成功登录显示主窗口
                MainWindow mainWindow = new MainWindow();
                mainWindow.ShowDialog();

                //关闭程序
                App.Current.Shutdown();
            }
 
        } 

    }
}
