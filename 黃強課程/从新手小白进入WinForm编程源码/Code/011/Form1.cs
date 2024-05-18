using _011.Properties;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Resources;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _011
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();


            //通过代码访问Form1.resx中的资源
           //ComponentResourceManager resources = new ComponentResourceManager(typeof(Form1));
           // button2.Image =   (Image)(resources.GetObject("button1.Image"));

            ResourceManager resources = new ResourceManager(typeof(Form1)); 
            button2.Image = (Image)(resources.GetObject("button1.Image"));

            //访问Resources.resx中的资源
            //  ResourceManager res2 = new ResourceManager(typeof(Properties.Resources));
            //  this.button3.Image = (Image)(res2.GetObject("music"));

            
            this.button3.Image = Resources.music;//资源类的静态属性直接获取


            //访问自己新建的Resources1.resx中的资源
            ResourceManager res4 = new ResourceManager(typeof(Resource1));
            this.button4.Image = (Image)(res4.GetObject("dance"));

           // this.button4.Image = Resource1.dance;//资源类的静态属性直接获取
        }
    }
}
