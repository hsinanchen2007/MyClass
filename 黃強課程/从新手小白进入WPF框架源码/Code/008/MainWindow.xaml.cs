using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace _008
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();


        }


        private void Window_Loaded(object sender, RoutedEventArgs e)
        {
            // 窗口加载完成时的处理代码
            Console.WriteLine("窗口加载完成");

        }

        private void Window_SizeChanged(object sender, SizeChangedEventArgs e)
        {
            // 窗口大小更改时的处理代码
            Console.WriteLine("窗口大小改变");
        }

        private void Window_LocationChanged(object sender, EventArgs e)
        {
            // 窗口位置更改时的处理代码
            Console.WriteLine("窗口位置改变");
        }


        private void Window_Closing(object sender, CancelEventArgs e)
        {
            // 尝试关闭窗口时的处理代码
            Console.WriteLine("窗口关闭中");
        }

        private void Window_Closed(object sender, EventArgs e)
        {
            // 窗口已经关闭并且已完成清理操作时的处理代码
            Console.WriteLine("窗口已关闭");
        }


    }
}
