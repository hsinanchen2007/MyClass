#include <iostream>
#include <set>

int main() {
    std::cout << "=== std::multiset ===" << std::endl;
    
    // 允許重複元素
    std::multiset<int> ms;
    
    ms.insert(30);
    ms.insert(10);
    ms.insert(30);  // 重複，會被保留
    ms.insert(20);
    ms.insert(30);  // 第三個 30
    
    std::cout << "元素: ";
    for (int n : ms) std::cout << n << " ";
    std::cout << std::endl;
    
    std::cout << "30 的數量: " << ms.count(30) << std::endl;
    
    // equal_range：取得所有等於某值的元素範圍
    auto range = ms.equal_range(30);
    std::cout << "所有 30：";
    for (auto it = range.first; it != range.second; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
