/*
 * 範例4-6：條件語句的實際應用
 * 綜合應用條件語句解決實際問題
 */
 
#include <iostream>
#include <string>
#include <iomanip>
 
int main() {
    std::cout << "=== 條件語句的實際應用 ===" << std::endl;
    
    // 1. 登錄系統
    std::cout << "\n1. 登錄系統示例：" << std::endl;
    
    std::string correctUsername = "admin";
    std::string correctPassword = "123456";
    
    std::string inputUsername, inputPassword;
    
    // 模擬輸入
    inputUsername = "admin";
    inputPassword = "123456";
    
    if (inputUsername == correctUsername && inputPassword == correctPassword) {
        std::cout << "登錄成功！歡迎，" << inputUsername << std::endl;
    } else {
        std::cout << "登錄失敗！用戶名或密碼錯誤" << std::endl;
        
        if (inputUsername != correctUsername) {
            std::cout << "用戶名錯誤" << std::endl;
        }
        
        if (inputPassword != correctPassword) {
            std::cout << "密碼錯誤" << std::endl;
        }
    }
    
    // 2. 計算BMI並判斷健康狀況
    std::cout << "\n2. BMI健康指數計算：" << std::endl;
    
    double height = 1.75;  // 米
    double weight = 70.0;  // 公斤
    double bmi = weight / (height * height);
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "身高：" << height << " 米" << std::endl;
    std::cout << "體重：" << weight << " 公斤" << std::endl;
    std::cout << "BMI：" << bmi << std::endl;
    
    std::string healthStatus;
    
    if (bmi < 18.5) {
        healthStatus = "體重過輕";
    } else if (bmi < 24.0) {
        healthStatus = "正常範圍";
    } else if (bmi < 27.0) {
        healthStatus = "體重過重";
    } else if (bmi < 30.0) {
        healthStatus = "輕度肥胖";
    } else if (bmi < 35.0) {
        healthStatus = "中度肥胖";
    } else {
        healthStatus = "重度肥胖";
    }
    
    std::cout << "健康狀況：" << healthStatus << std::endl;
    
    // 3. 電費計算（階梯電價）
    std::cout << "\n3. 階梯電價計算：" << std::endl;
    
    double electricityUsed = 350.0;  // 度
    double totalCost = 0.0;
    
    if (electricityUsed <= 240.0) {
        totalCost = electricityUsed * 0.4883;  // 第一階梯
    } else if (electricityUsed <= 400.0) {
        totalCost = 240.0 * 0.4883 + (electricityUsed - 240.0) * 0.5383;  // 第二階梯
    } else {
        totalCost = 240.0 * 0.4883 + 160.0 * 0.5383 + (electricityUsed - 400.0) * 0.7883;  // 第三階梯
    }
    
    std::cout << "用電量：" << electricityUsed << " 度" << std::endl;
    std::cout << "電費總額：" << totalCost << " 元" << std::endl;
    
    // 4. 交通信號燈模擬
    std::cout << "\n4. 交通信號燈模擬：" << std::endl;
    
    std::string lightColor = "yellow";
    int seconds = 3;
    
    std::cout << "當前信號燈：" << lightColor << std::endl;
    
    if (lightColor == "red") {
        std::cout << "紅燈：停止" << std::endl;
        std::cout << "等待時間：" << seconds << " 秒" << std::endl;
    } else if (lightColor == "yellow") {
        std::cout << "黃燈：準備" << std::endl;
        std::cout << "剩餘時間：" << seconds << " 秒" << std::endl;
        
        if (seconds <= 2) {
            std::cout << "警告：即將變紅燈！" << std::endl;
        }
    } else if (lightColor == "green") {
        std::cout << "綠燈：通行" << std::endl;
        std::cout << "剩餘時間：" << seconds << " 秒" << std::endl;
    } else {
        std::cout << "錯誤：未知的信號燈顏色" << std::endl;
    }
    
    // 5. 學生獎學金評定
    std::cout << "\n5. 學生獎學金評定：" << std::endl;
    
    double averageScore = 88.5;
    bool hasGoodBehavior = true;
    bool noFailedCourses = true;
    bool participatedActivities = true;
    
    std::cout << "平均成績：" << averageScore << std::endl;
    std::cout << "品德優良：" << (hasGoodBehavior ? "是" : "否") << std::endl;
    std::cout << "無不及格科目：" << (noFailedCourses ? "是" : "否") << std::endl;
    std::cout << "參與活動：" << (participatedActivities ? "是" : "否") << std::endl;
    
    std::string scholarshipLevel = "無";
    
    // 使用嵌套if-else評定獎學金等級
    if (averageScore >= 85.0 && hasGoodBehavior && noFailedCourses) {
        if (averageScore >= 95.0 && participatedActivities) {
            scholarshipLevel = "特等獎學金";
        } else if (averageScore >= 90.0) {
            scholarshipLevel = "一等獎學金";
        } else if (averageScore >= 85.0) {
            scholarshipLevel = "二等獎學金";
        }
    } else if (averageScore >= 80.0 && hasGoodBehavior && noFailedCourses) {
        scholarshipLevel = "三等獎學金";
    } else if (averageScore >= 75.0 && noFailedCourses) {
        scholarshipLevel = "進步獎";
    }
    
    std::cout << "獎學金等級：" << scholarshipLevel << std::endl;
    
    // 6. 使用switch處理菜單選項
    std::cout << "\n6. 簡單計算器：" << std::endl;
    
    int choice = 3;  // 1-加法 2-減法 3-乘法 4-除法
    double num1 = 15.0, num2 = 3.0;
    double calcResult = 0.0;
    char op = ' ';
    
    switch (choice) {
        case 1:
            calcResult = num1 + num2;
            op = '+';
            break;
        case 2:
            calcResult = num1 - num2;
            op = '-';
            break;
        case 3:
            calcResult = num1 * num2;
            op = '*';
            break;
        case 4:
            if (num2 != 0.0) {
                calcResult = num1 / num2;
                op = '/';
            } else {
                std::cout << "錯誤：除數不能為零！" << std::endl;
                return 1;
            }
            break;
        default:
            std::cout << "錯誤：無效的選擇！" << std::endl;
            return 1;
    }
    
    std::cout << num1 << " " << op << " " << num2 << " = " << calcResult << std::endl;
    
    return 0;
}
 