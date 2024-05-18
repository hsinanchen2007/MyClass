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

namespace _024
{

    //老师类,实现了 INotifyPropertyChanged 接口
    public class Teacher: INotifyPropertyChanged
    {
        private string name;

        public string Name
        {
            get
            {
                return name;
            }
            set
            {
                name = value;
                NotifyPropertyChanged();
            }
        }

        public event PropertyChangedEventHandler PropertyChanged;

        private void NotifyPropertyChanged([CallerMemberName] String propertyName = "")
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
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
