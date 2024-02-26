#include <iostream>

int main()
{
      char answer;

      std::cout << "可以格式化您的硬盘吗?[Y/N]";
      std::cin >> answer;
      std::cout << "\n";

      switch( answer )
      {
      case 'Y':
      case 'y':
            std::cout << "我想还是别了, 数据丢了妈妈会骂的~" << "\n";
            break;

      case 'N':
      case 'n':
            std::cout << "您的选择是正确的, 硬盘不能随便给人格式化!" << "\n";
            break;

      default:
            std::cout << "请输入[Y/N]回答问题。" << "\n";
            break;
      }

      std::cout << "输入任意键结束程序!" << "\n";
      std::cin.get();
      std::cin.ignore(100, '\n');

      return 0;
}