#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>

struct Student {
    std::string name;
    int score;
};

int main() {
    std::vector<Student> students = {
        {"Alice", 85},
        {"Bob", 92},
        {"Charlie", 78},
        {"Diana", 95},
        {"Eve", 88},
        {"Frank", 72},
        {"Grace", 91}
    };
    
    // 1. 按分數排序（降序）
    std::cout << "=== 按分數排序 ===" << std::endl;
    std::sort(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.score > b.score;
        });
    
    for (const auto& s : students) {
        std::cout << s.name << ": " << s.score << std::endl;
    }
    
    // 2. 找出分數 >= 90 的學生
    std::cout << "\n=== 分數 >= 90 ===" << std::endl;
    auto high_it = std::find_if(students.begin(), students.end(),
        [](const Student& s) { return s.score < 90; });
    
    std::cout << "優秀學生: ";
    for (auto it = students.begin(); it != high_it; ++it) {
        std::cout << it->name << " ";
    }
    std::cout << std::endl;
    
    // 3. 計算平均分
    std::cout << "\n=== 平均分 ===" << std::endl;
    int total = std::accumulate(students.begin(), students.end(), 0,
        [](int sum, const Student& s) { return sum + s.score; });
    double average = static_cast<double>(total) / students.size();
    std::cout << "平均分: " << average << std::endl;
    
    // 4. 統計及格（>= 80）人數
    std::cout << "\n=== 及格人數 ===" << std::endl;
    int pass_count = std::count_if(students.begin(), students.end(),
        [](const Student& s) { return s.score >= 80; });
    std::cout << "及格人數: " << pass_count << "/" << students.size() << std::endl;
    
    // 5. 提取所有分數到另一個 vector
    std::cout << "\n=== 提取分數 ===" << std::endl;
    std::vector<int> scores(students.size());
    std::transform(students.begin(), students.end(), scores.begin(),
        [](const Student& s) { return s.score; });
    
    std::cout << "所有分數: ";
    for (int score : scores) std::cout << score << " ";
    std::cout << std::endl;
    
    // 6. 找最高分和最低分
    std::cout << "\n=== 最高最低分 ===" << std::endl;
    auto minmax = std::minmax_element(students.begin(), students.end(),
        [](const Student& a, const Student& b) {
            return a.score < b.score;
        });
    
    std::cout << "最高分: " << minmax.second->name << " (" << minmax.second->score << ")" << std::endl;
    std::cout << "最低分: " << minmax.first->name << " (" << minmax.first->score << ")" << std::endl;
    
    return 0;
}
