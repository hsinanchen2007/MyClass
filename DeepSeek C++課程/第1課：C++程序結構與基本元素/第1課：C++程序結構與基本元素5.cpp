/*
 * 範例1-5：簡單計算與輸出
 * 展示如何在輸出中進行計算
 */
 
#include <iostream>
 
int main() {
    // 定義變數
    int a = 10;
    int b = 20;
    
    // 輸出基本變數
    std::cout << "變數 a = " << a << std::endl;
    std::cout << "變數 b = " << b << std::endl;
    
    // 在輸出中進行計算
    std::cout << "a + b = " << (a + b) << std::endl;
    std::cout << "b - a = " << (b - a) << std::endl;
    std::cout << "a * b = " << (a * b) << std::endl;
    std::cout << "b / a = " << (b / a) << std::endl;
    
    // 注意：整數除法會捨棄小數部分
    // 10 / 3 會得到 3，而不是 3.333
    std::cout << "10 / 3 = " << (10 / 3) << " (整數除法)" << std::endl;
    
    return 0;
}
 