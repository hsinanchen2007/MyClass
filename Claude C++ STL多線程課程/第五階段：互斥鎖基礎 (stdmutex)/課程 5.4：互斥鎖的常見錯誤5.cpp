// 檔案：lesson_5_4_double_lock.cpp
// 說明：重複鎖定的錯誤

#include <iostream>
#include <mutex>

std::mutex mtx;

void outerFunction();
void innerFunction();

void innerFunction() {
    mtx.lock();  // 💀 已經被 outerFunction 鎖定了！
    std::cout << "Inner function" << std::endl;
    mtx.unlock();
}

void outerFunction() {
    mtx.lock();
    std::cout << "Outer function" << std::endl;
    
    innerFunction();  // 💀 呼叫另一個也需要鎖的函式
    
    mtx.unlock();
}

int main() {
    outerFunction();  // 💀 死結！（或未定義行為）
    return 0;
}
