#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
#include <functional>

struct Product {
    std::string name;
    double price;
    int quantity;
};

int main() {
    std::vector<Product> products = {
        {"Apple", 1.50, 100},
        {"Banana", 0.75, 150},
        {"Orange", 2.00, 80},
        {"Mango", 3.00, 50},
        {"Grape", 2.50, 120}
    };
    
    // 1. 按價格排序（使用 Lambda）
    std::cout << "=== 按價格排序 ===" << std::endl;
    std::sort(products.begin(), products.end(),
        [](const Product& a, const Product& b) {
            return a.price < b.price;
        });
    
    for (const auto& p : products) {
        std::cout << p.name << ": $" << p.price << std::endl;
    }
    
    // 2. 找出價格超過 2 元的產品
    std::cout << "\n=== 價格超過 $2 ===" << std::endl;
    double threshold = 2.0;
    
    auto it = std::find_if(products.begin(), products.end(),
        [threshold](const Product& p) { return p.price > threshold; });
    
    while (it != products.end()) {
        std::cout << it->name << ": $" << it->price << std::endl;
        it = std::find_if(++it, products.end(),
            [threshold](const Product& p) { return p.price > threshold; });
    }
    
    // 3. 計算總庫存價值
    std::cout << "\n=== 總庫存價值 ===" << std::endl;
    double total_value = std::accumulate(products.begin(), products.end(), 0.0,
        [](double sum, const Product& p) {
            return sum + p.price * p.quantity;
        });
    std::cout << "總價值: $" << total_value << std::endl;
    
    // 4. 統計低庫存產品（數量 < 100）
    std::cout << "\n=== 低庫存產品 ===" << std::endl;
    int low_stock_count = std::count_if(products.begin(), products.end(),
        [](const Product& p) { return p.quantity < 100; });
    std::cout << "低庫存產品數: " << low_stock_count << std::endl;
    
    // 5. 對所有產品打 9 折
    std::cout << "\n=== 打 9 折後 ===" << std::endl;
    double discount = 0.9;
    std::for_each(products.begin(), products.end(),
        [discount](Product& p) { p.price *= discount; });
    
    for (const auto& p : products) {
        std::cout << p.name << ": $" << p.price << std::endl;
    }
    
    // 6. 使用 transform 生成價格列表
    std::cout << "\n=== 價格列表 ===" << std::endl;
    std::vector<double> prices(products.size());
    std::transform(products.begin(), products.end(), prices.begin(),
        [](const Product& p) { return p.price; });
    
    std::cout << "價格: ";
    for (double price : prices) {
        std::cout << "$" << price << " ";
    }
    std::cout << std::endl;
    
    return 0;
}
