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

namespace _014
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

        private void radioButton_Checked(object sender, RoutedEventArgs e)
        {
            RadioButton radio = (RadioButton)sender;
            Console.WriteLine(radio.Content+  "单选按钮被选中!"   + radio.IsChecked);
        }

        private void radioButton_Unchecked(object sender, RoutedEventArgs e)
        {
            RadioButton radio = (RadioButton)sender;
            Console.WriteLine(radio.Content + "单选按钮取消选中！！！！" + radio.IsChecked);
        }
    }
}
