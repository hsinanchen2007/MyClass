#include<stdio.h>
#include<string.h> 


//利用位移运算实现大小端转换 
short  convert(short  s)
{
	//0x1234
	//0x3400            //0x0012
	return (s << 8 | s >> 8);
}



int  main()
{
	//口诀 ：   小端：  高高低低      大端：  高低高低

 
	//方法一---------------------------------------------------
	//两个字节， 数据高位为 0x 12  ，低位为 0x 34
	short   n = 0x1234;
 
	char  *p = (char *)&n; 
	printf("0x%x%x\n" , *p,   *(p+1));
	//             p 是低位      p+1是高位
    // 	  小端   34                 12
	//   大端   12                  34 
	//输出0x1234表示是大端 ， 0x3412是小端


	//方法二---------------------------------------------------
	union  A
	{
		short  s;
		char  c[2];
	};

	A  a;
	a.s = 0x1234;
	//c[0]是地址低位  ，  c[1]是地址高位

	printf("0x%x%x\n",  a.c[0],  a.c[1]);
	//输出0x1234表示是大端 ， 0x3412是小端


	printf("%x    ,    %x  \n", 0x1234 ,  convert(0x1234)  );



	return 0;
}