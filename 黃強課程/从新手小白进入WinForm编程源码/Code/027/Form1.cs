using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _027
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //纯代码手工创建
            DateTimePicker dtp = new DateTimePicker();

            dtp.CustomFormat = "yyyy年MM月dd日  tt HH:mm:ss";
            dtp.Format =  DateTimePickerFormat.Custom;
            dtp.Location = new  Point(218, 145);
            dtp.Size = new  Size(409, 25);
            dtp.TabIndex = 0;

            //把控件加入到Form1中
            Controls.Add(dtp);
          
        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {
            MessageBox.Show(dateTimePicker1.Text  );
        }
    }
}
