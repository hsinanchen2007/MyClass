#ifndef MYBUTTON_H
#define MYBUTTON_H

#include<QPushButton>


class MyButton : public QPushButton
{
public:
    MyButton();

    //手动设置布局中的大小（虚函数）
         QSize sizeHint() const Q_DECL_OVERRIDE
         {
             return QSize(300,300);
         }
       //手动设置布局中的最小大小（虚函数）
        QSize minimumSizeHint() const Q_DECL_OVERRIDE
        {
            return QSize(180,180);
        }

};

#endif // MYBUTTON_H
