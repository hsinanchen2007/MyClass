using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _034
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //让托盘默认隐藏
            //notifyIcon1.Visible = false;

        }

        private void Form1_SizeChanged(object sender, EventArgs e)
        {
            if(this.WindowState == FormWindowState.Minimized)
            {
                //最小化的时候，让托盘显示
                notifyIcon1.Visible = true;
                //同时，窗口不要再任务栏显示
                this.ShowInTaskbar = false;

                //弹出托盘气泡(如果弹不出来， 需要在操作系统中，通知和操作-》专注助手设置  开启)
                this.notifyIcon1.ShowBalloonTip(3000); //测试气泡

            }
        }

        private void notifyIcon1_DoubleClick(object sender, EventArgs e)
        {
            //双击托盘的时候，显示我们的窗口，并且隐藏托盘
            this.notifyIcon1.Visible = false;
            this.WindowState = FormWindowState.Normal;
            this.ShowInTaskbar = true; 
        }
    }
}
