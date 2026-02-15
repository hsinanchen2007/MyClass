#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // partial_sort：只排序前 n 個
    std::cout << "=== partial_sort ===" << std::endl;
    std::vector<int> vec = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    
    // 只需要最小的 3 個，排好放在最前面
    std::partial_sort(vec.begin(), vec.begin() + 3, vec.end());
    std::cout << "前 3 個最小（已排序）: ";
    for (int n : vec) std::cout << n << " ";
    std::cout << std::endl;
    
    // nth_element：找第 n 個元素
    std::cout << "\n=== nth_element ===" << std::endl;
    std::vector<int> vec2 = {5, 2, 8, 1, 9, 3, 7, 4, 6};
    
    // 找中位數（第 4 個元素，索引 4）
    std::nth_element(vec2.begin(), vec2.begin() + 4, vec2.end());
    std::cout << "nth_element(4) 後: ";
    for (int n : vec2) std::cout << n << " ";
    std::cout << std::endl;
    std::cout << "第 5 個元素（索引 4）: " << vec2[4] << std::endl;
    
    return 0;
}
