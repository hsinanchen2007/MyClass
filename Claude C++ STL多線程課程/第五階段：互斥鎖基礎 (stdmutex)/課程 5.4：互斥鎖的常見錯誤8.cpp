// 檔案：lesson_5_4_unlock_unowned.cpp
// 說明：解鎖未鎖定或不屬於自己的互斥鎖

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void wrongUnlock() {
    // 沒有 lock()
    mtx.unlock();  // 💀 未定義行為！
}

void wrongThread() {
    mtx.lock();
    
    std::thread t([&]() {
        mtx.unlock();  // 💀 在不同執行緒解鎖！未定義行為！
    });
    t.join();
}

int main() {
    // 這些都是錯誤的用法
    // wrongUnlock();
    // wrongThread();
    
    std::cout << "這些函式都有問題，不要這樣做！" << std::endl;
    
    return 0;
}
