/*
 * 範例6-4：C++ string類
 * std::string 是C++標準庫中的字符串類，比C風格字符串更安全易用
 */
 
#include <iostream>
#include <string>  // string類頭文件
#include <algorithm>
 
int main() {
    std::cout << "=== C++ string類演示 ===" << std::endl;
    
    // 1. string對象的創建和初始化
    std::cout << "1. string對象的創建和初始化：" << std::endl;
    
    // 方法1：默認構造函數
    std::string str1;
    std::cout << "默認構造: \"" << str1 << "\"" << std::endl;
    
    // 方法2：使用C風格字符串初始化
    std::string str2 = "Hello";
    std::cout << "從C字符串初始化: \"" << str2 << "\"" << std::endl;
    
    // 方法3：使用另一個string對象初始化
    std::string str3(str2);
    std::cout << "從string對象初始化: \"" << str3 << "\"" << std::endl;
    
    // 方法4：使用多個相同字符
    std::string str4(5, '*');
    std::cout << "5個'*': \"" << str4 << "\"" << std::endl;
    
    // 方法5：使用子字符串
    std::string str5 = "Hello World";
    std::string str6(str5, 6, 5);  // 從位置6開始，長度5
    std::cout << "子字符串: \"" << str6 << "\"" << std::endl;
    
    // 2. 字符串操作
    std::cout << "\n2. 字符串操作：" << std::endl;
    
    std::string s = "Hello";
    
    // 獲取長度
    std::cout << "長度: " << s.length() << " (或 " << s.size() << ")" << std::endl;
    
    // 檢查是否為空
    std::cout << "是否為空: " << (s.empty() ? "是" : "否") << std::endl;
    
    // 訪問字符
    std::cout << "第一個字符: " << s[0] << std::endl;
    std::cout << "第二個字符: " << s.at(1) << std::endl;  // 帶範圍檢查
    
    // 修改字符
    s[1] = 'a';
    std::cout << "修改後: \"" << s << "\"" << std::endl;
    
    // 3. 字符串連接
    std::cout << "\n3. 字符串連接：" << std::endl;
    
    std::string s1 = "Hello";
    std::string s2 = " World";
    
    // 方法1：使用+運算符
    std::string s3 = s1 + s2;
    std::cout << "使用+: \"" << s3 << "\"" << std::endl;
    
    // 方法2：使用+=運算符
    s1 += s2;
    std::cout << "使用+=: \"" << s1 << "\"" << std::endl;
    
    // 方法3：使用append函數
    std::string s4 = "Hello";
    s4.append(" C++");
    std::cout << "使用append: \"" << s4 << "\"" << std::endl;
    
    // 4. 字符串比較
    std::cout << "\n4. 字符串比較：" << std::endl;
    
    std::string a = "apple";
    std::string b = "banana";
    std::string c = "apple";
    
    // 使用比較運算符
    std::cout << "\"apple\" == \"banana\": " << (a == b) << std::endl;
    std::cout << "\"apple\" != \"banana\": " << (a != b) << std::endl;
    std::cout << "\"apple\" < \"banana\": " << (a < b) << std::endl;
    std::cout << "\"apple\" == \"apple\": " << (a == c) << std::endl;
    
    // 使用compare函數
    int result = a.compare(b);
    if (result < 0) {
        std::cout << "\"apple\" 小於 \"banana\"" << std::endl;
    }
    
    // 5. 子字符串操作
    std::cout << "\n5. 子字符串操作：" << std::endl;
    
    std::string text = "Hello World, welcome to C++ programming";
    
    // 提取子字符串
    std::string sub1 = text.substr(6, 5);  // 從位置6開始，長度5
    std::cout << "substr(6, 5): \"" << sub1 << "\"" << std::endl;
    
    // 查找子字符串
    size_t pos = text.find("welcome");
    if (pos != std::string::npos) {
        std::cout << "找到 \"welcome\" 在位置: " << pos << std::endl;
    }
    
    // 查找字符
    pos = text.find('W');
    if (pos != std::string::npos) {
        std::cout << "找到 'W' 在位置: " << pos << std::endl;
    }
    
    // 從末尾查找
    pos = text.rfind('o');
    if (pos != std::string::npos) {
        std::cout << "從末尾找到 'o' 在位置: " << pos << std::endl;
    }
    
    // 6. 字符串修改
    std::cout << "\n6. 字符串修改：" << std::endl;
    
    std::string str = "I like C programming";
    
    // 插入
    str.insert(7, "++ ");
    std::cout << "插入後: \"" << str << "\"" << std::endl;
    
    // 替換
    str.replace(2, 4, "love");  // 從位置2開始，替換4個字符
    std::cout << "替換後: \"" << str << "\"" << std::endl;
    
    // 刪除
    str.erase(15, 12);  // 從位置15開始，刪除12個字符
    std::cout << "刪除後: \"" << str << "\"" << std::endl;
    
    // 7. 字符串轉換
    std::cout << "\n7. 字符串轉換：" << std::endl;
    
    // 數字轉字符串
    int num = 42;
    std::string numStr = std::to_string(num);
    std::cout << "整數轉字符串: \"" << numStr << "\"" << std::endl;
    
    double pi = 3.14159;
    std::string piStr = std::to_string(pi);
    std::cout << "浮點數轉字符串: \"" << piStr << "\"" << std::endl;
    
    // 字符串轉數字
    std::string intStr = "123";
    int intVal = std::stoi(intStr);  // string to int
    std::cout << "字符串轉整數: " << intVal << std::endl;
    
    std::string doubleStr = "3.14";
    double doubleVal = std::stod(doubleStr);  // string to double
    std::cout << "字符串轉浮點數: " << doubleVal << std::endl;
    
    // 8. 字符串遍歷
    std::cout << "\n8. 字符串遍歷：" << std::endl;
    
    std::string word = "Hello";
    
    std::cout << "使用下標遍歷: ";
    for (size_t i = 0; i < word.length(); i++) {
        std::cout << word[i] << " ";
    }
    std::cout << std::endl;
    
    std::cout << "使用範圍for循環: ";
    for (char ch : word) {
        std::cout << ch << " ";
    }
    std::cout << std::endl;
    
    // 9. 字符串算法
    std::cout << "\n9. 字符串算法：" << std::endl;
    
    std::string demo = "Hello World";
    
    // 轉換大小寫（需要#include <algorithm>和<cctype>）
    std::transform(demo.begin(), demo.end(), demo.begin(), ::toupper);
    std::cout << "轉換為大寫: \"" << demo << "\"" << std::endl;
    
    std::transform(demo.begin(), demo.end(), demo.begin(), ::tolower);
    std::cout << "轉換為小寫: \"" << demo << "\"" << std::endl;
    
    // 反轉字符串
    std::reverse(demo.begin(), demo.end());
    std::cout << "反轉後: \"" << demo << "\"" << std::endl;
    
    return 0;
}
 