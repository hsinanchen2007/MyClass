#include <iostream>
#include <iterator>
 
int main() {
    std::ostream_iterator<int> out(std::cout, " ");
    
    // 可以寫入
    *out = 10;  // 輸出 "10 "
    ++out;
    *out = 20;  // 輸出 "20 "
    ++out;
    *out = 30;  // 輸出 "30 "
    
    std::cout << std::endl;
    
    // 但不能讀取！
    // int x = *out;  // 這不會如你預期的工作
    
    // 也不能回頭或跳躍
    // --out;  // 不支援
    // out + 1;  // 不支援
    
    return 0;
}
 