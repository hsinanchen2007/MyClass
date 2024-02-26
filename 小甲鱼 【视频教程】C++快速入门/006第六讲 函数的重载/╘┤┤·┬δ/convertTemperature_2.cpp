#include <iostream>

void convertTemperature(double tempIn, char typeIn);
void convertTemperature(int tempIn, char typeIn);

int main()
{
	double tempIn;
	int tempInInt;
	char typeIn;

	std::cout << "请以【xx.x C】或【xx.x F】的形式输入温度: ";
      std::cin >> tempIn >> typeIn;
      std::cin.ignore(100, '\n');
      std::cout << "\n";
	convertTemperature(tempIn, typeIn);

	std::cout << "请以【xx C】或【xx F】的形式输入温度: ";
      std::cin >> tempInInt >> typeIn;
      std::cin.ignore(100, '\n');
      std::cout << "\n";
	convertTemperature(tempInInt, typeIn);

	return 0;
}

void convertTemperature(double tempIn, char typeIn)
{     
      const unsigned short ADD_SUBTRACT = 32;
      const double RATIO = 9.0 / 5.0;
      
      double tempOut;
      char typeOut;      
      
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
}

void convertTemperature(int tempIn, char typeIn)
{     
      const unsigned short ADD_SUBTRACT = 32;
      const double RATIO = 9.0 / 5.0;
      
      int tempOut;
      char typeOut;      
      
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
}