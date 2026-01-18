/*
 * 範例6-1：一維數組基礎
 * 數組是相同類型元素的集合，連續存儲在內存中
 */
 
#include <iostream>
 
int main() {
    std::cout << "=== 一維數組基礎演示 ===" << std::endl;
    
    // 1. 數組的聲明和初始化
    std::cout << "1. 數組的聲明和初始化：" << std::endl;
    
    // 方法1：聲明後單獨賦值
    int arr1[5];  // 聲明一個包含5個整數的數組
    arr1[0] = 10;
    arr1[1] = 20;
    arr1[2] = 30;
    arr1[3] = 40;
    arr1[4] = 50;
    
    std::cout << "arr1[2] = " << arr1[2] << std::endl;
    
    // 方法2：聲明時初始化
    int arr2[5] = {1, 2, 3, 4, 5};  // 完全初始化
    int arr3[5] = {1, 2, 3};        // 部分初始化，剩餘元素為0
    int arr4[] = {10, 20, 30, 40, 50};  // 自動推導數組大小
    
    std::cout << "arr2[3] = " << arr2[3] << std::endl;
    std::cout << "arr3[4] = " << arr3[4] << " (部分初始化，未指定值為0)" << std::endl;
    std::cout << "arr4 的大小自動推導為 " << sizeof(arr4)/sizeof(arr4[0]) << std::endl;
    
    // 2. 訪問數組元素
    std::cout << "\n2. 訪問數組元素：" << std::endl;
    
    int numbers[] = {10, 20, 30, 40, 50};
    int size = sizeof(numbers) / sizeof(numbers[0]);  // 計算數組元素個數
    
    std::cout << "數組元素：" << std::endl;
    for (int i = 0; i < size; i++) {
        std::cout << "  numbers[" << i << "] = " << numbers[i] << std::endl;
    }
    
    // 3. 數組元素的修改
    std::cout << "\n3. 數組元素的修改：" << std::endl;
    
    numbers[2] = 300;  // 修改第三個元素
    std::cout << "修改後 numbers[2] = " << numbers[2] << std::endl;
    
    // 4. 數組的大小和內存
    std::cout << "\n4. 數組的大小和內存：" << std::endl;
    
    std::cout << "數組總大小：sizeof(numbers) = " << sizeof(numbers) << " 位元組" << std::endl;
    std::cout << "每個元素大小：sizeof(numbers[0]) = " << sizeof(numbers[0]) << " 位元組" << std::endl;
    std::cout << "元素個數：sizeof(numbers)/sizeof(numbers[0]) = " 
              << sizeof(numbers)/sizeof(numbers[0]) << std::endl;
    
    // 5. 數組的地址
    std::cout << "\n5. 數組的地址：" << std::endl;
    
    for (int i = 0; i < size; i++) {
        std::cout << "  numbers[" << i << "] 的地址："
                  << &numbers[i] << "，值：" << numbers[i] << std::endl;
    }
    
    // 6. 數組的注意事項
    std::cout << "\n6. 數組的注意事項：" << std::endl;
    
    // 訪問越界是未定義行為
    // std::cout << "numbers[10] = " << numbers[10] << std::endl;  // 錯誤！
    
    // 數組不能直接賦值
    int a[3] = {1, 2, 3};
    int b[3];
    // b = a;  // 錯誤！數組不能直接賦值
    
    // 需要逐元素複製
    for (int i = 0; i < 3; i++) {
        b[i] = a[i];
    }
    
    std::cout << "數組複製成功" << std::endl;
    
    return 0;
}
 