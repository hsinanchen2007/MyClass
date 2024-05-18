using _056.Properties;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _056
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


            //绘制图标ico ,指定起始坐标，原大小绘制
            g.DrawIcon(Resources.pc, 10, 10);

            //绘制ico，指定绘制矩形，缩放绘制
            g.DrawIcon(Resources.pc, new Rectangle( 140, 10,50,50));


            //绘制jpg，png ，bmp 原图大小绘制
            g.DrawImage(Resources.dance, 200, 10);

            //绘制jpg，png ，bmp 缩放绘制
            g.DrawImage(Resources.bg, new Rectangle(300, 10, 100, 100));

            //绘制jpg，png ，bmp 裁剪缩放绘制
            g.DrawImage(Resources.snow, new Rectangle(420, 10, 100, 100),
               new Rectangle(0, 0, 200, 400), GraphicsUnit.Pixel);


            //释放资源
            g.Dispose();
        }
    }
}
