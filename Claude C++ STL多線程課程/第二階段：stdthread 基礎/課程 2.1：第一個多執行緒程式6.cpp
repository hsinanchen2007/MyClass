// 檔案：lesson_2_1_multiple.cpp

#include <iostream>
#include <thread>

int main() {
    std::thread t1([]() {
        for (int i = 0; i < 3; ++i)
            std::cout << "A";
    });
    
    std::thread t2([]() {
        for (int i = 0; i < 3; ++i)
            std::cout << "B";
    });
    
    t1.join();
    t2.join();
    
    std::cout << std::endl;
    return 0;
}
