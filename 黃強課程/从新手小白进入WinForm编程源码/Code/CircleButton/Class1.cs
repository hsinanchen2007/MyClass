using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyNS
{
    public class CircleButton:  Button
    {

        private int _diameter ; //圆形按钮的直径


        //圆形按钮的直径属性 
        [CategoryAttribute("外观"), BrowsableAttribute(true), Description("圆形按钮的直径")]

        public int Diameter //属性
        {
            set
            {
                _diameter = value;
                //改直径的时候，改变控件的大小
                this.ClientSize = new Size(_diameter, _diameter);
            }
            get
            {
                return _diameter;
            }

        }

        //构造函数
        public CircleButton()
        {
            this.Diameter = 100;
            this.BackColor = Color.Red;
            this.FlatStyle = FlatStyle.Flat;
            this.FlatAppearance.BorderSize = 0;

        }


        //重写OnPaint,让控件的区域变成圆形
        protected override void OnPaint(System.Windows.Forms.PaintEventArgs e)
        {
            base.OnPaint(e);
            GraphicsPath path = new GraphicsPath();
            path.AddEllipse(0, 0, Diameter, Diameter); //添加了一个椭圆路径
            this.Region = new Region(path); //把区域变成圆形
        }

        //重写OnSizeChanged
        protected override void OnSizeChanged(EventArgs e)
        {
            base.OnSizeChanged(e);

            //如果直径和控件的长宽不同，那么设置直径
            if (Diameter != Width || Diameter != Height)
            {
                _diameter = Width = Height;
            }
        }

    }
}
