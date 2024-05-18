using System;
using System.Collections;
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

namespace _020
{

    //联系信息类
    public class Contact
    {
        public string City { get; set; }
        public string Phone { get; set; }
    }

    //老师类
    public class Teacher
    {
        public string Name { get; set; }
        public Contact Contact { get; set; }
        public ArrayList Skill { get; set; }
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
    }
}
