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

namespace _068
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

        private void button_Back_Click(object sender, RoutedEventArgs e)
        {
            //返回上一页
            if(frame.CanGoBack )
            {
                 frame.GoBack();
            }
 
        }

        private void button_1_Click(object sender, RoutedEventArgs e)
        {
            frame.Content = new Page1();
        }

        private void button_2_Click(object sender, RoutedEventArgs e)
        {
            frame.Navigate(new Uri("Page2.xaml" ,UriKind.Relative));
        }

        private void button_3_Click(object sender, RoutedEventArgs e)
        {
            frame.Navigate(new  Page3() );
        }

        private void button_Forward_Click(object sender, RoutedEventArgs e)
        {
            //去下一页
            if(frame.CanGoForward)
            {
                frame.GoForward();
            }
  
        }
    }
}
