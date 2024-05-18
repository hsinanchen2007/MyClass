using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _060
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        //打开文档的序号
        private int index = 0;

        private void 新建文档ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Form f = new Form();//新建一个子文档
            
            f.MdiParent = this;//设置窗口的mdi容器
            f.Text = "文档"+ (++index); //文档标题

            f.Show();//显示子文档
        }

        private void 关闭所有文档ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //遍历所有子窗口
            foreach(   Form  f  in this.MdiChildren )
            {
                f.Close();//关闭子窗口
            }
        }

        private void 激活某个文档ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //遍历所有子窗口
            foreach (Form f in this.MdiChildren)
            {
                if(f.Text =="文档2")
                {
                    f.Activate();//激活文档
                }
            }
        }

        //当某个文档被激活时触发
        private void Form1_MdiChildActivate(object sender, EventArgs e)
        {
            MessageBox.Show("当前激活的是" + this.ActiveMdiChild.Text);
        }
    }
}
