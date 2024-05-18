using Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using ViewModel;

namespace View
{
     
     
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
         

        public MainWindow()
        {
            InitializeComponent();

            //设置绑定的数据上下文
            this.DataContext = new MainWindowViewModel();
 
        }
         
    }
}
