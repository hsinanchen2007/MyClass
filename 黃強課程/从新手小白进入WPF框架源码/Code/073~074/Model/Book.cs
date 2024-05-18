using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Model
{
    //书籍类
    public  class Book
    {
        public Book(string name, string isbn, string author)
        {
            Name = name;
            Isbn = isbn;
            Author = author;
        }

        public string Name { get; set; }
        public string Isbn { get; set; }
        public string Author { get; set; }

    }
}
