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

namespace _030
{
    /// <summary>
    /// MainWindow.xaml 的交互逻辑
    /// </summary>
    public partial class MainWindow : Window
    {
        // 递归遍历逻辑树并打印元素名称
        private void PrintLogicalTree(DependencyObject element, string indent = "")
        {
            Console.WriteLine(indent + element.GetType().Name);

            foreach (object child in LogicalTreeHelper.GetChildren(element))
            {

                if (child is DependencyObject obj)
                {
                    PrintLogicalTree(obj, indent + "  ");
                }

            }

        }


        // 遍历可视化树并打印元素名称
        private void PrintVisualTree(DependencyObject element, string indent = "")
        {

            Console.WriteLine(indent + element.GetType().Name);
            for (int i = 0; i < VisualTreeHelper.GetChildrenCount(element); i++)
            {
                DependencyObject child = VisualTreeHelper.GetChild(element, i);
                PrintVisualTree(child, indent + "  ");
            }

        }




        public MainWindow()
        {
            InitializeComponent();

            // 访问逻辑树结构
            Console.WriteLine("------------逻辑树----------------");
            PrintLogicalTree(this);
            Console.WriteLine("-------------------------------------");


        }


        //内容渲染完成之后再打印
        private void Window_ContentRendered(object sender, EventArgs e)
        {
            // 访问可视化树结构 
            Console.WriteLine("------------可视化树----------------");
            PrintVisualTree(this);
            Console.WriteLine("-------------------------------------");

        }
    }
}
