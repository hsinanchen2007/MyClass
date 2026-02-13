#include <iostream>
#include <vector>
#include <list>
#include <chrono>
#include <string>
#include <numeric>

struct Timer {
    std::chrono::high_resolution_clock::time_point start_;
    std::string label_;
    Timer(const std::string& label) : label_(label),
        start_(std::chrono::high_resolution_clock::now()) {}
    ~Timer() {
        auto end = std::chrono::high_resolution_clock::now();
        auto us = std::chrono::duration_cast<std::chrono::microseconds>(end - start_).count();
        std::cout << label_ << ": " << us << " μs" << std::endl;
    }
};

int main() {
    const int N = 1'000'000;

    // 順序遍歷：vector vs list
    {
        std::vector<int> v(N);
        std::iota(v.begin(), v.end(), 0);

        Timer t("vector 遍歷");
        long long sum = 0;
        for (int x : v) sum += x;
    }

    {
        std::list<int> lst;
        for (int i = 0; i < N; ++i) lst.push_back(i);

        Timer t("list   遍歷");
        long long sum = 0;
        for (int x : lst) sum += x;
    }

    return 0;
}
