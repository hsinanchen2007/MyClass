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

namespace _017
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
            //根据key查找 ResourceDictionary 中的资源对象
           SolidColorBrush brush=(SolidColorBrush) FindResource("MyBrush");
           String str=(String) FindResource("MyString");

            //遍历资源字典
            foreach( String k in Resources.Keys )
            {
                Console.WriteLine(k + "->" + Resources[k] );
            }

            //动态改变资源的值，来测试  StaticResource 和 DynamicResource的区别
            Resources["MyString"] = "这是改变之后的值！";

            Resources["MyImage"] =  new BitmapImage( new Uri( "/Images/cat.bmp" , UriKind.Relative) );

        }
    }
}
