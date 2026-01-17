/*
 * 範例2-2：浮點數類型 (float, double)
 * 浮點數用於存儲帶有小數部分的數字
 * double 比 float 精度更高，更常用
 */
 
#include <iostream>
#include <iomanip>  // 用於控制輸出格式
 
int main() {
    std::cout << "=== 浮點數類型演示 ===" << std::endl;
    
    // 1. float 類型（單精度浮點數）
    float pi_float = 3.1415926535f;  // 注意後綴 f 表示 float
    float radius = 5.0f;
    float area_float = pi_float * radius * radius;
    
    std::cout << "float 計算圓面積：" << std::endl;
    std::cout << "半徑：" << radius << " 公尺" << std::endl;
    std::cout << "面積：" << area_float << " 平方公尺" << std::endl;
    
    // 2. double 類型（雙精度浮點數，更精確）
    double pi_double = 3.141592653589793;
    double area_double = pi_double * radius * radius;
    
    std::cout << "\ndouble 計算圓面積：" << std::endl;
    std::cout << "面積：" << area_double << " 平方公尺" << std::endl;
    
    // 3. 浮點數運算
    double x = 10.5, y = 3.2;
    std::cout << "\n浮點數運算：" << std::endl;
    std::cout << std::fixed << std::setprecision(2);  // 固定小數點，顯示2位小數
    std::cout << x << " + " << y << " = " << (x + y) << std::endl;
    std::cout << x << " - " << y << " = " << (x - y) << std::endl;
    std::cout << x << " * " << y << " = " << (x * y) << std::endl;
    std::cout << x << " / " << y << " = " << (x / y) << std::endl;
    
    // 4. 精度比較
    std::cout << "\n精度比較（圓周率）：" << std::endl;
    std::cout << std::setprecision(10);  // 顯示10位小數
    std::cout << "float  : " << pi_float << std::endl;
    std::cout << "double : " << pi_double << std::endl;
    
    return 0;
}
 