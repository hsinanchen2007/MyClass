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

namespace _051
{
    //自定义的树节点
    public class TreeNode
    {
        //名称
        public string Name { get; set; }

        //节点图标
        public string Image { get; set; }

        //子节点的集合
        public List<TreeNode> Children { get; set; }

    }


    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();


            List<TreeNode> list = new List<TreeNode>();



            TreeNode n1 = new TreeNode
            {
                Name = "黄老师",
                Image = "/Images/plane.png",
                Children = new List<TreeNode>()
            };

            TreeNode n2 = new TreeNode
            {
                Name = "李老师",
                Image = "/Images/plane.png"
            };


            TreeNode n11 = new TreeNode
            {
                Name = "C++",
                Image = "/Images/ball.png",
                Children = new List<TreeNode>()
            };

            TreeNode n12 = new TreeNode
            {
                Name = "JAVA",
                Image = "/Images/ball.png",
            };

            TreeNode n111 = new TreeNode
            {
                Name = "基础",
                Image = "/Images/cat.bmp",
            };


            TreeNode n112 = new TreeNode
            {
                Name = "高级",
                Image = "/Images/cat.bmp",
            };

            n1.Children.Add(n11);
            n1.Children.Add(n12);

            n11.Children.Add(n111);
            n11.Children.Add(n112);

            list.Add(n1);
            list.Add(n2);


            treeView.ItemsSource = list;
            treeView.SelectedValuePath = "Name";



        }

        private void treeView_SelectedItemChanged(object sender, RoutedPropertyChangedEventArgs<object> e)
        {
              TreeNode n = (TreeNode)treeView.SelectedItem; 

              Console.WriteLine(n.Name + "  ,"  +  n.Image);  
        }
    }
}
