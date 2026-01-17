/*
 * 範例3-6：條件運算符與其他運算符
 * 條件運算符 (?:)、逗號運算符 (,)、sizeof 等
 */
 
#include <iostream>
 
int main() {
    std::cout << "=== 條件運算符與其他運算符演示 ===" << std::endl;
    
    // 1. 條件運算符 (三元運算符) ?:
    std::cout << "1. 條件運算符 (三元運算符) ?:" << std::endl;
    
    int score = 85;
    std::string result = (score >= 60) ? "及格" : "不及格";
    
    std::cout << "分數: " << score << std::endl;
    std::cout << "結果: " << result << std::endl;
    
    // 嵌套條件運算符
    char grade = (score >= 90) ? 'A' :
                 (score >= 80) ? 'B' :
                 (score >= 70) ? 'C' :
                 (score >= 60) ? 'D' : 'F';
    
    std::cout << "等級: " << grade << std::endl;
    
    // 條件運算符返回的值可以參與運算
    int a = 10, b = 20;
    int max = (a > b) ? a : b;
    int min = (a < b) ? a : b;
    
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "較大值: " << max << std::endl;
    std::cout << "較小值: " << min << std::endl;
    
    // 2. 逗號運算符 ,
    std::cout << "\n2. 逗號運算符 ," << std::endl;
    
    // 逗號運算符會依次執行表達式，返回最後一個表達式的值
    int x = 1, y = 2, z = 3;
    int commaResult = (x++, y++, z++, x + y + z);
    
    std::cout << "表達式: (x++, y++, z++, x + y + z)" << std::endl;
    std::cout << "結果: " << commaResult << std::endl;
    std::cout << "現在 x = " << x << ", y = " << y << ", z = " << z << std::endl;
    
    // 常見用法：for循環中的多個變數
    std::cout << "\n逗號運算符在for循環中的應用:" << std::endl;
    for (int i = 0, j = 10; i < j; i++, j--) {
        std::cout << "i = " << i << ", j = " << j << std::endl;
    }
    
    // 3. sizeof 運算符
    std::cout << "\n3. sizeof 運算符" << std::endl;
    
    std::cout << "基本類型的大小（位元組）:" << std::endl;
    std::cout << "sizeof(char): " << sizeof(char) << std::endl;
    std::cout << "sizeof(int): " << sizeof(int) << std::endl;
    std::cout << "sizeof(double): " << sizeof(double) << std::endl;
    std::cout << "sizeof(bool): " << sizeof(bool) << std::endl;
    
    // 變數和類型都可以
    int num = 100;
    double price = 99.99;
    
    std::cout << "\n變數的大小:" << std::endl;
    std::cout << "sizeof(num): " << sizeof(num) << std::endl;
    std::cout << "sizeof(price): " << sizeof(price) << std::endl;
    
    // 數組的大小
    int arr[10];
    std::cout << "\n數組的大小:" << std::endl;
    std::cout << "sizeof(arr): " << sizeof(arr) << std::endl;
    std::cout << "數組元素個數: " << sizeof(arr) / sizeof(arr[0]) << std::endl;
    
    // 4. 運算符優先級演示
    std::cout << "\n4. 運算符優先級演示" << std::endl;
    
    int m = 1, n = 2, p = 3;
    
    // 複雜表達式
    int complexResult1 = m + n * p;        // 先乘後加
    int complexResult2 = (m + n) * p;      // 括號優先
    int complexResult3 = m++ + --n * p;    // 前綴遞減優先於乘法
    
    std::cout << "m = " << m << ", n = " << n << ", p = " << p << std::endl;
    std::cout << "m + n * p = " << complexResult1 << std::endl;
    std::cout << "(m + n) * p = " << complexResult2 << std::endl;
    std::cout << "m++ + --n * p = " << complexResult3 << std::endl;
    
    // 使用括號明確優先級
    std::cout << "\n使用括號明確優先級（推薦）:" << std::endl;
    int clearResult = ((m + n) * p) / 2;
    std::cout << "((m + n) * p) / 2 = " << clearResult << std::endl;
    
    return 0;
}
 