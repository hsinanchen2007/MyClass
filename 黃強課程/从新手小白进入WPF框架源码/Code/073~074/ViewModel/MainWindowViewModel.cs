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

    class DelCommand : ICommand
    {
        public event EventHandler CanExecuteChanged;

        private MainWindowViewModel vm;

        public DelCommand(MainWindowViewModel vm)
        {
            this.vm = vm;
        }

        public bool CanExecute(object parameter)
        {
            return true;
        }

        //传入的参数是命令的绑定的参数Book类的对象
        public void Execute(object parameter)
        {
            Book  b = parameter as Book;
            //删除执行的内容
            vm.Books.Remove(b);
        }
    }

    internal class MainWindowViewModel : INotifyPropertyChanged
    {
        //数据访问层
        public DAL dal = new DAL();

        public MainWindowViewModel()
        { 
            Books = dal.GetBookList() ;
            DelCommand  = new DelCommand(this);
        }


        //对应界面上的  ListView显示的数据
        //ObservableCollection 可以通知界面更新的
        private ObservableCollection<Book> books; 
        public ObservableCollection<Book> Books
        {
            get { return books; }
            set { 
                books = value;
                OnPropertyChanged("Books");
            }
        }


        //删除命令 ，对应界面的删除按钮的点击操作
        public  DelCommand  DelCommand { get; set; }


        //通知属性已经更改
        public event PropertyChangedEventHandler PropertyChanged;
        public void OnPropertyChanged(string propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        }
    }
}
