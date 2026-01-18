/*
 * 範例4-4：嵌套條件與複雜條件
 * 展示複雜的條件判斷結構
 */
 
#include <iostream>
#include <string>
 
int main() {
    std::cout << "=== 嵌套條件與複雜條件演示 ===" << std::endl;
    
    // 1. 多重嵌套條件
    bool isMember = true;
    double purchaseAmount = 1200.0;
    bool hasCoupon = true;
    
    double discount = 0.0;
    
    if (isMember) {
        if (purchaseAmount > 1000.0) {
            if (hasCoupon) {
                discount = 0.2;  // 會員 + 大額購買 + 優惠券：20%折扣
                std::cout << "尊貴會員，您享受20%折扣！" << std::endl;
            } else {
                discount = 0.15;  // 會員 + 大額購買：15%折扣
                std::cout << "尊貴會員，您享受15%折扣！" << std::endl;
            }
        } else {
            discount = 0.1;  // 會員：10%折扣
            std::cout << "尊貴會員，您享受10%折扣！" << std::endl;
        }
    } else {
        if (purchaseAmount > 1000.0) {
            discount = 0.05;  // 大額購買：5%折扣
            std::cout << "感謝大額購買，您享受5%折扣！" << std::endl;
        } else {
            discount = 0.0;  // 無折扣
            std::cout << "抱歉，您沒有折扣" << std::endl;
        }
    }
    
    double finalAmount = purchaseAmount * (1 - discount);
    std::cout << "原價：" << purchaseAmount << " 元，折扣後：" << finalAmount << " 元" << std::endl;
    
    // 2. 使用邏輯運算符簡化嵌套條件
    std::cout << "\n使用邏輯運算符簡化：" << std::endl;
    
    int hour = 20;
    bool isWeekend = true;
    bool isHoliday = false;
    
    // 判斷是否應該播放背景音樂
    if ((hour >= 8 && hour <= 22) || isWeekend || isHoliday) {
        std::cout << "播放背景音樂" << std::endl;
    } else {
        std::cout << "靜音時間，不播放音樂" << std::endl;
    }
    
    // 3. 複雜的條件組合
    int age = 25;
    bool hasLicense = true;
    bool hasInsurance = true;
    bool isIntoxicated = false;
    
    std::cout << "\n駕駛資格檢查：" << std::endl;
    std::cout << "年齡：" << age << " 歲" << std::endl;
    std::cout << "有駕照：" << (hasLicense ? "是" : "否") << std::endl;
    std::cout << "有保險：" << (hasInsurance ? "是" : "否") << std::endl;
    std::cout << "是否酒駕：" << (isIntoxicated ? "是" : "否") << std::endl;
    
    if (age >= 18 && hasLicense && hasInsurance && !isIntoxicated) {
        std::cout << "✅ 可以合法駕駛" << std::endl;
    } else {
        std::cout << "❌ 不能駕駛，原因：" << std::endl;
        
        if (age < 18) {
            std::cout << "  - 年齡未滿18歲" << std::endl;
        }
        
        if (!hasLicense) {
            std::cout << "  - 沒有駕照" << std::endl;
        }
        
        if (!hasInsurance) {
            std::cout << "  - 沒有保險" << std::endl;
        }
        
        if (isIntoxicated) {
            std::cout << "  - 酒後不能駕駛" << std::endl;
        }
    }
    
    // 4. 條件表達式中的賦值（注意與比較的區別）
    int a = 5;
    int b = 10;
    
    // 錯誤示例：少了一個等號（這是賦值，不是比較）
    if (a = 10) {  // 注意：這裡是賦值，不是比較！
        std::cout << "\n注意：if (a = 10) 總是為真，因為賦值表達式的值為10（非零）" << std::endl;
        std::cout << "現在 a 的值是：" << a << std::endl;
    }
    
    // 正確示例：比較
    a = 5;  // 恢復原始值
    if (a == 10) {  // 這是比較
        std::cout << "這行不會執行，因為 a 不等於 10" << std::endl;
    }
    
    // 防止錯誤的技巧：將常量放在左邊
    if (10 == a) {  // 如果寫成 10 = a，編譯器會報錯
        std::cout << "a 等於 10" << std::endl;
    } else {
        std::cout << "a 不等於 10" << std::endl;
    }
    
    return 0;
}
 