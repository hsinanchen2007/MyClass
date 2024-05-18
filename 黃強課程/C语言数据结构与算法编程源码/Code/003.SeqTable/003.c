#include <stdio.h>
#include <stdlib.h>

//定义顺序表

//这样的好处是，int 表示元素是整数
//以后如果我希望元素是char ，
//只需要改这里1处就行啦
typedef  int  ElemType ;

#define SeqTableSize  10

typedef  struct  SeqTable
{
	//这里也可以使用数组
	//ElemType  data[SeqTableSize];
	ElemType * data;//指向分配的连续空间
	int  size;//表中元素的个数
	int  capicity;//顺序表的最大容量
}SeqTable;

//初始化顺序表
void Init( SeqTable* table)
{
	table->size = 0;
	table->capicity = SeqTableSize;//容量

	//分配连续的内存空间
	table->data = (ElemType*)malloc(table->capicity * sizeof(ElemType));

	if (table->data != NULL)
	{
		printf("顺序表初始化成功!\n");
	}


}

//尾部添加元素（效率高，无需移动任何元素）
void Add(SeqTable* table ,ElemType e)
{
	if (table->size >= table->capicity)
	{
		printf("顺序表空间已满，无法添加!\n");
		return;
    }

	//在下一个空闲区域赋值元素
	table->data[table->size] = e;
	//加了一个元素，元素个数自然要+1
	table->size++;
}


//在索引位置插入元素（效率低， 需移动现有元素）
void Insert(SeqTable* table, int  index ,ElemType e)
{
	if (table->size >= table->capicity)
	{
		printf("顺序表空间已满，无法插入!\n");
		return;
	}

	//判断索引的合法性
	if (index >= 0 && index < table->size)
	{
		//从数组末尾开始，依次往后移动一位
		for (int i = table->size ; i >  index; --i)
		{
			table->data[i] = table->data[i - 1];
		}

		//留的空位放新元素
		table->data[index] = e;
		//元素个数需要+1
		table->size++;
	}
	else
	{
		printf("插入位置非法!\n");
	}
 
}

//查找顺序表中某个元素第一次出现的位置
int   Find(SeqTable* table, ElemType e)
{
	for (int i = 0; i < table->size; ++i)
	{
		if (table->data[i] == e)
		{
			return i;
		 }
	}
	//未找到返回-1
	return -1;
}


//获取指定索引位置的元素值
ElemType   Get(SeqTable* table,  int index)
{ 
	if(index>=0 && index < table->size)
	{
		return table->data[index];
	}
	else
	{
		printf("非法的索引值!\n");
		//返回非法值-1
		return -1;
	}

}

//删除指定索引元素
void  Remove(SeqTable* table, int index)
{ 

	if (table->size == 0)
	{
		printf("删除失败、顺序表是空的!\n");
		return;
	}

	if (index >= 0 && index < table->size)
	{
		//将后一个元素往前移动一步
		for (int i = index; i < table->size -1 ; ++i)
		{
			table->data[i] = table->data[i + 1];
		 }
		//元素个数-1
		table->size--;
	}
	else
	{
		printf("删除失败、非法的索引值!\n"); 
	}
}



void  RemoveLast(SeqTable* table )
{ 
	if (table->size == 0)
	{
		printf("删除失败、顺序表是空的!\n");
		return;
	}
	 
	 //元素个数-1就等价于删除了最后一个元素
	//哪怕这个位置的元素值还存在，我们也不会去使用它
	 //table->data[table ->size - 1] = 0;
	 table->size--; 
}


//清空顺序表
void Clear(SeqTable* table )
{
	table->size = 0;//清空长度，里面的元素内容无需关心

	//可以释放或者不释放，看业务需求
	//free(table->data);

	printf("清空顺序表成功!\n");
}


//打印顺序表中的所有元素
void Print(SeqTable* table)
{
	for (int i = 0; i < table->size; ++i)
	{
		printf("%d     ", table->data[i]);
	}
	printf("\n");
}

int main()
{
	//定义顺序表结构变量
	SeqTable table;

	//初始化
	Init(&table);

	//在尾部添加元素
	Add(&table, 1);

	//在尾部添加元素
	Add(&table,2);

	//在尾部添加元素
	Add(&table, 3);

	//插入元素
	Insert(&table, 0, 4);
	  
	//插入元素
	Insert(&table, 1, 5);

	//插入元素,非法索引位置
	Insert(&table, 5, 6);

	//打印顺序表
	Print(&table);


	//查找元素
	int pos= Find(&table, 5);
	printf("元素5第一次出现的位置：%d\n", pos);
	//查找元素
	int pos2 = Find(&table, 555);
	printf("元素555第一次出现的位置：%d\n", pos2);

	//获取元素
	ElemType  e = Get(&table, 3);
	printf("索引3位置的元素是：%d\n", e);

	//获取元素
	ElemType  e2 = Get(&table, 333);
	printf("索引333位置的元素是：%d\n", e2);


	//删除指定索引元素
	Remove(&table, 0);
	//打印顺序表
	Print(&table);


	//删除指定索引元素
	Remove(&table, 1); 
	//打印顺序表
	Print(&table);

	//删除指定索引元素
	Remove(&table, 100);

	//删除末尾元素
	RemoveLast(&table);
	//打印顺序表
	Print(&table);

	//删除末尾元素
	RemoveLast(&table);
	//打印顺序表
	Print(&table);

	//删除末尾元素
	RemoveLast(&table);
	//打印顺序表
	Print(&table);


	//删除末尾元素
	RemoveLast(&table);
	//打印顺序表
	Print(&table);


	//清空
	Clear(&table);



	return 0;
}
 