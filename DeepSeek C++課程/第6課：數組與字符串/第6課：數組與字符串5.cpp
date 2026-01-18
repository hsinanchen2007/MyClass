/*
 * 範例6-5：字符數組與字符串綜合應用
 * 綜合應用C風格字符串和C++ string類
 */
 
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
 
int main() {
    std::cout << "=== 字符數組與字符串綜合應用 ===" << std::endl;
    
    // 1. 密碼驗證系統
    std::cout << "\n1. 密碼驗證系統：" << std::endl;
    
    const char* correctPassword = "secret123";
    char userPassword[50];
    
    // 模擬用戶輸入（實際應用中會從輸入流讀取）
    strcpy(userPassword, "secret123");
    
    if (strcmp(userPassword, correctPassword) == 0) {
        std::cout << "密碼正確！登入成功。" << std::endl;
    } else {
        std::cout << "密碼錯誤！" << std::endl;
    }
    
    // 2. 字符串統計
    std::cout << "\n2. 字符串統計：" << std::endl;
    
    std::string text = "The quick brown fox jumps over the lazy dog";
    
    // 統計單詞數
    int wordCount = 0;
    bool inWord = false;
    
    for (char ch : text) {
        if (std::isspace(ch)) {
            inWord = false;
        } else if (!inWord) {
            inWord = true;
            wordCount++;
        }
    }
    
    std::cout << "文本: \"" << text << "\"" << std::endl;
    std::cout << "單詞數: " << wordCount << std::endl;
    
    // 統計字母頻率
    int letterCount[26] = {0};
    for (char ch : text) {
        if (std::isalpha(ch)) {
            char lower = std::tolower(ch);
            letterCount[lower - 'a']++;
        }
    }
    
    std::cout << "字母頻率:" << std::endl;
    for (int i = 0; i < 26; i++) {
        if (letterCount[i] > 0) {
            std::cout << "  " << char('a' + i) << ": " << letterCount[i] << std::endl;
        }
    }
    
    // 3. 字符串反轉
    std::cout << "\n3. 字符串反轉：" << std::endl;
    
    std::string original = "Hello World";
    std::string reversed = original;
    
    std::reverse(reversed.begin(), reversed.end());
    std::cout << "原始: \"" << original << "\"" << std::endl;
    std::cout << "反轉: \"" << reversed << "\"" << std::endl;
    
    // 4. 回文判斷
    std::cout << "\n4. 回文判斷：" << std::endl;
    
    std::string palindrome1 = "racecar";
    std::string palindrome2 = "hello";
    
    auto isPalindrome = [](const std::string& str) {
        std::string cleanStr;
        
        // 移除空格和標點，轉換為小寫
        for (char ch : str) {
            if (std::isalnum(ch)) {
                cleanStr += std::tolower(ch);
            }
        }
        
        // 判斷是否回文
        std::string reversed = cleanStr;
        std::reverse(reversed.begin(), reversed.end());
        
        return cleanStr == reversed;
    };
    
    std::cout << "\"" << palindrome1 << "\" 是回文嗎？" 
              << (isPalindrome(palindrome1) ? "是" : "否") << std::endl;
    std::cout << "\"" << palindrome2 << "\" 是回文嗎？" 
              << (isPalindrome(palindrome2) ? "是" : "否") << std::endl;
    
    // 5. CSV數據解析
    std::cout << "\n5. CSV數據解析：" << std::endl;
    
    std::string csvData = "John,Doe,30,New York\nJane,Smith,25,Los Angeles\nBob,Johnson,35,Chicago";
    
    std::vector<std::vector<std::string>> records;
    std::string line;
    size_t start = 0, end = 0;
    
    // 按行分割
    while ((end = csvData.find('\n', start)) != std::string::npos) {
        line = csvData.substr(start, end - start);
        start = end + 1;
        
        // 按逗號分割每行
        std::vector<std::string> fields;
        size_t fieldStart = 0, fieldEnd = 0;
        
        while ((fieldEnd = line.find(',', fieldStart)) != std::string::npos) {
            fields.push_back(line.substr(fieldStart, fieldEnd - fieldStart));
            fieldStart = fieldEnd + 1;
        }
        fields.push_back(line.substr(fieldStart));
        
        records.push_back(fields);
    }
    
    // 處理最後一行
    if (start < csvData.length()) {
        line = csvData.substr(start);
        std::vector<std::string> fields;
        size_t fieldStart = 0, fieldEnd = 0;
        
        while ((fieldEnd = line.find(',', fieldStart)) != std::string::npos) {
            fields.push_back(line.substr(fieldStart, fieldEnd - fieldStart));
            fieldStart = fieldEnd + 1;
        }
        fields.push_back(line.substr(fieldStart));
        
        records.push_back(fields);
    }
    
    // 顯示解析結果
    std::cout << "解析結果:" << std::endl;
    for (const auto& record : records) {
        std::cout << "  姓名: " << record[0] << " " << record[1]
                  << ", 年齡: " << record[2]
                  << ", 城市: " << record[3] << std::endl;
    }
    
    // 6. 簡單文本加密
    std::cout << "\n6. 簡單文本加密（凱撒密碼）:" << std::endl;
    
    std::string plainText = "HELLO WORLD";
    int shift = 3;
    std::string encrypted;
    
    for (char ch : plainText) {
        if (std::isalpha(ch)) {
            char base = std::isupper(ch) ? 'A' : 'a';
            encrypted += static_cast<char>((ch - base + shift) % 26 + base);
        } else {
            encrypted += ch;
        }
    }
    
    std::cout << "原始文本: \"" << plainText << "\"" << std::endl;
    std::cout << "加密文本: \"" << encrypted << "\"" << std::endl;
    
    // 解密
    std::string decrypted;
    for (char ch : encrypted) {
        if (std::isalpha(ch)) {
            char base = std::isupper(ch) ? 'A' : 'a';
            decrypted += static_cast<char>((ch - base - shift + 26) % 26 + base);
        } else {
            decrypted += ch;
        }
    }
    
    std::cout << "解密文本: \"" << decrypted << "\"" << std::endl;
    
    // 7. 字符串排序
    std::cout << "\n7. 字符串排序:" << std::endl;
    
    std::vector<std::string> words = {"banana", "apple", "cherry", "date", "elderberry"};
    
    std::cout << "排序前:" << std::endl;
    for (const auto& word : words) {
        std::cout << "  " << word << std::endl;
    }
    
    std::sort(words.begin(), words.end());
    
    std::cout << "排序後:" << std::endl;
    for (const auto& word : words) {
        std::cout << "  " << word << std::endl;
    }
    
    // 按長度排序
    std::sort(words.begin(), words.end(), 
              [](const std::string& a, const std::string& b) {
                  return a.length() < b.length();
              });
    
    std::cout << "按長度排序後:" << std::endl;
    for (const auto& word : words) {
        std::cout << "  " << word << " (長度: " << word.length() << ")" << std::endl;
    }
    
    return 0;
}
 