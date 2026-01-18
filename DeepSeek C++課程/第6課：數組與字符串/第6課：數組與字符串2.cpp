/*
 * 範例6-2：多維數組
 * 多維數組是數組的數組，常用的是二維數組（矩陣）
 */
 
#include <iostream>
#include <iomanip>
 
int main() {
    std::cout << "=== 多維數組演示 ===" << std::endl;
    
    // 1. 二維數組的聲明和初始化
    std::cout << "1. 二維數組的聲明和初始化：" << std::endl;
    
    // 方法1：逐行初始化
    int matrix1[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    
    // 方法2：連續初始化
    int matrix2[2][3] = {1, 2, 3, 4, 5, 6};
    
    // 方法3：部分初始化
    int matrix3[3][3] = {
        {1},        // 第一行：1, 0, 0
        {4, 5},     // 第二行：4, 5, 0
        {7, 8, 9}   // 第三行：7, 8, 9
    };
    
    // 2. 訪問二維數組元素
    std::cout << "\n2. 訪問二維數組元素：" << std::endl;
    
    std::cout << "matrix1[2][3] = " << matrix1[2][3] << std::endl;
    std::cout << "matrix2[1][2] = " << matrix2[1][2] << std::endl;
    std::cout << "matrix3[0][2] = " << matrix3[0][2] << " (部分初始化，未指定值為0)" << std::endl;
    
    // 3. 遍歷二維數組
    std::cout << "\n3. 遍歷二維數組（矩陣形式）：" << std::endl;
    
    std::cout << "matrix1 的內容：" << std::endl;
    for (int i = 0; i < 3; i++) {          // 行
        for (int j = 0; j < 4; j++) {      // 列
            std::cout << std::setw(4) << matrix1[i][j];
        }
        std::cout << std::endl;
    }
    
    // 4. 三維數組
    std::cout << "\n4. 三維數組：" << std::endl;
    
    int cube[2][3][4] = {
        {   // 第一層
            {1, 2, 3, 4},
            {5, 6, 7, 8},
            {9, 10, 11, 12}
        },
        {   // 第二層
            {13, 14, 15, 16},
            {17, 18, 19, 20},
            {21, 22, 23, 24}
        }
    };
    
    std::cout << "cube[1][2][3] = " << cube[1][2][3] << std::endl;
    
    // 5. 多維數組的內存佈局
    std::cout << "\n5. 多維數組的內存佈局：" << std::endl;
    
    int arr2D[2][3] = {{1, 2, 3}, {4, 5, 6}};
    
    std::cout << "二維數組的內存地址：" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << "arr2D[" << i << "][" << j << "] 地址: "
                      << &arr2D[i][j] << " 值: " << arr2D[i][j] << std::endl;
        }
    }
    
    // 6. 多維數組的應用：矩陣運算
    std::cout << "\n6. 多維數組的應用：矩陣運算（矩陣相加）" << std::endl;
    
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int B[2][3] = {{6, 5, 4}, {3, 2, 1}};
    int C[2][3];  // 存儲結果
    
    // 矩陣相加
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    
    // 顯示結果
    std::cout << "矩陣 A：" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << std::setw(3) << A[i][j];
        }
        std::cout << std::endl;
    }
    
    std::cout << "矩陣 B：" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << std::setw(3) << B[i][j];
        }
        std::cout << std::endl;
    }
    
    std::cout << "矩陣 C = A + B：" << std::endl;
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << std::setw(3) << C[i][j];
        }
        std::cout << std::endl;
    }
    
    // 7. 多維數組作為函數參數
    std::cout << "\n7. 多維數組作為函數參數：" << std::endl;
    
    // 注意：傳遞多維數組時，除了第一維，其他維度必須指定大小
    auto printMatrix = [](int mat[][3], int rows) {
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << std::setw(3) << mat[i][j];
            }
            std::cout << std::endl;
        }
    };
    
    std::cout << "通過函數打印矩陣：" << std::endl;
    printMatrix(A, 2);
    
    return 0;
}
 