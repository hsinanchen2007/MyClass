#include <iostream>
#include <fstream>
#include <windows.h>         // Ϊ��ʹ��Sleep()���� 

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
	
	InitFishC();  // ��ʼ�����ݡ� 
	while( 1 )
	{ 
		std::cout << "��ѡ����Ҫ���еĲ���: \n";
		std::cout << "1. ��ӡ���ݵ���Ļ\n";
		std::cout << "2. ¼������\n"; 
		std::cout << "3. �˳�����\n"; 
		std::cin >> i;
		
		switch( i )
		{
			case 1: 
				if( ReadFishC() )
					std::cout << "�ɹ���ȡ�ļ�^_^\n\n";
				else
					std::cout << "��ȡ�ļ�ʧ��T_T\n\n";
				break;
			case 2:
				RecordFishC();
				break;
			case 3:
				return 0;	
		}
	}
	
	std::cout << "��ʼ��ʧ��T_T......\n\n";
		 
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
