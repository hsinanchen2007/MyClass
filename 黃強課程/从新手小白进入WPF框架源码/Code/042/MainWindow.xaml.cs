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

namespace _042
{

    //复杂的数据类
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

            /*
            //每一项是简单的字符串
            List<string> list = new List<string>();
            list.Add("编程");
            list.Add("音乐"); 
            list.Add("篮球");
            //数据源赋值
            comboBox.ItemsSource = list;

            */

            //每一项是一个对象
            List<Stu> list = new List<Stu>
            {
                new Stu(1, "张三", 100),
                new Stu(2, "李四", 80),
                new Stu(3, "王五", 75)
            };

            comboBox.ItemsSource = list;

            //设置显示的每一项对象的属性
            comboBox.DisplayMemberPath = "Name";

            //设置选择的对象的属性
            comboBox.SelectedValuePath = "Score";

        }

        private void comboBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            // 不设置 SelectedValuePath属性的时候， SelectedItem 与  SelectedValue 是一样的
            //设置了 SelectedValuePath属性，那么 SelectedValue 就会按Path指定的属性显示
            Console.WriteLine(comboBox.SelectedItem + ","  + comboBox.SelectedValue  );

            
        }
    }
}
