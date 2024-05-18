using System;
using System.Collections.Generic;
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

namespace _067
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

        private void buttonMT_Click(object sender, RoutedEventArgs e)
        {
            Window1  w= new Window1();

            //弹出模态窗口
            w.ShowDialog();
        }

        private void buttonFMT_Click(object sender, RoutedEventArgs e)
        {
            Window1 w = new Window1();

            //设置父窗口，当父窗口关闭时，子窗口也会关闭
            w.Owner = this;

            //弹出非模态窗口
            w.Show();
        }
    }
}
