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

namespace _029
{

    //老师类, 将Teacher改为依赖对象，Name属性改为只读依赖属性
   //因此，它只支持 OneWay    源-》控件
    public class Teacher:  DependencyObject
    {
        //输入  propdp  按两次Tab键，自动生成依赖属性的代码

        //依赖属性的辅助类
        internal static readonly DependencyPropertyKey NamePropertyKey = DependencyProperty.RegisterReadOnly(
       "Name",
        typeof(String),
        typeof(Teacher),
       new PropertyMetadata("黄强老师")
       );


        //只读依赖属性
        public static readonly DependencyProperty  NameProperty =  
            NamePropertyKey.DependencyProperty;


        //属性包装器
        public String Name
        {
            get { return (String)GetValue(NameProperty); }
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

            InitializeComponent(); 

            //设置绑定的数据上下文
            DataContext = teacher;

        }
 
        private void textBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            //打印数据源的值，看控件改变了之后，数据源是否改变了
            Console.WriteLine( teacher.Name );
        }
    }
}
