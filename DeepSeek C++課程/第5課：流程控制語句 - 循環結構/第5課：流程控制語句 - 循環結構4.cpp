/*
 * 範例5-4：break與continue
 * break：立即跳出當前循環
 * continue：跳過本次循環的剩餘部分，進入下一次循環
 */
 
#include <iostream>
 
int main() {
    std::cout << "=== break與continue演示 ===" << std::endl;
    
    // 1. break基本用法
    std::cout << "1. break基本用法：" << std::endl;
    std::cout << "尋找第一個能被3和5整除的數（1-100）：" << std::endl;
    
    for (int i = 1; i <= 100; i++) {
        if (i % 3 == 0 && i % 5 == 0) {
            std::cout << "找到：" << i << std::endl;
            break;  // 找到後立即跳出循環
        }
        std::cout << "檢查 " << i << "..." << std::endl;
    }
    
    // 2. continue基本用法
    std::cout << "\n2. continue基本用法：" << std::endl;
    std::cout << "輸出1-10中的奇數：" << std::endl;
    
    for (int i = 1; i <= 10; i++) {
        if (i % 2 == 0) {  // 如果是偶數
            continue;       // 跳過偶數，不執行後面的輸出
        }
        std::cout << i << " ";
    }
    std::cout << std::endl;
    
    // 3. break在while循環中的使用
    std::cout << "\n3. break在while循環中：" << std::endl;
    int number = 1;
    
    while (true) {  // 看似無限循環
        std::cout << "當前數字：" << number << std::endl;
        
        if (number >= 5) {
            std::cout << "達到條件，跳出循環" << std::endl;
            break;  // 跳出循環
        }
        
        number++;
    }
    
    // 4. continue在while循環中的使用
    std::cout << "\n4. continue在while循環中：" << std::endl;
    int n = 0;
    
    while (n < 10) {
        n++;
        
        if (n % 3 == 0) {
            continue;  // 跳過3的倍數
        }
        
        std::cout << n << " ";
    }
    std::cout << std::endl;
    
    // 5. 搜索示例：在數組中查找元素
    std::cout << "\n5. 在數組中查找元素：" << std::endl;
    int numbers[] = {23, 45, 67, 89, 12, 34, 56};
    int target = 89;
    bool found = false;
    
    for (int i = 0; i < 7; i++) {
        if (numbers[i] == target) {
            std::cout << "找到目標 " << target << " 在位置 " << i << std::endl;
            found = true;
            break;  // 找到後立即停止搜索
        }
    }
    
    if (!found) {
        std::cout << "沒有找到目標 " << target << std::endl;
    }
    
    // 6. 過濾示例：跳過不符合條件的數據
    std::cout << "\n6. 處理數據，跳過無效值：" << std::endl;
    int data[] = {12, -5, 8, 0, 15, -3, 20};
    int dataCount = 7;
    
    std::cout << "有效的正數：" << std::endl;
    for (int i = 0; i < dataCount; i++) {
        if (data[i] <= 0) {
            continue;  // 跳過非正數
        }
        
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
    
    // 7. 多層循環中的break
    std::cout << "\n7. 多層循環中的break：" << std::endl;
    
    for (int i = 1; i <= 3; i++) {
        std::cout << "外層循環 i = " << i << std::endl;
        
        for (int j = 1; j <= 3; j++) {
            std::cout << "  內層循環 j = " << j << std::endl;
            
            if (i == 2 && j == 2) {
                std::cout << "   條件滿足，跳出內層循環" << std::endl;
                break;  // 只跳出內層循環
            }
        }
    }
    
    // 8. 標籤與goto（不推薦，但了解其存在）
    std::cout << "\n8. 跳出多重循環（不使用goto的方法）：" << std::endl;
    bool shouldBreak = false;
    
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 3; j++) {
            std::cout << "(" << i << "," << j << ") ";
            
            if (i == 2 && j == 2) {
                std::cout << "\n找到(2,2)，跳出所有循環" << std::endl;
                shouldBreak = true;
                break;
            }
        }
        
        if (shouldBreak) {
            break;  // 跳出外層循環
        }
    }
    
    // 9. 實際應用：質數判斷
    std::cout << "\n9. 判斷一個數是否為質數：" << std::endl;
    int num = 17;
    bool isPrime = true;
    
    if (num <= 1) {
        isPrime = false;
    } else {
        for (int i = 2; i <= num / 2; i++) {
            if (num % i == 0) {
                isPrime = false;
                break;  // 找到因數，立即跳出，無需繼續檢查
            }
        }
    }
    
    if (isPrime) {
        std::cout << num << " 是質數" << std::endl;
    } else {
        std::cout << num << " 不是質數" << std::endl;
    }
    
    // 10. 實際應用：計算有效數據的平均值
    std::cout << "\n10. 計算有效數據的平均值（跳過-1）：" << std::endl;
    int values[] = {10, 20, -1, 30, 40, -1, 50};
    int validCount = 0;
    int total = 0;
    
    for (int i = 0; i < 7; i++) {
        if (values[i] == -1) {
            std::cout << "跳過無效值（-1）" << std::endl;
            continue;  // 跳過無效數據
        }
        
        validCount++;
        total += values[i];
        std::cout << "添加有效值：" << values[i] << std::endl;
    }
    
    if (validCount > 0) {
        double average = static_cast<double>(total) / validCount;
        std::cout << "有效數據個數：" << validCount << std::endl;
        std::cout << "總和：" << total << std::endl;
        std::cout << "平均值：" << average << std::endl;
    } else {
        std::cout << "沒有有效數據" << std::endl;
    }
    
    return 0;
}
 