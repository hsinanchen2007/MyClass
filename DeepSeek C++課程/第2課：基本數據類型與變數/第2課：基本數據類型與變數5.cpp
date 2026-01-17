/*
 * 範例2-5：不同整數類型
 * short, int, long, long long
 * signed（有符號，預設）和 unsigned（無符號）
 */
 
#include <iostream>
#include <climits>
 
int main() {
    std::cout << "=== 不同整數類型的區別 ===" << std::endl;
    
    // 1. 不同大小的整數類型
    short smallNumber = 32767;           // 通常 16 位元
    int normalNumber = 2147483647;       // 通常 32 位元
    long long bigNumber = 9223372036854775807LL;  // 通常 64 位元
    
    std::cout << "short 變數：" << smallNumber << std::endl;
    std::cout << "int 變數：" << normalNumber << std::endl;
    std::cout << "long long 變數：" << bigNumber << std::endl;
    
    // 2. 有符號和無符號類型
    signed int negativeNumber = -100;     // 有符號，可以為負數
    unsigned int positiveOnly = 100;      // 無符號，只能為非負數
    
    std::cout << "\n有符號和無符號：" << std::endl;
    std::cout << "有符號整數：" << negativeNumber << std::endl;
    std::cout << "無符號整數：" << positiveOnly << std::endl;
    
    // 警告：無符號整數的陷阱
    unsigned int zeroMinusOne = 0;
    zeroMinusOne = zeroMinusOne - 1;  // 會變成很大的正數
    
    std::cout << "\n無符號整數的陷阱：" << std::endl;
    std::cout << "0 - 1 = " << zeroMinusOne << " (在無符號整數中)" << std::endl;
    
    // 3. 類型的大小（位元組數）
    std::cout << "\n各類型的大小（位元組）：" << std::endl;
    std::cout << "short: " << sizeof(short) << " 位元組" << std::endl;
    std::cout << "int: " << sizeof(int) << " 位元組" << std::endl;
    std::cout << "long: " << sizeof(long) << " 位元組" << std::endl;
    std::cout << "long long: " << sizeof(long long) << " 位元組" << std::endl;
    
    // 4. 類型的最小值和最大值
    std::cout << "\n各類型的範圍：" << std::endl;
    std::cout << "short: [" << SHRT_MIN << ", " << SHRT_MAX << "]" << std::endl;
    std::cout << "int: [" << INT_MIN << ", " << INT_MAX << "]" << std::endl;
    std::cout << "unsigned int: [0, " << UINT_MAX << "]" << std::endl;
    std::cout << "long long: [" << LLONG_MIN << ", " << LLONG_MAX << "]" << std::endl;
    
    return 0;
}
 