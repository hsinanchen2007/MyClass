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

namespace _013
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();

            //按回车键会触发Click事件
            button.IsDefault = true;

            //按Esc键会触发Click事件
            button.IsCancel = true;


            //设置按钮的点击模式
            button.ClickMode = ClickMode.Hover; //光标移上去就触发Click事件
            button.ClickMode = ClickMode.Press; //鼠标按上去才触发Click事件
            button.ClickMode = ClickMode.Release; //鼠标按上去释放时才触发Click事件
        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            Console.WriteLine("按钮被点击了!!!");
        }
    }
}
