using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _023
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void listView1_ColumnClick(object sender, ColumnClickEventArgs e)
        {
            MessageBox.Show("点击了   " +  listView1.Columns[   e.Column ].Text );
        }

        private void listView1_SelectedIndexChanged(object sender, EventArgs e)
        {
            if(listView1.SelectedItems.Count>0)
            {
            //    MessageBox.Show(listView1.SelectedItems[0].Text);
            }
        }

        private void listView1_MouseClick(object sender, MouseEventArgs e)
        {
            //通过一个坐标点获取相应的项
           ListViewItem  item=   listView1.GetItemAt(e.X, e.Y);
        
            if(item!=null)
            {
                //通过坐标点获取点击的子项
                ListViewItem.ListViewSubItem  subItem= item.GetSubItemAt(e.X, e.Y);
                if(subItem!=null)
                {
                    int row = item.Index;//行
                    int col = item.SubItems.IndexOf(subItem);//列
                    MessageBox.Show("第"+row+"行，第"+col+"列     "+ subItem.Text);
                }
            }
        }
    }
}
