// 檔案：lesson_5_1_with_mutex.cpp
// 說明：使用互斥鎖保護共享資源

#include <iostream>
#include <thread>
#include <mutex>

int counter = 0;      // 共享資源
std::mutex mtx;       // 保護 counter 的互斥鎖

void increment() {
    for (int i = 0; i < 100000; ++i) {
        mtx.lock();       // 🔒 進入臨界區段前獲取鎖
        ++counter;        // 安全！一次只有一個執行緒能執行
        mtx.unlock();     // 🔓 離開臨界區段後釋放鎖
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);
    
    t1.join();
    t2.join();
    
    std::cout << "預期: 200000" << std::endl;
    std::cout << "實際: " << counter << std::endl;  // 保證是 200000
    
    return 0;
}
