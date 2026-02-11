#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    std::vector<int> vec = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    
    // std::bind：綁定參數
    auto is_greater_than_5 = std::bind(std::greater<int>(), 
                                        std::placeholders::_1, 5);
    
    int count = std::count_if(vec.begin(), vec.end(), is_greater_than_5);
    std::cout << "大於5的個數: " << count << std::endl;
    
    // 等價的 Lambda 寫法（更推薦）
    int count2 = std::count_if(vec.begin(), vec.end(),
        [](int n) { return n > 5; }
    );
    std::cout << "大於5的個數（Lambda）: " << count2 << std::endl;
    
    return 0;
}
