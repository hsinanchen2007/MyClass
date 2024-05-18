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

namespace _054
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Debug.WriteLine("Paint 事件产生！");

            //获取了窗口的图形环境,  方法一
            Graphics g = e.Graphics;

            //画矩形(正方形)
            Pen pen = new Pen(Color.Red);
            g.DrawRectangle(pen, new Rectangle(100,100,200,200));

            //绘制文字
            Font font = new Font(new FontFamily("华文行楷"), 16);
            Brush bsh = new SolidBrush(Color.Blue);

            g.DrawString("你好，这是绘制的!", font, bsh, new Point(100, 50));


            //如果希望 窗口重新绘制的时候也出现
            //Form1_Click(null, null);

            //注意释放绘图资源
            g.Dispose();
        }

        private void Form1_Click(object sender, EventArgs e)
        {
            /*
            //获取了窗口的图形环境 ，方法二
            Graphics g = this.CreateGraphics(); 

            //画椭圆（圆）
            Pen pen = new Pen(Color.Green);
            g.DrawEllipse(pen, new Rectangle(120, 120, 150, 150));

             
            //注意释放绘图资源
            g.Dispose();

            */


            //获取了窗口的图形环境 ，方法三
            Graphics g = Graphics.FromHwnd(this.Handle);

            //填充椭圆（圆）
            Brush bsh = new SolidBrush(Color.Yellow);
            g.FillPie(bsh, new Rectangle(120, 120, 150, 150) , 0 ,180);


            //注意释放绘图资源
            g.Dispose();

        }
    }
}
