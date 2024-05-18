using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Model
{
    //数据访问层，操作数据库
    public class DAL
    {

        //模拟查询数据库书籍表数据
        public ObservableCollection<Book>  GetBookList()
        {
            ObservableCollection<Book>  list    = new ObservableCollection<Book>();
            list.Add(new Book("Java高级编程", "111", "李老师"));
            list.Add(new Book("C++高级编程", "222", "黄老师"));
            list.Add(new Book("C#高级编程", "333", "马老师"));

            return list; 
        }

        //模拟查询数据库用户表数据
        public List<User> GetUserList()
        {
            List<User> list = new List<User>();
            list.Add(new User("admin", "123", "1111111"));
            list.Add(new User("张三", "123", "2222222"));  
            return list;
        }  
 
     
        //通过用户名查找用户
        public  User  FindUserByName(String name)
        { 
             List<User> users = GetUserList();

            foreach ( User u in users )
            {
                if(u.Name == name)
                    return u;
            }

            return null;
        }

    }
}
