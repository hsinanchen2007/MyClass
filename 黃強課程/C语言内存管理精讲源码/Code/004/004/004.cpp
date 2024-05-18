#include<stdio.h>
#include<stdlib.h>


int  main()
{

	//手动分配、这里就是分配了堆内存
	int  *p = (int*)malloc(10 *  sizeof(int ));

	//手动释放
	free(p);


     int MB = 0;
	 while (malloc(1024 * 1024))//每次分配1M
	 {
			MB++;
	 }
	 printf("分配了 %d MB \n", MB); 


	return 0;
}