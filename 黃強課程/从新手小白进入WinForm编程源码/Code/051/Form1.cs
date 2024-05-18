using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _051
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //设置字体对话框的初始值
            fontDialog1.Font = new Font(new FontFamily("华文行楷"), 16);
            fontDialog1.Color = Color.Green;

           DialogResult  dr=   fontDialog1.ShowDialog();
            if( dr == DialogResult.OK )
            {
                //如果用户点击了确定按钮
                button1.Font = fontDialog1.Font; //选择的字体
                button1.ForeColor = fontDialog1.Color;//选择的颜色
            }
        }
    }
}
