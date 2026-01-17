/*
 * 範例3-5：位運算符
 * 用於對整數的二進制位進行操作
 */
 
#include <iostream>
#include <bitset>  // 用於顯示二進制
 
int main() {
    std::cout << "=== 位運算符演示 ===" << std::endl;
    
    unsigned int a = 60;  // 二進制: 0011 1100
    unsigned int b = 13;  // 二進制: 0000 1101
    
    std::cout << "a = 60 (二進制: " << std::bitset<8>(a) << ")" << std::endl;
    std::cout << "b = 13 (二進制: " << std::bitset<8>(b) << ")" << std::endl;
    std::cout << std::endl;
    
    // 位與 (AND) - &
    unsigned int c = a & b;
    std::cout << "位與 (AND) - &" << std::endl;
    std::cout << "a & b = " << c << std::endl;
    std::cout << "二進制: " << std::bitset<8>(a) << " &" << std::endl;
    std::cout << "         " << std::bitset<8>(b) << std::endl;
    std::cout << "         ----------" << std::endl;
    std::cout << "         " << std::bitset<8>(c) << std::endl;
    std::cout << std::endl;
    
    // 位或 (OR) - |
    c = a | b;
    std::cout << "位或 (OR) - |" << std::endl;
    std::cout << "a | b = " << c << std::endl;
    std::cout << "二進制: " << std::bitset<8>(a) << " |" << std::endl;
    std::cout << "         " << std::bitset<8>(b) << std::endl;
    std::cout << "         ----------" << std::endl;
    std::cout << "         " << std::bitset<8>(c) << std::endl;
    std::cout << std::endl;
    
    // 位異或 (XOR) - ^
    c = a ^ b;
    std::cout << "位異或 (XOR) - ^" << std::endl;
    std::cout << "a ^ b = " << c << std::endl;
    std::cout << "二進制: " << std::bitset<8>(a) << " ^" << std::endl;
    std::cout << "         " << std::bitset<8>(b) << std::endl;
    std::cout << "         ----------" << std::endl;
    std::cout << "         " << std::bitset<8>(c) << std::endl;
    std::cout << std::endl;
    
    // 位取反 (NOT) - ~
    c = ~a;
    std::cout << "位取反 (NOT) - ~" << std::endl;
    std::cout << "~a = " << c << std::endl;
    std::cout << "二進制: ~" << std::bitset<8>(a) << std::endl;
    std::cout << "         ----------" << std::endl;
    std::cout << "         " << std::bitset<8>(c) << std::endl;
    std::cout << std::endl;
    
    // 左移 (Left Shift) - <<
    c = a << 2;
    std::cout << "左移 (Left Shift) - <<" << std::endl;
    std::cout << "a << 2 = " << c << std::endl;
    std::cout << "二進制: " << std::bitset<8>(a) << " << 2" << std::endl;
    std::cout << "         ----------" << std::endl;
    std::cout << "         " << std::bitset<8>(c) << std::endl;
    std::cout << "相當於乘以 2^2 = 4: 60 * 4 = 240" << std::endl;
    std::cout << std::endl;
    
    // 右移 (Right Shift) - >>
    c = a >> 2;
    std::cout << "右移 (Right Shift) - >>" << std::endl;
    std::cout << "a >> 2 = " << c << std::endl;
    std::cout << "二進制: " << std::bitset<8>(a) << " >> 2" << std::endl;
    std::cout << "         ----------" << std::endl;
    std::cout << "         " << std::bitset<8>(c) << std::endl;
    std::cout << "相當於除以 2^2 = 4: 60 / 4 = 15" << std::endl;
    std::cout << std::endl;
    
    // 實際應用：權限控制
    std::cout << "實際應用：權限控制" << std::endl;
    
    // 定義權限標誌
    const unsigned int READ = 1;    // 0001
    const unsigned int WRITE = 2;   // 0010
    const unsigned int EXECUTE = 4; // 0100
    
    unsigned int userPermissions = 0;
    
    // 添加權限（使用位或）
    userPermissions = userPermissions | READ;    // 添加讀權限
    userPermissions = userPermissions | WRITE;   // 添加寫權限
    
    std::cout << "用戶權限: " << std::bitset<4>(userPermissions) << std::endl;
    
    // 檢查權限（使用位與）
    bool canRead = (userPermissions & READ) != 0;
    bool canWrite = (userPermissions & WRITE) != 0;
    bool canExecute = (userPermissions & EXECUTE) != 0;
    
    std::cout << "可以讀取: " << (canRead ? "是" : "否") << std::endl;
    std::cout << "可以寫入: " << (canWrite ? "是" : "否") << std::endl;
    std::cout << "可以執行: " << (canExecute ? "是" : "否") << std::endl;
    
    // 移除權限（使用位與和位取反）
    userPermissions = userPermissions & ~WRITE;  // 移除寫權限
    
    std::cout << "\n移除寫權限後:" << std::endl;
    std::cout << "用戶權限: " << std::bitset<4>(userPermissions) << std::endl;
    canWrite = (userPermissions & WRITE) != 0;
    std::cout << "可以寫入: " << (canWrite ? "是" : "否") << std::endl;
    
    return 0;
}
 