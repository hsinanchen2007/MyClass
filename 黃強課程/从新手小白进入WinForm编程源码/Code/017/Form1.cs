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

namespace _017
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //内容是否改变
            Boolean b1 = richTextBox1.Modified;
            //是否可以撤销
            Boolean b2 = richTextBox1.CanUndo;

            //从索引1开始，选中3个字符
            richTextBox1.Select(1, 3);

            //设置选中文本的背景色
            richTextBox1.SelectionBackColor = Color.Red;

            //设置选中文本的字体
            richTextBox1.SelectionFont =
                new Font("华文行楷", 28, FontStyle.Underline);

            //再次选中一段
            richTextBox1.Select(6, 3);

            //设置选中文本的文本颜色
            richTextBox1.SelectionColor = Color.Yellow;

            //全选
            //richTextBox1.SelectAll();

             b1 = richTextBox1.Modified;
             b2 = richTextBox1.CanUndo;

            //获取选择的起始位置和长度
            int  start= richTextBox1.SelectionStart;
            int  len = richTextBox1.SelectionLength;
        }

        private void buttonAdd_Click(object sender, EventArgs e)
        {
            richTextBox1.AppendText(Environment.NewLine+"这是添加的一行文本");
        }

        private void buttonFind_Click(object sender, EventArgs e)
        {
           int pos=richTextBox1.Find("第二行");
            if(pos>=0)//找到了
            {
                //再次选中一段
                richTextBox1.Select(pos, 3);
                //设置选中文本的文本颜色
                richTextBox1.SelectionBackColor = Color.Blue;

                //替换选中的文本
                richTextBox1.SelectedText = "XXX";

                //滚动到插入符号的位置
                richTextBox1.ScrollToCaret();
            }
        }

        private void buttonCut_Click(object sender, EventArgs e)
        {
            //剪切你选中的内容
            richTextBox1.Cut();
        }

        private void buttonPaste_Click(object sender, EventArgs e)
        {
            //粘贴剪切板里面的内容
            richTextBox1.Paste();
        }

        private void buttonUndo_Click(object sender, EventArgs e)
        {
            //撤销你的更改
            richTextBox1.Undo();
        }

        private void buttonCopy_Click(object sender, EventArgs e)
        {
            //复制选择的内容
            richTextBox1.Copy();
        }

        private void buttonLoad_Click(object sender, EventArgs e)
        {
            richTextBox1.LoadFile("1.rtf");
        }

        private void buttonSave_Click(object sender, EventArgs e)
        {
           richTextBox1.SaveFile("1.rtf");

            // richTextBox1.SaveFile("1.txt");
        }
    }
}
