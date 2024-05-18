using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _005
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //创建一个窗口对象
            Form f = new Form();
            f.Text = "测试窗口";
            f.BackColor = Color.Pink;
            //人工指定起始坐标
            f.StartPosition = FormStartPosition.Manual;

            //设置窗口的坐标和大小
            f.SetDesktopBounds(100, 100, 400, 400);

            //显示窗口(非模态，不用关闭当前窗口，可以操作其他父窗口)
             f.Show();

            //以模态的方式显示窗口（必须先关闭本窗口，才可以操作其它）
            //f.ShowDialog();

            //隐藏窗口
            //f.Hide();

            //关闭窗口
            f.Close();

            //激活窗口
           //this.Activate();
        }
    }
}
