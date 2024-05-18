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

namespace _037
{


    //分组类， 产生一个 组ID  的附加属性
    class MyGroup
    {
      // Using a DependencyProperty as the backing store for MyProperty.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty  IdProperty =
            DependencyProperty.RegisterAttached("Id", typeof(int), typeof(MyGroup), new PropertyMetadata(0));


        //两个静态访问器
        public static int GetId(DependencyObject obj)
        {
            return (int)obj.GetValue(IdProperty);
        }

        public static void SetId(DependencyObject obj, int value)
        {
            obj.SetValue(IdProperty, value);
        }  

    }

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
            //依赖对象，Button
            Button button = (Button)sender;

            //使用静态访问器获取附加属性的值
           int  id = MyGroup.GetId( button );
            MessageBox.Show("按钮的组ID是：" + id.ToString());
        }
    }
}
