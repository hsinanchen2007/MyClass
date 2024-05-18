using _077;
using Model;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using ViewModel;

namespace View
{
    /// <summary>
    /// Login.xaml 的交互逻辑
    /// </summary>
    public partial class Login : Window
    {

 
        public Login()
        {
            InitializeComponent();

            //将数据上下文设置为  ViewModel
            this.DataContext = new LoginViewModel();
             
        }
  

        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            if (DialogResult != true)
            {
                App.Current.Shutdown();
            }
        }
    }
}
