/*
 * 範例3-3：賦值運算符與複合賦值運算符
 * 用於賦值和簡化運算
 */
 
#include <iostream>
 
int main() {
    std::cout << "=== 賦值運算符與複合賦值運算符演示 ===" << std::endl;
    
    // 基本賦值運算符
    int x = 10;  // 初始化賦值
    int y;
    y = 20;      // 賦值
    int z = x;   // 用變數初始化
    
    std::cout << "基本賦值：" << std::endl;
    std::cout << "x = " << x << std::endl;
    std::cout << "y = " << y << std::endl;
    std::cout << "z = " << z << std::endl;
    
    // 複合賦值運算符
    int a = 10;
    
    std::cout << "\n複合賦值運算符：" << std::endl;
    std::cout << "初始值 a = " << a << std::endl;
    
    a += 5;      // a = a + 5
    std::cout << "a += 5 後: " << a << std::endl;
    
    a -= 3;      // a = a - 3
    std::cout << "a -= 3 後: " << a << std::endl;
    
    a *= 2;      // a = a * 2
    std::cout << "a *= 2 後: " << a << std::endl;
    
    a /= 4;      // a = a / 4
    std::cout << "a /= 4 後: " << a << std::endl;
    
    a %= 3;      // a = a % 3
    std::cout << "a %= 3 後: " << a << std::endl;
    
    // 多重賦值
    int p, q, r;
    p = q = r = 100;  // 從右向左賦值
    
    std::cout << "\n多重賦值：" << std::endl;
    std::cout << "p = " << p << ", q = " << q << ", r = " << r << std::endl;
    
    // 賦值表達式的值
    std::cout << "\n賦值表達式的值：" << std::endl;
    int m, n;
    n = (m = 15) + 5;  // m = 15，然後 n = m + 5
    
    std::cout << "n = (m = 15) + 5 的結果：" << std::endl;
    std::cout << "m = " << m << std::endl;
    std::cout << "n = " << n << std::endl;
    
    // 複合賦值的優勢
    std::cout << "\n複合賦值的優勢：" << std::endl;
    
    // 方法1：傳統寫法
    int value1 = 10;
    value1 = value1 + 5;
    value1 = value1 * 2;
    std::cout << "方法1（傳統）: value1 = " << value1 << std::endl;
    
    // 方法2：複合賦值
    int value2 = 10;
    value2 += 5;   // 更簡潔
    value2 *= 2;
    std::cout << "方法2（複合）: value2 = " << value2 << std::endl;
    
    // 對於複雜表達式，複合賦值更高效
    int arr[5] = {1, 2, 3, 4, 5};
    int sum = 0;
    
    for (int i = 0; i < 5; i++) {
        sum += arr[i];  // 比 sum = sum + arr[i] 更好
    }
    
    std::cout << "數組總和: " << sum << std::endl;
    
    return 0;
}
 