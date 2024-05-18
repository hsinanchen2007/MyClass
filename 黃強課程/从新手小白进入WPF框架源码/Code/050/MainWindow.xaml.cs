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

namespace _050
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

        private void treeView_SelectedItemChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
            Console.WriteLine(   treeView.SelectedItem +  "    ->   "  +  treeView.SelectedValue );

            TreeViewItem  tvi = treeView.SelectedItem as   TreeViewItem;
            Console.WriteLine(tvi.Header);
        }

        private void TreeViewItem_Selected(object sender, RoutedEventArgs e)
        {
            Console.WriteLine("触发" + sender + "Selected 事件");
        }

        private void TreeViewItem_Unselected(object sender, RoutedEventArgs e)
        {
            Console.WriteLine("触发" + sender + "Unselected 事件");
        }
    }
}
