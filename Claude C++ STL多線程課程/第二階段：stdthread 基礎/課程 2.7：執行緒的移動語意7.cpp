#include <iostream>
#include <thread>

class ScopedThread {
    std::thread t;
public:
    explicit ScopedThread(std::thread thread) 
        : t(std::move(thread)) {
        if (!t.joinable()) {
            throw std::logic_error("No thread");
        }
    }
    
    ~ScopedThread() {
        t.join();
    }
    
    // 禁止複製
    ScopedThread(const ScopedThread&) = delete;
    ScopedThread& operator=(const ScopedThread&) = delete;
    
    // 允許移動
    ScopedThread(ScopedThread&&) = default;
    ScopedThread& operator=(ScopedThread&&) = default;
};

int main() {
    ScopedThread st(std::thread([]() {
        std::cout << "自動管理的執行緒" << std::endl;
    }));
    
    // 離開作用域時自動 join
    return 0;
}
