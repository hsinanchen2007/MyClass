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

namespace _006
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void Form1_Click(object sender, EventArgs e)
        {
            //鼠标单击
            Debug.WriteLine("鼠标单击Form1_Click");
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {
            //鼠标单击,告诉你是哪个鼠标键，左、中、右
            Debug.WriteLine("鼠标"+ e.Button  + "单击Form1_MouseClick");
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            Debug.WriteLine("鼠标移动Form1_MouseMove");
        }

        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            Debug.WriteLine("键盘按下Form1_KeyDown     "+e.KeyCode);
        }
    }
}
