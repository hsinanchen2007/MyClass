using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _026
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //纯代码手工创建
            MonthCalendar mc = new MonthCalendar();
            mc.Location = new System.Drawing.Point(373, 78);
            mc.MaxDate = new System.DateTime(2020, 12, 10, 0, 0, 0, 0);
            mc.MaxSelectionCount = 100;
            mc.MinDate = new System.DateTime(2020, 12, 1, 0, 0, 0, 0);
            mc.DateChanged += new System.Windows.Forms.DateRangeEventHandler(this.monthCalendar1_DateChanged);

            //添加控件到Form1上
            this.Controls.Add(mc);
        }

        private void monthCalendar1_DateChanged(object sender, DateRangeEventArgs e)
        {
            MonthCalendar mc = sender as MonthCalendar;
            //选择的日期区间
            MessageBox.Show(mc.SelectionStart + "            " + mc.SelectionEnd);
        }
    }
}
