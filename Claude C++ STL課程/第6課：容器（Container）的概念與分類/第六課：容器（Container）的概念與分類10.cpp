#include <iostream>
#include <unordered_set>

int main() {
    std::cout << "=== std::unordered_set ===" << std::endl;
    
    std::unordered_set<int> us;
    
    us.insert(30);
    us.insert(10);
    us.insert(50);
    us.insert(20);
    us.insert(40);
    
    // 順序不固定（取決於雜湊）
    std::cout << "元素（順序不固定）: ";
    for (int n : us) std::cout << n << " ";
    std::cout << std::endl;
    
    // 查找：平均 O(1)
    if (us.find(30) != us.end()) {
        std::cout << "找到 30" << std::endl;
    }
    
    // 雜湊表資訊
    std::cout << "桶的數量: " << us.bucket_count() << std::endl;
    std::cout << "負載因子: " << us.load_factor() << std::endl;
    
    return 0;
}
