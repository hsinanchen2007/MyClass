using _039.Properties;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _039
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //纯代码创建控件
            ToolStrip ts = new ToolStrip();
            ts.Dock = DockStyle.Left;//添加到窗口的左侧
            ts.ImageScalingSize = new Size(40, 40); //设置图标的大小

            //工具条上的按钮
            ToolStripButton ts1 = new ToolStripButton("跳舞", Resources.dance2);
            ts1.DisplayStyle = ToolStripItemDisplayStyle.Image;
            ts.Items.Add(ts1); //添加按钮到工具条上

            ToolStripButton ts2 = new ToolStripButton("跳舞", Resources.app);
            ts2.DisplayStyle = ToolStripItemDisplayStyle.ImageAndText;
            ts2.TextImageRelation = TextImageRelation.ImageAboveText;
            ts.Items.Add(ts2);

            ToolStripButton ts3 = new ToolStripButton("跳舞", Resources.edit);
            ts3.TextImageRelation = TextImageRelation.TextBeforeImage;
            ts.Items.Add(ts3);

            //添加控件到Form1上
            this.Controls.Add(ts);
       }

        private void toolStripButton1_Click(object sender, EventArgs e)
        {
            MessageBox.Show("按钮被点击！");
        }
    }
}
