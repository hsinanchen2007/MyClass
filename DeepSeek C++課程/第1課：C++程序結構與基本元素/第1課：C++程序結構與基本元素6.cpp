/*
 * 範例1-6：常見錯誤示範
 * 展示初學者常見的錯誤
 * 每種錯誤都有註解說明
 */
 
#include <iostream>
 
int main() {
    // 正確：完整的語句以分號結束
    std::cout << "這是正確的語句" << std::endl;
    
    // 錯誤1：缺少分號
    // std::cout << "缺少分號" << std::endl  // 錯誤！
    
    // 錯誤2：拼寫錯誤
    // Std::cout << "S要大寫" << std::endl;  // 錯誤！
    // std:cout << "少了一個冒號" << std::endl;  // 錯誤！
    
    // 錯誤3：使用中文標點
    // std::cout << "使用中文分號；" << std::endl；  // 錯誤！
    
    // 錯誤4：忘記包含頭文件
    // 如果註解掉 #include <iostream>，下面這行會出錯
    
    // 錯誤5：main函數名稱錯誤
    // int Main() { ... }  // 錯誤！必須是小寫main
    
    // 錯誤6：忘記返回值
    // 如果註解掉 return 0;，有些編譯器會警告
    
    return 0;
}
 