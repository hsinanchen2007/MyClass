#include <iostream>
#include <map>
#include <string>

int main() {
    std::cout << "=== std::multimap ===" << std::endl;
    
    // 一個鍵可以對應多個值
    std::multimap<std::string, std::string> phonebook;
    
    phonebook.insert({"Alice", "0912-345-678"});
    phonebook.insert({"Alice", "02-1234-5678"});  // Alice 有兩個號碼
    phonebook.insert({"Bob", "0923-456-789"});
    phonebook.insert({"Alice", "03-9876-5432"});  // Alice 第三個號碼
    
    std::cout << "電話簿:" << std::endl;
    for (const auto& entry : phonebook) {
        std::cout << "  " << entry.first << ": " << entry.second << std::endl;
    }
    
    // 查找 Alice 的所有號碼
    std::cout << "\nAlice 的所有號碼:" << std::endl;
    auto range = phonebook.equal_range("Alice");
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << "  " << it->second << std::endl;
    }
    
    std::cout << "\nAlice 有 " << phonebook.count("Alice") << " 個號碼" << std::endl;
    
    return 0;
}
