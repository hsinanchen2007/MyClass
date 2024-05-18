using System.Windows;
using System.Windows.Controls;

namespace _009
{
    internal class MainWindow : Window
    {
        public MainWindow()
        {
            InitializeComponent();
        }

        //初始化窗口的一些控件
        void InitializeComponent()
        {
            //标签文本控件
            Label lbl = new Label();
            lbl.Content = "黄强老师!";
            Content = lbl;
        }

    }
}
