using _031.Properties;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _031
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //纯代码手动创建
            ImageList imgList = new ImageList();

            //加入图片到图像列表
            imgList.Images.Add(Resources.computer);
            imgList.Images.Add(Resources.dance);
            imgList.Images.Add(Resources.note);
            imgList.Images.Add(Resources.music);

            imgList.ImageSize = new Size(16, 16);

            //创建树视图控件
            TreeView tv = new TreeView();
            tv.Location = new Point(200, 30);
            tv.Size = new Size(300, 400);
            tv.ImageList = imgList; //设置树视图的图像列表

      
            tv.Nodes.Add("爱好");//加入第一个根节点

            //加入第二个根节点
            TreeNode tn2 = new TreeNode("其它", 0, 0);
            tv.Nodes.Add(tn2);

            //在第一个根节点下加入三个节点
            TreeNode tn1 = tv.Nodes[0];
            TreeNode tn11 = new TreeNode("电脑", 0, 0);
            TreeNode tn12 = new TreeNode("音乐", 3, 3);
            TreeNode tn13 = new TreeNode("跳舞", 1, 1);
            tn1.Nodes.Add(tn11);
            tn1.Nodes.Add(tn12);
            tn1.Nodes.Add(tn13);
             

            //在第二个根节点下加入一个节点
            TreeNode tn21 = new TreeNode("写作", 2, 2);
            tn2.Nodes.Add(tn21);


            tv.ExpandAll();//展开所有节点
             

            //添加控件到Form1
            this.Controls.Add(tv);
        }
    }
}
