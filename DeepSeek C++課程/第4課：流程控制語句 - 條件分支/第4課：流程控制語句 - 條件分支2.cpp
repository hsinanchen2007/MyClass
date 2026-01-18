/*
 * 範例4-2：if-else語句
 * if-else用於在兩個選項中選擇一個執行
 */
 
#include <iostream>
 
int main() {
    std::cout << "=== if-else語句演示 ===" << std::endl;
    
    // 1. 基本的if-else
    int age = 16;
    
    if (age >= 18) {
        std::cout << "你可以觀看所有級別的電影" << std::endl;
    } else {
        std::cout << "你只能觀看輔導級以下的電影" << std::endl;
    }
    
    // 2. 多個條件判斷
    int score = 85;
    
    if (score >= 90) {
        std::cout << "成績優秀！" << std::endl;
    } else if (score >= 80) {
        std::cout << "成績良好" << std::endl;
    } else if (score >= 70) {
        std::cout << "成績中等" << std::endl;
    } else if (score >= 60) {
        std::cout << "成績及格" << std::endl;
    } else {
        std::cout << "成績不及格，需要補考" << std::endl;
    }
    
    // 3. 條件表達式可以包含運算
    int num = 15;
    
    if (num % 2 == 0) {
        std::cout << num << " 是偶數" << std::endl;
    } else {
        std::cout << num << " 是奇數" << std::endl;
    }
    
    // 4. 嵌套if語句
    int year = 2024;
    bool isLeapYear = false;
    
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                isLeapYear = true;
            } else {
                isLeapYear = false;
            }
        } else {
            isLeapYear = true;
        }
    } else {
        isLeapYear = false;
    }
    
    if (isLeapYear) {
        std::cout << year << " 年是閏年" << std::endl;
    } else {
        std::cout << year << " 年不是閏年" << std::endl;
    }
    
    // 5. 簡化嵌套if（使用邏輯運算符）
    bool isLeapYear2 = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    
    if (isLeapYear2) {
        std::cout << "簡化判斷：" << year << " 年是閏年" << std::endl;
    } else {
        std::cout << "簡化判斷：" << year << " 年不是閏年" << std::endl;
    }
    
    // 6. if-else語句的返回值可以賦值給變數
    int x = 10, y = 20;
    int maxValue;
    
    if (x > y) {
        maxValue = x;
    } else {
        maxValue = y;
    }
    
    std::cout << x << " 和 " << y << " 中較大的是：" << maxValue << std::endl;
    
    // 也可以使用條件運算符簡化
    int minValue = (x < y) ? x : y;
    std::cout << x << " 和 " << y << " 中較小的是：" << minValue << std::endl;
    
    return 0;
}
 