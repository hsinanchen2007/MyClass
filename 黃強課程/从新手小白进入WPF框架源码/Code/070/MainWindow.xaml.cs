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

namespace _070
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

        private void CommandBinding_CanExecute(object sender, CanExecuteRoutedEventArgs e)
        {//检测命令是否能执行 
            //这里CanExecute 每次传过来都是false
            Console.WriteLine("CanExecute...." + e.CanExecute);

            //true 让命令源按钮 可以启用
            //false  禁用按钮


            //如果输入框选择的 有内容，剪切按钮才可以启用 
            if( textBox.SelectionLength > 0 )
            {
              e.CanExecute = true;
            }

        }

        private void CommandBinding_Executed(object sender, ExecutedRoutedEventArgs e)
        {//命令执行的内容
            Console.WriteLine("Execute!!!" );

            textBox.Cut();
        }
    }
}
