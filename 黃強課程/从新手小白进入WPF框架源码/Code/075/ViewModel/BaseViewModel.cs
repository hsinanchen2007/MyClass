using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;

namespace _075.ViewModel
{

    //ViewModel的公共类，实现
    internal class BaseViewModel: INotifyPropertyChanged
    {
        //通知属性已经更改
        public event PropertyChangedEventHandler PropertyChanged;

        //这里加了CallerMemberName ，可以自动获取 属性名称，参数可以不传
        public void OnPropertyChanged([CallerMemberName] string propertyName = null)
        {
            PropertyChanged?.Invoke(this, new PropertyChangedEventArgs(propertyName));
        } 
    }
}
