/*
 * 範例4-1：基本if語句
 * if語句用於根據條件決定是否執行某段代碼
 */
 
#include <iostream>
 
int main() {
    std::cout << "=== 基本if語句演示 ===" << std::endl;
    
    int age = 18;
    
    // 最基本的if語句
    if (age >= 18) {
        std::cout << "你已經成年了！" << std::endl;
    }
    
    std::cout << "程序繼續執行..." << std::endl;
    
    // if語句可以不用大括號，但只控制緊接著的一條語句
    int score = 85;
    if (score >= 60)
        std::cout << "恭喜，你及格了！" << std::endl;
    
    // 注意：沒有大括號時，只控制下一條語句
    if (score >= 60)
        std::cout << "這是if控制的語句" << std::endl;
        std::cout << "這是不受if控制的語句，總是會執行" << std::endl;  // 注意縮進不代表控制
    
    // 推薦總是使用大括號，即使只有一條語句
    int temperature = 30;
    if (temperature > 25) {
        std::cout << "今天天氣炎熱，建議減少外出" << std::endl;
    }
    
    // 比較運算符在條件中的使用
    int a = 10, b = 20;
    if (a < b) {
        std::cout << a << " 小於 " << b << std::endl;
    }
    
    // 邏輯運算符在條件中的使用
    int hour = 14;  // 24小時制
    if (hour >= 9 && hour <= 17) {
        std::cout << "現在是工作時間" << std::endl;
    }
    
    return 0;
}
 