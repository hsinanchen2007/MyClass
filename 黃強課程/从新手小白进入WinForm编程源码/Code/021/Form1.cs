using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _021
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //纯代码手工创建
            ListBox lb = new ListBox();

            lb.Font = new System.Drawing.Font("宋体", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            lb.ForeColor = System.Drawing.Color.Red;
            lb.ItemHeight = 25;
            lb.Items.AddRange(new object[] {
            "AAA",
            "BBB",
            "DDD",
            "CCCC",
            "EEE"});

            lb.Items.Add("编程");

            lb.Location = new System.Drawing.Point(262, 300);
            lb.MultiColumn = true;
            lb.SelectionMode = System.Windows.Forms.SelectionMode.MultiSimple;
            lb.Size = new System.Drawing.Size(374, 179);
            lb.TabIndex = 0;
            lb.SelectedIndexChanged += new System.EventHandler(this.listBox1_SelectedIndexChanged);

            //把控件加到Form1
            this.Controls.Add(lb);
        }

        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            ListBox list = sender as ListBox;

            String strSelect = "";
            //获取多选的项目
            for(int i=0;i< list.SelectedItems.Count;++i)
            {
                strSelect += "  ";
                strSelect += list.SelectedItems[i];
            }
            MessageBox.Show(strSelect);
        }
    }
}
