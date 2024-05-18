using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _048
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            DialogResult  dr = MessageBox.Show("这个是消息对话框！","标题");
            Debug.WriteLine("返回结果" + dr.ToString());
        }

        private void button2_Click(object sender, EventArgs e)
        {
            //包含3个按钮  Yes  No  Cancel
            DialogResult dr = MessageBox.Show("这个是消息对话框！","标题",
                MessageBoxButtons.YesNoCancel  );
            Debug.WriteLine("返回结果" + dr.ToString());
        }

        private void button3_Click(object sender, EventArgs e)
        {
            //包含3个按钮  Yes  No  Cancel ,包含图标
            DialogResult dr = MessageBox.Show("这个是消息对话框！", "标题",
                MessageBoxButtons.YesNoCancel ,MessageBoxIcon.Information );
            Debug.WriteLine("返回结果" + dr.ToString());
        }
    }
}
