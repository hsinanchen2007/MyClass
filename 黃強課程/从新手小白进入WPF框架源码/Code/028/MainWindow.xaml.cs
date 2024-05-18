using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
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

namespace _028
{

    //老师类, 将Teacher改为依赖对象，Name属性改为依赖属性
    public class Teacher:  DependencyObject
    {
         //输入  propdp  按两次Tab键，自动生成依赖属性的代码

     // Using a DependencyProperty as the backing store for MyProperty.  This enables animation, styling, binding, etc...
        public static readonly DependencyProperty  NameProperty =
            DependencyProperty.Register("Name", typeof(String), typeof(Teacher), new PropertyMetadata("黄强老师"));
         

        //写一个属性包装器，让依赖属性用起来跟普通属性一样的写法
        public String  Name
        {
            get { return (String)GetValue(NameProperty); }
            set { SetValue(NameProperty, value); }
        }

   

    }


    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        //数据源
        Teacher teacher;

        public MainWindow()
        {
            teacher = new Teacher();
            teacher.Name = "黄强老师";

            InitializeComponent(); 

            //设置绑定的数据上下文
            DataContext = teacher;

        }

        private void button_Click(object sender, RoutedEventArgs e)
        {
            //改变数据源的值
            teacher.Name = "改了啦";
        }

        private void textBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            //打印数据源的值，看控件改变了之后，数据源是否改变了
            Console.WriteLine( teacher.Name );
        }
    }
}
