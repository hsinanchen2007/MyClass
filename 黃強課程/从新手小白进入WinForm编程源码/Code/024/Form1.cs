using _024.Properties;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _024
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //首先新建ImageList 添加小图标
            ImageList imgList = new ImageList();
            //添加四个图片
            imgList.Images.Add(Resources.computer);
            imgList.Images.Add(Resources.dance);
            imgList.Images.Add("music",Resources.music); //添加图片，同时指定key
            imgList.Images.Add(Resources.note);
            //设定图片的大小
            imgList.ImageSize = new Size(20, 20);



            //创建ListView控件 
            ListView listView1 = new ListView();
            listView1.View = View.Details; 
            listView1.Location = new  Point(169, 31);
            listView1.Size = new  Size(482, 364);
            listView1.SmallImageList = imgList;//设置小图标列表
            listView1.TabIndex = 0;
            listView1.GridLines = true;
            listView1.HideSelection = false;//显示 选择的项
            listView1.FullRowSelect = true;

            //设置列表头
            ColumnHeader columnHeader1 = new ColumnHeader();
            columnHeader1.Text = "第一列";
            columnHeader1.Width = 200; //设置列宽
            ColumnHeader columnHeader2 = new ColumnHeader();
            columnHeader2.Text = "第二列";
            ColumnHeader columnHeader3 = new ColumnHeader();
            columnHeader3.Text = "第三列";
            listView1.Columns.AddRange(new  ColumnHeader[] { columnHeader1,   columnHeader2,   columnHeader3});

            //设置列表内容
            ListViewItem listViewItem1 = new ListViewItem("音乐");
            listViewItem1.ImageKey = "music";
            listViewItem1.SubItems.Add(new ListViewItem.ListViewSubItem(listViewItem1, "111"));
            listViewItem1.SubItems.Add(new ListViewItem.ListViewSubItem(listViewItem1, "222"));
            listView1.Items.Add(listViewItem1);
         

            ListViewItem listViewItem2 = new ListViewItem("编程",0);
            listViewItem2.SubItems.AddRange(new string[] { "333","444"});
            listView1.Items.Add(listViewItem2);

            ListViewItem listViewItem3 = new ListViewItem("跳舞",1);
            listView1.Items.Add(listViewItem3);
             
            ListViewItem listViewItem4 = new ListViewItem("写作", 3);
            listView1.Items.Add(listViewItem4);

            //把控件添加到Form1上去
            this.Controls.Add(listView1);

            //添加事件
             listView1.MouseClick += new System.Windows.Forms.MouseEventHandler(this.listView1_MouseClick);


        }


        private void listView1_MouseClick(object sender, MouseEventArgs e)
        {
            ListView listView1 = sender as ListView;

            //通过一个坐标点获取相应的项
            ListViewItem item = listView1.GetItemAt(e.X, e.Y);

            if (item != null)
            {
                //通过坐标点获取点击的子项
                ListViewItem.ListViewSubItem subItem = item.GetSubItemAt(e.X, e.Y);
                if (subItem != null)
                {
                    int row = item.Index;//行
                    int col = item.SubItems.IndexOf(subItem);//列
                    MessageBox.Show("第" + row + "行，第" + col + "列     " + subItem.Text);
                }
            }
        }
    }


}
