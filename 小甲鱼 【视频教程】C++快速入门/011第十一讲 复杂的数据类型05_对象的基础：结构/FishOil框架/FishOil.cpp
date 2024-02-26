#include <iostream>
#include <fstream>
#include <windows.h>         // 为了使用Sleep()函数 

struct FishOil
{
	std::string name;
	std::string uid;
	char sex;
}; 

bool InitFishC();
bool ReadFishC(); 
void RecordFishC();
bool WriteFishC(FishOil *OilData);

int main()
{
	int i;
	
	InitFishC();  // 初始化数据。 
	while( 1 )
	{ 
		std::cout << "请选择需要进行的操作: \n";
		std::cout << "1. 打印数据到屏幕\n";
		std::cout << "2. 录入数据\n"; 
		std::cout << "3. 退出程序\n"; 
		std::cin >> i;
		
		switch( i )
		{
			case 1: 
				if( ReadFishC() )
					std::cout << "成功读取文件^_^\n\n";
				else
					std::cout << "读取文件失败T_T\n\n";
				break;
			case 2:
				RecordFishC();
				break;
			case 3:
				return 0;	
		}
	}
	
	std::cout << "初始化失败T_T......\n\n";
		 
	return 0;
	
}

bool InitFishC()
{

} 

bool ReadFishC()
{

}

void RecordFishC()
{

}

bool WriteFishC( FishOil *pOilData )
{

}
