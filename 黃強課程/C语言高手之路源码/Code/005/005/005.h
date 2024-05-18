//防止头文件重复包含指令
//方法一： 判断文件的方式
#pragma  once

int    a = 100;


//方法二：利用条件编译
/*
#ifndef      __HEADR_005__
#define     __HEADR_005__

int    a = 100;


#endif

*/