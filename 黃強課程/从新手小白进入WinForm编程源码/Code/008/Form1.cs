using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _008
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //退出消息循环，从而导致程序退出
            Application.Exit();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //重启运用程序
            Application.Restart();
        }
    }
}
