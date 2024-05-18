#include<windows.h>
#include<stdio.h>

DWORD   WINAPI   ThreadFun(LPVOID  paramter);

//�������ƺ�ͣ��ʱ��
struct  Car
{
	char         name[20];
	DWORD   time; 
};

HANDLE  hSemaphore = INVALID_HANDLE_VALUE;

int  main()
{
	//ֻ��3��ͣ��λ��Դ
    hSemaphore = CreateSemaphore(NULL, 3, 3, L"ͣ��λ");

	HANDLE  hArr[5] = { INVALID_HANDLE_VALUE };

	for (int i = 0; i < 5; ++i)
	{
		  Car *pCar = new Car;
		  sprintf(pCar->name, "����%c", 'A' + i);
		  pCar->time = 3 + i * 3; 

		  //���������߳�
		  hArr[i]= CreateThread(NULL, 0, ThreadFun, (LPVOID)pCar, 0, NULL);  
	}

	//�ȴ������߳�ִ�����
	WaitForMultipleObjects(5, hArr, true, INFINITE);

	return 0;
}

DWORD   WINAPI   ThreadFun(LPVOID  paramter)
{
	//�����ʣ��ͣ��λ��Դ�����ź�״̬�����ͷ���
	WaitForSingleObject(hSemaphore, INFINITE);

	Car  *pCar = (Car *)paramter;

	printf("%s����ͣ����,ͣ��%d�룡\n", pCar->name, pCar->time);
	Sleep(pCar->time * 1000);
	printf("%sʻ��ͣ������\n", pCar->name);

	//�ͷ�һ��ͣ��λ���ź���+1��
	ReleaseSemaphore(hSemaphore,1,NULL);

	return  0;
}
