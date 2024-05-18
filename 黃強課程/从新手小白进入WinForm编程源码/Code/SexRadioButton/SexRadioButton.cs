using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SexRadioButton
{
    //定义一个委托类型
    public delegate void SexRadioButtonHandler(string sex);

    public partial class SexRadioButton: UserControl
    {

        [CategoryAttribute("操作"), BrowsableAttribute(true), Description("当用户选择性别后的事件")]

        //留给用户订阅的一个事件，选择的性别改变的时候触发
        public event SexRadioButtonHandler SexRadioButtonClick;


        public SexRadioButton()
        {
            InitializeComponent();
        }

        private void radioButton1_Click(object sender, EventArgs e)
        {
            RadioButton rb = sender as RadioButton;

            if(SexRadioButtonClick!=null)
            {//说明用户订阅了
                SexRadioButtonClick(rb.Text);
            }
        }
    }
}
