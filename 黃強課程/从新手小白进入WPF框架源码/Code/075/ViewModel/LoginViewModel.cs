using _075.ViewModel;
using Model;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Input;

namespace ViewModel
{ 
     

    internal class LoginViewModel : BaseViewModel
    {

        public LoginViewModel()
        {
            LoginCommand = new RelayCommand( parameter=>
            {
                //命令的执行内容 

                if (string.IsNullOrEmpty(Name) || string.IsNullOrEmpty(Pwd))
                {
                     Error = "用户名密码不能为空!";
                    return;
                }

                User u =  dal.FindUserByName(Name);

                if (u != null && u.Pwd == Pwd)
                {
                    Window w = parameter as Window;
                    //关闭窗口
                    w.DialogResult = true;
                }
                else
                {
                   Error = "用户名密码错误!";
                }

            });
        }


        //属性对应  界面上用户名的TextBox 控件
        private String name ="admin";
        public String Name
        {
            get { return name; }
            set { 
                name = value;
                OnPropertyChanged();
            }
        }

        //属性对应  界面上密码的TextBox 控件
        private String pwd;
        public String Pwd
        {
            get { return pwd; }
            set { 
                pwd = value;
                OnPropertyChanged();
            }
        }


        //属性对应  界面上报错信息的Label 控件
        private String error="暂无信息";
        public String Error
        {
            get { return error; }
            set
            { 
                error = value; 
                OnPropertyChanged();
              }
        }

        //命令属性，对应界面上的  按钮登录事件
        public  ICommand LoginCommand { get; set; }

        //数据访问层
        public DAL dal = new DAL();
         


    }
}
