#include <iostream>

int main()
{     
      const unsigned short ADD_SUBTRACT = 32;
      const double RATIO = 9.0 / 5.0;
      
      float tempIn, tempOut;
      char typeIn, typeOut;

      std::cout << "���ԡ�xx.x������ʽ�����¶�: ";
      while( !(std::cin >> tempIn) )
      {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "���ԡ�xx.x������ʽ�����¶�: ";
      }

      do{
            std::cout << "���ԡ�xx.x C����xx.x F������ʽ�����¶�: ";
            std::cin >> typeIn;

      }while( 
            (typeIn != 'C') && (typeIn != 'c') && 
            (typeIn != 'F') && (typeIn != 'f') 
            );

      std::cout << "\n";
      
      switch( typeIn )
      {
      case 'C':
      case 'c':
            tempOut = (tempIn * RATIO) + ADD_SUBTRACT;
            typeOut = 'F';
            typeIn = 'C';
            break;

      case 'F':
      case 'f':
            tempOut = (tempIn - ADD_SUBTRACT) / RATIO;
            typeOut = 'C';
            typeIn = 'F';
            break;

      default:
            typeOut = 'E';
            break;                  
      }

      if( typeOut != 'E' )
      {
            std::cout << tempIn << typeIn << " = " << tempOut << typeOut << "\n\n";
      }
      else
      {
            std::cout << "�밴�ո�����ʽ����!" << "\n\n";
      }

      std::cout << "�����������ַ�����!" << "\n";
      std::cin.get();

      return 0;
}