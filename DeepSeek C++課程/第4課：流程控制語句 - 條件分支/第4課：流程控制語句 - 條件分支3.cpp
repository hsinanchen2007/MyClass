/*
 * 範例4-3：switch-case語句
 * 用於多路分支選擇，比多個if-else更清晰
 */
 
#include <iostream>
 
int main() {
    std::cout << "=== switch-case語句演示 ===" << std::endl;
    
    // 1. 基本的switch-case
    int dayOfWeek = 3;
    
    std::cout << "今天是星期";
    switch (dayOfWeek) {
        case 1:
            std::cout << "一" << std::endl;
            break;
        case 2:
            std::cout << "二" << std::endl;
            break;
        case 3:
            std::cout << "三" << std::endl;
            break;
        case 4:
            std::cout << "四" << std::endl;
            break;
        case 5:
            std::cout << "五" << std::endl;
            break;
        case 6:
            std::cout << "六" << std::endl;
            break;
        case 7:
            std::cout << "日" << std::endl;
            break;
        default:
            std::cout << "？ (無效的輸入，請輸入1-7)" << std::endl;
            break;
    }
    
    // 2. case的多值處理（多個case執行相同代碼）
    char grade = 'B';
    
    std::cout << "你的成績等級 " << grade << " 對應的評語是：";
    switch (grade) {
        case 'A':
        case 'a':
            std::cout << "優秀！" << std::endl;
            break;
        case 'B':
        case 'b':
            std::cout << "良好" << std::endl;
            break;
        case 'C':
        case 'c':
            std::cout << "中等" << std::endl;
            break;
        case 'D':
        case 'd':
            std::cout << "及格" << std::endl;
            break;
        case 'F':
        case 'f':
            std::cout << "不及格" << std::endl;
            break;
        default:
            std::cout << "無效的成績等級" << std::endl;
            break;
    }
    
    // 3. 計算器示例
    char operatorChar = '+';
    double num1 = 10.5, num2 = 5.5, result = 0.0;
    
    switch (operatorChar) {
        case '+':
            result = num1 + num2;
            break;
        case '-':
            result = num1 - num2;
            break;
        case '*':
            result = num1 * num2;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
            } else {
                std::cout << "錯誤：除數不能為零！" << std::endl;
                return 1;  // 返回非零表示錯誤
            }
            break;
        default:
            std::cout << "錯誤：不支持的運算符！" << std::endl;
            return 1;
    }
    
    std::cout << num1 << " " << operatorChar << " " << num2 << " = " << result << std::endl;
    
    // 4. break的重要性（沒有break會發生穿透）
    int option = 2;
    
    std::cout << "\n沒有break的switch-case（演示穿透現象）：" << std::endl;
    switch (option) {
        case 1:
            std::cout << "執行case 1" << std::endl;
            // 注意：這裡沒有break！
        case 2:
            std::cout << "執行case 2" << std::endl;
            // 注意：這裡沒有break！
        case 3:
            std::cout << "執行case 3" << std::endl;
            // 注意：這裡沒有break！
        default:
            std::cout << "執行default" << std::endl;
    }
    
    std::cout << "\n有break的switch-case：" << std::endl;
    switch (option) {
        case 1:
            std::cout << "執行case 1" << std::endl;
            break;
        case 2:
            std::cout << "執行case 2" << std::endl;
            break;
        case 3:
            std::cout << "執行case 3" << std::endl;
            break;
        default:
            std::cout << "執行default" << std::endl;
    }
    
    // 5. switch的限制：只能用於整數類型或枚舉
    int value = 65;
    
    switch (value) {
        case 'A':  // 'A'的ASCII碼是65，所以這個case會匹配
            std::cout << "值等於字符'A'的ASCII碼" << std::endl;
            break;
        case 66:
            std::cout << "值等於66" << std::endl;
            break;
        default:
            std::cout << "其他值" << std::endl;
    }
    
    return 0;
}
 