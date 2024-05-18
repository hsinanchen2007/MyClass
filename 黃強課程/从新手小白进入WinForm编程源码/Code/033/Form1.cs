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

namespace _033
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();

            //禁止弹出脚本错误
            webBrowser1.ScriptErrorsSuppressed = true;

        }

        private void webBrowser1_DocumentCompleted(object sender, WebBrowserDocumentCompletedEventArgs e)
        {
            Debug.WriteLine("网页加载完成！");

            //刷新按钮状态
            buttonBack.Enabled = webBrowser1.CanGoBack;
            buttonForward.Enabled = webBrowser1.CanGoForward;
        }

        private void webBrowser1_NewWindow(object sender, CancelEventArgs e)
        {
            Debug.WriteLine("点击一个链接时，产生了新窗口！");

    
            //禁止在新窗口中打开
            e.Cancel = true;
            //跳转到新网页
            webBrowser1.Navigate(webBrowser1.StatusText);


        }

        private void buttonForward_Click(object sender, EventArgs e)
        {
            webBrowser1.GoForward();//前进
        }

        private void buttonBack_Click(object sender, EventArgs e)
        {
            webBrowser1.GoBack();//后退     
        }

        private void buttonRefresh_Click(object sender, EventArgs e)
        {
            webBrowser1.Refresh();//刷新
        }
    }
}
