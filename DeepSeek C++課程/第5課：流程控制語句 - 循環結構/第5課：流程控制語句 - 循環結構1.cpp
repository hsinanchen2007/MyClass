/*
 * 範例5-1：for循環基礎
 * for循環用於已知循環次數的情況
 * 語法：for(初始化; 條件; 更新) { 循環體 }
 */
 
#include <iostream>
 
int main() {
    std::cout << "=== for循環基礎演示 ===" << std::endl;
    
    // 1. 最基本的for循環：從1數到5
    std::cout << "1. 從1數到5：" << std::endl;
    for (int i = 1; i <= 5; i++) {
        std::cout << "i = " << i << std::endl;
    }
    
    // 2. 倒數計時：從5到1
    std::cout << "\n2. 倒數計時（5到1）：" << std::endl;
    for (int count = 5; count >= 1; count--) {
        std::cout << count << "..." << std::endl;
    }
    std::cout << "發射！" << std::endl;
    
    // 3. 跳著數：每次增加2
    std::cout << "\n3. 偶數（0到10）：" << std::endl;
    for (int num = 0; num <= 10; num += 2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    
    // 4. 計算1到10的總和
    std::cout << "\n4. 計算1到10的總和：" << std::endl;
    int sum = 0;
    for (int i = 1; i <= 10; i++) {
        sum += i;  // 累加
        std::cout << "加 " << i << "，目前總和：" << sum << std::endl;
    }
    std::cout << "1到10的總和 = " << sum << std::endl;
    
    // 5. 循環變數作用域（C++11以前）
    std::cout << "\n5. 循環變數作用域：" << std::endl;
    int i;  // 需要在外部聲明，才能在循環後使用
    for (i = 1; i <= 3; i++) {
        std::cout << "循環內 i = " << i << std::endl;
    }
    std::cout << "循環後 i = " << i << std::endl;
    
    // 6. 循環變數作用域（C++11及以後）
    std::cout << "\n6. C++11 for循環作用域：" << std::endl;
    for (int j = 1; j <= 3; j++) {
        std::cout << "循環內 j = " << j << std::endl;
    }
    // std::cout << "循環後 j = " << j << std::endl; // 錯誤！j只在循環內有效
    
    // 7. 複合初始化（多個循環變數）
    std::cout << "\n7. 多個循環變數：" << std::endl;
    for (int a = 1, b = 10; a <= 5; a++, b--) {
        std::cout << "a = " << a << ", b = " << b << std::endl;
    }
    
    // 8. for循環的靈活性
    std::cout << "\n8. 靈活的for循環：" << std::endl;
    int x = 0;
    for (; x < 5; ) {  // 省略初始化和更新
        std::cout << "x = " << x << std::endl;
        x++;  // 在循環體內更新
    }
    
    return 0;
}
 