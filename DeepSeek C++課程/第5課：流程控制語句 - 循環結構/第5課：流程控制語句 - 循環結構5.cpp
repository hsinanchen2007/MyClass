/*
 * 範例5-5：嵌套循環
 * 循環內部包含另一個循環
 * 常用於處理二維數據、圖形輸出等
 */
 
#include <iostream>
#include <iomanip>
 
int main() {
    std::cout << "=== 嵌套循環演示 ===" << std::endl;
    
    // 1. 基本的嵌套循環：乘法表
    std::cout << "1. 九九乘法表（部分）：" << std::endl;
    
    for (int i = 1; i <= 3; i++) {          // 外層循環：控制行
        for (int j = 1; j <= 3; j++) {      // 內層循環：控制列
            std::cout << i << "×" << j << "=" 
                      << std::setw(2) << (i * j) << "  ";
        }
        std::cout << std::endl;  // 換行
    }
    
    // 2. 矩形圖案
    std::cout << "\n2. 矩形圖案（5行10列）：" << std::endl;
    
    int rows = 5;
    int cols = 10;
    
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    
    // 3. 直角三角形
    std::cout << "\n3. 直角三角形：" << std::endl;
    
    for (int i = 1; i <= 5; i++) {
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    
    // 4. 倒直角三角形
    std::cout << "\n4. 倒直角三角形：" << std::endl;
    
    for (int i = 5; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    
    // 5. 金字塔
    std::cout << "\n5. 金字塔圖案：" << std::endl;
    
    int height = 5;
    
    for (int i = 1; i <= height; i++) {
        // 打印空格
        for (int space = 1; space <= height - i; space++) {
            std::cout << " ";
        }
        
        // 打印星號
        for (int star = 1; star <= (2 * i - 1); star++) {
            std::cout << "*";
        }
        
        std::cout << std::endl;
    }
    
    // 6. 二維數組處理
    std::cout << "\n6. 二維數組處理：" << std::endl;
    
    int matrix[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    std::cout << "矩陣內容：" << std::endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            std::cout << std::setw(3) << matrix[i][j];
        }
        std::cout << std::endl;
    }
    
    // 7. 計算矩陣對角線和
    std::cout << "\n7. 計算矩陣對角線和：" << std::endl;
    
    int squareMatrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    
    int diagonalSum = 0;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << std::setw(3) << squareMatrix[i][j];
            
            if (i == j) {  // 主對角線
                diagonalSum += squareMatrix[i][j];
            }
        }
        std::cout << std::endl;
    }
    
    std::cout << "主對角線和：" << diagonalSum << std::endl;
    
    // 8. 組合問題：投擲兩個骰子的所有可能
    std::cout << "\n8. 投擲兩個骰子的所有可能：" << std::endl;
    
    std::cout << "    ";
    for (int j = 1; j <= 6; j++) {
        std::cout << std::setw(4) << j;
    }
    std::cout << std::endl;
    std::cout << "   +-----------------------" << std::endl;
    
    for (int die1 = 1; die1 <= 6; die1++) {
        std::cout << die1 << " |";
        for (int die2 = 1; die2 <= 6; die2++) {
            std::cout << std::setw(4) << (die1 + die2);
        }
        std::cout << std::endl;
    }
    
    // 9. 查找二維數組中的元素
    std::cout << "\n9. 在二維數組中查找元素：" << std::endl;
    
    int searchMatrix[3][3] = {
        {12, 23, 34},
        {45, 56, 67},
        {78, 89, 90}
    };
    
    int targetValue = 56;
    bool found = false;
    int foundRow = -1, foundCol = -1;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (searchMatrix[i][j] == targetValue) {
                found = true;
                foundRow = i;
                foundCol = j;
                break;  // 跳出內層循環
            }
        }
        if (found) {
            break;  // 跳出外層循環
        }
    }
    
    if (found) {
        std::cout << "找到 " << targetValue << " 在位置 (" 
                  << foundRow << ", " << foundCol << ")" << std::endl;
    } else {
        std::cout << "沒有找到 " << targetValue << std::endl;
    }
    
    // 10. 不同類型的循環嵌套
    std::cout << "\n10. 不同類型的循環嵌套：" << std::endl;
    
    int outer = 1;
    
    while (outer <= 3) {
        std::cout << "外層 while 循環，outer = " << outer << std::endl;
        
        for (int inner = 1; inner <= 2; inner++) {
            std::cout << "  內層 for 循環，inner = " << inner << std::endl;
        }
        
        outer++;
    }
    
    return 0;
}
 