#include <iostream>
#include <vector>
#include <numeric>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5};
    
    // accumulate：累加
    std::cout << "=== accumulate ===" << std::endl;
    int sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << "總和: " << sum << std::endl;
    
    // accumulate 可以自訂運算
    int product = std::accumulate(vec.begin(), vec.end(), 1, 
        std::multiplies<int>());
    std::cout << "乘積: " << product << std::endl;
    
    // iota：填充遞增序列
    std::cout << "\n=== iota ===" << std::endl;
    std::vector<int> seq(10);
    std::iota(seq.begin(), seq.end(), 1);  // 從 1 開始
    std::cout << "iota: ";
    for (int n : seq) std::cout << n << " ";
    std::cout << std::endl;
    
    // partial_sum：部分和
    std::cout << "\n=== partial_sum ===" << std::endl;
    std::vector<int> partial(vec.size());
    std::partial_sum(vec.begin(), vec.end(), partial.begin());
    std::cout << "部分和: ";
    for (int n : partial) std::cout << n << " ";
    std::cout << std::endl;
    
    // adjacent_difference：相鄰差
    std::cout << "\n=== adjacent_difference ===" << std::endl;
    std::vector<int> data = {1, 3, 6, 10, 15};
    std::vector<int> diff(data.size());
    std::adjacent_difference(data.begin(), data.end(), diff.begin());
    std::cout << "相鄰差: ";
    for (int n : diff) std::cout << n << " ";
    std::cout << std::endl;
    
    // inner_product：內積
    std::cout << "\n=== inner_product ===" << std::endl;
    std::vector<int> v1 = {1, 2, 3};
    std::vector<int> v2 = {4, 5, 6};
    int dot = std::inner_product(v1.begin(), v1.end(), v2.begin(), 0);
    std::cout << "內積: " << dot << " (1*4 + 2*5 + 3*6 = 32)" << std::endl;
    
    return 0;
}
