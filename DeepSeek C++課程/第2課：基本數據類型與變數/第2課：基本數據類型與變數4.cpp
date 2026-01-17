/*
 * 範例2-4：布林類型 (bool)
 * 用於表示邏輯值：真(true)或假(false)
 * 在C++中，true是1，false是0
 */
 
#include <iostream>
 
int main() {
    std::cout << "=== 布林類型演示 ===" << std::endl;
    
    // 1. 布林變數的聲明與初始化
    bool isSunny = true;
    bool isRaining = false;
    bool isWeekend = true;
    
    std::cout << "今天晴天：" << isSunny << std::endl;
    std::cout << "今天下雨：" << isRaining << std::endl;
    std::cout << "今天是週末：" << isWeekend << std::endl;
    
    // 2. 布林值在輸出時的顯示
    std::cout << "\n布林值顯示（使用boolalpha）：" << std::endl;
    std::cout << std::boolalpha;  // 以 true/false 形式顯示布林值
    std::cout << "今天晴天：" << isSunny << std::endl;
    std::cout << "今天下雨：" << isRaining << std::endl;
    
    // 3. 關係運算返回布林值
    int a = 10, b = 5;
    std::cout << "\n關係運算：" << std::endl;
    std::cout << a << " > " << b << " : " << (a > b) << std::endl;
    std::cout << a << " < " << b << " : " << (a < b) << std::endl;
    std::cout << a << " == " << b << " : " << (a == b) << std::endl;
    std::cout << a << " != " << b << " : " << (a != b) << std::endl;
    
    // 4. 邏輯運算
    bool condition1 = true;
    bool condition2 = false;
    
    std::cout << "\n邏輯運算：" << std::endl;
    std::cout << "條件1：" << condition1 << std::endl;
    std::cout << "條件2：" << condition2 << std::endl;
    std::cout << "條件1 AND 條件2：" << (condition1 && condition2) << std::endl;
    std::cout << "條件1 OR 條件2：" << (condition1 || condition2) << std::endl;
    std::cout << "NOT 條件1：" << (!condition1) << std::endl;
    
    // 5. 實際應用：條件判斷
    int score = 85;
    bool isPass = (score >= 60);  // 分數大於等於60分為及格
    
    std::cout << "\n實際應用：考試成績" << std::endl;
    std::cout << "分數：" << score << std::endl;
    std::cout << "是否及格：" << isPass << std::endl;
    
    return 0;
}
 