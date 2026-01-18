/*
 * 範例6：循環的實際應用
 * 綜合應用各種循環解決實際問題
 */
 
#include <iostream>
#include <iomanip>
#include <cmath>
 
int main() {
    std::cout << "=== 循環的實際應用 ===" << std::endl;
    
    // 1. 統計學生成績
    std::cout << "\n1. 統計學生成績：" << std::endl;
    
    int scores[] = {85, 92, 78, 95, 88, 76, 90, 84, 79, 91};
    int studentCount = 10;
    
    int highest = scores[0];
    int lowest = scores[0];
    int total = 0;
    
    // 找出最高分、最低分，計算總分
    for (int i = 0; i < studentCount; i++) {
        if (scores[i] > highest) {
            highest = scores[i];
        }
        
        if (scores[i] < lowest) {
            lowest = scores[i];
        }
        
        total += scores[i];
    }
    
    double average = static_cast<double>(total) / studentCount;
    
    std::cout << "學生人數：" << studentCount << std::endl;
    std::cout << "最高分：" << highest << std::endl;
    std::cout << "最低分：" << lowest << std::endl;
    std::cout << "平均分：" << average << std::endl;
    
    // 計算成績分佈
    int gradeA = 0, gradeB = 0, gradeC = 0, gradeD = 0, gradeF = 0;
    
    for (int i = 0; i < studentCount; i++) {
        if (scores[i] >= 90) {
            gradeA++;
        } else if (scores[i] >= 80) {
            gradeB++;
        } else if (scores[i] >= 70) {
            gradeC++;
        } else if (scores[i] >= 60) {
            gradeD++;
        } else {
            gradeF++;
        }
    }
    
    std::cout << "\n成績分佈：" << std::endl;
    std::cout << "A等：" << gradeA << " 人" << std::endl;
    std::cout << "B等：" << gradeB << " 人" << std::endl;
    std::cout << "C等：" << gradeC << " 人" << std::endl;
    std::cout << "D等：" << gradeD << " 人" << std::endl;
    std::cout << "F等：" << gradeF << " 人" << std::endl;
    
    // 2. 財務計算：複利
    std::cout << "\n2. 複利計算：" << std::endl;
    
    double principal = 10000.0;  // 本金
    double annualRate = 0.05;    // 年利率
    int years = 10;              // 年數
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "本金：" << principal << " 元" << std::endl;
    std::cout << "年利率：" << (annualRate * 100) << "%" << std::endl;
    std::cout << "投資年限：" << years << " 年" << std::endl;
    std::cout << "\n年度增長情況：" << std::endl;
    
    double amount = principal;
    
    for (int year = 1; year <= years; year++) {
        amount *= (1 + annualRate);
        std::cout << "第" << std::setw(2) << year << "年："
                  << std::setw(10) << amount << " 元" << std::endl;
    }
    
    double totalInterest = amount - principal;
    std::cout << "\n最終金額：" << amount << " 元" << std::endl;
    std::cout << "總利息：" << totalInterest << " 元" << std::endl;
    
    // 3. 質數生成器
    std::cout << "\n3. 找出1-100之間的所有質數：" << std::endl;
    
    int primeCount = 0;
    std::cout << "1-100之間的質數有：";
    
    for (int num = 2; num <= 100; num++) {
        bool isPrime = true;
        
        // 檢查是否為質數
        for (int i = 2; i <= sqrt(num); i++) {
            if (num % i == 0) {
                isPrime = false;
                break;
            }
        }
        
        if (isPrime) {
            std::cout << num << " ";
            primeCount++;
            
            // 每10個換一行
            if (primeCount % 10 == 0) {
                std::cout << std::endl << "                 ";
            }
        }
    }
    
    std::cout << std::endl;
    std::cout << "總共有 " << primeCount << " 個質數" << std::endl;
    
    // 4. 圖形時鐘（模擬）
    std::cout << "\n4. 模擬時鐘（每小時打印一次）：" << std::endl;
    
    std::cout << "    ";
    for (int hour = 0; hour < 12; hour++) {
        std::cout << std::setw(3) << hour;
    }
    std::cout << std::endl;
    
    for (int minute = 0; minute < 60; minute += 5) {
        std::cout << std::setw(2) << minute << " |";
        
        for (int hour = 0; hour < 12; hour++) {
            // 模擬時鐘位置計算
            if (minute == 0) {
                std::cout << "  X";  // 整點
            } else if (minute == 30) {
                std::cout << "  O";  // 半點
            } else {
                std::cout << "  .";  // 其他時間
            }
        }
        std::cout << std::endl;
    }
    
    // 5. 遊戲：猜數字（完整版）
    std::cout << "\n5. 猜數字遊戲（完整版）：" << std::endl;
    
    srand(time(0));  // 設置隨機種子
    int secret = rand() % 100 + 1;  // 1-100的隨機數
    int guess;
    int attempts = 0;
    const int MAX_ATTEMPTS = 7;
    
    std::cout << "我想了一個1到100之間的數字，你有" << MAX_ATTEMPTS << "次機會猜中它！" << std::endl;
    
    while (attempts < MAX_ATTEMPTS) {
        attempts++;
        std::cout << "\n第" << attempts << "次猜測，請輸入數字：";
        
        // 模擬不同猜測
        if (attempts == 1) {
            guess = 50;
            std::cout << guess << std::endl;
        } else if (attempts == 2) {
            guess = (guess < secret) ? 75 : 25;
            std::cout << guess << std::endl;
        } else if (attempts == 3) {
            guess = (guess < secret) ? 88 : 38;
            std::cout << guess << std::endl;
        } else if (attempts == 4) {
            guess = secret;  // 這次猜中
            std::cout << guess << std::endl;
        }
        
        if (guess < secret) {
            std::cout << "太小了！" << std::endl;
        } else if (guess > secret) {
            std::cout << "太大了！" << std::endl;
        } else {
            std::cout << "恭喜！你猜對了！" << std::endl;
            break;
        }
        
        if (attempts == MAX_ATTEMPTS) {
            std::cout << "很遺憾，你沒有猜中。正確數字是：" << secret << std::endl;
        }
    }
    
    // 6. 數據過濾和轉換
    std::cout << "\n6. 數據過濾和轉換：" << std::endl;
    
    const int DATA_SIZE = 10;
    int originalData[DATA_SIZE] = {15, -3, 8, 0, 22, -7, 19, 4, -1, 11};
    int processedData[DATA_SIZE];
    int processedCount = 0;
    
    std::cout << "原始數據：";
    for (int i = 0; i < DATA_SIZE; i++) {
        std::cout << originalData[i] << " ";
    }
    std::cout << std::endl;
    
    // 過濾負數和零，對正數加倍
    for (int i = 0; i < DATA_SIZE; i++) {
        if (originalData[i] <= 0) {
            continue;  // 跳過非正數
        }
        
        processedData[processedCount] = originalData[i] * 2;
        processedCount++;
    }
    
    std::cout << "處理後數據（正數加倍）：";
    for (int i = 0; i < processedCount; i++) {
        std::cout << processedData[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "有效數據個數：" << processedCount << std::endl;
    
    // 7. 模擬進度條
    std::cout << "\n7. 進度條模擬：" << std::endl;
    
    int totalTasks = 50;
    
    std::cout << "處理進度：[";
    
    for (int task = 1; task <= totalTasks; task++) {
        // 模擬處理每個任務
        std::cout << "#";
        
        // 每10個任務顯示一次百分比
        if (task % (totalTasks / 10) == 0) {
            int percent = (task * 100) / totalTasks;
            std::cout << " " << percent << "%";
        }
    }
    
    std::cout << "] 完成！" << std::endl;
    
    return 0;
}
 