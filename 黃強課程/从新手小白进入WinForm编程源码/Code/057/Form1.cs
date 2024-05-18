using _057.Properties;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _057
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            //获取绘图环境对象
            Graphics g = e.Graphics;

            //移动原点坐标
            g.TranslateTransform(200, 100);
 
            //旋转当前坐标系一个角度
            g.RotateTransform(90);

            //缩放当前坐标系
            g.ScaleTransform(0.5f, 0.5f);


            //重置坐标系到初始状态
            g.ResetTransform();

            //绘制一张图片
            g.DrawImage(Resources.plane, 0, 0);

            //释放资源
            g.Dispose();
        }
    }
}
