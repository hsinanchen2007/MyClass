using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _028
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //纯代码手工打造
            NumericUpDown nud = new NumericUpDown();

            nud.DecimalPlaces = 3;
            nud.Font = new System.Drawing.Font("宋体", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(134)));
            nud.Increment = new Decimal(0.001);
            nud.Location = new System.Drawing.Point(266, 176);
            nud.Size = new System.Drawing.Size(218, 36);
            nud.TabIndex = 0;
            nud.Maximum = 1;
            nud.Minimum = 0.1M;
            //把控件加入到窗体
            this.Controls.Add(nud);

        }

        private void numericUpDown1_ValueChanged(object sender, EventArgs e)
        {
            MessageBox.Show(numericUpDown1.Value.ToString()  );
        }
    }
}
