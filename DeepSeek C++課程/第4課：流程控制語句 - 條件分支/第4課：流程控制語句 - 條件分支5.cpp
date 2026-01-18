/*
 * 範例4-5：break與continue在條件中的使用
 * 雖然break和continue主要用於循環，但在switch中也有重要作用
 */
 
#include <iostream>
 
int main() {
    std::cout << "=== break與continue在條件中的使用 ===" << std::endl;
    
    // 1. break在switch中的應用
    int menuChoice = 2;
    
    std::cout << "菜單選擇：" << std::endl;
    switch (menuChoice) {
        case 1:
            std::cout << "1. 開始新遊戲" << std::endl;
            // 這裡可以執行開始遊戲的代碼
            break;  // 跳出switch
            
        case 2:
            std::cout << "2. 載入遊戲" << std::endl;
            // 這裡可以執行載入遊戲的代碼
            break;  // 跳出switch
            
        case 3:
            std::cout << "3. 遊戲設置" << std::endl;
            // 這裡可以執行設置的代碼
            break;  // 跳出switch
            
        case 4:
            std::cout << "4. 退出遊戲" << std::endl;
            // 這裡可以執行退出的代碼
            break;  // 跳出switch
            
        default:
            std::cout << "無效選擇，請重新輸入" << std::endl;
            break;  // 雖然default是最後一個，但養成習慣總是加break
    }
    
    // 2. 使用break提前結束條件判斷
    std::cout << "\n使用break提前結束條件判斷：" << std::endl;
    
    int score = 95;
    bool hasCheated = false;
    bool isDisqualified = false;
    
    // 模擬一系列檢查
    if (hasCheated) {
        std::cout << "作弊，取消資格！" << std::endl;
        isDisqualified = true;
    }
    
    if (!isDisqualified) {
        if (score < 0 || score > 100) {
            std::cout << "分數無效！" << std::endl;
            isDisqualified = true;
        }
    }
    
    if (!isDisqualified) {
        if (score >= 90) {
            std::cout << "優秀！" << std::endl;
        } else if (score >= 60) {
            std::cout << "及格" << std::endl;
        } else {
            std::cout << "不及格" << std::endl;
        }
    }
    
    // 3. 在循環中使用break和continue（預覽，下一課詳細講解）
    std::cout << "\n循環中的break和continue（預覽）：" << std::endl;
    
    for (int i = 1; i <= 10; i++) {
        if (i == 3) {
            continue;  // 跳過3
        }
        
        if (i == 8) {
            break;     // 在8時結束循環
        }
        
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    // 4. 條件表達式的值
    std::cout << "\n條件表達式的值：" << std::endl;
    
    int x = 10, y = 20;
    
    // 條件表達式本身有值
    std::cout << "x > y 的值是：" << (x > y) << std::endl;
    std::cout << "x < y 的值是：" << (x < y) << std::endl;
    
    // 可以將條件表達式的值賦給變數
    bool isGreater = (x > y);
    bool isLess = (x < y);
    
    std::cout << "isGreater: " << isGreater << std::endl;
    std::cout << "isLess: " << isLess << std::endl;
    
    // 5. 複雜條件表達式的求值順序
    std::cout << "\n複雜條件表達式的求值順序：" << std::endl;
    
    int a = 1, b = 2, c = 3;
    
    // 注意運算符優先級：關係運算符高於邏輯運算符
    bool result1 = a < b && b < c;      // 等價於 (a < b) && (b < c)
    bool result2 = a < b || b > c;      // 等價於 (a < b) || (b > c)
    bool result3 = !(a > b) && c > b;   // 等價於 (!(a > b)) && (c > b)
    
    std::cout << "a < b && b < c: " << result1 << std::endl;
    std::cout << "a < b || b > c: " << result2 << std::endl;
    std::cout << "!(a > b) && c > b: " << result3 << std::endl;
    
    return 0;
}
 