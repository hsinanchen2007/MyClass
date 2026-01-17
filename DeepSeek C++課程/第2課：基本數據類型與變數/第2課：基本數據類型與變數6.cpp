/*
 * 範例2-6：類型轉換與自動類型推導 (C++11)
 * 1. 隱式類型轉換（自動轉換）
 * 2. 顯式類型轉換（強制轉換）
 * 3. auto 關鍵字（C++11）
 */
 
#include <iostream>
 
int main() {
    std::cout << "=== 類型轉換與自動類型推導 ===" << std::endl;
    
    // 1. 隱式類型轉換（編譯器自動進行）
    int intNum = 10;
    double doubleNum = 3.14;
    
    // 整數轉浮點數
    double result1 = intNum + doubleNum;  // intNum 被轉換為 double
    std::cout << "隱式轉換：" << intNum << " + " << doubleNum << " = " << result1 << std::endl;
    
    // 浮點數轉整數（小數部分被捨棄）
    int result2 = intNum + doubleNum;  // doubleNum 被轉換為 int
    std::cout << "隱式轉換（小數丟失）：" << intNum << " + " << doubleNum << " = " << result2 << std::endl;
    
    // 2. 顯式類型轉換（C風格）
    double pi = 3.14159;
    int intPi = (int)pi;  // C風格類型轉換
    std::cout << "\n顯式轉換（C風格）：" << std::endl;
    std::cout << "pi = " << pi << std::endl;
    std::cout << "(int)pi = " << intPi << std::endl;
    
    // 3. 顯式類型轉換（C++風格，推薦）
    double price = 19.99;
    int intPrice = static_cast<int>(price);  // C++風格類型轉換
    std::cout << "\n顯式轉換（C++風格）：" << std::endl;
    std::cout << "price = " << price << std::endl;
    std::cout << "static_cast<int>(price) = " << intPrice << std::endl;
    
    // 4. 自動類型推導（C++11 auto）
    auto x = 10;           // x 被推導為 int
    auto y = 3.14;         // y 被推導為 double
    auto z = 'A';          // z 被推導為 char
    auto flag = true;      // flag 被推導為 bool
    
    std::cout << "\n自動類型推導（auto）：" << std::endl;
    std::cout << "auto x = 10;    // x 是 " << typeid(x).name() << std::endl;
    std::cout << "auto y = 3.14;  // y 是 " << typeid(y).name() << std::endl;
    std::cout << "auto z = 'A';   // z 是 " << typeid(z).name() << std::endl;
    std::cout << "auto flag = true; // flag 是 " << typeid(flag).name() << std::endl;
    
    // 5. auto 的實際應用
    auto sum = x + y;  // sum 被推導為 double
    std::cout << "\nauto 實際應用：" << std::endl;
    std::cout << "x + y = " << sum << " (類型: " << typeid(sum).name() << ")" << std::endl;
    
    return 0;
}
 