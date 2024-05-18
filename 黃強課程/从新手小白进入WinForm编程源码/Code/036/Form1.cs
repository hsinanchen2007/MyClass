using _036.Properties;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _036
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();


            //纯手工创建菜单

            //创建图像列表
            ImageList imgList = new ImageList();
            imgList.Images.Add(Resources.app);
            imgList.Images.Add(Resources.copy);
            imgList.Images.Add(Resources._new);
            imgList.Images.Add(Resources.edit); 
            imgList.Images.Add(Resources.quit);

            //代表了一个菜单栏
            MenuStrip ms = new MenuStrip();
            ms.BackColor = Color.Green;
            ms.Dock = DockStyle.Top;
            ms.ImageList = imgList;//设置菜单栏的图像列表
            ms.ImageScalingSize = new Size(30, 30);//设置菜单图标的大小

            //创建菜单项
            ToolStripMenuItem ts1 = new ToolStripMenuItem("文件");
            ts1.ImageIndex = 0;

            //为ts1创建子菜单
            ToolStripMenuItem ts11 = new ToolStripMenuItem("新建", Resources._new);
            ts11.ShortcutKeys = Keys.Control | Keys.N;
            ToolStripMenuItem ts12 = new ToolStripMenuItem("打开", Resources.copy); 
            ToolStripMenuItem ts13 = new ToolStripMenuItem("保存",Resources.edit);
            ToolStripMenuItem ts14 = new ToolStripMenuItem("其他"); //带勾选的菜单
            ts14.Checked = false;


            //添加菜单响应事件
            ts11.Click += Ts11_Click;
            ts14.Click += Ts14_Click;


            //将四个子菜单加入到ts1菜单中
            ts1.DropDownItems.AddRange(new ToolStripItem[] { ts11, ts12, ts13,
                new ToolStripSeparator(),    ts14 }); 

            ToolStripMenuItem ts2 = new ToolStripMenuItem("退出");
            ts2.ImageIndex = 3;

            //将菜单添加到菜单栏里面
            ms.Items.Add(ts1);
            ms.Items.Add(ts2);

            //将菜单添加到窗口Form1
            this.Controls.Add(ms);
        }

        private void Ts14_Click(object sender, EventArgs e)
        {
            //点击后就取消勾选，勾选后点击就取消
            ToolStripMenuItem ts14 = sender as ToolStripMenuItem;
            ts14.Checked = !ts14.Checked;
        }

        private void Ts11_Click(object sender, EventArgs e)
        {
            MessageBox.Show("新建菜单被点击");
        }
    }
}
