using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _044
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //纯代码创建控件
            TableLayoutPanel tlp = new TableLayoutPanel();
            tlp.RowCount = 2;//2行
            tlp.ColumnCount = 3;//3列

            tlp.CellBorderStyle = System.Windows.Forms.TableLayoutPanelCellBorderStyle.Single;
      

            //设置3列宽的比例
            tlp.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50F));
            tlp.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 50F));
            tlp.ColumnStyles.Add(new ColumnStyle(SizeType.Absolute, 155F));

            tlp.Controls.Add(new Button(), 0, 0); //第一行，第一列添加一个按钮
            tlp.Controls.Add(new Button(), 2, 0); //第三行，第一列添加一个按钮
            tlp.Controls.Add(new Button(), 1, 1); //第二行，第二列添加一个按钮

            //设置表格布局面板的坐标和大小
            tlp.Location = new  Point(191, 280);
            tlp.Size = new System.Drawing.Size(462, 170);

            //设置2行高度的比例
            tlp.RowStyles.Add(new  RowStyle( SizeType.Percent, 50F));
            tlp.RowStyles.Add(new  RowStyle( SizeType.Percent, 50F));


            tlp.TabIndex = 0;

            //把控件加入到Form1中
            this.Controls.Add(tlp);

        }
    }
}
