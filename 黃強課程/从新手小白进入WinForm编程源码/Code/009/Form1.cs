using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _009
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //隐藏控件
            //myLabel.Hide();


            //纯手工代码生成Label控件（完全可以copy系统的代码）
            Label label2 = new  Label();
            label2.BackColor = Color.Lime;
            label2.Font = new  Font("宋体", 22.2F,  FontStyle.Regular,  GraphicsUnit.Point, ((byte)(134)));
            label2.ForeColor =  Color.Red;
            //起始坐标点
            label2.Location = new  Point(263, 260);
            //控件大小一样
            label2.Size = new  Size(352, 58);
            label2.Text = "这是一个纯代码生成文本控件";
            label2.Click += new  EventHandler(this.label1_Click);
            
            //把这个控件加入到窗口上
            this.Controls.Add( label2);
        }

        private void label1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("这个文本被点击！！！");
        }

        private void linkLabel1_LinkClicked(object sender, LinkLabelLinkClickedEventArgs e)
        {
            MessageBox.Show("这个超链接文本LinkClicked被点击！！！");
        }
 
    }
}
