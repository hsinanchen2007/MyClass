#include<iostream> 
using  namespace  std; 
 

int  main()
{
	//������ڴ棬4���ֽ�
	int  *pA = new int;
	*pA = 123;
	cout << *pA << endl;

	//������ڴ�ʱ����ʼ��
	int  *pB = new int(456);
	cout << *pB << endl;

	//����������ڴ棬����ʼ��
	int  *pC = new int[3]{66,77,88};
	for (int i = 0; i < 3; ++i)
	{
		cout<<pC[i] << "    ";
	}
	cout <<endl;


	delete  pA;//�ͷŶ��ڴ�
	delete  pB;

	delete  []pC;//�ͷ�������ڴ�
	 
	return 0;
}