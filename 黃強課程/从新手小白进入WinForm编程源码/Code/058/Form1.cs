using _058.Properties;
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

namespace _058
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private float  angle = 0;
        private void Form1_Click(object sender, EventArgs e)
        {
            //先擦除上一次绘制图片  Refresh = Invalidate + Update
            //this.Refresh(); //马上触发Form1_Paint函数

            this.Invalidate();//使窗口无效，发送WM_PAINT消息，但是这个消息是
                              //一个低优先级的消息，并不会马上触发Form1_Paint函数 ，除非遇到Update方法才会马上触发

            this.Update();


            Debug.WriteLine("我开始绘制图片了！！！");

            //获取窗口的绘制环境对象
            Graphics g = Graphics.FromHwnd(this.Handle);
             
            angle = (angle+ 30) %360 ;//每次累加30度

            //将原点坐标移动到窗口的中心
            g.TranslateTransform(this.ClientSize.Width / 2, this.ClientSize.Height / 2);

            //旋转坐标系
            g.RotateTransform(angle);

            //绘制图片
            g.DrawImage(Resources.plane, 
                -Resources.plane.Width/2,
                -Resources.plane.Height / 2);

            //释放资源
            g.Dispose();

            Debug.WriteLine("绘制图片结束了！！！");
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Debug.WriteLine("Paint事件被触发！！！");
        }
    }
}
