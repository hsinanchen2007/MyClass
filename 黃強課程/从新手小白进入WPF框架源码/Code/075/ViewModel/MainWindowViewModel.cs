using _075.ViewModel;
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

    internal class MainWindowViewModel : BaseViewModel
    {
        //数据访问层
        public DAL dal = new DAL();

        public MainWindowViewModel()
        { 
            Books = dal.GetBookList() ;
            DelCommand  = new RelayCommand( parameter=>
            {
                Book b = parameter as Book;
                //删除执行的内容
                Books.Remove(b);
            } );
        }


        //对应界面上的  ListView显示的数据
        //ObservableCollection 可以通知界面更新的
        private ObservableCollection<Book> books; 
        public ObservableCollection<Book> Books
        {
            get { return books; }
            set { 
                books = value;
                OnPropertyChanged();
            }
        }


        //删除命令 ，对应界面的删除按钮的点击操作
        public  ICommand  DelCommand { get; set; }

         
    }
}
