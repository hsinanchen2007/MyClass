// 047.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<vector>
#include<algorithm> //算法头文件

using namespace std;


void  Print(int x)
{
	cout << x << "  ";
}

 
int main()
{
 
	//提供一组凌乱的数据
	vector<int>  v = { 5,1,2,3,4 }; //很明显，它不是堆结构
  /*
                     5
			1                2
       3       4 
  */

	 //让数组中的元素组合成堆结构(默认大根堆)
	 //每个根节点都大于  左右子节点 
	make_heap(v.begin(), v.end());  //5  4  2  3  1
	/* 
	               5
			4             2
        3       1
	
	*/
	//遍历
	for_each(v.begin(), v.end(), Print);
	cout << endl;

	//构造小根堆
	make_heap(v.begin(), v.end(),greater<int>());   //1  3  2  5  4
/*
               1
          3         2
     5       4 
 */
	 //遍历
	for_each(v.begin(), v.end(), Print);
	cout << endl;

	cout << "--------------------------------------------" << endl;

	//放入一个元素到堆中，使其依然是一个堆,分两步
	//1.添加一个新元素到容器末尾 
	v.push_back(0);
	//2.调用push_heap让其依然是小根堆
	push_heap(v.begin(), v.end(),greater<int>()); //0  3  1  5  4  2
	/*
	          0
       3              1
	5    4       2   
	*/
	//遍历
	for_each(v.begin(), v.end(), Print);
	cout << endl;


	cout << "--------------------------------------------" << endl;

	//从堆中删除堆顶元素 ，使其依然是一个小根堆,分两步
   //1.调用pop_heap会将删除的堆顶元素移动到容器的尾部
	pop_heap(v.begin(), v.end(), greater<int>());    // 1  3  2  5  4    0(删除后移动到末尾的)
	//2.删除末尾元素，保证容器中正好是一个小根堆
	v.pop_back();
	for_each(v.begin(), v.end(), Print);  // 1  3  2  5  4  
	cout << endl;

	cout << "--------------------------------------------" << endl;
	//vecotr保存的小根堆，元素顺序并不是从大到小的
	//调用sort_heap之前必须保证是一个堆结构序列， 排序完之后，不再是堆了
	sort_heap(v.begin(), v.end() , greater<int>()); //将容器中元素排序
	for_each(v.begin(), v.end(), Print);  // 1 2 3 4 5  
	cout << endl;


	return 0;
}

