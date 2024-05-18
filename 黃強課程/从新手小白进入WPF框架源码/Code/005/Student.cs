using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Controls;

namespace _005
{
    //自定义的类，继承Button是为了方便在界面中观察效果
    internal class Student : Button
    {
         //学生年龄
          public String  Age { get; set; }
    }
}
