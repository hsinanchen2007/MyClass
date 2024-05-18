using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _055
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            //获取绘图环境
            Graphics g = e.Graphics;

       
            Pen pen1 = new Pen(Color.Red);
            pen1.DashStyle = DashStyle.Solid;//设置笔的样式，实心画笔
            pen1.Width = 5;//设置笔的粗细
            pen1.SetLineCap(LineCap.Round, LineCap.ArrowAnchor, DashCap.Flat);
            g.DrawLine(pen1, new Point(30, 30), new Point(300, 30));

            Pen pen2 = new Pen(Color.Green);
            pen2.DashStyle = DashStyle.Dash ;//设置笔的样式，虚线笔
            pen2.Width = 6;//设置笔的粗细
            pen2.SetLineCap(LineCap.RoundAnchor, LineCap.Square , DashCap.Triangle);
            g.DrawLine(pen2, new Point(30, 60), new Point(300, 60));

            Pen pen3 = new Pen(Color.Orange);
            pen3.DashStyle = DashStyle.DashDot;//设置笔的样式，虚线+点  笔
            pen3.Width = 6;//设置笔的粗细
            pen3.SetLineCap(LineCap.Square, LineCap.Flat , DashCap.Triangle);
            g.DrawLine(pen3, new Point(30, 90), new Point(300, 90));

            Pen pen4 = new Pen(Color.Yellow);
            pen4.DashStyle = DashStyle.DashDotDot;//设置笔的样式，虚线+点+点  笔
            pen4.Width = 6;//设置笔的粗细
            pen4.SetLineCap(LineCap.Square, LineCap.Flat, DashCap.Triangle);
            g.DrawLine(pen4, new Point(30, 120), new Point(300, 120));


            //--------------------------------------------------------------------------------

            //实心画刷
            Brush bsh1 = new SolidBrush(Color.Red);
            g.FillRectangle(bsh1, new RectangleF(30, 150, 200, 80));

            //渐变画刷
            Brush bsh2 = new LinearGradientBrush(  new Point(0, 0), new Point(255, 0), Color.Red, Color.Blue);
            g.FillRectangle(bsh2, 30, 250, 200, 80);



            g.Dispose();//释放资源
        }
    }
}
