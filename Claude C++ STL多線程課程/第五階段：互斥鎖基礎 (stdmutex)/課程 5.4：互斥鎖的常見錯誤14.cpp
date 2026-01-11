/*
# 第五階段：互斥鎖基礎 (std::mutex)

## 課程 5.4：互斥鎖的常見錯誤

---

### 引言

互斥鎖看似簡單，只有 `lock()` 和 `unlock()` 兩個主要操作，但實際開發中卻充滿陷阱。本課將系統性地分析最常見的錯誤，並學習如何避免它們。

---

### 一、錯誤總覽

```
┌─────────────────────────────────────────────────────────────┐
│                  互斥鎖常見錯誤                              │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  1. 忘記解鎖（Forgetting to Unlock）                        │
│     → 其他執行緒永遠等待                                    │
│                                                             │
│  2. 重複鎖定（Double Locking）                              │
│     → 同一執行緒對同一 mutex 呼叫兩次 lock()                │
│                                                             │
│  3. 解鎖未鎖定的互斥鎖（Unlocking Unowned Mutex）           │
│     → 未定義行為                                            │
│                                                             │
│  4. 例外導致未解鎖（Exception Without Unlock）              │
│     → 例外拋出後 unlock() 未執行                            │
│                                                             │
│  5. 鎖定順序不一致（Inconsistent Lock Ordering）            │
│     → 導致死結                                              │
│                                                             │
│  6. 保護範圍錯誤（Incorrect Protection Scope）              │
│     → 臨界區段設計不當                                      │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

### 二、錯誤 1：忘記解鎖

這是最常見也最危險的錯誤。

#### 錯誤範例

```cpp
// 檔案：lesson_5_4_forget_unlock.cpp
// 說明：忘記解鎖的錯誤示範

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mtx;
int counter = 0;

void buggyIncrement() {
    mtx.lock();
    ++counter;
    std::cout << "Counter = " << counter << std::endl;
    
    // 💀 忘記 unlock()！
    // mtx.unlock();
}

int main() {
    std::thread t1(buggyIncrement);
    t1.join();
    
    std::cout << "執行緒 1 完成" << std::endl;
    
    std::thread t2(buggyIncrement);  // 💀 永遠卡住！
    
    // 設定超時檢測
    std::this_thread::sleep_for(std::chrono::seconds(2));
    std::cout << "程式卡住了！（這行可能不會執行）" << std::endl;
    
    t2.join();  // 永遠不會返回
    
    return 0;
}
```

#### 更隱蔽的情況：早期返回

```cpp
// 檔案：lesson_5_4_early_return.cpp
// 說明：早期返回導致忘記解鎖

#include <iostream>
#include <mutex>

std::mutex mtx;

int getValue(int input) {
    mtx.lock();
    
    if (input < 0) {
        std::cout << "無效輸入" << std::endl;
        return -1;  // 💀 提前返回，沒有 unlock！
    }
    
    if (input == 0) {
        std::cout << "零值" << std::endl;
        return 0;   // 💀 又一個提前返回！
    }
    
    int result = input * 2;
    mtx.unlock();
    return result;
}

int main() {
    std::cout << getValue(10) << std::endl;   // OK
    std::cout << getValue(-5) << std::endl;   // 💀 鎖沒釋放
    std::cout << getValue(20) << std::endl;   // 💀 永遠卡住
    
    return 0;
}
```

#### 正確做法：使用 RAII

```cpp
// 檔案：lesson_5_4_raii_fix.cpp
// 說明：使用 lock_guard 自動管理鎖

#include <iostream>
#include <mutex>

std::mutex mtx;

int getValueSafe(int input) {
    std::lock_guard<std::mutex> lock(mtx);  // ✓ RAII
    
    if (input < 0) {
        std::cout << "無效輸入" << std::endl;
        return -1;  // ✓ lock_guard 解構時自動 unlock
    }
    
    if (input == 0) {
        std::cout << "零值" << std::endl;
        return 0;   // ✓ 同樣會自動 unlock
    }
    
    return input * 2;
}  // ✓ 函式結束，lock_guard 解構，自動 unlock

int main() {
    std::cout << getValueSafe(10) << std::endl;
    std::cout << getValueSafe(-5) << std::endl;
    std::cout << getValueSafe(20) << std::endl;  // ✓ 正常執行
    
    return 0;
}
```

---

### 三、錯誤 2：重複鎖定

同一執行緒對同一個 `std::mutex` 呼叫兩次 `lock()`。

#### 錯誤範例

```cpp
// 檔案：lesson_5_4_double_lock.cpp
// 說明：重複鎖定的錯誤

#include <iostream>
#include <mutex>

std::mutex mtx;

void outerFunction();
void innerFunction();

void innerFunction() {
    mtx.lock();  // 💀 已經被 outerFunction 鎖定了！
    std::cout << "Inner function" << std::endl;
    mtx.unlock();
}

void outerFunction() {
    mtx.lock();
    std::cout << "Outer function" << std::endl;
    
    innerFunction();  // 💀 呼叫另一個也需要鎖的函式
    
    mtx.unlock();
}

int main() {
    outerFunction();  // 💀 死結！（或未定義行為）
    return 0;
}
```

```
┌─────────────────────────────────────────────────────────────┐
│                   重複鎖定的後果                            │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  std::mutex：未定義行為（通常是死結）                        │
│                                                             │
│  outerFunction()                                            │
│       │                                                     │
│       ▼                                                     │
│  mtx.lock()  ← 成功                                         │
│       │                                                     │
│       ▼                                                     │
│  innerFunction()                                            │
│       │                                                     │
│       ▼                                                     │
│  mtx.lock()  ← 💀 同一執行緒再次嘗試鎖定                     │
│       │          已經持有的鎖                               │
│       ▼                                                     │
│  永遠等待自己釋放鎖（死結）                                  │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

#### 解決方案 1：使用 std::recursive_mutex

```cpp
// 檔案：lesson_5_4_recursive_mutex.cpp
// 說明：使用遞迴互斥鎖解決重複鎖定

#include <iostream>
#include <mutex>

std::recursive_mutex rmtx;  // ✓ 遞迴互斥鎖

void innerFunction() {
    rmtx.lock();  // ✓ 同一執行緒可以再次鎖定
    std::cout << "Inner function" << std::endl;
    rmtx.unlock();
}

void outerFunction() {
    rmtx.lock();
    std::cout << "Outer function" << std::endl;
    
    innerFunction();  // ✓ 正常運作
    
    rmtx.unlock();
}

int main() {
    outerFunction();  // ✓ 正常執行
    std::cout << "完成" << std::endl;
    return 0;
}
```

#### 解決方案 2：重構程式碼（更好的做法）

```cpp
// 檔案：lesson_5_4_refactor.cpp
// 說明：透過重構避免重複鎖定

#include <iostream>
#include <mutex>

std::mutex mtx;

// 內部實作（假設鎖已被持有，不加鎖）
void innerFunctionImpl() {
    std::cout << "Inner function" << std::endl;
}

// 公開介面（需要鎖）
void innerFunction() {
    std::lock_guard<std::mutex> lock(mtx);
    innerFunctionImpl();
}

void outerFunction() {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << "Outer function" << std::endl;
    
    innerFunctionImpl();  // ✓ 呼叫不加鎖的版本
}

int main() {
    outerFunction();
    std::cout << "完成" << std::endl;
    return 0;
}
```

---

### 四、錯誤 3：解鎖未鎖定的互斥鎖

```cpp
// 檔案：lesson_5_4_unlock_unowned.cpp
// 說明：解鎖未鎖定或不屬於自己的互斥鎖

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;

void wrongUnlock() {
    // 沒有 lock()
    mtx.unlock();  // 💀 未定義行為！
}

void wrongThread() {
    mtx.lock();
    
    std::thread t([&]() {
        mtx.unlock();  // 💀 在不同執行緒解鎖！未定義行為！
    });
    t.join();
}

int main() {
    // 這些都是錯誤的用法
    // wrongUnlock();
    // wrongThread();
    
    std::cout << "這些函式都有問題，不要這樣做！" << std::endl;
    
    return 0;
}
```

```
┌─────────────────────────────────────────────────────────────┐
│              互斥鎖的所有權規則                              │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  規則 1：誰鎖定，誰解鎖                                      │
│  ────────────────────────                                   │
│  執行緒 A 呼叫 lock()，只有執行緒 A 能呼叫 unlock()          │
│                                                             │
│  規則 2：先鎖定，後解鎖                                      │
│  ────────────────────────                                   │
│  必須先成功呼叫 lock() 或 try_lock()，才能呼叫 unlock()      │
│                                                             │
│  規則 3：配對原則                                            │
│  ────────────────                                           │
│  每個成功的 lock()/try_lock() 必須有且只有一個 unlock()      │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

### 五、錯誤 4：例外導致未解鎖

這是 C++ 特有的問題，也是 RAII 如此重要的原因。

#### 錯誤範例

```cpp
// 檔案：lesson_5_4_exception_unsafe.cpp
// 說明：例外導致 unlock 未執行

#include <iostream>
#include <mutex>
#include <stdexcept>

std::mutex mtx;

void riskyOperation(int value) {
    mtx.lock();
    
    std::cout << "開始處理 " << value << std::endl;
    
    if (value < 0) {
        throw std::invalid_argument("值不能為負數");  // 💀 例外拋出
        // unlock() 永遠不會執行！
    }
    
    std::cout << "處理完成" << std::endl;
    mtx.unlock();
}

int main() {
    try {
        riskyOperation(10);   // OK
        riskyOperation(-5);   // 💀 拋出例外，鎖沒釋放
    } catch (const std::exception& e) {
        std::cout << "捕獲例外：" << e.what() << std::endl;
    }
    
    // 此時 mtx 仍處於鎖定狀態！
    std::cout << "嘗試再次操作..." << std::endl;
    riskyOperation(20);  // 💀 死結！
    
    return 0;
}
```

#### 正確做法：使用 RAII

```cpp
// 檔案：lesson_5_4_exception_safe.cpp
// 說明：使用 RAII 確保例外安全

#include <iostream>
#include <mutex>
#include <stdexcept>

std::mutex mtx;

void safeOperation(int value) {
    std::lock_guard<std::mutex> lock(mtx);  // ✓ RAII
    
    std::cout << "開始處理 " << value << std::endl;
    
    if (value < 0) {
        throw std::invalid_argument("值不能為負數");
        // ✓ 例外拋出時，lock_guard 解構，自動 unlock
    }
    
    std::cout << "處理完成" << std::endl;
}  // ✓ 正常返回時也會自動 unlock

int main() {
    try {
        safeOperation(10);
        safeOperation(-5);  // 拋出例外
    } catch (const std::exception& e) {
        std::cout << "捕獲例外：" << e.what() << std::endl;
    }
    
    // ✓ 鎖已被正確釋放
    std::cout << "嘗試再次操作..." << std::endl;
    safeOperation(20);  // ✓ 正常執行
    
    return 0;
}
```

#### 輸出

```
開始處理 10
處理完成
開始處理 -5
捕獲例外：值不能為負數
嘗試再次操作...
開始處理 20
處理完成
```

---

### 六、錯誤 5：鎖定順序不一致

這會導致死結，我們在第八階段會詳細討論。

```cpp
// 檔案：lesson_5_4_lock_order.cpp
// 說明：鎖定順序不一致導致死結

#include <iostream>
#include <thread>
#include <mutex>

std::mutex mutexA;
std::mutex mutexB;

void thread1() {
    mutexA.lock();
    std::cout << "Thread 1: locked A" << std::endl;
    
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    
    mutexB.lock();  // 💀 等待 Thread 2 釋放 B
    std::cout << "Thread 1: locked B" << std::endl;
    
    mutexB.unlock();
    mutexA.unlock();
}

void thread2() {
    mutexB.lock();  // ← 順序相反！
    std::cout << "Thread 2: locked B" << std::endl;
    
    std::this_thread::sleep_for(std::chrono::milliseconds(10));
    
    mutexA.lock();  // 💀 等待 Thread 1 釋放 A
    std::cout << "Thread 2: locked A" << std::endl;
    
    mutexA.unlock();
    mutexB.unlock();
}

int main() {
    std::thread t1(thread1);
    std::thread t2(thread2);
    
    t1.join();
    t2.join();
    
    // 💀 程式永遠不會到達這裡
    std::cout << "完成" << std::endl;
    
    return 0;
}
```

```
┌─────────────────────────────────────────────────────────────┐
│                    死結形成過程                              │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  時間   Thread 1              Thread 2                      │
│  ────   ────────              ────────                      │
│   T1    lock(A) ✓                                           │
│   T2                          lock(B) ✓                     │
│   T3    lock(B) 等待...                                     │
│   T4                          lock(A) 等待...               │
│                                                             │
│         Thread 1 等待 B       Thread 2 等待 A               │
│         B 被 Thread 2 持有    A 被 Thread 1 持有            │
│                                                             │
│                    💀 死結！                                 │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

#### 解決方案：統一鎖定順序

```cpp
// 總是先鎖 A，再鎖 B
void thread1() {
    std::lock_guard<std::mutex> lockA(mutexA);
    std::lock_guard<std::mutex> lockB(mutexB);
    // 工作...
}

void thread2() {
    std::lock_guard<std::mutex> lockA(mutexA);  // ✓ 同樣的順序
    std::lock_guard<std::mutex> lockB(mutexB);
    // 工作...
}
```

---

### 七、錯誤 6：保護範圍錯誤

#### 錯誤 6a：保護範圍太小

```cpp
// 檔案：lesson_5_4_scope_too_small.cpp
// 說明：保護範圍太小，仍有競爭條件

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

std::mutex mtx;
std::vector<int> data;

void unsafeAppend(int value) {
    // 錯誤：檢查和操作分開保護
    
    mtx.lock();
    bool shouldAppend = (data.size() < 10);
    mtx.unlock();
    
    // 💀 此時其他執行緒可能已經改變了 data.size()！
    
    if (shouldAppend) {
        mtx.lock();
        data.push_back(value);  // 💀 可能超過限制！
        mtx.unlock();
    }
}

void safeAppend(int value) {
    // 正確：整個操作在同一個臨界區段
    std::lock_guard<std::mutex> lock(mtx);
    
    if (data.size() < 10) {
        data.push_back(value);  // ✓ 安全
    }
}
```

#### 錯誤 6b：保護範圍太大

```cpp
// 檔案：lesson_5_4_scope_too_large.cpp
// 說明：保護範圍太大，降低效能

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex mtx;
int result = 0;

void inefficientWork(int input) {
    std::lock_guard<std::mutex> lock(mtx);  // 💀 整個函式都被鎖住
    
    // 這部分不需要鎖
    int temp = input * input;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));  // 模擬耗時計算
    temp += input;
    
    // 只有這裡需要鎖
    result += temp;
}

void efficientWork(int input) {
    // 不需要鎖的部分
    int temp = input * input;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
    temp += input;
    
    // 只鎖必要的部分
    {
        std::lock_guard<std::mutex> lock(mtx);
        result += temp;  // ✓ 最小化臨界區段
    }
}

int main() {
    auto start = std::chrono::steady_clock::now();
    
    std::thread t1(inefficientWork, 10);
    std::thread t2(inefficientWork, 20);
    t1.join();
    t2.join();
    
    auto mid = std::chrono::steady_clock::now();
    
    result = 0;
    
    std::thread t3(efficientWork, 10);
    std::thread t4(efficientWork, 20);
    t3.join();
    t4.join();
    
    auto end = std::chrono::steady_clock::now();
    
    auto inefficient_time = std::chrono::duration_cast<std::chrono::milliseconds>(mid - start);
    auto efficient_time = std::chrono::duration_cast<std::chrono::milliseconds>(end - mid);
    
    std::cout << "低效版本：" << inefficient_time.count() << " ms" << std::endl;
    std::cout << "高效版本：" << efficient_time.count() << " ms" << std::endl;
    
    return 0;
}
```

#### 輸出

```
低效版本：200 ms   （串行執行）
高效版本：100 ms   （並行執行）
```

---

### 八、錯誤檢查清單

```
┌─────────────────────────────────────────────────────────────┐
│               互斥鎖使用檢查清單                             │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  □ 每個 lock() 都有對應的 unlock()                          │
│                                                             │
│  □ 所有提前返回的路徑都會釋放鎖                              │
│    → 使用 RAII（lock_guard/unique_lock）                    │
│                                                             │
│  □ 例外拋出時鎖會被正確釋放                                  │
│    → 使用 RAII                                              │
│                                                             │
│  □ 沒有在同一執行緒重複鎖定 std::mutex                      │
│    → 如需要，使用 recursive_mutex 或重構                    │
│                                                             │
│  □ 只在持有鎖的執行緒呼叫 unlock()                          │
│                                                             │
│  □ 多個互斥鎖的鎖定順序一致                                  │
│    → 或使用 std::lock() / std::scoped_lock                  │
│                                                             │
│  □ 臨界區段盡可能小                                          │
│    → 只包含必要的共享資料存取                                │
│                                                             │
│  □ 臨界區段內沒有阻塞操作                                    │
│    → 避免 I/O、sleep、等待其他資源                          │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

### 九、最佳實踐總結

```cpp
// 檔案：lesson_5_4_best_practices.cpp
// 說明：互斥鎖最佳實踐範例

#include <iostream>
#include <mutex>
#include <vector>
#include <stdexcept>

class SafeCounter {
private:
    mutable std::mutex mtx;  // mutable 允許在 const 方法中鎖定
    int count = 0;
    
public:
    // ✓ 最佳實踐 1：使用 RAII
    void increment() {
        std::lock_guard<std::mutex> lock(mtx);
        ++count;
    }
    
    // ✓ 最佳實踐 2：最小化臨界區段
    int getAndReset() {
        int result;
        {
            std::lock_guard<std::mutex> lock(mtx);
            result = count;
            count = 0;
        }  // 鎖在這裡釋放
        
        // 後續處理不需要鎖
        return result;
    }
    
    // ✓ 最佳實踐 3：const 方法也要保護
    int get() const {
        std::lock_guard<std::mutex> lock(mtx);
        return count;
    }
    
    // ✓ 最佳實踐 4：例外安全
    void riskyOperation(int value) {
        std::lock_guard<std::mutex> lock(mtx);
        
        if (value < 0) {
            throw std::invalid_argument("負值");
            // 例外拋出時 lock_guard 自動解鎖
        }
        
        count += value;
    }
};

int main() {
    SafeCounter counter;
    
    counter.increment();
    counter.increment();
    std::cout << "Count: " << counter.get() << std::endl;
    
    try {
        counter.riskyOperation(-1);
    } catch (...) {
        std::cout << "例外被捕獲，鎖已正確釋放" << std::endl;
    }
    
    counter.increment();  // 正常運作
    std::cout << "Final count: " << counter.get() << std::endl;
    
    return 0;
}
```

---

### 十、本課重點回顧

| 錯誤類型 | 後果 | 解決方案 |
|----------|------|----------|
| 忘記解鎖 | 其他執行緒永遠等待 | 使用 RAII |
| 重複鎖定 | 死結/未定義行為 | recursive_mutex 或重構 |
| 解鎖未持有的鎖 | 未定義行為 | 遵守所有權規則 |
| 例外導致未解鎖 | 鎖洩漏 | 使用 RAII |
| 鎖定順序不一致 | 死結 | 統一順序或 std::lock |
| 保護範圍錯誤 | 競爭條件或效能差 | 仔細設計臨界區段 |

**核心建議：永遠使用 RAII（lock_guard 或 unique_lock）來管理鎖！**

---

### 下一課預告

在 **課程 5.5：保護共享資料實作** 中，我們將：
- 實作一個完整的執行緒安全計數器類別
- 實作一個執行緒安全的銀行帳戶類別
- 學習如何設計執行緒安全的介面

---

準備好繼續嗎？
*/



// 檔案：lesson_5_4_best_practices.cpp
// 說明：互斥鎖最佳實踐範例

#include <iostream>
#include <mutex>
#include <vector>
#include <stdexcept>

class SafeCounter {
private:
    mutable std::mutex mtx;  // mutable 允許在 const 方法中鎖定
    int count = 0;
    
public:
    // ✓ 最佳實踐 1：使用 RAII
    void increment() {
        std::lock_guard<std::mutex> lock(mtx);
        ++count;
    }
    
    // ✓ 最佳實踐 2：最小化臨界區段
    int getAndReset() {
        int result;
        {
            std::lock_guard<std::mutex> lock(mtx);
            result = count;
            count = 0;
        }  // 鎖在這裡釋放
        
        // 後續處理不需要鎖
        return result;
    }
    
    // ✓ 最佳實踐 3：const 方法也要保護
    int get() const {
        std::lock_guard<std::mutex> lock(mtx);
        return count;
    }
    
    // ✓ 最佳實踐 4：例外安全
    void riskyOperation(int value) {
        std::lock_guard<std::mutex> lock(mtx);
        
        if (value < 0) {
            throw std::invalid_argument("負值");
            // 例外拋出時 lock_guard 自動解鎖
        }
        
        count += value;
    }
};

int main() {
    SafeCounter counter;
    
    counter.increment();
    counter.increment();
    std::cout << "Count: " << counter.get() << std::endl;
    
    try {
        counter.riskyOperation(-1);
    } catch (...) {
        std::cout << "例外被捕獲，鎖已正確釋放" << std::endl;
    }
    
    counter.increment();  // 正常運作
    std::cout << "Final count: " << counter.get() << std::endl;
    
    return 0;
}
