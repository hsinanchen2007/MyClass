/*
 * 範例1-4：基本數據類型展示
 * 雖然詳細的數據類型會在下一課講解
 * 但這裡先展示一些基本類型
 */
 
#include <iostream>
 
int main() {
    // 整數類型
    int age = 25;                     // 整數
    double height = 175.5;           // 雙精度浮點數
    char grade = 'A';                // 單個字符
    bool isStudent = true;           // 布林值（真/假）
    
    // 輸出變數的值
    std::cout << "年齡：" << age << " 歲" << std::endl;
    std::cout << "身高：" << height << " 公分" << std::endl;
    std::cout << "成績：" << grade << std::endl;
    std::cout << "是否學生：" << isStudent << std::endl;
    
    // 布林值會輸出為 1(true) 或 0(false)
    // 我們可以使用條件運算符來顯示"是"/"否"
    std::cout << "是否學生：" 
              << (isStudent ? "是" : "否") 
              << std::endl;
    
    return 0;
}
 