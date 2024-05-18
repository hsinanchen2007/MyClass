using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Model
{
    //用户类
   public class User
   {
        public User(string name, string pwd,   string phone)
        {
            Name = name;
            Pwd = pwd; 
            Phone = phone;
        }

        public string Name { get; set; }
        public string Pwd { get; set; } 
        public string Phone { get; set; }
    }
}
