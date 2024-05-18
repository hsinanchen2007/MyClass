using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _018
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //使用纯代码手工创建复选框
            CheckBox cb4 = new CheckBox();

            cb4.Font = new System.Drawing.Font("苏新诗卵石体", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            cb4.ForeColor = System.Drawing.Color.Red;
            cb4.Location = new System.Drawing.Point(152, 254); 
            cb4.Size = new System.Drawing.Size(155, 40);
            cb4.TabIndex = 0;
            cb4.Text = "纯代码复选框";
            cb4.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;

            //把控件加到Form1窗体上
            this.Controls.Add(cb4);
        }

        //3个checkBox公用一个响应函数
        private void checkBox_CheckedChanged(object sender, EventArgs e)
        {
            //CheckedChanged事件仅仅适用于两态复选框
            CheckBox cb = sender as CheckBox;
            MessageBox.Show(cb.Text + "  状态  "+  cb.Checked );
        }


        private void checkBox3_CheckStateChanged(object sender, EventArgs e)
        {
            //CheckStateChanged更加通用，它适用于三态  或 两态
            CheckBox cb = sender as CheckBox;
            //使用CheckState可以判断出是哪种状态， Checked只能判断两种状态 true 表示 选中或者中间态， false表示未选中
            MessageBox.Show(cb.Text + "  状态  " +  cb.CheckState);
        }
    }
}
