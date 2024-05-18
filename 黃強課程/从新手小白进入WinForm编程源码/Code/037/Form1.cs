using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _037
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //纯代码添加右键菜单

            ContextMenuStrip cms = new ContextMenuStrip();

            ToolStripMenuItem ts1 = new ToolStripMenuItem("第二个");

            //为ts1添加两个子菜单
            ToolStripMenuItem ts11 = new ToolStripMenuItem("子菜单一");
            ToolStripMenuItem ts12 = new ToolStripMenuItem("子菜单二");
            ts1.DropDownItems.Add(ts11);
            ts1.DropDownItems.Add(ts12);

            ToolStripMenuItem ts2 = new ToolStripMenuItem("第三个");
            //添加菜单项
            cms.Items.AddRange(new ToolStripItem[] { ts1, ts2 });

            //将菜单设置到Form1的右键菜单
            this.ContextMenuStrip = cms;
        }

        private void 新建ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            MessageBox.Show("新建菜单被点击！");
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {

            //为什么不用e.Location,它是相对于 窗口左上角的坐标点

            if(e.Button == MouseButtons.Right)
            {//如果是鼠标右键点击
                contextMenuStrip1.Show(  MousePosition );//相对于桌面左上角的坐标
            }
        }
    }
}
