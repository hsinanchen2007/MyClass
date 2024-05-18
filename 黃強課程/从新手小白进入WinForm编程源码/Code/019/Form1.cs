using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _019
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //使用纯代码创建控件了
            RadioButton rb4 = new RadioButton();

            rb4.AutoSize = true;
            rb4.Location = new System.Drawing.Point(104, 201);
            rb4.Size = new System.Drawing.Size(58, 19);
            rb4.TabIndex = 0;
            rb4.TabStop = true;
            rb4.Text = "男性";

            RadioButton rb5 = new RadioButton();

            rb5.AutoSize = true;
            rb5.Location = new System.Drawing.Point(360, 201);
            rb5.Size = new System.Drawing.Size(58, 19);
            rb5.TabIndex = 0;
            rb5.TabStop = true;
            rb5.Text = "女性";

            this.Controls.Add(rb4);
            this.Controls.Add(rb5);
        }

        private void radioButton_CheckedChanged(object sender, EventArgs e)
        {
            //所有的单选按钮共享这一个事件处理函数
            RadioButton rb = sender as RadioButton;
            if (rb.Checked)
            {
                MessageBox.Show(rb.Text + "   " + rb.Checked);
            } 
        }
    }
}
