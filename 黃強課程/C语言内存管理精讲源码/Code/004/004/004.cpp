#include<stdio.h>
#include<stdlib.h>


int  main()
{

	//�ֶ����䡢������Ƿ����˶��ڴ�
	int  *p = (int*)malloc(10 *  sizeof(int ));

	//�ֶ��ͷ�
	free(p);


     int MB = 0;
	 while (malloc(1024 * 1024))//ÿ�η���1M
	 {
			MB++;
	 }
	 printf("������ %d MB \n", MB); 


	return 0;
}