using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _007
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            Debug.WriteLine("窗口被加载Form1_Load");
        }
 
        private void Form1_Activated(object sender, EventArgs e)
        {
            Debug.WriteLine("窗口被激活Form1_Activated");
        }

        private void Form1_Shown(object sender, EventArgs e)
        {
            Debug.WriteLine("窗口第一次显示Form1_Shown");
        }
        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            Debug.WriteLine("窗口关闭中Form1_FormClosing");
        }

        private void Form1_FormClosed(object sender, FormClosedEventArgs e)
        {
            Debug.WriteLine("窗口关闭后Form1_FormClosed");
        }

        //其它的事件
        private void Form1_Deactivate(object sender, EventArgs e)
        {
            Debug.WriteLine("窗口未激活Form1_Deactivate");
        }

        private void Form1_Move(object sender, EventArgs e)
        {
            Debug.WriteLine("窗口移动Form1_Move");
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Debug.WriteLine("窗口绘制Form1_Paint");
        }

        private void Form1_SizeChanged(object sender, EventArgs e)
        {
            Debug.WriteLine("窗口大小改变Form1_SizeChanged");
        }
    }
}
