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

namespace _010
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();


            //根据x:Name  来访问控件对象 
            myLbl.Content = "更改文本";

            //可以直接使用label对象
            myLbl.FontStyle = FontStyles.Italic;
            myLbl.FontFamily = new FontFamily("华文彩云");

        }
    }
}
