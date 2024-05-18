using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _020
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //纯代码生成控件
            ComboBox cb = new ComboBox();

            cb.Font = new System.Drawing.Font("宋体", 16.2F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            cb.ForeColor = System.Drawing.Color.Red;
            cb.FormattingEnabled = true;
            cb.Items.Add("AAA");
            cb.Items.Add("DDD");
            cb.Items.Add("CCC");
            cb.Items.Add("BBB");
            cb.Items.Add("字母");
            cb.Sorted=true; //排序选项
            cb.DropDownStyle = ComboBoxStyle.DropDownList;
            cb.SelectedIndex = 1;
            cb.Location = new System.Drawing.Point(265, 184);
            cb.Size = new System.Drawing.Size(220, 35);
            cb.TabIndex = 0;

            //加入控件到Form1中 
            this.Controls.Add(cb);

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            //MessageBox.Show("选择了" + comboBox1.SelectedIndex);

           // MessageBox.Show("选择了" + comboBox1.SelectedItem.ToString());

        }

        private void comboBox1_TextChanged(object sender, EventArgs e)
        {
            MessageBox.Show("内容改变     " + comboBox1.Text);
        }
    }
}
