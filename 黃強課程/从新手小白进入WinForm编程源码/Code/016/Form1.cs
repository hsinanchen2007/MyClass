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

namespace _016
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //纯代码创建富文本输入框
            RichTextBox rt = new RichTextBox();

            rt.BackColor = System.Drawing.Color.Red;
            rt.Font = new System.Drawing.Font("宋体", 18F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            rt.ForeColor = System.Drawing.Color.Black;
            rt.Location = new System.Drawing.Point(209, 237);
            rt.Size = new System.Drawing.Size(399, 195);
            rt.TabIndex = 0;
            rt.Text = "这是第一行内容\n这是第二行内容......................................\n第三行";
            rt.WordWrap = false;

            //将控件添加到Form1上
            this.Controls.Add(rt);
       
        }

        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {
            Debug.WriteLine(richTextBox1.Text);
        }
    }
}
