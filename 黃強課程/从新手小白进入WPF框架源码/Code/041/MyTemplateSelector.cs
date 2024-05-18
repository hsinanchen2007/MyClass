using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace _041
{
    //自定义的数据模板选择器
    public  class MyTemplateSelector :  DataTemplateSelector
    {

       public DataTemplate SmallTemplate { get; set; }
       public DataTemplate LargeTemplate { get; set; }

        //重写选择模板的逻辑
        public override DataTemplate SelectTemplate(object item, DependencyObject container)
        {
            if (item == null)
            {
                return null; // Null value can be passed by IDE designer
            }

            //如果滑块的值小于10，用小的数据模板展示，如果大于10，则用大模板展示数据
            double num = (double)item;
            return num <= 10 ? SmallTemplate : LargeTemplate;

        }
    }
}
