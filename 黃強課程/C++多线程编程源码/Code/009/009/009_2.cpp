#include<windows.h>
#include<stdio.h>
 
 

int  main()
{
	//����Semaphoreʵ�ֳ���ֻ����һ����������
	HANDLE  hSemaphore = CreateSemaphore(NULL, 3, 3, L"ͣ��λ");
	  if(GetLastError()== ERROR_ALREADY_EXISTS)
	  {
		  printf("�����Ѿ������벻Ҫ����������̣�");
		  getchar();
		  CloseHandle(hSemaphore);
		  return  0;
      }

	  printf("�����һ��������"); 
	  getchar();

	return 0;
}
 