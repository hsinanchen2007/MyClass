#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <queue>
#include <string>

int main() {
    // 案例 1：儲存學生成績列表 → vector
    std::cout << "=== 案例 1：學生成績 ===" << std::endl;
    std::vector<int> scores = {85, 92, 78, 95, 88};
    std::cout << "第三個學生: " << scores[2] << std::endl;
    
    // 案例 2：去重的標籤 → set 或 unordered_set
    std::cout << "\n=== 案例 2：去重標籤 ===" << std::endl;
    std::set<std::string> tags;
    tags.insert("C++");
    tags.insert("Programming");
    tags.insert("C++");  // 重複，被忽略
    tags.insert("STL");
    for (const auto& tag : tags) std::cout << tag << " ";
    std::cout << std::endl;
    
    // 案例 3：字數統計 → map 或 unordered_map
    std::cout << "\n=== 案例 3：字數統計 ===" << std::endl;
    std::string text = "hello world hello c++ world world";
    std::unordered_map<std::string, int> word_count;
    
    // 簡化的分詞
    std::string word;
    for (char c : text) {
        if (c == ' ') {
            if (!word.empty()) {
                word_count[word]++;
                word.clear();
            }
        } else {
            word += c;
        }
    }
    if (!word.empty()) word_count[word]++;
    
    for (const auto& pair : word_count) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    
    // 案例 4：任務排程 → priority_queue
    std::cout << "\n=== 案例 4：任務排程 ===" << std::endl;
    std::priority_queue<std::pair<int, std::string>> tasks;
    
    tasks.push({3, "一般任務"});
    tasks.push({5, "緊急任務"});
    tasks.push({1, "低優先任務"});
    tasks.push({4, "重要任務"});
    
    std::cout << "按優先順序處理:" << std::endl;
    while (!tasks.empty()) {
        auto task = tasks.top();
        std::cout << "  優先級 " << task.first << ": " << task.second << std::endl;
        tasks.pop();
    }
    
    return 0;
}
