#include <iostream>
#include <vector>
#include <cstdint>
#include <deque>

int main() {
    // 1. 需要大量布林值且只做簡單讀寫 → vector<bool> 可以接受
    std::vector<bool> flags(1'000'000, false);
    flags[42] = true;
    // 注意：不要用 auto，明確寫 bool
    bool val = flags[42];  // OK
    // auto val2 = flags[42];  // 危險！得到代理物件

    // 2. 需要標準容器行為（取引用、指標、傳給模板）→ 避免 vector<bool>
    std::vector<uint8_t> safe_flags(1000, 0);
    uint8_t& ref = safe_flags[0];  // 正常引用
    uint8_t* ptr = safe_flags.data();  // 正常指標

    // 3. 在泛型程式碼中，永遠不要假設 vector<T> 的行為是統一的
    // 如果你寫的模板可能被 bool 實例化，要特別注意

    return 0;
}
