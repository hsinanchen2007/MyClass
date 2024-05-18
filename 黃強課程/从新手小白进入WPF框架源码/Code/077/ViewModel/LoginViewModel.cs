using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
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

    //批注了之后，源生成器  会将 ViewModel 自动实现 INotifyPropertyChanged
    [ObservableObject]
    internal  partial  class LoginViewModel 
    {

        public LoginViewModel()
        { 

        }

        //属性对应  界面上用户名的TextBox 控件
        //源生成器自动将首字母大写生成属性
        [ObservableProperty]
        private String name ="admin";

        //属性对应  界面上密码的TextBox 控件
        //源生成器自动将首字母大写生成属性
        [ObservableProperty]
        private String pwd;



        //属性对应  界面上报错信息的Label 控件
        //源生成器自动将首字母大写生成属性
        [ObservableProperty]
        private String error="暂无信息";

        //命令属性，对应界面上的  按钮登录事件
        //源生成器，会自动生成   (方法名)Login + Command 的命令类型,实现ICommand
        [RelayCommand]
        public  void Login (object parameter)
        {

            //命令的执行内容  
            if (string.IsNullOrEmpty(Name) || string.IsNullOrEmpty(Pwd))
            {
                Error = "用户名密码不能为空!";
                return;
            }

            User u = dal.FindUserByName(Name);

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

        }

        //数据访问层
        public DAL dal = new DAL();
         


    }
}
