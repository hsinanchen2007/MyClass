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

namespace _071
{

    //自定义的命令，要实现ICommand接口
    public class MyCommand : ICommand
    {
        //事件
        public event EventHandler CanExecuteChanged;

        public bool CanExecute(object parameter)
        {
            Console.WriteLine("CanExecute ->" + parameter);
           // return  true;   // 启用
           // return false;   // 禁用


            String  str= parameter as String;

            return str?.Length > 0; //如果输入框里是有内容的，才返回true

        }

        //命令执行的内容
        public void Execute(object parameter)
        {
           MessageBox.Show( parameter?.ToString() );
        }


        //定义一个方法， 手动触发CanExecuteChanged事件
        public void RaiseCanExecuteChanged()
        {
            //我们观察猜测的
            //表面上，没有为 CanExecuteChanged 这个事件添加任何订阅方法
            //例如 CanExecuteChanged+= fun；
            //但是其实我们为按钮设置命令时，自动加入了一个此事件订阅的方法，
            //并且这个订阅的方法，会去调用命令的CanExecute()方法 

           Delegate [] dels= CanExecuteChanged?.GetInvocationList();

            //System.Windows.Input.CanExecuteChangedEventManager+HandlerSink
            // OnCanExecuteChanged

            CanExecuteChanged?.Invoke(this, EventArgs.Empty);
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

            button2_Click(null, null);
        }
         

        private void button2_Click(object sender, RoutedEventArgs e)
        {
             MyCommand  c=    Resources["myCmd"]  as MyCommand;

            //触发CanExecuteChanged
            c.RaiseCanExecuteChanged();
        }
         

        private void textBox_TextChanged(object sender, TextChangedEventArgs e)
        {
            //不停的检测
            button2_Click(null, null);
        }
    }
}
