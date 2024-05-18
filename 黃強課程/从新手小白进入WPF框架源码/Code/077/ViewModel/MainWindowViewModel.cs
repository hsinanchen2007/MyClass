using CommunityToolkit.Mvvm.ComponentModel;
using CommunityToolkit.Mvvm.Input;
using Model;
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace ViewModel
{
    //批注了之后，源生成器  会将 ViewModel 自动实现 INotifyPropertyChanged
    [ObservableObject]
    internal  partial  class MainWindowViewModel  
    {
        //数据访问层
        public DAL dal = new DAL();

        public MainWindowViewModel()
        { 
            Books = dal.GetBookList() ; 
        }


        //对应界面上的  ListView显示的数据
        //ObservableCollection 可以通知界面更新的
        //源生成器自动将首字母大写生成属性
        [ObservableProperty]
        private ObservableCollection<Book> books;



    //删除命令 ，对应界面的删除按钮的点击操作
    //源生成器，会自动生成   (方法名)Del + Command 的命令类型,实现ICommand
    [RelayCommand]
    public  void  Del( object parameter)
     { 
            Book b = parameter as Book;
            //删除执行的内容
            Books.Remove(b);
     }

         
    }
}
