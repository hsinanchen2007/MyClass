/*
 * 範例6-3：C風格字符串
 * C風格字符串是以空字符('\0')結尾的字符數組
 */
 
#include <iostream>
#include <cstring>  // C風格字符串函數頭文件
 
int main() {
    std::cout << "=== C風格字符串演示 ===" << std::endl;
    
    // 1. C風格字符串的創建
    std::cout << "1. C風格字符串的創建：" << std::endl;
    
    // 方法1：字符數組（需要手動添加'\0'）
    char str1[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
    
    // 方法2：字符串字面量（自動添加'\0'）
    char str2[] = "Hello";
    
    // 方法3：指針形式
    const char* str3 = "Hello";  // 字符串字面量是常量
    
    std::cout << "str1: " << str1 << std::endl;
    std::cout << "str2: " << str2 << std::endl;
    std::cout << "str3: " << str3 << std::endl;
    
    // 2. 字符串長度
    std::cout << "\n2. 字符串長度：" << std::endl;
    
    std::cout << "strlen(str1): " << strlen(str1) << std::endl;
    std::cout << "sizeof(str1): " << sizeof(str1) << " (包含'\\0')" << std::endl;
    
    // 3. 字符串複製
    std::cout << "\n3. 字符串複製：" << std::endl;
    
    char source[] = "Hello World";
    char destination[20];
    
    strcpy(destination, source);  // 複製字符串
    std::cout << "複製後 destination: " << destination << std::endl;
    
    // 安全版本：strncpy
    char dest2[10];
    strncpy(dest2, source, 9);  // 最多複製9個字符
    dest2[9] = '\0';  // 確保以'\0'結尾
    std::cout << "安全複製後 dest2: " << dest2 << std::endl;
    
    // 4. 字符串連接
    std::cout << "\n4. 字符串連接：" << std::endl;
    
    char hello[] = "Hello";
    char world[] = " World";
    char greeting[20];
    
    strcpy(greeting, hello);
    strcat(greeting, world);  // 連接字符串
    
    std::cout << "連接後: " << greeting << std::endl;
    
    // 5. 字符串比較
    std::cout << "\n5. 字符串比較：" << std::endl;
    
    char strA[] = "apple";
    char strB[] = "banana";
    char strC[] = "apple";
    
    int result1 = strcmp(strA, strB);  // 比較字符串
    int result2 = strcmp(strA, strC);
    
    std::cout << "strcmp(\"apple\", \"banana\"): " << result1 << std::endl;
    std::cout << "strcmp(\"apple\", \"apple\"): " << result2 << std::endl;
    
    if (result1 < 0) {
        std::cout << "\"apple\" 小於 \"banana\"" << std::endl;
    }
    
    if (result2 == 0) {
        std::cout << "\"apple\" 等於 \"apple\"" << std::endl;
    }
    
    // 6. 字符串查找
    std::cout << "\n6. 字符串查找：" << std::endl;
    
    char text[] = "Hello World, welcome to C++";
    char* found;
    
    // 查找字符
    found = strchr(text, 'W');
    if (found != nullptr) {
        std::cout << "找到 'W' 在位置: " << (found - text) << std::endl;
        std::cout << "從該位置開始的字符串: " << found << std::endl;
    }
    
    // 查找子字符串
    found = strstr(text, "welcome");
    if (found != nullptr) {
        std::cout << "找到子字符串 \"welcome\" 在位置: " << (found - text) << std::endl;
    }
    
    // 7. 字符串轉換
    std::cout << "\n7. 字符串轉換：" << std::endl;
    
    // 字符串轉數字
    char numStr[] = "12345";
    int number = atoi(numStr);  // ASCII to integer
    std::cout << "atoi(\"12345\"): " << number << std::endl;
    
    char floatStr[] = "3.14159";
    double pi = atof(floatStr);  // ASCII to float
    std::cout << "atof(\"3.14159\"): " << pi << std::endl;
    
    // 數字轉字符串
    char buffer[20];
    int value = 42;
    sprintf(buffer, "數字是: %d", value);  // 格式化輸出到字符串
    std::cout << "sprintf 結果: " << buffer << std::endl;
    
    // 8. 字符串分割
    std::cout << "\n8. 字符串分割：" << std::endl;
    
    char csv[] = "apple,banana,orange,grape";
    char* token;
    
    std::cout << "分割 \"" << csv << "\"：" << std::endl;
    
    token = strtok(csv, ",");  // 第一次調用
    while (token != nullptr) {
        std::cout << "  " << token << std::endl;
        token = strtok(nullptr, ",");  // 後續調用
    }
    
    return 0;
}
 