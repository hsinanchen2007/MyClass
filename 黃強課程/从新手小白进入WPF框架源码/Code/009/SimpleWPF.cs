using System.Windows;
using System.Windows.Media;

namespace _009
{
    internal class SimpleWPF
    {
        //入口函数
        [System.STAThreadAttribute()]
        public  static void  Main()
        {

            /*
            //新建一个窗口
            Window  mainWindow = new Window();
            mainWindow.Title = "WPF窗口";
            mainWindow.Width = 640;
            mainWindow.Height = 480;
            mainWindow.Background = new SolidColorBrush(Colors.Red);
            mainWindow.Show();

            // 应用程序对象
            Application app = new Application();
            app.MainWindow = mainWindow;//设置主窗口
            app.Run();//开启消息循环

            */


            //新建一个窗口
            MainWindow mainWindow = new MainWindow();
            mainWindow.Title = "WPF窗口";
            mainWindow.Width = 640;
            mainWindow.Height = 480;
            mainWindow.Background = new SolidColorBrush(Colors.Red);
            mainWindow.Show();

            // 应用程序对象
            App app = new App(); 
            app.MainWindow = mainWindow;//设置主窗口
            app.Run();//开启消息循环

        }

    }
}
