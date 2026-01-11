// 檔案：lesson_5_4_scope_too_small.cpp
// 說明：保護範圍太小，仍有競爭條件

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mtx;
std::vector<int> data;

void unsafeAppend(int value) {
    // 錯誤：檢查和操作分開保護
    
    mtx.lock();
    bool shouldAppend = (data.size() < 10);
    mtx.unlock();
    
    // 💀 此時其他執行緒可能已經改變了 data.size()！
    
    if (shouldAppend) {
        mtx.lock();
        data.push_back(value);  // 💀 可能超過限制！
        mtx.unlock();
    }
}

void safeAppend(int value) {
    // 正確：整個操作在同一個臨界區段
    std::lock_guard<std::mutex> lock(mtx);
    
    if (data.size() < 10) {
        data.push_back(value);  // ✓ 安全
    }
}
