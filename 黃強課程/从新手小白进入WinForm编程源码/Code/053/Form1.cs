using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _053
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            //设置默认的文件名
            saveFileDialog1.FileName = "未命名";
            //设置默认的文件类型
            saveFileDialog1.Filter = "文本|*.txt|C#文件|*.cs|所有文件|*.*";
            //设置默认的文件类型索引
            saveFileDialog1.FilterIndex = 2;
           //设置初始的保存路径
            saveFileDialog1.InitialDirectory = @"d:\";


            DialogResult  dr=    saveFileDialog1.ShowDialog();
            if(dr == DialogResult.OK )
            {
                //如果用户点击确定
                MessageBox.Show(saveFileDialog1.FileName);
            }
        }
    }
}
