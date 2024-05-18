using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _050
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //默认选中的目录
            folderBrowserDialog1.SelectedPath = @"c:\intel";

           DialogResult dr=    folderBrowserDialog1.ShowDialog();
            if(dr == DialogResult.OK )
            {
                //用户点击了确定，我们才使用选择的目录
                MessageBox.Show(folderBrowserDialog1.SelectedPath);
            }
        }
    }
}
