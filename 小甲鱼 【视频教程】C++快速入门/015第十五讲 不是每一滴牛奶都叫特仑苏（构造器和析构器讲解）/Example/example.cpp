#include <iostream>
#include <string>
#include <fstream>

class StoreQuote
{
public:
	std::string quote, speaker;
	std::ofstream fileOutput;
	
	StoreQuote();
	~StoreQuote();
	
	void inputQuote();
	void inputSpeaker();
	bool write();	
};

StoreQuote::StoreQuote()
{
	fileOutput.open("test.txt", std::ios::app);
}

StoreQuote::~StoreQuote()
{
	fileOutput.close();
}

void StoreQuote::inputQuote()
{
	std::getline(std::cin, quote);
}

void StoreQuote::inputSpeaker()
{
	std::getline(std::cin, speaker);
}

bool StoreQuote::write()
{
	if( fileOutput.is_open() )
	{
		fileOutput << quote << "|" << speaker << "\n";
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	StoreQuote quote;
	
	std::cout << "������һ�����ԣ�\n";
	quote.inputQuote();
	
	std::cout << "���������ߣ�\n";
	quote.inputSpeaker();
	
	if( quote.write() )
	{
		std::cout << "�ɹ�д���ļ�^_^";
	}
	else
	{
		std::cout << "д���ļ�ʧ��T_T";
		return 1;
	}
	
	return 0;
}
