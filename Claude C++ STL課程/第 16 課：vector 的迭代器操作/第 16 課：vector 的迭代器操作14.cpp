#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {10, 20, 30};
    auto it = v.begin();  // 指向 10

    std::cout << "*it = " << *it << std::endl;  // 10

    // 這個 push_back 可能導致記憶體重新配置
    // 如果發生重新配置，it 就失效了！
    v.push_back(40);
    v.push_back(50);
    v.push_back(60);

    // 危險！it 可能已經失效
    // std::cout << *it << std::endl;  // 未定義行為！

    // 安全的做法：重新取得迭代器
    it = v.begin();
    std::cout << "*it = " << *it << std::endl;  // 10

    return 0;
}
