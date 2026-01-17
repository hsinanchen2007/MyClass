/*
 * 範例1-3：main函數的不同形式
 * C++允許main函數有不同的參數形式
 * 但最常用的是無參數形式
 */
 
#include <iostream>
 
// 形式1：最常見的無參數形式
int main() {
    std::cout << "形式1：無參數的main函數" << std::endl;
    return 0;
}
 
/*
// 形式2：帶參數的main函數（用於接收命令行參數）
int main(int argc, char* argv[]) {
    std::cout << "參數數量：" << argc << std::endl;
    return 0;
}
 
// 形式3：void參數列表（C風格，不推薦在C++中使用）
int main(void) {
    std::cout << "使用void參數列表" << std::endl;
    return 0;
}
*/
 