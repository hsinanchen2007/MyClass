/*
 * 範例2-3：字符類型 (char)
 * 用於存儲單個字符（字母、數字、符號等）
 * 使用單引號 ' ' 包圍
 */
 
#include <iostream>
 
int main() {
    std::cout << "=== 字符類型演示 ===" << std::endl;
    
    // 1. 基本字符
    char letter = 'A';
    char digit = '7';
    char symbol = '$';
    char space = ' ';
    char newline = '\n';  // 特殊字符：換行
    
    std::cout << "字母：" << letter << std::endl;
    std::cout << "數字：" << digit << std::endl;
    std::cout << "符號：" << symbol << std::endl;
    std::cout << "空格：" << "開始" << space << "結束" << std::endl;
    std::cout << "換行：" << "第一行" << newline << "第二行" << std::endl;
    
    // 2. 字符的本質是數字（ASCII碼）
    std::cout << "\n字符的ASCII碼：" << std::endl;
    std::cout << "'A' 的ASCII碼：" << (int)letter << std::endl;
    std::cout << "'7' 的ASCII碼：" << (int)digit << std::endl;
    std::cout << "'$' 的ASCII碼：" << (int)symbol << std::endl;
    
    // 3. 字符運算（基於ASCII碼）
    char small_a = 'a';
    char capital_a = 'A';
    
    std::cout << "\n字符運算：" << std::endl;
    std::cout << "小寫 a：" << small_a << " (ASCII: " << (int)small_a << ")" << std::endl;
    std::cout << "大寫 A：" << capital_a << " (ASCII: " << (int)capital_a << ")" << std::endl;
    std::cout << "大小寫轉換：" << std::endl;
    std::cout << "小寫轉大寫：" << (char)(small_a - 32) << std::endl;  // 'a' 轉 'A'
    std::cout << "大寫轉小寫：" << (char)(capital_a + 32) << std::endl; // 'A' 轉 'a'
    
    // 4. 特殊字符（跳脫序列）
    std::cout << "\n特殊字符（跳脫序列）：" << std::endl;
    std::cout << "換行：第一行\\n第二行" << std::endl;
    std::cout << "製表符：姓名\\t年齡\\t成績" << std::endl;
    std::cout << "雙引號：他說：\\\"你好！\\\"" << std::endl;
    std::cout << "反斜線：路徑 C:\\\\Program Files\\\\" << std::endl;
    
    return 0;
}
 