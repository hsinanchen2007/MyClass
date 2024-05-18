using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Input;

namespace _075.ViewModel
{
    //以后不用为每个命令单独写一个类了，每个命令都可以使用这个类
    //只不过执行的内容不同
    internal class RelayCommand : ICommand
    {
        public event EventHandler CanExecuteChanged;
      
        //命令执行的函数，参数为object，无返回值的
        private Action<object> executeAction;
        //判断命名能否执行的函数，参数为object，返回值为 bool
        private Func<object, bool> canExecuteFunc; 

        //构造函数中传入
        public RelayCommand(Action<object> execute, Func<object, bool> canExecute = null)
        {
            executeAction = execute;
            canExecuteFunc = canExecute;
        }
         

        public bool CanExecute(object parameter)
        {
           if( canExecuteFunc != null )
            {
                //返回是否能执行
                return canExecuteFunc(parameter);
            }

            return true;
        }

        public void Execute(object parameter)
        {
            //执行命令内容
             if ( executeAction != null )
            {
                executeAction(parameter);
            }
        }
    }
}
