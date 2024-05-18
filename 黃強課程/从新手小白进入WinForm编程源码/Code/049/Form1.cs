using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _049
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //默认选中的颜色
            colorDialog1.Color =Color.Red;

             DialogResult  dr =   colorDialog1.ShowDialog();
            if(dr == DialogResult.OK )
            {
                //只有用户确定的时候，才使用选择的颜色
                this.BackColor = colorDialog1.Color;
            }
        }
    }
}
