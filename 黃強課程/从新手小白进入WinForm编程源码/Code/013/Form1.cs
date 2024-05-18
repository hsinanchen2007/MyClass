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

namespace _013
{
    public partial class Form1 : Form
    {
        //作为类的成员变量
        private TextBox txt = null;
        public Form1()
        {
            InitializeComponent();

            //纯代码生成输入框控件
            txt = new TextBox();
            txt.BackColor =  Color.Lime;
            txt.Font = new  Font("宋体", 13.2F,  FontStyle.Regular,  GraphicsUnit.Point, ((byte)(134)));
            txt.ForeColor =  Color.Red;
            txt.Location = new  Point(224,348); 
            txt.Size = new  Size(372, 38);
            txt.TabIndex = 0;
            txt.Text = "这是纯代码创建的输入框";
            txt.TextChanged += new System.EventHandler(this.textBox3_TextChanged);

            //加入控件到Form1上
            Controls.Add(txt);
        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {
            Debug.WriteLine("文本改变    " + textBox1.Text);
        }
        private void textBox3_TextChanged(object sender, EventArgs e)
        {
            Debug.WriteLine("文本改变    " + txt.Text);
        }
    }
}
