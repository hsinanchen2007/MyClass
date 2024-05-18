using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _032
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //纯代码方式创建进度条
            ProgressBar pb = new ProgressBar();
            pb.Location = new Point(200,200);
            pb.Size = new Size(300, 40);
            pb.Maximum = 100;
            pb.Minimum = 0;

            //设置进度条的当前值
            pb.Value = 50;

            //把控件添加到Form1
            this.Controls.Add(pb);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            //如果进度条没有达到最大值
            if (progressBar1.Value< progressBar1.Maximum)
            {
                //progressBar1.Value++; //进度+1

                //按照步长Step进行递增
                progressBar1.PerformStep();
            }

        }
    }
}
