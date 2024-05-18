#include<windows.h>
#include<queue>
#include <process.h> 
using namespace  std;
 
//��һ���ֿ�
queue<int>  store;
int   StoreSize = 3;// �ֿ���Է�3������

int  ID = 1;//������ʼID

//���ʱ�����飬ģ��������������ѵ��ٶ�
int   arr1[10] = { 2,1,4,0,3,4,6,1,9,0};
int   arr2[10] = { 1,9,5,4,9,3,4,0,2,6};


//��Ҫ����event��֪ͨ
HANDLE   hEvent1 = INVALID_HANDLE_VALUE;//�л���ʱ֪ͨ������ȡ����
HANDLE   hEvent2 = INVALID_HANDLE_VALUE;//�ֿ�Ϊ��֪ͨ�����߿�ʼ����


//������
void  ProducerThread(LPVOID  param);
//������
void  ConsumerThread(LPVOID  param);

int main()
{

	hEvent1 = CreateEvent(NULL, TRUE, TRUE, L"�¼�����1");//��Ҫ�ȿ�ʼ����
	hEvent2 = CreateEvent(NULL, TRUE, FALSE, L"�¼�����2");//һ��ʼ���ֿ�û��ȡ

	uintptr_t  t1=  _beginthread(ProducerThread,  0, NULL);
	uintptr_t  t2 = _beginthread(ConsumerThread, 0, NULL);

	//���޵ȴ������߳����н���
	HANDLE   hArr []= {  (HANDLE)t1   ,(HANDLE)t2 };
	WaitForMultipleObjects(2, hArr, TRUE, INFINITE);

	CloseHandle(hEvent1);
	CloseHandle(hEvent2);

	return 0;
}

//������
void  ProducerThread(LPVOID  param)
{
	
	while (TRUE)
	{
		//��event�Ƿ���������
		WaitForSingleObject(hEvent1, INFINITE);
		if (store.size() < StoreSize)//�вֿ��λ������
		{
			int  id = ID++;//����ID��
			printf("��������: %d\n" , id);
			store.push(id);//�ѻ�����õ��ֿ���

			Sleep( arr1[id%10] *1000 );//������ʱ�죬��ʱ��
		}
		else //�ֿ�����,��Ҫֹͣ����
		{
			ResetEvent(hEvent1);//���¼���Ϊ���ź�״̬
			printf("�ֿ����ˣ�\n");
		}

		//�ֿ��л���,����֪ͨ������ȡ����
		if (store.size() > 0)
		{
			SetEvent(hEvent2);//�������ߵ��¼�����Ϊ���ź�
		}


	} 

}

//������
void  ConsumerThread(LPVOID  param)
{
	while (TRUE)
	{

		//��event2�Ƿ�����ȡ����
		WaitForSingleObject(hEvent2, INFINITE);
		if (store.size() > 0)
		{
			int id = store.front();//��ȡ�����еĻ���Ƚ��ȳ�
			store.pop();//ж�߻���ڳ��ֿ��λ
			printf("                                   ȡ������: %d\n", id);

			Sleep(arr2[id % 10] * 1000);
		}
		else //�ֿ����
		{
			ResetEvent(hEvent2);//��Ϊ���źţ�����ȡ������
			printf("                                   �ֿ���ˣ�\n");
		}

		if (store.size() < 3)//˵���ֿ�û���������Լ�������
		{
			SetEvent(hEvent1);//֪ͨ�����߼�����������
		}

	}

}