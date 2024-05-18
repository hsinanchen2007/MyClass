using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _052
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //过滤文件类型
            openFileDialog1.Filter = "文本|*.txt|C#文件|*.cs|所有文件|*.*";
            //默认选择第几个过滤
            openFileDialog1.FilterIndex =2;
            //默认打开的文件目录
            openFileDialog1.InitialDirectory = @"c:\";


           DialogResult  dr=   openFileDialog1.ShowDialog();
            if(dr == DialogResult.OK)
            {
                //文件的绝对路径
                MessageBox.Show(openFileDialog1.FileName);
            }
        }
    }
}
