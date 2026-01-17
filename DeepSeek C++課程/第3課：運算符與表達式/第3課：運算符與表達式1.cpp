/*
 * 範例3-1：算術運算符
 * 用於基本的數學計算：加、減、乘、除、取餘數
 */
 
#include <iostream>
 
int main() {
    std::cout << "=== 算術運算符演示 ===" << std::endl;
    
    int a = 20;
    int b = 6;
    double c = 20.0;
    double d = 6.0;
    
    std::cout << "整數運算：" << std::endl;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "a + b = " << (a + b) << std::endl;  // 加法
    std::cout << "a - b = " << (a - b) << std::endl;  // 減法
    std::cout << "a * b = " << (a * b) << std::endl;  // 乘法
    std::cout << "a / b = " << (a / b) << std::endl;  // 整數除法
    std::cout << "a % b = " << (a % b) << std::endl;  // 取餘數
    
    std::cout << "\n浮點數運算：" << std::endl;
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "c / d = " << (c / d) << std::endl;  // 浮點數除法
    
    // 注意：整數除法和浮點數除法的區別
    std::cout << "\n整數除法 vs 浮點數除法：" << std::endl;
    std::cout << "10 / 4 = " << (10 / 4) << " (整數除法，結果為整數)" << std::endl;
    std::cout << "10.0 / 4 = " << (10.0 / 4) << " (浮點數除法，結果為浮點數)" << std::endl;
    
    // 取餘運算符 (%) 只能用於整數
    // std::cout << "10.5 % 3.2 = " << (10.5 % 3.2) << std::endl; // 錯誤！
    std::cout << "10 % 3 = " << (10 % 3) << std::endl;
    
    // 運算符的優先級
    std::cout << "\n運算符優先級：" << std::endl;
    int result1 = 2 + 3 * 4;      // 先乘除後加減
    int result2 = (2 + 3) * 4;    // 括號優先
    
    std::cout << "2 + 3 * 4 = " << result1 << std::endl;
    std::cout << "(2 + 3) * 4 = " << result2 << std::endl;
    
    return 0;
}
 