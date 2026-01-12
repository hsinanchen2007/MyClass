///*
//# 第五階段：互斥鎖基礎 (std::mutex)
//
//## 課程 5.5：保護共享資料實作
//
//---
//
//### 引言
//
//前幾課我們學習了 `std::mutex` 的基本操作和常見錯誤。現在，讓我們將這些知識付諸實踐，設計並實作完整的執行緒安全類別。這是多執行緒程式設計中最重要的技能之一。
//
//---
//
//### 一、執行緒安全類別的設計原則
//
//```
//┌─────────────────────────────────────────────────────────────┐
//│              執行緒安全類別設計原則                          │
//├─────────────────────────────────────────────────────────────┤
//│                                                             │
//│  1. 封裝原則                                                │
//│     → 互斥鎖和資料放在同一個類別中                          │
//│     → 外部無法直接存取資料或鎖                              │
//│                                                             │
//│  2. 最小介面原則                                            │
//│     → 只暴露必要的操作                                      │
//│     → 避免返回內部資料的指標或引用                          │
//│                                                             │
//│  3. 原子操作原則                                            │
//│     → 每個公開方法應該是原子的                              │
//│     → 檢查和操作應在同一個臨界區段                          │
//│                                                             │
//│  4. 不變量保護原則                                          │
//│     → 確保類別的不變量在任何時刻都成立                      │
//│     → 臨界區段結束前恢復不變量                              │
//│                                                             │
//└─────────────────────────────────────────────────────────────┘
//```
//
//---
//
//### 二、實作一：執行緒安全計數器
//
//從最簡單的例子開始。
//
//```cpp
//// 檔案：lesson_5_5_safe_counter.cpp
//// 說明：執行緒安全的計數器類別
//
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <vector>
//
//class ThreadSafeCounter {
//private:
//    mutable std::mutex mtx;  // mutable：允許在 const 方法中使用
//    int count = 0;
//    
//public:
//    // 建構函式
//    ThreadSafeCounter() = default;
//    
//    // 禁止複製（互斥鎖不可複製）
//    ThreadSafeCounter(const ThreadSafeCounter&) = delete;
//    ThreadSafeCounter& operator=(const ThreadSafeCounter&) = delete;
//    
//    // 遞增
//    void increment() {
//        std::lock_guard<std::mutex> lock(mtx);
//        ++count;
//    }
//    
//    // 遞減
//    void decrement() {
//        std::lock_guard<std::mutex> lock(mtx);
//        --count;
//    }
//    
//    // 增加指定值
//    void add(int value) {
//        std::lock_guard<std::mutex> lock(mtx);
//        count += value;
//    }
//    
//    // 獲取當前值
//    int get() const {
//        std::lock_guard<std::mutex> lock(mtx);
//        return count;
//    }
//    
//    // 重設並返回舊值（原子操作）
//    int reset() {
//        std::lock_guard<std::mutex> lock(mtx);
//        int oldValue = count;
//        count = 0;
//        return oldValue;
//    }
//    
//    // 條件遞增：只有當前值小於 max 時才遞增
//    bool incrementIfLessThan(int max) {
//        std::lock_guard<std::mutex> lock(mtx);
//        if (count < max) {
//            ++count;
//            return true;
//        }
//        return false;
//    }
//};
//
//// 測試
//void workerIncrement(ThreadSafeCounter& counter, int times) {
//    for (int i = 0; i < times; ++i) {
//        counter.increment();
//    }
//}
//
//int main() {
//    ThreadSafeCounter counter;
//    
//    const int numThreads = 4;
//    const int incrementsPerThread = 100000;
//    
//    std::vector<std::thread> threads;
//    
//    for (int i = 0; i < numThreads; ++i) {
//        threads.emplace_back(workerIncrement, std::ref(counter), incrementsPerThread);
//    }
//    
//    for (auto& t : threads) {
//        t.join();
//    }
//    
//    int expected = numThreads * incrementsPerThread;
//    int actual = counter.get();
//    
//    std::cout << "預期值：" << expected << std::endl;
//    std::cout << "實際值：" << actual << std::endl;
//    std::cout << "結果：" << (expected == actual ? "✓ 正確" : "✗ 錯誤") << std::endl;
//    
//    return 0;
//}
//```
//
//#### 輸出
//
//```
//預期值：400000
//實際值：400000
//結果：✓ 正確
//```
//
//---
//
//### 三、為什麼禁止複製？
//
//```
//┌─────────────────────────────────────────────────────────────┐
//│           為什麼含有 mutex 的類別應禁止複製？                │
//├─────────────────────────────────────────────────────────────┤
//│                                                             │
//│  問題 1：std::mutex 本身不可複製                            │
//│  ─────────────────────────────                              │
//│  std::mutex mtx1;                                           │
//│  std::mutex mtx2 = mtx1;  // 編譯錯誤！                     │
//│                                                             │
//│  問題 2：複製語意不明確                                     │
//│  ─────────────────────                                      │
//│  如果允許複製：                                             │
//│  • 複製時原物件被鎖定怎麼辦？                               │
//│  • 新物件應該共享鎖還是有自己的鎖？                         │
//│  • 複製後兩個物件是否獨立？                                 │
//│                                                             │
//│  解決方案                                                   │
//│  ────────                                                   │
//│  1. 禁止複製和賦值                                          │
//│     Counter(const Counter&) = delete;                       │
//│     Counter& operator=(const Counter&) = delete;            │
//│                                                             │
//│  2. 如果需要複製語意，明確定義行為                          │
//│     （見下方範例）                                           │
//│                                                             │
//└─────────────────────────────────────────────────────────────┘
//```
//
//#### 如果確實需要複製
//
//```cpp
//// 檔案：lesson_5_5_copyable_counter.cpp
//// 說明：可複製的執行緒安全計數器（明確定義複製行為）
//
//#include <iostream>
//#include <mutex>
//
//class CopyableCounter {
//private:
//    mutable std::mutex mtx;
//    int count = 0;
//    
//public:
//    CopyableCounter() = default;
//    
//    // 明確定義複製建構函式
//    CopyableCounter(const CopyableCounter& other) {
//        std::lock_guard<std::mutex> lock(other.mtx);  // 鎖定來源
//        count = other.count;  // 複製值
//        // 新物件有自己的 mutex（預設建構）
//    }
//    
//    // 明確定義複製賦值運算子
//    CopyableCounter& operator=(const CopyableCounter& other) {
//        if (this != &other) {
//            // 需要同時鎖定兩個物件，注意死結！
//            std::scoped_lock lock(mtx, other.mtx);
//            count = other.count;
//        }
//        return *this;
//    }
//    
//    void increment() {
//        std::lock_guard<std::mutex> lock(mtx);
//        ++count;
//    }
//    
//    int get() const {
//        std::lock_guard<std::mutex> lock(mtx);
//        return count;
//    }
//};
//
//int main() {
//    CopyableCounter c1;
//    c1.increment();
//    c1.increment();
//    
//    CopyableCounter c2 = c1;  // 複製
//    
//    std::cout << "c1 = " << c1.get() << std::endl;  // 2
//    std::cout << "c2 = " << c2.get() << std::endl;  // 2
//    
//    c1.increment();
//    
//    std::cout << "c1 = " << c1.get() << std::endl;  // 3
//    std::cout << "c2 = " << c2.get() << std::endl;  // 2（獨立）
//    
//    return 0;
//}
//```
//
//---
//
//### 四、實作二：執行緒安全銀行帳戶
//
//更複雜的實際案例。
//
//```cpp
//// 檔案：lesson_5_5_bank_account.cpp
//// 說明：執行緒安全的銀行帳戶類別
//
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <vector>
//#include <string>
//#include <stdexcept>
//
//class BankAccount {
//private:
//    mutable std::mutex mtx;
//    std::string accountId;
//    double balance;
//    
//public:
//    BankAccount(const std::string& id, double initialBalance)
//        : accountId(id), balance(initialBalance) {
//        if (initialBalance < 0) {
//            throw std::invalid_argument("初始餘額不能為負");
//        }
//    }
//    
//    // 禁止複製
//    BankAccount(const BankAccount&) = delete;
//    BankAccount& operator=(const BankAccount&) = delete;
//    
//    // 允許移動
//    BankAccount(BankAccount&& other) noexcept {
//        std::lock_guard<std::mutex> lock(other.mtx);
//        accountId = std::move(other.accountId);
//        balance = other.balance;
//        other.balance = 0;
//    }
//    
//    // 存款
//    void deposit(double amount) {
//        if (amount <= 0) {
//            throw std::invalid_argument("存款金額必須為正");
//        }
//        
//        std::lock_guard<std::mutex> lock(mtx);
//        balance += amount;
//        std::cout << "[" << accountId << "] 存款 " << amount 
//                  << "，餘額：" << balance << std::endl;
//    }
//    
//    // 提款
//    bool withdraw(double amount) {
//        if (amount <= 0) {
//            throw std::invalid_argument("提款金額必須為正");
//        }
//        
//        std::lock_guard<std::mutex> lock(mtx);
//        
//        if (balance >= amount) {
//            balance -= amount;
//            std::cout << "[" << accountId << "] 提款 " << amount 
//                      << "，餘額：" << balance << std::endl;
//            return true;
//        }
//        
//        std::cout << "[" << accountId << "] 提款失敗：餘額不足" << std::endl;
//        return false;
//    }
//    
//    // 查詢餘額
//    double getBalance() const {
//        std::lock_guard<std::mutex> lock(mtx);
//        return balance;
//    }
//    
//    // 獲取帳戶 ID
//    std::string getId() const {
//        std::lock_guard<std::mutex> lock(mtx);
//        return accountId;
//    }
//    
//    // 轉帳（靜態方法，需要鎖定兩個帳戶）
//    static bool transfer(BankAccount& from, BankAccount& to, double amount) {
//        if (&from == &to) {
//            return false;  // 不能轉給自己
//        }
//        
//        if (amount <= 0) {
//            throw std::invalid_argument("轉帳金額必須為正");
//        }
//        
//        // 使用 std::scoped_lock 同時鎖定兩個帳戶，避免死結
//        std::scoped_lock lock(from.mtx, to.mtx);
//        
//        if (from.balance >= amount) {
//            from.balance -= amount;
//            to.balance += amount;
//            std::cout << "[轉帳] " << from.accountId << " → " << to.accountId 
//                      << "：" << amount << std::endl;
//            return true;
//        }
//        
//        std::cout << "[轉帳失敗] " << from.accountId << " 餘額不足" << std::endl;
//        return false;
//    }
//};
//
//// 模擬交易
//void simulateTransactions(BankAccount& account, int id) {
//    for (int i = 0; i < 5; ++i) {
//        account.deposit(100);
//        account.withdraw(50);
//    }
//}
//
//int main() {
//    BankAccount alice("Alice", 1000);
//    BankAccount bob("Bob", 500);
//    
//    std::cout << "=== 初始狀態 ===" << std::endl;
//    std::cout << "Alice: " << alice.getBalance() << std::endl;
//    std::cout << "Bob: " << bob.getBalance() << std::endl;
//    
//    std::cout << "\n=== 並行交易 ===" << std::endl;
//    
//    std::thread t1([&]() {
//        for (int i = 0; i < 3; ++i) {
//            BankAccount::transfer(alice, bob, 100);
//        }
//    });
//    
//    std::thread t2([&]() {
//        for (int i = 0; i < 3; ++i) {
//            BankAccount::transfer(bob, alice, 50);
//        }
//    });
//    
//    std::thread t3(simulateTransactions, std::ref(alice), 1);
//    std::thread t4(simulateTransactions, std::ref(bob), 2);
//    
//    t1.join();
//    t2.join();
//    t3.join();
//    t4.join();
//    
//    std::cout << "\n=== 最終狀態 ===" << std::endl;
//    std::cout << "Alice: " << alice.getBalance() << std::endl;
//    std::cout << "Bob: " << bob.getBalance() << std::endl;
//    std::cout << "總額: " << (alice.getBalance() + bob.getBalance()) << std::endl;
//    std::cout << "（初始總額為 1500，應保持不變）" << std::endl;
//    
//    return 0;
//}
//```
//
//---
//
//### 五、介面設計的陷阱
//
//#### 危險：返回內部資料的引用
//
//```cpp
//// 檔案：lesson_5_5_dangerous_interface.cpp
//// 說明：危險的介面設計
//
//#include <iostream>
//#include <mutex>
//#include <vector>
//
//class DangerousContainer {
//private:
//    std::mutex mtx;
//    std::vector<int> data;
//    
//public:
//    // 💀 危險！返回內部資料的引用
//    std::vector<int>& getData() {
//        std::lock_guard<std::mutex> lock(mtx);
//        return data;  // 鎖在這裡就釋放了！
//    }
//    
//    // 💀 危險！返回內部資料的指標
//    int* getFirst() {
//        std::lock_guard<std::mutex> lock(mtx);
//        if (!data.empty()) {
//            return &data[0];  // 返回後鎖就釋放了！
//        }
//        return nullptr;
//    }
//    
//    void add(int value) {
//        std::lock_guard<std::mutex> lock(mtx);
//        data.push_back(value);
//    }
//};
//
///*
// * 問題分析：
// * 
// * Thread A:                          Thread B:
// * auto& vec = container.getData();   
// *   // 鎖已釋放！                    container.add(100);
// * vec.push_back(1);                    // 同時修改！
// *   // 💀 競爭條件！
// */
//```
//
//#### 安全：複製資料或提供安全的操作
//
//```cpp
//// 檔案：lesson_5_5_safe_interface.cpp
//// 說明：安全的介面設計
//
//#include <iostream>
//#include <mutex>
//#include <vector>
//#include <functional>
//#include <algorithm>
//
//class SafeContainer {
//private:
//    mutable std::mutex mtx;
//    std::vector<int> data;
//    
//public:
//    // ✓ 安全：返回複本
//    std::vector<int> getData() const {
//        std::lock_guard<std::mutex> lock(mtx);
//        return data;  // 返回複本，不是引用
//    }
//    
//    // ✓ 安全：返回值的複本
//    int getAt(size_t index) const {
//        std::lock_guard<std::mutex> lock(mtx);
//        if (index < data.size()) {
//            return data[index];  // 返回值，不是引用
//        }
//        throw std::out_of_range("索引超出範圍");
//    }
//    
//    // ✓ 安全：提供操作而非資料存取
//    void add(int value) {
//        std::lock_guard<std::mutex> lock(mtx);
//        data.push_back(value);
//    }
//    
//    // ✓ 安全：使用回呼函式處理資料
//    void forEach(const std::function<void(int)>& func) const {
//        std::lock_guard<std::mutex> lock(mtx);
//        for (int value : data) {
//            func(value);
//        }
//    }
//    
//    // ✓ 安全：在鎖保護下執行操作
//    template<typename Func>
//    auto withLock(Func&& func) -> decltype(func(data)) {
//        std::lock_guard<std::mutex> lock(mtx);
//        return func(data);
//    }
//    
//    // ✓ 安全：批次操作
//    void addAll(const std::vector<int>& values) {
//        std::lock_guard<std::mutex> lock(mtx);
//        data.insert(data.end(), values.begin(), values.end());
//    }
//    
//    size_t size() const {
//        std::lock_guard<std::mutex> lock(mtx);
//        return data.size();
//    }
//    
//    bool empty() const {
//        std::lock_guard<std::mutex> lock(mtx);
//        return data.empty();
//    }
//};
//
//int main() {
//    SafeContainer container;
//    
//    container.add(10);
//    container.add(20);
//    container.add(30);
//    
//    // 使用 forEach
//    std::cout << "forEach: ";
//    container.forEach([](int v) {
//        std::cout << v << " ";
//    });
//    std::cout << std::endl;
//    
//    // 使用 withLock 進行複雜操作
//    int sum = container.withLock([](std::vector<int>& data) {
//        int total = 0;
//        for (int v : data) {
//            total += v;
//        }
//        return total;
//    });
//    std::cout << "Sum: " << sum << std::endl;
//    
//    // 獲取複本
//    auto copy = container.getData();
//    std::cout << "Copy size: " << copy.size() << std::endl;
//    
//    return 0;
//}
//```
//
//---
//
//### 六、實作三：執行緒安全的 Logger
//
//實際應用中常見的日誌系統。
//
//```cpp
//// 檔案：lesson_5_5_thread_safe_logger.cpp
//// 說明：執行緒安全的日誌記錄器
//
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <string>
//#include <sstream>
//#include <chrono>
//#include <iomanip>
//#include <vector>
//#include <fstream>
//
//class ThreadSafeLogger {
//public:
//    enum class Level {
//        DEBUG,
//        INFO,
//        WARNING,
//        ERROR
//    };
//    
//private:
//    mutable std::mutex mtx;
//    std::ostream& output;
//    Level minLevel;
//    bool includeTimestamp;
//    bool includeThreadId;
//    
//    std::string levelToString(Level level) const {
//        switch (level) {
//            case Level::DEBUG:   return "DEBUG";
//            case Level::INFO:    return "INFO ";
//            case Level::WARNING: return "WARN ";
//            case Level::ERROR:   return "ERROR";
//            default:             return "?????";
//        }
//    }
//    
//    std::string getTimestamp() const {
//        auto now = std::chrono::system_clock::now();
//        auto time = std::chrono::system_clock::to_time_t(now);
//        auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
//            now.time_since_epoch()) % 1000;
//        
//        std::ostringstream oss;
//        oss << std::put_time(std::localtime(&time), "%H:%M:%S");
//        oss << '.' << std::setfill('0') << std::setw(3) << ms.count();
//        return oss.str();
//    }
//    
//public:
//    ThreadSafeLogger(std::ostream& out = std::cout, 
//                     Level level = Level::DEBUG,
//                     bool timestamp = true,
//                     bool threadId = true)
//        : output(out)
//        , minLevel(level)
//        , includeTimestamp(timestamp)
//        , includeThreadId(threadId) {}
//    
//    // 禁止複製
//    ThreadSafeLogger(const ThreadSafeLogger&) = delete;
//    ThreadSafeLogger& operator=(const ThreadSafeLogger&) = delete;
//    
//    void setLevel(Level level) {
//        std::lock_guard<std::mutex> lock(mtx);
//        minLevel = level;
//    }
//    
//    void log(Level level, const std::string& message) {
//        if (level < minLevel) {
//            return;  // 過濾低級別日誌
//        }
//        
//        // 在鎖外準備訊息（減少臨界區段）
//        std::ostringstream oss;
//        
//        if (includeTimestamp) {
//            oss << "[" << getTimestamp() << "] ";
//        }
//        
//        oss << "[" << levelToString(level) << "] ";
//        
//        if (includeThreadId) {
//            oss << "[T:" << std::this_thread::get_id() << "] ";
//        }
//        
//        oss << message << std::endl;
//        
//        std::string formatted = oss.str();
//        
//        // 只在輸出時鎖定
//        std::lock_guard<std::mutex> lock(mtx);
//        output << formatted;
//        output.flush();
//    }
//    
//    void debug(const std::string& msg)   { log(Level::DEBUG, msg); }
//    void info(const std::string& msg)    { log(Level::INFO, msg); }
//    void warning(const std::string& msg) { log(Level::WARNING, msg); }
//    void error(const std::string& msg)   { log(Level::ERROR, msg); }
//};
//
//// 全域 Logger（實際專案中可能使用單例模式）
//ThreadSafeLogger logger;
//
//void worker(int id) {
//    logger.info("Worker " + std::to_string(id) + " 開始");
//    
//    for (int i = 0; i < 3; ++i) {
//        logger.debug("Worker " + std::to_string(id) + 
//                     " 執行任務 " + std::to_string(i));
//        std::this_thread::sleep_for(std::chrono::milliseconds(10));
//    }
//    
//    logger.info("Worker " + std::to_string(id) + " 結束");
//}
//
//int main() {
//    logger.info("=== 程式開始 ===");
//    
//    std::vector<std::thread> threads;
//    
//    for (int i = 1; i <= 3; ++i) {
//        threads.emplace_back(worker, i);
//    }
//    
//    for (auto& t : threads) {
//        t.join();
//    }
//    
//    logger.info("=== 程式結束 ===");
//    
//    return 0;
//}
//```
//
//#### 輸出範例
//
//```
//[14:32:15.123] [INFO ] [T:140001] === 程式開始 ===
//[14:32:15.124] [INFO ] [T:140002] Worker 1 開始
//[14:32:15.124] [INFO ] [T:140003] Worker 2 開始
//[14:32:15.124] [INFO ] [T:140004] Worker 3 開始
//[14:32:15.124] [DEBUG] [T:140002] Worker 1 執行任務 0
//[14:32:15.124] [DEBUG] [T:140003] Worker 2 執行任務 0
//[14:32:15.125] [DEBUG] [T:140004] Worker 3 執行任務 0
//...
//[14:32:15.156] [INFO ] [T:140002] Worker 1 結束
//[14:32:15.157] [INFO ] [T:140003] Worker 2 結束
//[14:32:15.157] [INFO ] [T:140004] Worker 3 結束
//[14:32:15.158] [INFO ] [T:140001] === 程式結束 ===
//```
//
//---
//
//### 七、實作四：執行緒安全的設定管理器
//
//```cpp
//// 檔案：lesson_5_5_config_manager.cpp
//// 說明：執行緒安全的設定管理器
//
//#include <iostream>
//#include <thread>
//#include <mutex>
//#include <map>
//#include <string>
//#include <optional>
//#include <vector>
//
//class ConfigManager {
//private:
//    mutable std::mutex mtx;
//    std::map<std::string, std::string> config;
//    
//public:
//    // 設定值
//    void set(const std::string& key, const std::string& value) {
//        std::lock_guard<std::mutex> lock(mtx);
//        config[key] = value;
//    }
//    
//    // 獲取值（使用 optional 表示可能不存在）
//    std::optional<std::string> get(const std::string& key) const {
//        std::lock_guard<std::mutex> lock(mtx);
//        auto it = config.find(key);
//        if (it != config.end()) {
//            return it->second;
//        }
//        return std::nullopt;
//    }
//    
//    // 獲取值，若不存在則返回預設值
//    std::string getOrDefault(const std::string& key, 
//                              const std::string& defaultValue) const {
//        std::lock_guard<std::mutex> lock(mtx);
//        auto it = config.find(key);
//        if (it != config.end()) {
//            return it->second;
//        }
//        return defaultValue;
//    }
//    
//    // 檢查是否存在
//    bool has(const std::string& key) const {
//        std::lock_guard<std::mutex> lock(mtx);
//        return config.find(key) != config.end();
//    }
//    
//    // 刪除
//    bool remove(const std::string& key) {
//        std::lock_guard<std::mutex> lock(mtx);
//        return config.erase(key) > 0;
//    }
//    
//    // 獲取所有 key
//    std::vector<std::string> keys() const {
//        std::lock_guard<std::mutex> lock(mtx);
//        std::vector<std::string> result;
//        result.reserve(config.size());
//        for (const auto& [key, value] : config) {
//            result.push_back(key);
//        }
//        return result;
//    }
//    
//    // 批次設定
//    void setAll(const std::map<std::string, std::string>& values) {
//        std::lock_guard<std::mutex> lock(mtx);
//        for (const auto& [key, value] : values) {
//            config[key] = value;
//        }
//    }
//    
//    // 原子性的「若不存在則設定」
//    bool setIfAbsent(const std::string& key, const std::string& value) {
//        std::lock_guard<std::mutex> lock(mtx);
//        if (config.find(key) == config.end()) {
//            config[key] = value;
//            return true;
//        }
//        return false;
//    }
//    
//    // 原子性的「比較並交換」
//    bool compareAndSet(const std::string& key, 
//                       const std::string& expected,
//                       const std::string& newValue) {
//        std::lock_guard<std::mutex> lock(mtx);
//        auto it = config.find(key);
//        if (it != config.end() && it->second == expected) {
//            it->second = newValue;
//            return true;
//        }
//        return false;
//    }
//    
//    size_t size() const {
//        std::lock_guard<std::mutex> lock(mtx);
//        return config.size();
//    }
//};
//
//// 測試
//void configWriter(ConfigManager& cfg, int id) {
//    for (int i = 0; i < 5; ++i) {
//        std::string key = "key_" + std::to_string(i);
//        std::string value = "writer" + std::to_string(id) + "_value" + std::to_string(i);
//        cfg.set(key, value);
//        std::this_thread::sleep_for(std::chrono::milliseconds(1));
//    }
//}
//
//void configReader(ConfigManager& cfg, int id) {
//    for (int i = 0; i < 5; ++i) {
//        std::string key = "key_" + std::to_string(i);
//        auto value = cfg.get(key);
//        if (value) {
//            std::cout << "Reader " << id << ": " << key << " = " << *value << std::endl;
//        }
//        std::this_thread::sleep_for(std::chrono::milliseconds(2));
//    }
//}
//
//int main() {
//    ConfigManager config;
//    
//    // 初始設定
//    config.set("app.name", "MyApp");
//    config.set("app.version", "1.0.0");
//    
//    std::vector<std::thread> threads;
//    
//    // 啟動寫入者
//    threads.emplace_back(configWriter, std::ref(config), 1);
//    threads.emplace_back(configWriter, std::ref(config), 2);
//    
//    // 啟動讀取者
//    threads.emplace_back(configReader, std::ref(config), 1);
//    threads.emplace_back(configReader, std::ref(config), 2);
//    
//    for (auto& t : threads) {
//        t.join();
//    }
//    
//    std::cout << "\n=== 最終設定 ===" << std::endl;
//    for (const auto& key : config.keys()) {
//        std::cout << key << " = " << config.getOrDefault(key, "") << std::endl;
//    }
//    
//    return 0;
//}
//```
//
//---
//
//### 八、設計模式：將鎖封裝在類別中
//
//```
//┌─────────────────────────────────────────────────────────────┐
//│              執行緒安全類別設計總結                          │
//├─────────────────────────────────────────────────────────────┤
//│                                                             │
//│  class ThreadSafeClass {                                    │
//│  private:                                                   │
//│      mutable std::mutex mtx;   // 1. 鎖是私有的             │
//│      Data data;                // 2. 資料是私有的           │
//│                                                             │
//│  public:                                                    │
//│      // 3. 禁止複製                                         │
//│      ThreadSafeClass(const ThreadSafeClass&) = delete;      │
//│      ThreadSafeClass& operator=(const ThreadSafeClass&) = delete;  │
//│                                                             │
//│      // 4. 所有公開方法都是原子的                           │
//│      void operation() {                                     │
//│          std::lock_guard<std::mutex> lock(mtx);             │
//│          // 操作 data                                       │
//│      }                                                      │
//│                                                             │
//│      // 5. 不返回內部資料的引用/指標                        │
//│      Data getData() const {                                 │
//│          std::lock_guard<std::mutex> lock(mtx);             │
//│          return data;  // 返回複本                          │
//│      }                                                      │
//│  };                                                         │
//│                                                             │
//└─────────────────────────────────────────────────────────────┘
//```
//
//---
//
//### 九、本課重點回顧
//
//1. **封裝原則**：鎖和資料放在同一類別，外部無法直接存取
//2. **禁止複製**：含有 mutex 的類別通常應禁止複製
//3. **mutable mutex**：允許在 const 方法中使用鎖
//4. **安全介面**：不返回內部資料的引用或指標
//5. **原子操作**：檢查和操作應在同一臨界區段
//6. **減少臨界區段**：只鎖定必要的部分
//7. **使用 scoped_lock**：同時鎖定多個互斥鎖時避免死結
//
//---
//
//### 下一課預告
//
//在 **課程 5.6：互斥鎖的效能考量** 中，我們將學習：
//- 鎖的開銷測量
//- 粗粒度鎖 vs 細粒度鎖
//- 鎖競爭的影響
//- 效能優化策略
//
//這是第五階段的最後一課，將為進入 RAII 鎖管理器做好準備！
//
//---
//
//準備好繼續嗎？
//*/
//



// 檔案：lesson_5_5_config_manager.cpp
// 說明：執行緒安全的設定管理器

#include <iostream>
#include <thread>
#include <mutex>
#include <map>
#include <string>
#include <optional>
#include <vector>

class ConfigManager {
private:
    mutable std::mutex mtx;
    std::map<std::string, std::string> config;
    
public:
    // 設定值
    void set(const std::string& key, const std::string& value) {
        std::lock_guard<std::mutex> lock(mtx);
        config[key] = value;
    }
    
    // 獲取值（使用 optional 表示可能不存在）
    std::optional<std::string> get(const std::string& key) const {
        std::lock_guard<std::mutex> lock(mtx);
        auto it = config.find(key);
        if (it != config.end()) {
            return it->second;
        }
        return std::nullopt;
    }
    
    // 獲取值，若不存在則返回預設值
    std::string getOrDefault(const std::string& key, 
                              const std::string& defaultValue) const {
        std::lock_guard<std::mutex> lock(mtx);
        auto it = config.find(key);
        if (it != config.end()) {
            return it->second;
        }
        return defaultValue;
    }
    
    // 檢查是否存在
    bool has(const std::string& key) const {
        std::lock_guard<std::mutex> lock(mtx);
        return config.find(key) != config.end();
    }
    
    // 刪除
    bool remove(const std::string& key) {
        std::lock_guard<std::mutex> lock(mtx);
        return config.erase(key) > 0;
    }
    
    // 獲取所有 key
    std::vector<std::string> keys() const {
        std::lock_guard<std::mutex> lock(mtx);
        std::vector<std::string> result;
        result.reserve(config.size());
        for (const auto& [key, value] : config) {
            result.push_back(key);
        }
        return result;
    }
    
    // 批次設定
    void setAll(const std::map<std::string, std::string>& values) {
        std::lock_guard<std::mutex> lock(mtx);
        for (const auto& [key, value] : values) {
            config[key] = value;
        }
    }
    
    // 原子性的「若不存在則設定」
    bool setIfAbsent(const std::string& key, const std::string& value) {
        std::lock_guard<std::mutex> lock(mtx);
        if (config.find(key) == config.end()) {
            config[key] = value;
            return true;
        }
        return false;
    }
    
    // 原子性的「比較並交換」
    bool compareAndSet(const std::string& key, 
                       const std::string& expected,
                       const std::string& newValue) {
        std::lock_guard<std::mutex> lock(mtx);
        auto it = config.find(key);
        if (it != config.end() && it->second == expected) {
            it->second = newValue;
            return true;
        }
        return false;
    }
    
    size_t size() const {
        std::lock_guard<std::mutex> lock(mtx);
        return config.size();
    }
};

// 測試
void configWriter(ConfigManager& cfg, int id) {
    for (int i = 0; i < 5; ++i) {
        std::string key = "key_" + std::to_string(i);
        std::string value = "writer" + std::to_string(id) + "_value" + std::to_string(i);
        cfg.set(key, value);
        std::this_thread::sleep_for(std::chrono::milliseconds(1));
    }
}

void configReader(ConfigManager& cfg, int id) {
    for (int i = 0; i < 5; ++i) {
        std::string key = "key_" + std::to_string(i);
        auto value = cfg.get(key);
        if (value) {
            std::cout << "Reader " << id << ": " << key << " = " << *value << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
    }
}

int main() {
    ConfigManager config;
    
    // 初始設定
    config.set("app.name", "MyApp");
    config.set("app.version", "1.0.0");
    
    std::vector<std::thread> threads;
    
    // 啟動寫入者
    threads.emplace_back(configWriter, std::ref(config), 1);
    threads.emplace_back(configWriter, std::ref(config), 2);
    
    // 啟動讀取者
    threads.emplace_back(configReader, std::ref(config), 1);
    threads.emplace_back(configReader, std::ref(config), 2);
    
    for (auto& t : threads) {
        t.join();
    }
    
    std::cout << "\n=== 最終設定 ===" << std::endl;
    for (const auto& key : config.keys()) {
        std::cout << key << " = " << config.getOrDefault(key, "") << std::endl;
    }
    
    return 0;
}
