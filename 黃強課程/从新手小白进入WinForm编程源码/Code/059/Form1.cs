using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _059
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private SolidBrush GetBrush(int x, int y)
        {
            //通过一个坐标产生一个画刷
            Color c = Color.FromArgb((x * 10) % 256, (y + x) % 256, (y * 10) % 256);
            return new SolidBrush(c);
        }


        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {

            //普通绘图
            if(e.Button == MouseButtons.Left)
            {
                this.Text = "普通绘图";

                //获取绘图环境
                Graphics g = Graphics.FromHwnd(this.Handle);

                //把整个窗口背景色填充为白色
                g.FillRectangle(new SolidBrush(Color.White), this.ClientRectangle);

                int W = 30;//正方块的宽度
                int Space = 4;//每个方块的间隔
                for( int i=0; i<  this.ClientSize.Width;i+=(W+Space ) )
                {
                    for (int j = 0; j < this.ClientSize.Height; j += (W + Space))
                    {
                        g.FillRectangle(GetBrush(i,j), i, j, W, W);
                    }
                }

                g.Dispose();//释放资源

            }
            else
            {
                //双缓冲绘图
                this.Text = "双缓冲绘图";

                //第一步，新建一个与窗口大小一样的内存画布
                Bitmap bmp = new Bitmap(ClientSize.Width, ClientSize.Height);

                //第二步，创建一个内存画布的绘图环境
                Graphics gBmp = Graphics.FromImage(bmp);

                //第三步，将复杂的绘图绘制到内存bmp中，此时用户并不可见

                //把整个窗口背景色填充为白色
                gBmp.FillRectangle(new SolidBrush(Color.White), this.ClientRectangle);

                int W = 30;//正方块的宽度
                int Space = 4;//每个方块的间隔
                for (int i = 0; i < this.ClientSize.Width; i += (W + Space))
                {
                    for (int j = 0; j < this.ClientSize.Height; j += (W + Space))
                    {
                        gBmp.FillRectangle(GetBrush(i, j), i, j, W, W);
                    }
                }


                //第四步，一次性将内存bmp中的图像 绘制到窗口上，那么此时用户将看到图像
                Graphics gForm = Graphics.FromHwnd(this.Handle);//获取窗口的绘图环境
                gForm.DrawImage(bmp, 0, 0);//内存图像与窗口大小一致

                //释放资源
                gBmp.Dispose();
                gForm.Dispose();
                bmp.Dispose();

            }
        }
    }
}
