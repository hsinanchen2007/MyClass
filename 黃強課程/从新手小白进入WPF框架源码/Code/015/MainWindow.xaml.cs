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

namespace _015
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

        private void checkBox_Checked(object sender, RoutedEventArgs e)
        {
            CheckBox  cb = (CheckBox)sender;
            Console.WriteLine(cb.Content + "被选中" + cb.IsChecked);
        }

        private void checkBox_Unchecked(object sender, RoutedEventArgs e)
        {
            CheckBox cb = (CheckBox)sender;
            Console.WriteLine(cb.Content + "取消选中" + cb.IsChecked);
        }

        private void checkBox_Indeterminate(object sender, RoutedEventArgs e)
        {
            CheckBox cb = (CheckBox)sender;
            Console.WriteLine(cb.Content + "不确定状态" +  (cb.IsChecked == null ?"null": "不是null") );
        }
    }
}
