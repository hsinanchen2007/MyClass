using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _014
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //纯代码创建工具提示
            ToolTip tt = new ToolTip();
            tt.AutoPopDelay = 30000;//30秒
            tt.IsBalloon = false;
            tt.InitialDelay = 10;//10毫秒

            //为哪个控件设置工具提示
            tt.SetToolTip(this, "这是纯代码的提示：窗口");
            tt.SetToolTip(this.button1, "这是纯代码的提示：按钮");
            tt.SetToolTip(this.label1, "这是纯代码的提示：标签");
        }
    }
}
