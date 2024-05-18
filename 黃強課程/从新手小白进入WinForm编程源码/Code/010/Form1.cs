using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _010
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //纯手工代码生成一个按钮
            Button btn4 = new Button();
            btn4.BackColor = Color.Blue;
            btn4.ForeColor = Color.White;
            btn4.Font = new  Font("微软繁粗圆", 16.2F,  FontStyle.Regular, 
                GraphicsUnit.Point, ((byte)(134)));
            btn4.Location = new System.Drawing.Point(294, 344);
            btn4.Name = "button1";
            btn4.Size = new System.Drawing.Size(194, 66);
            btn4.TabIndex = 0;
            btn4.Text = "纯代码按钮";
            btn4.Click += new System.EventHandler(this.button4_Click);

            //把按钮添加到Form1上
            this.Controls.Add(btn4);

        }

        private void button1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("按钮被点击了！");
        }

        private void button4_Click(object sender, EventArgs e)
        {
            MessageBox.Show("按钮4被点击了！");
        }
    }
}
