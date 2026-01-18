/*
 * 範例5-3：do-while循環
 * do-while循環至少執行一次，然後檢查條件
 * 語法：do { 循環體 } while(條件);
 */
 
#include <iostream>
#include <string>
 
int main() {
    std::cout << "=== do-while循環演示 ===" << std::endl;
    
    // 1. 基本的do-while循環
    std::cout << "1. 從1數到5：" << std::endl;
    int i = 1;
    do {
        std::cout << "i = " << i << std::endl;
        i++;
    } while (i <= 5);
    
    // 2. do-while與while的區別
    std::cout << "\n2. do-while與while的區別：" << std::endl;
    
    // while循環：先檢查條件
    int a = 10;
    std::cout << "while循環（條件一開始就為假）：" << std::endl;
    while (a < 5) {
        std::cout << "這行不會執行" << std::endl;
        a++;
    }
    std::cout << "while循環結束，a = " << a << std::endl;
    
    // do-while循環：先執行一次
    int b = 10;
    std::cout << "\ndo-while循環（條件一開始就為假）：" << std::endl;
    do {
        std::cout << "這行會執行一次，b = " << b << std::endl;
        b++;
    } while (b < 5);
    std::cout << "do-while循環結束，b = " << b << std::endl;
    
    // 3. 用戶菜單系統
    std::cout << "\n3. 簡單菜單系統：" << std::endl;
    int choice;
    
    do {
        std::cout << "\n===== 主菜單 =====" << std::endl;
        std::cout << "1. 查看餘額" << std::endl;
        std::cout << "2. 存款" << std::endl;
        std::cout << "3. 取款" << std::endl;
        std::cout << "4. 退出" << std::endl;
        std::cout << "請選擇操作（1-4）：";
        
        // 模擬用戶輸入（這裡固定選擇）
        static int menuCounter = 0;
        menuCounter++;
        
        if (menuCounter == 1) {
            choice = 1;  // 查看餘額
        } else if (menuCounter == 2) {
            choice = 2;  // 存款
        } else if (menuCounter == 3) {
            choice = 4;  // 退出
        }
        
        std::cout << choice << std::endl;
        
        switch (choice) {
            case 1:
                std::cout << "您的餘額是：1000元" << std::endl;
                break;
            case 2:
                std::cout << "存款功能（開發中）" << std::endl;
                break;
            case 3:
                std::cout << "取款功能（開發中）" << std::endl;
                break;
            case 4:
                std::cout << "感謝使用，再見！" << std::endl;
                break;
            default:
                std::cout << "無效選擇，請重新輸入！" << std::endl;
        }
        
    } while (choice != 4);
    
    // 4. 輸入驗證（確保用戶輸入有效值）
    std::cout << "\n4. 輸入驗證（必須輸入正數）：" << std::endl;
    int number;
    
    do {
        std::cout << "請輸入一個正整數：";
        
        // 模擬用戶輸入
        static int inputCounter = 0;
        inputCounter++;
        
        if (inputCounter == 1) {
            number = -5;  // 無效輸入
            std::cout << number << std::endl;
        } else if (inputCounter == 2) {
            number = 0;   // 無效輸入（我們要求正數）
            std::cout << number << std::endl;
        } else {
            number = 10;  // 有效輸入
            std::cout << number << std::endl;
        }
        
        if (number <= 0) {
            std::cout << "輸入無效！必須是正整數。" << std::endl;
        }
    } while (number <= 0);
    
    std::cout << "您輸入的是：" << number << std::endl;
    
    // 5. 猜數字遊戲
    std::cout << "\n5. 猜數字遊戲：" << std::endl;
    int secretNumber = 42;
    int guess;
    int attempts = 0;
    
    std::cout << "我想到了一個1到100之間的數字..." << std::endl;
    
    do {
        attempts++;
        std::cout << "第" << attempts << "次猜測：";
        
        // 模擬不同猜測
        if (attempts == 1) {
            guess = 50;
        } else if (attempts == 2) {
            guess = 25;
        } else if (attempts == 3) {
            guess = 42;  // 正確答案
        }
        
        std::cout << guess << std::endl;
        
        if (guess < secretNumber) {
            std::cout << "太小了！" << std::endl;
        } else if (guess > secretNumber) {
            std::cout << "太大了！" << std::endl;
        } else {
            std::cout << "恭喜！你猜對了！" << std::endl;
        }
        
    } while (guess != secretNumber && attempts < 5);
    
    if (guess != secretNumber) {
        std::cout << "遊戲結束！正確數字是：" << secretNumber << std::endl;
    }
    
    // 6. 計算平均分數
    std::cout << "\n6. 計算多個分數的平均值：" << std::endl;
    int score;
    int sum = 0;
    int count = 0;
    char another;
    
    do {
        count++;
        std::cout << "輸入第" << count << "個分數：";
        
        // 模擬輸入一些分數
        if (count == 1) {
            score = 85;
        } else if (count == 2) {
            score = 92;
        } else if (count == 3) {
            score = 78;
        } else {
            score = -1;  // 結束標誌
        }
        
        if (score != -1) {
            std::cout << score << std::endl;
            sum += score;
            
            // 模擬詢問是否繼續
            if (count < 3) {
                another = 'y';
            } else {
                another = 'n';
            }
            
            std::cout << "是否繼續輸入分數？(y/n): " << another << std::endl;
        } else {
            another = 'n';
        }
        
    } while (another == 'y' || another == 'Y');
    
    if (count > 0) {
        double average = static_cast<double>(sum) / count;
        std::cout << "共輸入 " << count << " 個分數" << std::endl;
        std::cout << "總分：" << sum << std::endl;
        std::cout << "平均分：" << average << std::endl;
    } else {
        std::cout << "沒有輸入分數" << std::endl;
    }
    
    return 0;
}
 