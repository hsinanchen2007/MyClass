#include <iostream>

int main()
{     
      const unsigned short ADD_SUBTRACT = 32;
      const double RATIO = 9.0 / 5.0;
      
      float tempIn, tempOut;
      char typeIn, typeOut;

      std::cout << "请以【xx.x】的形式输入温度: ";
      while( !(std::cin >> tempIn) )
      {
            std::cin.clear();
            std::cin.ignore(100, '\n');
            std::cout << "请以【xx.x】的形式输入温度: ";
      }

      do{
            std::cout << "请以【xx.x C】或【xx.x F】的形式输入温度: ";
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
            std::cout << "请按照给出格式输入!" << "\n\n";
      }

      std::cout << "请输入任意字符结束!" << "\n";
      std::cin.get();

      return 0;
}