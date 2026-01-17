/*
 * 範例3-2：關係運算符與邏輯運算符
 * 用於比較和邏輯判斷
 */
 
#include <iostream>
 
int main() {
    std::cout << "=== 關係運算符與邏輯運算符演示 ===" << std::endl;
    
    int x = 10;
    int y = 5;
    int z = 10;
    
    // 關係運算符（比較運算符）
    std::cout << "關係運算符：" << std::endl;
    std::cout << "x = " << x << ", y = " << y << ", z = " << z << std::endl;
    std::cout << "x > y : " << (x > y) << std::endl;    // 大於
    std::cout << "x < y : " << (x < y) << std::endl;    // 小於
    std::cout << "x >= z : " << (x >= z) << std::endl;  // 大於等於
    std::cout << "x <= z : " << (x <= z) << std::endl;  // 小於等於
    std::cout << "x == z : " << (x == z) << std::endl;  // 等於
    std::cout << "x != y : " << (x != y) << std::endl;  // 不等於
    
    // 邏輯運算符
    std::cout << "\n邏輯運算符：" << std::endl;
    bool isSunny = true;
    bool isWarm = false;
    bool isWeekend = true;
    
    std::cout << std::boolalpha;  // 輸出 true/false 而非 1/0
    std::cout << "isSunny: " << isSunny << std::endl;
    std::cout << "isWarm: " << isWarm << std::endl;
    std::cout << "isWeekend: " << isWeekend << std::endl;
    
    std::cout << "\n邏輯運算：" << std::endl;
    std::cout << "isSunny && isWarm : " << (isSunny && isWarm) << std::endl;  // 邏輯與 (AND)
    std::cout << "isSunny || isWarm : " << (isSunny || isWarm) << std::endl;  // 邏輯或 (OR)
    std::cout << "!isSunny : " << (!isSunny) << std::endl;                    // 邏輯非 (NOT)
    
    // 組合邏輯
    bool goodWeather = isSunny && !isWarm;  // 晴天但不熱
    bool goodDay = isWeekend && goodWeather; // 週末且好天氣
    
    std::cout << "\n組合邏輯：" << std::endl;
    std::cout << "好天氣（晴天但不熱）: " << goodWeather << std::endl;
    std::cout << "好日子（週末且好天氣）: " << goodDay << std::endl;
    
    // 短路求值
    std::cout << "\n短路求值：" << std::endl;
    int a = 5, b = 0;
    
    // 邏輯與：如果第一個為假，第二個不會被求值
    if (b != 0 && a / b > 2) {
        std::cout << "這行不會執行" << std::endl;
    } else {
        std::cout << "短路求值避免了除以零的錯誤" << std::endl;
    }
    
    // 邏輯或：如果第一個為真，第二個不會被求值
    if (a > 0 || b / a > 0) {
        std::cout << "短路求值：第二個表達式不會被求值" << std::endl;
    }
    
    return 0;
}
 