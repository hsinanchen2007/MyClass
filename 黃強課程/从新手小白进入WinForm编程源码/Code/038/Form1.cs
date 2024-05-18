using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _038
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            toolStripStatusLabel2.Alignment = ToolStripItemAlignment.Right;

            //纯代码添加状态栏

            StatusStrip ss = new StatusStrip();

            ToolStripStatusLabel ssLbl = new ToolStripStatusLabel();
            ssLbl.Text = "纯代码";
            ssLbl.BackColor = Color.Yellow;

            ss.Items.Add(ssLbl);

            ToolStripProgressBar ssPro = new ToolStripProgressBar();
            ssPro.Value = 80;
            ss.Items.Add(ssPro);

            //将控件添加到Form1上
            this.Controls.Add(ss);

        }

        private void toolStripStatusLabel1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("文本被点击");
        }
    }
}
