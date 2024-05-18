using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _015
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //纯手工创建掩码输入框
            MaskedTextBox mt = new MaskedTextBox();

            mt.Location = new System.Drawing.Point(196, 190);
            mt.Mask = "手机号码  100  0000 0000";
            mt.Size = new System.Drawing.Size(424, 25);
            mt.TabIndex = 0;
            mt.PromptChar = 'X';//替换_

            //将控件加入到Form1中
            this.Controls.Add(mt);
        }

        private void maskedTextBox1_MaskInputRejected(object sender, MaskInputRejectedEventArgs e)
        {//当输入不符合规则的时候触发
            MessageBox.Show(e.RejectionHint.ToString());
        }
    }
}
