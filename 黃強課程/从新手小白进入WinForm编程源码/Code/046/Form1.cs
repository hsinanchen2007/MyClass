using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _046
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //设置选中页的索引，第二页
            tabControl1.SelectedIndex = 1;
        }

        private void tabControl1_SelectedIndexChanged(object sender, EventArgs e)
        {
            MessageBox.Show("当前页面    " + tabControl1.SelectedTab.Text);
        }
    }
}
