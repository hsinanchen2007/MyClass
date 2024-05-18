#include<stdio.h>
#include<Windows.h> //windows��ͷ�ļ�

//�������̵ĺ���������
#define Row 20
#define Col   20

//���嵱ǰ������ڵ�����
int  curRow = 0;
int  curCol = 0;

//������Ϸ���Ʒ����
#define  UP   'w'
#define  DOWN   's'
#define  LEFT   'a'
#define  RIGHT   'd'

//�������ӵİ���
#define  HERE   ' '

//��ǰ��˭���� 1���һ��2��Ҷ�
int   who = 1;

//�ո����ӵ����
int  player = 0;

//��¼����������ӵĸ���
int  count[2] = { 0 };

//Ϊ���̽�ģ��0��ʾδռ�ã�1��ʾ�Ѿ�����һ����
int  data[Row][Col] = { 0 };

//��������
void  DrawQiPan();
//�ƶ����λ�õ�����
void   MoveCursor(int row, int col);
//�������ĺ���
void   KeyPress(char key);
//���Ӻ���
void   HereOne( );
//���ĳ������Ƿ�Ӯ�ˣ�����ֵ0 ��ʾûӮ��1��ʾӮ��
int   CheckWin(int  arr[Row][Col],int player);
//Ai������
void   AI( );
//����һ����������λ��,���û�ҵ�������(-1��-1)
COORD FindEmpty();  

//����һ���õĿ�������λ��,���û�ҵ�������(-1��-1)
COORD FindGoodEmpty(int  who);

//������Щλ�÷����5���ӻ�ʤ��
int  Find5(int who, COORD cos[]);//����ֵ�ǿɻ�ʤλ�õĸ���
//����һ������Ӯ��λ��
COORD   FindWin(who);
//������Щλ�÷����4���ӻ����ס�����������ֵ�ǹؼ�λ�õĸ���
int  Find4(int who, COORD cos[]);
//����һ�����ܷ���ס��λ��
COORD   FindMayWin(who);
//��������Ƿ�����������Ŀţ������������п�λ��
//�з���1��û�з���0
int  Check4AndBlank(int arr[Row][Col], int  who);


int  main()
{
	system("color 0A");//�ı䱳��ɫ��ǰ��ɫ

	//��������
	DrawQiPan();

	//��ʼ�����λ��
	MoveCursor(curRow, curCol);
	
	while (1)
	{
		if (who == 1)//��ʾ���һ
		{
			char key = getch();
			KeyPress(key); 
		}
		else //����AI��Ҷ�
		{
			AI();
			HereOne();
		}

		if (player > 0)
		{
			//������5�����ϲ���Ӯ
			if (count[player - 1] >=  5)
			{
				//���ո����ӵ�����Ƿ�Ӯ��
				int  ret = CheckWin(data,player);
				if (ret)
				{
					MoveCursor(21, 3);
					printf("��ϲ���%dʤ����\n", player);

					break;//��ֹѭ��
				}
			}
		
		}
		
	}


	//�ó�����ͣһ�£���Ҫ�˳�
	system("pause");

	return 0;
}


//��������
void  DrawQiPan()
{
	for (int i = 0; i < Row; ++i)
	{
		for (int j = 0; j < Col; ++j)
		{
			printf("��");//����ȫ�ǵ�+��
		}
		printf("\n");
	}
}

//�ƶ����λ�õ�����
void   MoveCursor(int row, int col)
{
	//��ȡ��ɫ����̨���ڵľ�������ڵı�ʶ��
	HANDLE  hCmd = GetStdHandle(STD_OUTPUT_HANDLE);
	//����ƶ�������
	COORD co ;
	co.X = col * 2;
	co.Y =  row;

	//�ƶ����
	SetConsoleCursorPosition(hCmd, co);

}

//�������ĺ���
void   KeyPress(char key)
{
	player = 0;

	switch (key)
	{ 
	case UP://����
		if (curRow > 0) //���û����һ��
		{
			--curRow;
			MoveCursor(curRow, curCol);
		} 
		break;
	case DOWN://����
		if (curRow < Row-1) //���û�����һ��
		{
			++curRow;
			MoveCursor(curRow, curCol);
		} 
		break;
	case LEFT://����
		if (curCol > 0) //���û����һ��
		{
			--curCol;
			MoveCursor(curRow, curCol);
		}
		break; 
	case RIGHT://����
		if (curCol < Col-1) //���û�����һ��
		{
			++curCol;
			MoveCursor(curRow, curCol);
		}
		break;

	case HERE://��������
		HereOne();
		break;


	default:
		break;
	}
}


//���Ӻ���
void   HereOne()
{
	//���е�λ�òſ�������
	if (data[curRow][curCol] == 0)
	{ 
		//���Ϊ�Ѿ�����һ����
		data[curRow][curCol] =who;

		//�ո����ӵ����
		player = who;

		//�������ӵ���Ŀ
		++count[who - 1];

		//��ʾ�����һ����
		if (who == 1)
		{
			//�ڹ���λ�ô�ӡ�ַ���
			printf("��");//ȫ�ǵģ������Զ�����һ��
			who = 2;//���Ӻ��ֵ���һ�����
		}
		else
		{//��ʾ����Ҷ�����
			printf("��");
			who = 1;
		}

		//�ù�궨�����ӵ�λ��
		MoveCursor(curRow, curCol);
		  
	}


}


//���ĳ������Ƿ�Ӯ�ˣ�����ֵ0 ��ʾûӮ��1��ʾӮ��
int   CheckWin(int  arr[Row][Col], int player)
{
	for (int i = 0; i < Row; ++i)
	{
		 for (int j= 0; j < Col; ++j)
		{
			 //�ҵ�����µ�һ����
			 if (arr[i][j] == player)
			 {
				 //�Ե�ǰ��Ϊ�����

				
				 int N;
				  //������
				 N= 0;
				 for (int k = 1; k <= 4; ++k) //5������Ҫ�Ƚ�4��
				 {
					 if (j + k < Col)
					 {
						 if (arr[i][j] == arr[i][j + k])
						 {
							 ++N;
						 }
					 }
				
				 }
				 if (N == 4) return 1;


				 //������ 
				 N = 0;
				 for (int k = 1; k <= 4; ++k) //5������Ҫ�Ƚ�4��
				 {
					 if (i + k < Row)
					 {
						 if (arr[i][j] == arr[i+k][j])
						 {
							 ++N;
						 }
					 }

				 }
				 if (N == 4) return 1;


				 //��б������ 
				 N = 0;
				 for (int k = 1; k <= 4; ++k) //5������Ҫ�Ƚ�4��
				 {
					 if ((i + k < Row ) &&(j-k>0) )
					 {
						 //�������������ӣ��������μ���
						 if (arr[i][j] == arr[i + k][j-k])
						 {
							 ++N;
						 }
					 }

				 }
				 if (N == 4) return 1;


				 //��б������ 
				 N = 0;
				 for (int k = 1; k <= 4; ++k) //5������Ҫ�Ƚ�4��
				 {
					 if ((i + k < Row) && (j +k <Col))
					 {
						 //���������������� 
						 if (arr[i][j] == arr[i + k][j + k])
						 {
							 ++N;
						 }
					 }

				 }
				 if (N == 4) return 1;
					 
			 } 


		}
	}



	return  0;//ûӮ
}

//Ai��������ȷ��AI���ӵ����λ��
void   AI()
{
	Sleep(1000);//˯��1s

	 //�ҵ�һ���Լ�����Ӯ��λ��
	COORD  co = FindWin(2);
	if (co.X ==-1)
	{ //�Լ���ʱû����Ӯ��λ��
		 

		//��һ�Ҷ�����Ӯ��λ�ã�����ռ�ˣ���ֹ���ֻ�ʤ
		 co = FindWin(1);
		 if (co.X == -1)
		 { //������ʱû����Ӯ��λ��

			 //���ҵ�һ���Լ����ˣ����ַ���ס��λ��
			 co = FindMayWin(2);  
			 if (co.X == -1)
			 { //�Լ���ʱû�����öԷ�����ס��λ�� 

				 co = FindMayWin(1); //�ҵ����ֿ������ˣ��ҷ���ס��λ��
				 if (co.X == -1)
				 { //������ʱû���ܷ���ס��λ�� 

					 //co = FindEmpty(); 
					 //ΪAI�ҵ�һ���õĿ�λ��
					 co = FindGoodEmpty(2);
				 }
			 } 
		
		 }
	}

	curRow = co.Y;
	curCol = co.X;

	MoveCursor(curRow, curCol);
}

//����һ����������λ��,���û�ҵ�������(-1��-1)
COORD FindEmpty()
{
	COORD  co = {-1,-1};

	for (int i = 0; i < Row; ++i)
	{
		for (int j = 0; j < Col; ++j)
		{
			//�ҵ�һ�ſ��е�λ��
			if (data[i][j] == 0)
			{ 
				co.X = j;
				co.Y = i;

				return co;
			}
		}
	}

	return co;
}
//����һ���õĿ�������λ��,���û�ҵ�������(-1��-1)
COORD FindGoodEmpty(int  who)
{
	COORD  co = { -1,-1 };

	//��ȷ���Է���˭
	int  other = (who == 1 ? 2 : 1);

	for (int i = 0; i < Row; ++i)
	{
		for (int j = 0; j < Col; ++j)
		{
			 //����Ѱ��
			// �жϴӵ�ǰλ�õ���������5��û�жԷ�����
			if (  (j+4<Col)&&  (data[i][j] != other) && (data[i][j + 1] != other)
				&& (data[i][j + 2] != other) && (data[i][j + 3] != other)
				&& (data[i][j + 4] != other))
			{
				//����5��λ�ã��Լ����ӻ��� ��λ�ã�
				for (int k = 0; k < 5; ++k)
				{
					//�ҵ�һ������λ��
					if (data[i][j + k] == 0)
					{
						co.X = j + k;
						co.Y = i;
						return co;
					}
				}
			}

			//����Ѱ��
			// �жϴӵ�ǰλ�õ���������5��û�жԷ�����
			if ((i + 4 < Row) && (data[i][j] != other) && (data[i+ 1][j ] != other)
				&& (data[i+ 2][j ] != other) && (data[i+ 3][j ] != other)
				&& (data[i+ 4][j ] != other))
			{
				//����5��λ�ã��Լ����ӻ��� ��λ�ã�
				for (int k = 0; k < 5; ++k)
				{
					//�ҵ�һ������λ��
					if (data[i+ k][j ] == 0)
					{
						co.X = j ;
						co.Y = i+ k;
						return co;
					}
				}
			}


			//��б����Ѱ��
			// �жϴӵ�ǰλ�õ���������5��û�жԷ�����
			if (  (i+4<Row) &&(j-4>=0)&& (data[i][j] != other) && (data[i + 1][j-1] != other)
				&& (data[i + 2][j-2] != other) && (data[i + 3][j-3] != other)
				&& (data[i + 4][j-4] != other))
			{
				//����5��λ�ã��Լ����ӻ��� ��λ�ã�
				for (int k = 0; k < 5; ++k)
				{
					//�ҵ�һ������λ��
					if (data[i + k][ j - k] == 0)
					{
						co.X = j- k;
						co.Y = i + k;
						return co;
					}
				}
			}

			//��б����Ѱ��
			// �жϴӵ�ǰλ�õ���������5��û�жԷ�����
			if ((i + 4 < Row) && (j + 4 < Col)&&(data[i][j] != other) && (data[i + 1][j + 1] != other)
				&& (data[i + 2][j + 2] != other) && (data[i + 3][j + 3] != other)
				&& (data[i + 4][j+ 4] != other))
			{
				//����5��λ�ã��Լ����ӻ��� ��λ�ã�
				for (int k = 0; k < 5; ++k)
				{
					//�ҵ�һ������λ��
					if (data[i + k][j + k] == 0)
					{
						co.X = j + k;
						co.Y = i + k;
						return co;
					}
				}
			}
		}
	}

	return co;
}
//������Щλ�÷����5���ӻ�ʤ��������ֵ�ǿɻ�ʤλ�õĸ���
int  Find5(int who, COORD cos[])
{
	//�ȿ���һ���������ݣ���������ʵ��������
	int  arr[Row][Col] = { 0 };
	memcpy(arr, data, Row * Col * sizeof(4));


	int N = 0;//ʤ��λ�õĸ���

	//��arr����һ�����ӣ��������ܷ�Ӯ
	for (int i = 0; i < Row; ++i)
	{
		for (int j = 0; j < Col; ++j)
		{
			//�ҵ�һ�ſ��е�λ��
			if (arr[i][j] == 0)
			{
				arr[i][j] = who;//ģ������һ������

				if (CheckWin(arr, who))
				{ //˵������������ӣ�����ʤ��
					cos[N].X =j;
					cos[N].Y = i;
					++N;
				}

				arr[i][j] = 0;//��ԭ��������һ�ε�̽��
			}
		}
	}

	return N;
}

//����һ������Ӯ��λ��
COORD   FindWin(who)
{
	COORD cos[5] = { 0 };
	int  N = Find5(who,cos);

	if (N > 0)
	{
		return cos[0];
	}

	//û�ҵ�
	COORD co = { -1,-1 };
	return co;
}

//��������Ƿ�����������Ŀţ������������п�λ��
//�з���1��û�з���0
int  Check4AndBlank(int arr[Row][Col], int  who)
{
	for (int i = 0; i < Row; ++i)
	{
		for (int j = 0; j < Col; ++j)
		{
			//�ҵ�����µ�һ����
			if (arr[i][j] == who)
			{
				//�Ե�ǰ��Ϊ�����

				int N;
				//������
				N = 0;
				for (int k = 1; k <= 3; ++k) //4������Ҫ�Ƚ�3��
				{
					if (j + k < Col)
					{
						if (arr[i][j] == arr[i][j + k])
						{
							++N;
						}
					}

				}
				if (N == 3)//�ﵽ����4��
				{
					//�������������ǿ��е�
					if ((j - 1 >= 0) && (j + 4 < Col)
						&& (arr[i][j - 1] == 0) && (arr[i][j + 4] == 0))
					{
						return 1;
					}
				}


				//������ 
				N = 0;
				for (int k = 1; k <= 3; ++k) //4������Ҫ�Ƚ�3��
				{
					if (i + k < Row)
					{
						if (arr[i][j] == arr[i + k][j])
						{
							++N;
						}
					}

				}
				if (N == 3)
				{
					if ((i - 1 >= 0) && (i + 4 < Row) && (arr[i - 1][j] == 0) && (arr[i + 4][j] == 0))
					{
						return 1;
					}
				}

				//�������б���
				N = 0;
				for (int k = 1; k <= 3; ++k) //4������Ҫ�Ƚ�3��
				{
					if ( (i+k<Row) && (j - k >=0))
					{
						if (arr[i][j] == arr[i+k][j - k])
						{
							++N;
						}
					}

				}
				if (N == 3)//�ﵽ����4��
				{
					//�������������ǿ��е�
					if ((i - 1 >= 0) && (j + 1 < Col)&&(i +4   <Row ) && (j - 1>=0)
						&& (arr[i-1][j +1] == 0) && (arr[i+4][j- 4] == 0))
					{
						return 1;
					}
				}


				//���ұ���б���
				N = 0;
				for (int k = 1; k <= 3; ++k) //4������Ҫ�Ƚ�3��
				{
					if ((i + k < Row) && (j + k < Col))
					{
						if (arr[i][j] == arr[i + k][j + k])
						{
							++N;
						}
					}

				}
				if (N == 3)//�ﵽ����4��
				{
					//�������������ǿ��е�
					if ((i - 1 >= 0) && (j - 1 >=0) && (i + 4 < Row) && (j +4 <Col)
						&& (arr[i - 1][j - 1] == 0) && (arr[i + 4][j + 4] == 0))
					{
						return 1;
					}
				}

			}
		}
	}
		return 0;
 }

//������Щλ�÷����4���ӻ����ס�����������ֵ�ǹؼ�λ�õĸ���
int  Find4(int who, COORD cos[])
{
	//�ȿ���һ���������ݣ���������ʵ��������
	int  arr[Row][Col] = { 0 };
	memcpy(arr, data, Row * Col * sizeof(4));


	int N = 0;//ʤ��λ�õĸ���

	//��arr����һ�����ӣ��������ܷ�Ӯ
	for (int i = 0; i < Row; ++i)
	{
		for (int j = 0; j < Col; ++j)
		{
			//�ҵ�һ�ſ��е�λ��
			if (arr[i][j] == 0)
			{
				arr[i][j] = who;//ģ������һ������

				if (Check4AndBlank(arr, who))
				{ //˵������������ӣ����޷����ضԷ���
					cos[N].X = j;
					cos[N].Y = i;
					++N;
				}

				arr[i][j] = 0;//��ԭ��������һ�ε�̽��
			}
		}
	}

	return N;
}


//����һ�����Է��ز�ס��λ�õ�λ��
COORD   FindMayWin(who)
{
	COORD cos[5] = { 0 };
	int  N = Find4(who, cos);

	if (N > 0)
	{
		return cos[0];
	}

	//û�ҵ�
	COORD co = { -1,-1 };
	return co;
}