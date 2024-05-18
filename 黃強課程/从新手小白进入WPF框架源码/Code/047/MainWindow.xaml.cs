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

namespace _047
{

    public class Stu
    {
        public int Id { get; set; }
        public string Name { get; set; }
        public int Score { get; set; }

        public Stu(int id, string name, int score)
        {
            Id = id;
            Name = name;
            Score = score;
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


            List<Stu> list = new List<Stu>
            {
                new Stu(1, "张三", 100),
                new Stu(2, "李四", 80),
                new Stu(3, "王五", 75)
            };

            listView.ItemsSource = list;


        }
    }
}
