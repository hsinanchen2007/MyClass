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
    //自定义命令类
    class LoginCommand : ICommand
    {
        public event EventHandler CanExecuteChanged;
        public LoginViewModel vm;
        public LoginCommand(LoginViewModel vm)
        {
            this.vm = vm;
        }

        public bool CanExecute(object parameter)
        {
            return true;
        }

        public void Execute(object parameter)
        {
            //命令的执行内容
            String Name =vm.Name ;
            String Pwd = vm.Pwd ;

            if (string.IsNullOrEmpty(Name) || string.IsNullOrEmpty(Pwd))
            {
                vm.Error = "用户名密码不能为空!";
                return;
            }

            User u = vm.dal.FindUserByName(Name);

            if (u != null && u.Pwd == Pwd)
            {
                Window w = parameter as Window;
                //关闭窗口
                w.DialogResult = true;
            }
            else
            {
                vm.Error = "用户名密码错误!";
            }

        }
    }



    internal class LoginViewModel : INotifyPropertyChanged
    {

        public LoginViewModel()
        {
            LoginCommand = new LoginCommand(this);
        }


        //属性对应  界面上用户名的TextBox 控件
        private String name ="admin";
        public String Name
        {
            get { return name; }
            set { 
                name = value;
                OnPropertyChanged("Name");
            }
        }

        //属性对应  界面上密码的TextBox 控件
        private String pwd;
        public String Pwd
        {
            get { return pwd; }
            set { 
                pwd = value;
                OnPropertyChanged("Pwd");
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
                OnPropertyChanged("Error");
              }
        }

        //命令属性，对应界面上的  按钮登录事件
        public  LoginCommand LoginCommand { get; set; }

        //数据访问层
        public DAL dal = new DAL();
         
        //通知属性已经更改
        public event PropertyChangedEventHandler PropertyChanged;
        public void OnPropertyChanged(string propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }

    }
}
