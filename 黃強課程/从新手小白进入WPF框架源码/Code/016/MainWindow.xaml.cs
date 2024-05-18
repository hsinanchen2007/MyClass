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

namespace _016
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

        private void button_Click(object sender, RoutedEventArgs e)
        {
            Console.WriteLine("Source :   " + image.Source);


            BitmapImage img = new BitmapImage();
            img.BeginInit();

            //绝对的PACK URI (省略了当前程序集)
            //  img.UriSource =new Uri("pack://application:,,,/Images/cat.bmp"); 

            //绝对的PACK URI ( 有当前程序集)
            // img.UriSource =new Uri("pack://application:,,,/016;component/Images/cat.bmp");

            //相对的PACK URI ( 省略了当前程序集)
           img.UriSource = new Uri("/Images/cat.bmp", UriKind.Relative);

            //相对的PACK URI ( 带当前程序集)
             //  img.UriSource = new Uri("/016;component/Images/cat.bmp", UriKind.Relative);

            img.EndInit();

            image.Source = img;

        }
    }
}
