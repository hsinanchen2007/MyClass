/*
 * 範例5-2：while循環
 * while循環用於循環次數未知，但循環條件明確的情況
 * 語法：while(條件) { 循環體 }
 */
 
#include <iostream>
 
int main() {
    std::cout << "=== while循環演示 ===" << std::endl;
    
    // 1. 基本的while循環
    std::cout << "1. 從1數到5：" << std::endl;
    int i = 1;  // 初始化
    while (i <= 5) {  // 條件檢查
        std::cout << "i = " << i << std::endl;
        i++;  // 更新
    }
    
    // 2. 計算1到100的總和
    std::cout << "\n2. 計算1到100的總和：" << std::endl;
    int num = 1;
    int total = 0;
    
    while (num <= 100) {
        total += num;
        num++;
    }
    std::cout << "1到100的總和 = " << total << std::endl;
    
    // 3. 用戶輸入驗證
    std::cout << "\n3. 用戶輸入驗證（模擬）：" << std::endl;
    int password = 123456;
    int userInput = 0;
    int attempts = 0;
    const int MAX_ATTEMPTS = 3;
    
    // 模擬用戶嘗試輸入密碼
    while (userInput != password && attempts < MAX_ATTEMPTS) {
        attempts++;
        
        // 模擬不同輸入
        if (attempts == 1) {
            userInput = 111111;
        } else if (attempts == 2) {
            userInput = 654321;
        } else {
            userInput = 123456;  // 正確密碼
        }
        
        std::cout << "嘗試 " << attempts << ": 輸入 " << userInput;
        
        if (userInput == password) {
            std::cout << " - 登錄成功！" << std::endl;
        } else {
            std::cout << " - 密碼錯誤！" << std::endl;
        }
    }
    
    if (userInput != password) {
        std::cout << "嘗試次數過多，帳戶已鎖定！" << std::endl;
    }
    
    // 4. 計算階乘
    std::cout << "\n4. 計算階乘（5!）：" << std::endl;
    int n = 5;
    int factorial = 1;
    int counter = 1;
    
    while (counter <= n) {
        factorial *= counter;
        std::cout << counter << "! = " << factorial << std::endl;
        counter++;
    }
    std::cout << n << "! = " << factorial << std::endl;
    
    // 5. 斐波那契數列
    std::cout << "\n5. 斐波那契數列（前10個）：" << std::endl;
    int a = 0, b = 1;
    int count = 0;
    
    std::cout << a << " " << b << " ";
    count = 2;  // 已經輸出了兩個
    
    while (count < 10) {
        int next = a + b;
        std::cout << next << " ";
        
        // 更新前兩個數
        a = b;
        b = next;
        count++;
    }
    std::cout << std::endl;
    
    // 6. 條件複雜的while循環
    std::cout << "\n6. 條件複雜的while循環：" << std::endl;
    int value = 100;
    int divisor = 3;
    
    std::cout << value << " 除以 " << divisor << " 的過程：" << std::endl;
    while (value >= divisor) {
        std::cout << value << " / " << divisor << " = " << (value / divisor);
        std::cout << "，餘數 " << (value % divisor) << std::endl;
        value /= divisor;  // value = value / divisor
    }
    std::cout << "最終值：" << value << std::endl;
    
    // 7. 注意：避免無限循環
    std::cout << "\n7. 注意：避免無限循環" << std::endl;
    int safeCounter = 0;
    bool condition = true;
    
    // 使用安全計數器防止無限循環
    while (condition && safeCounter < 5) {
        std::cout << "安全循環 " << safeCounter + 1 << std::endl;
        safeCounter++;
        
        // 模擬某個條件會改變
        if (safeCounter == 3) {
            condition = false;  // 改變條件，使循環結束
        }
    }
    
    return 0;
}
 