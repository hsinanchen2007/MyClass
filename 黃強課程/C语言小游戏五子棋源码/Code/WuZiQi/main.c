#include<stdio.h>
#include<Windows.h> //windows的头文件

//定义棋盘的函数、列数
#define Row 20
#define Col   20

//定义当前光标所在的行列
int  curRow = 0;
int  curCol = 0;

//定义游戏控制方向键
#define  UP   'w'
#define  DOWN   's'
#define  LEFT   'a'
#define  RIGHT   'd'

//定义落子的按键
#define  HERE   ' '

//当前归谁落子 1玩家一，2玩家二
int   who = 1;

//刚刚落子的玩家
int  player = 0;

//记录两个玩家落子的个数
int  count[2] = { 0 };

//为棋盘建模，0表示未占用，1表示已经下了一颗子
int  data[Row][Col] = { 0 };

//绘制棋盘
void  DrawQiPan();
//移动光标位置到行列
void   MoveCursor(int row, int col);
//处理按键的函数
void   KeyPress(char key);
//落子函数
void   HereOne( );
//检测某个玩家是否赢了，返回值0 表示没赢，1表示赢了
int   CheckWin(int  arr[Row][Col],int player);
//Ai处理函数
void   AI( );
//查找一个空闲落子位置,如果没找到，返回(-1，-1)
COORD FindEmpty();  

//查找一个好的空闲落子位置,如果没找到，返回(-1，-1)
COORD FindGoodEmpty(int  who);

//查找哪些位置放入第5颗子会胜利
int  Find5(int who, COORD cos[]);//返回值是可获胜位置的个数
//查找一个可以赢的位置
COORD   FindWin(who);
//查找哪些位置放入第4颗子会防不住的情况，返回值是关键位置的个数
int  Find4(int who, COORD cos[]);
//查找一个可能防不住的位置
COORD   FindMayWin(who);
//查找玩家是否存在连续的四颗，并且两边留有空位置
//有返回1，没有返回0
int  Check4AndBlank(int arr[Row][Col], int  who);


int  main()
{
	system("color 0A");//改变背景色，前景色

	//绘制棋盘
	DrawQiPan();

	//初始化光标位置
	MoveCursor(curRow, curCol);
	
	while (1)
	{
		if (who == 1)//表示玩家一
		{
			char key = getch();
			KeyPress(key); 
		}
		else //电脑AI玩家二
		{
			AI();
			HereOne();
		}

		if (player > 0)
		{
			//落子了5颗以上才能赢
			if (count[player - 1] >=  5)
			{
				//检测刚刚落子的玩家是否赢了
				int  ret = CheckWin(data,player);
				if (ret)
				{
					MoveCursor(21, 3);
					printf("恭喜玩家%d胜利！\n", player);

					break;//终止循环
				}
			}
		
		}
		
	}


	//让程序暂停一下，不要退出
	system("pause");

	return 0;
}


//绘制棋盘
void  DrawQiPan()
{
	for (int i = 0; i < Row; ++i)
	{
		for (int j = 0; j < Col; ++j)
		{
			printf("＋");//这是全角的+号
		}
		printf("\n");
	}
}

//移动光标位置到行列
void   MoveCursor(int row, int col)
{
	//获取黑色控制台窗口的句柄（窗口的标识）
	HANDLE  hCmd = GetStdHandle(STD_OUTPUT_HANDLE);
	//光标移动的坐标
	COORD co ;
	co.X = col * 2;
	co.Y =  row;

	//移动光标
	SetConsoleCursorPosition(hCmd, co);

}

//处理按键的函数
void   KeyPress(char key)
{
	player = 0;

	switch (key)
	{ 
	case UP://向上
		if (curRow > 0) //如果没到第一行
		{
			--curRow;
			MoveCursor(curRow, curCol);
		} 
		break;
	case DOWN://向下
		if (curRow < Row-1) //如果没到最后一行
		{
			++curRow;
			MoveCursor(curRow, curCol);
		} 
		break;
	case LEFT://向左
		if (curCol > 0) //如果没到第一列
		{
			--curCol;
			MoveCursor(curRow, curCol);
		}
		break; 
	case RIGHT://向右
		if (curCol < Col-1) //如果没到最后一列
		{
			++curCol;
			MoveCursor(curRow, curCol);
		}
		break;

	case HERE://落下棋子
		HereOne();
		break;


	default:
		break;
	}
}


//落子函数
void   HereOne()
{
	//空闲的位置才可以落子
	if (data[curRow][curCol] == 0)
	{ 
		//标记为已经下了一颗子
		data[curRow][curCol] =who;

		//刚刚落子的玩家
		player = who;

		//增加落子的数目
		++count[who - 1];

		//表示该玩家一落子
		if (who == 1)
		{
			//在光标的位置打印字符串
			printf("●");//全角的，光标会自动后移一格
			who = 2;//落子后轮到下一个玩家
		}
		else
		{//表示该玩家二落子
			printf("○");
			who = 1;
		}

		//让光标定在下子的位置
		MoveCursor(curRow, curCol);
		  
	}


}


//检测某个玩家是否赢了，返回值0 表示没赢，1表示赢了
int   CheckWin(int  arr[Row][Col], int player)
{
	for (int i = 0; i < Row; ++i)
	{
		 for (int j= 0; j < Col; ++j)
		{
			 //找到玩家下的一颗子
			 if (arr[i][j] == player)
			 {
				 //以当前子为起点检测

				
				 int N;
				  //横向检测
				 N= 0;
				 for (int k = 1; k <= 4; ++k) //5颗子需要比较4次
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


				 //纵向检测 
				 N = 0;
				 for (int k = 1; k <= 4; ++k) //5颗子需要比较4次
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


				 //左斜方向检测 
				 N = 0;
				 for (int k = 1; k <= 4; ++k) //5颗子需要比较4次
				 {
					 if ((i + k < Row ) &&(j-k>0) )
					 {
						 //行数是依次增加，列数依次减少
						 if (arr[i][j] == arr[i + k][j-k])
						 {
							 ++N;
						 }
					 }

				 }
				 if (N == 4) return 1;


				 //右斜方向检测 
				 N = 0;
				 for (int k = 1; k <= 4; ++k) //5颗子需要比较4次
				 {
					 if ((i + k < Row) && (j +k <Col))
					 {
						 //行列数是依次增加 
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



	return  0;//没赢
}

//Ai处理函数，确定AI落子的最佳位置
void   AI()
{
	Sleep(1000);//睡眠1s

	 //找到一个自己可以赢的位置
	COORD  co = FindWin(2);
	if (co.X ==-1)
	{ //自己暂时没有能赢的位置
		 

		//找一找对手能赢的位置，给它占了，防止对手获胜
		 co = FindWin(1);
		 if (co.X == -1)
		 { //对手暂时没有能赢的位置

			 //先找到一个自己下了，对手防不住的位置
			 co = FindMayWin(2);  
			 if (co.X == -1)
			 { //自己暂时没有能让对方防不住的位置 

				 co = FindMayWin(1); //找到对手可能下了，我防不住的位置
				 if (co.X == -1)
				 { //对手暂时没有能防不住的位置 

					 //co = FindEmpty(); 
					 //为AI找到一个好的空位置
					 co = FindGoodEmpty(2);
				 }
			 } 
		
		 }
	}

	curRow = co.Y;
	curCol = co.X;

	MoveCursor(curRow, curCol);
}

//查找一个空闲落子位置,如果没找到，返回(-1，-1)
COORD FindEmpty()
{
	COORD  co = {-1,-1};

	for (int i = 0; i < Row; ++i)
	{
		for (int j = 0; j < Col; ++j)
		{
			//找到一颗空闲的位置
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
//查找一个好的空闲落子位置,如果没找到，返回(-1，-1)
COORD FindGoodEmpty(int  who)
{
	COORD  co = { -1,-1 };

	//先确定对方是谁
	int  other = (who == 1 ? 2 : 1);

	for (int i = 0; i < Row; ++i)
	{
		for (int j = 0; j < Col; ++j)
		{
			 //横向寻找
			// 判断从当前位置到后面连续5颗没有对方的子
			if (  (j+4<Col)&&  (data[i][j] != other) && (data[i][j + 1] != other)
				&& (data[i][j + 2] != other) && (data[i][j + 3] != other)
				&& (data[i][j + 4] != other))
			{
				//从这5个位置（自己的子或者 空位置）
				for (int k = 0; k < 5; ++k)
				{
					//找到一个空闲位置
					if (data[i][j + k] == 0)
					{
						co.X = j + k;
						co.Y = i;
						return co;
					}
				}
			}

			//纵向寻找
			// 判断从当前位置到下面连续5颗没有对方的子
			if ((i + 4 < Row) && (data[i][j] != other) && (data[i+ 1][j ] != other)
				&& (data[i+ 2][j ] != other) && (data[i+ 3][j ] != other)
				&& (data[i+ 4][j ] != other))
			{
				//从这5个位置（自己的子或者 空位置）
				for (int k = 0; k < 5; ++k)
				{
					//找到一个空闲位置
					if (data[i+ k][j ] == 0)
					{
						co.X = j ;
						co.Y = i+ k;
						return co;
					}
				}
			}


			//左斜方向寻找
			// 判断从当前位置到下面连续5颗没有对方的子
			if (  (i+4<Row) &&(j-4>=0)&& (data[i][j] != other) && (data[i + 1][j-1] != other)
				&& (data[i + 2][j-2] != other) && (data[i + 3][j-3] != other)
				&& (data[i + 4][j-4] != other))
			{
				//从这5个位置（自己的子或者 空位置）
				for (int k = 0; k < 5; ++k)
				{
					//找到一个空闲位置
					if (data[i + k][ j - k] == 0)
					{
						co.X = j- k;
						co.Y = i + k;
						return co;
					}
				}
			}

			//右斜方向寻找
			// 判断从当前位置到下面连续5颗没有对方的子
			if ((i + 4 < Row) && (j + 4 < Col)&&(data[i][j] != other) && (data[i + 1][j + 1] != other)
				&& (data[i + 2][j + 2] != other) && (data[i + 3][j + 3] != other)
				&& (data[i + 4][j+ 4] != other))
			{
				//从这5个位置（自己的子或者 空位置）
				for (int k = 0; k < 5; ++k)
				{
					//找到一个空闲位置
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
//查找哪些位置放入第5颗子会胜利，返回值是可获胜位置的个数
int  Find5(int who, COORD cos[])
{
	//先拷贝一份棋盘数据，不玷污真实棋盘数据
	int  arr[Row][Col] = { 0 };
	memcpy(arr, data, Row * Col * sizeof(4));


	int N = 0;//胜利位置的个数

	//在arr中下一颗棋子，来看看能否赢
	for (int i = 0; i < Row; ++i)
	{
		for (int j = 0; j < Col; ++j)
		{
			//找到一颗空闲的位置
			if (arr[i][j] == 0)
			{
				arr[i][j] = who;//模拟下了一颗棋子

				if (CheckWin(arr, who))
				{ //说明下了这颗棋子，可以胜利
					cos[N].X =j;
					cos[N].Y = i;
					++N;
				}

				arr[i][j] = 0;//复原，方便下一次的探测
			}
		}
	}

	return N;
}

//查找一个可以赢的位置
COORD   FindWin(who)
{
	COORD cos[5] = { 0 };
	int  N = Find5(who,cos);

	if (N > 0)
	{
		return cos[0];
	}

	//没找到
	COORD co = { -1,-1 };
	return co;
}

//查找玩家是否存在连续的四颗，并且两边留有空位置
//有返回1，没有返回0
int  Check4AndBlank(int arr[Row][Col], int  who)
{
	for (int i = 0; i < Row; ++i)
	{
		for (int j = 0; j < Col; ++j)
		{
			//找到玩家下的一颗子
			if (arr[i][j] == who)
			{
				//以当前子为起点检测

				int N;
				//横向检测
				N = 0;
				for (int k = 1; k <= 3; ++k) //4颗子需要比较3次
				{
					if (j + k < Col)
					{
						if (arr[i][j] == arr[i][j + k])
						{
							++N;
						}
					}

				}
				if (N == 3)//达到连续4颗
				{
					//必须左右两边是空闲的
					if ((j - 1 >= 0) && (j + 4 < Col)
						&& (arr[i][j - 1] == 0) && (arr[i][j + 4] == 0))
					{
						return 1;
					}
				}


				//纵向检测 
				N = 0;
				for (int k = 1; k <= 3; ++k) //4颗子需要比较3次
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

				//向左边倾斜检测
				N = 0;
				for (int k = 1; k <= 3; ++k) //4颗子需要比较3次
				{
					if ( (i+k<Row) && (j - k >=0))
					{
						if (arr[i][j] == arr[i+k][j - k])
						{
							++N;
						}
					}

				}
				if (N == 3)//达到连续4颗
				{
					//必须左右两边是空闲的
					if ((i - 1 >= 0) && (j + 1 < Col)&&(i +4   <Row ) && (j - 1>=0)
						&& (arr[i-1][j +1] == 0) && (arr[i+4][j- 4] == 0))
					{
						return 1;
					}
				}


				//向右边倾斜检测
				N = 0;
				for (int k = 1; k <= 3; ++k) //4颗子需要比较3次
				{
					if ((i + k < Row) && (j + k < Col))
					{
						if (arr[i][j] == arr[i + k][j + k])
						{
							++N;
						}
					}

				}
				if (N == 3)//达到连续4颗
				{
					//必须左右两边是空闲的
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

//查找哪些位置放入第4颗子会防不住的情况，返回值是关键位置的个数
int  Find4(int who, COORD cos[])
{
	//先拷贝一份棋盘数据，不玷污真实棋盘数据
	int  arr[Row][Col] = { 0 };
	memcpy(arr, data, Row * Col * sizeof(4));


	int N = 0;//胜利位置的个数

	//在arr中下一颗棋子，来看看能否赢
	for (int i = 0; i < Row; ++i)
	{
		for (int j = 0; j < Col; ++j)
		{
			//找到一颗空闲的位置
			if (arr[i][j] == 0)
			{
				arr[i][j] = who;//模拟下了一颗棋子

				if (Check4AndBlank(arr, who))
				{ //说明下了这颗棋子，就无法防守对方了
					cos[N].X = j;
					cos[N].Y = i;
					++N;
				}

				arr[i][j] = 0;//复原，方便下一次的探测
			}
		}
	}

	return N;
}


//查找一个可以防守不住的位置的位置
COORD   FindMayWin(who)
{
	COORD cos[5] = { 0 };
	int  N = Find4(who, cos);

	if (N > 0)
	{
		return cos[0];
	}

	//没找到
	COORD co = { -1,-1 };
	return co;
}