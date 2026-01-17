/*
 * 範例3-4：遞增與遞減運算符
 * ++ 和 -- 運算符，分為前綴和後綴形式
 */
 
#include <iostream>
 
int main() {
    std::cout << "=== 遞增與遞減運算符演示 ===" << std::endl;
    
    // 前綴遞增 (++i)：先遞增，後使用
    std::cout << "前綴遞增 (++i)：" << std::endl;
    int a = 5;
    int b = ++a;  // a先增加到6，然後賦值給b
    
    std::cout << "a = 5" << std::endl;
    std::cout << "b = ++a" << std::endl;
    std::cout << "現在 a = " << a << ", b = " << b << std::endl;
    
    // 後綴遞增 (i++)：先使用，後遞增
    std::cout << "\n後綴遞增 (i++)：" << std::endl;
    int c = 5;
    int d = c++;  // 先把c的值(5)賦給d，然後c增加到6
    
    std::cout << "c = 5" << std::endl;
    std::cout << "d = c++" << std::endl;
    std::cout << "現在 c = " << c << ", d = " << d << std::endl;
    
    // 前綴遞減 (--i)
    std::cout << "\n前綴遞減 (--i)：" << std::endl;
    int e = 5;
    int f = --e;  // e先減少到4，然後賦值給f
    
    std::cout << "e = 5" << std::endl;
    std::cout << "f = --e" << std::endl;
    std::cout << "現在 e = " << e << ", f = " << f << std::endl;
    
    // 後綴遞減 (i--)
    std::cout << "\n後綴遞減 (i--)：" << std::endl;
    int g = 5;
    int h = g--;  // 先把g的值(5)賦給h，然後g減少到4
    
    std::cout << "g = 5" << std::endl;
    std::cout << "h = g--" << std::endl;
    std::cout << "現在 g = " << g << ", h = " << h << std::endl;
    
    // 在表達式中使用
    std::cout << "\n在表達式中使用：" << std::endl;
    int i = 5;
    int j = 10;
    
    int result1 = ++i + j;  // i先增到6，然後 6 + 10 = 16
    std::cout << "int result1 = ++i + j;" << std::endl;
    std::cout << "result1 = " << result1 << ", i = " << i << std::endl;
    
    int k = 5;
    int l = 10;
    
    int result2 = k++ + l;  // 先 5 + 10 = 15，然後k增到6
    std::cout << "int result2 = k++ + l;" << std::endl;
    std::cout << "result2 = " << result2 << ", k = " << k << std::endl;
    
    // 常見用法：循環計數器
    std::cout << "\n常見用法：循環計數器" << std::endl;
    std::cout << "使用後綴遞增：" << std::endl;
    
    for (int count = 1; count <= 5; count++) {
        std::cout << "count = " << count << std::endl;
    }
    
    // 前綴與後綴的性能差異（通常很小）
    std::cout << "\n性能提示：" << std::endl;
    std::cout << "前綴遞增(++i)通常比後綴遞增(i++)更高效" << std::endl;
    std::cout << "因為後綴遞增需要保存臨時值" << std::endl;
    std::cout << "在循環中推薦使用 ++i" << std::endl;
    
    // 陷阱：多次修改同一變數
    std::cout << "\n陷阱：未定義行為" << std::endl;
    int x = 5;
    // int y = x++ + ++x;  // 未定義行為！避免！
    std::cout << "int y = x++ + ++x; // 未定義行為，避免這樣寫！" << std::endl;
    
    return 0;
}
 