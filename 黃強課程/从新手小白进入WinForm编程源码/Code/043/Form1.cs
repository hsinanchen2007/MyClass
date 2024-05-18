using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _043
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //纯代码创建流布局面板
            FlowLayoutPanel flp = new FlowLayoutPanel();
            flp.FlowDirection = FlowDirection.TopDown;//从上到下
            flp.AutoScroll = true;
            flp.BorderStyle = BorderStyle.Fixed3D;

            //往布局中添加一个按钮控件
            Button  btn1 = new Button();
            btn1.Size = new Size(100, 60);
            btn1.Margin = new Padding(0, 40, 0, 0);
            flp.Controls.Add(btn1);

            flp.Controls.Add(new Button());
            flp.Controls.Add(new Button());
            flp.Controls.Add(new Button());
            flp.Controls.Add(new Button());
            flp.Location = new  Point(600, 76);
            flp.Padding = new  Padding(20, 30, 20, 0);
            flp.Size = new  Size(199, 483);
            flp.TabIndex = 0;
            flp.WrapContents = false; //是否包裹内容


            //将控件添加到Form1上
            this.Controls.Add(flp);
        }
    }
}
