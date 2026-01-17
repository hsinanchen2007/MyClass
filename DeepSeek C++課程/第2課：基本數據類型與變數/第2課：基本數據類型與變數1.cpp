/*
 * 範例2-1：整數類型 (int)
 * 整數是最基本的數據類型，用於存儲沒有小數部分的數字
 */
 
#include <iostream>
#include <climits>  // 包含整數類型的限制資訊
 
int main() {
    std::cout << "=== 整數類型演示 ===" << std::endl;
    
    // 1. 變數聲明與初始化
    int age = 25;           // 聲明並初始化一個整數變數
    int year;               // 只聲明，未初始化（值不確定）
    year = 2024;            // 賦值
    
    std::cout << "年齡：" << age << " 歲" << std::endl;
    std::cout << "年份：" << year << " 年" << std::endl;
    
    // 2. 同時聲明多個變數
    int width = 1920, height = 1080;
    std::cout << "解析度：" << width << "x" << height << std::endl;
    
    // 3. 整數的範圍（使用 climits 中的常數）
    std::cout << "\n整數類型的範圍：" << std::endl;
    std::cout << "int 的最小值：" << INT_MIN << std::endl;
    std::cout << "int 的最大值：" << INT_MAX << std::endl;
    
    // 4. 整數運算
    int a = 10, b = 3;
    std::cout << "\n整數運算：" << std::endl;
    std::cout << a << " + " << b << " = " << (a + b) << std::endl;
    std::cout << a << " - " << b << " = " << (a - b) << std::endl;
    std::cout << a << " * " << b << " = " << (a * b) << std::endl;
    std::cout << a << " / " << b << " = " << (a / b) << std::endl;
    std::cout << a << " % " << b << " = " << (a % b) << std::endl;
    
    // 注意：整數除法會捨棄小數部分
    std::cout << "整數除法 10/3 = " << (10/3) << " (不是 3.333)" << std::endl;
    
    return 0;
}
 