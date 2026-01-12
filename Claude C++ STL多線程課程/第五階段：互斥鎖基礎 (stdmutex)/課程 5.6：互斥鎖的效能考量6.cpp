/*
# 第五階段：互斥鎖基礎 (std::mutex)

## 課程 5.6：互斥鎖的效能考量

---

### 引言

互斥鎖是保護共享資料的利器，但它不是免費的。濫用鎖會導致程式效能急劇下降，甚至比單執行緒還慢。本課將深入探討鎖的效能特性，並學習如何在正確性與效能之間取得平衡。

---

### 一、鎖的開銷來源

```
┌─────────────────────────────────────────────────────────────┐
│                    鎖的開銷來源                              │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  1. 原子操作開銷                                            │
│     → CAS、記憶體屏障等指令比普通指令慢                      │
│     → 約 10-50 個 CPU 週期                                  │
│                                                             │
│  2. 快取一致性開銷                                          │
│     → 鎖變數在多核心間同步                                  │
│     → 快取行失效與重新載入                                  │
│     → 約 100-500 個 CPU 週期                                │
│                                                             │
│  3. 競爭開銷                                                │
│     → 自旋等待消耗 CPU                                      │
│     → 執行緒睡眠與喚醒（系統呼叫）                          │
│     → 上下文切換：1000-10000+ 個 CPU 週期                   │
│                                                             │
│  4. 序列化開銷                                              │
│     → 臨界區段只能串行執行                                  │
│     → 並行度降低                                            │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

### 二、測量鎖的基本開銷

```cpp
// 檔案：lesson_5_6_lock_overhead.cpp
// 說明：測量互斥鎖的基本開銷

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <iomanip>

std::mutex mtx;

// 無鎖操作
void noLockOperation(long long& counter, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        ++counter;
    }
}

// 有鎖操作
void withLockOperation(long long& counter, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        ++counter;
    }
}

// 計時函式
template<typename Func>
double measureTime(Func&& func) {
    auto start = std::chrono::high_resolution_clock::now();
    func();
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration<double, std::nano>(end - start).count();
}

int main() {
    const int iterations = 1000000;
    long long counter = 0;
    
    std::cout << "=== 互斥鎖開銷測量 ===" << std::endl;
    std::cout << "迭代次數：" << iterations << std::endl << std::endl;
    
    // 測量無鎖操作
    counter = 0;
    double noLockTime = measureTime([&]() {
        noLockOperation(counter, iterations);
    });
    
    // 測量有鎖操作（單執行緒，無競爭）
    counter = 0;
    double withLockTime = measureTime([&]() {
        withLockOperation(counter, iterations);
    });
    
    double lockOverhead = (withLockTime - noLockTime) / iterations;
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "無鎖操作總時間：" << noLockTime / 1e6 << " ms" << std::endl;
    std::cout << "有鎖操作總時間：" << withLockTime / 1e6 << " ms" << std::endl;
    std::cout << "每次鎖操作開銷：" << lockOverhead << " ns" << std::endl;
    std::cout << "效能比率：" << withLockTime / noLockTime << "x 慢" << std::endl;
    
    return 0;
}
```

#### 典型輸出

```
=== 互斥鎖開銷測量 ===
迭代次數：1000000

無鎖操作總時間：2.15 ms
有鎖操作總時間：45.32 ms
每次鎖操作開銷：43.17 ns
效能比率：21.08x 慢
```

---

### 三、競爭對效能的影響

```cpp
// 檔案：lesson_5_6_contention.cpp
// 說明：測量鎖競爭對效能的影響

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <iomanip>

std::mutex mtx;
long long sharedCounter = 0;

void incrementWithLock(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        std::lock_guard<std::mutex> lock(mtx);
        ++sharedCounter;
    }
}

double runTest(int numThreads, int totalIterations) {
    sharedCounter = 0;
    int iterationsPerThread = totalIterations / numThreads;
    
    std::vector<std::thread> threads;
    
    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(incrementWithLock, iterationsPerThread);
    }
    
    for (auto& t : threads) {
        t.join();
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    
    return std::chrono::duration<double, std::milli>(end - start).count();
}

int main() {
    const int totalIterations = 1000000;
    
    std::cout << "=== 鎖競爭效能測試 ===" << std::endl;
    std::cout << "總迭代次數：" << totalIterations << std::endl << std::endl;
    
    std::cout << std::setw(10) << "執行緒數" 
              << std::setw(15) << "時間 (ms)"
              << std::setw(15) << "相對效能"
              << std::endl;
    std::cout << std::string(40, '-') << std::endl;
    
    double baseTime = runTest(1, totalIterations);
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << std::setw(10) << 1 
              << std::setw(15) << baseTime
              << std::setw(15) << "1.00x"
              << std::endl;
    
    for (int numThreads : {2, 4, 8, 16}) {
        double time = runTest(numThreads, totalIterations);
        double ratio = time / baseTime;
        
        std::cout << std::setw(10) << numThreads 
                  << std::setw(15) << time
                  << std::setw(14) << ratio << "x"
                  << std::endl;
    }
    
    return 0;
}
```

#### 典型輸出

```
=== 鎖競爭效能測試 ===
總迭代次數：1000000

 執行緒數       時間 (ms)        相對效能
----------------------------------------
         1          42.35          1.00x
         2          98.67          2.33x
         4         187.42          4.43x
         8         412.56          9.74x
        16         856.23         20.22x
```

```
┌─────────────────────────────────────────────────────────────┐
│                  競爭的影響分析                              │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  觀察結果：                                                  │
│  • 執行緒增加，總時間反而增加！                              │
│  • 這是因為所有執行緒都在競爭同一個鎖                        │
│  • 臨界區段變成瓶頸，無法並行                                │
│                                                             │
│  時間 ↑                                                     │
│       │                                    ╱                │
│       │                              ╱                      │
│       │                        ╱                            │
│       │                  ╱                                  │
│       │            ╱                                        │
│       │      ╱                                              │
│       │ ╱                                                   │
│       └─────────────────────────────────→ 執行緒數          │
│         1    2    4    8    16                              │
│                                                             │
│  結論：高競爭場景下，多執行緒比單執行緒還慢！                │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

### 四、粗粒度鎖 vs 細粒度鎖

```
┌─────────────────────────────────────────────────────────────┐
│              粗粒度鎖 vs 細粒度鎖                            │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  粗粒度鎖（Coarse-grained Locking）                         │
│  ─────────────────────────────────                          │
│  • 一個鎖保護大量資料                                       │
│  • 實作簡單，不易出錯                                       │
│  • 並行度低，競爭嚴重                                       │
│                                                             │
│      ┌─────────────────────────────┐                        │
│      │          一個大鎖           │                        │
│      │  ┌─────┬─────┬─────┬─────┐  │                        │
│      │  │資料1│資料2│資料3│資料4│  │                        │
│      │  └─────┴─────┴─────┴─────┘  │                        │
│      └─────────────────────────────┘                        │
│                                                             │
│  細粒度鎖（Fine-grained Locking）                           │
│  ───────────────────────────────                            │
│  • 多個鎖保護不同資料                                       │
│  • 實作複雜，容易死結                                       │
│  • 並行度高，競爭減少                                       │
│                                                             │
│      ┌──────┐ ┌──────┐ ┌──────┐ ┌──────┐                    │
│      │ 鎖1  │ │ 鎖2  │ │ 鎖3  │ │ 鎖4  │                    │
│      │┌────┐│ │┌────┐│ │┌────┐│ │┌────┐│                    │
│      ││資料1│ ││資料2│ ││資料3│ ││資料4│                    │
│      │└────┘│ │└────┘│ │└────┘│ │└────┘│                    │
│      └──────┘ └──────┘ └──────┘ └──────┘                    │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

#### 比較實作

```cpp
// 檔案：lesson_5_6_lock_granularity.cpp
// 說明：比較粗粒度鎖與細粒度鎖的效能

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <array>
#include <iomanip>

const int NUM_BUCKETS = 16;
const int ITERATIONS = 100000;

// 粗粒度鎖：一個鎖保護所有資料
class CoarseGrainedCounters {
private:
    std::mutex mtx;
    std::array<long long, NUM_BUCKETS> counters{};
    
public:
    void increment(int bucket) {
        std::lock_guard<std::mutex> lock(mtx);  // 鎖整個結構
        ++counters[bucket % NUM_BUCKETS];
    }
    
    long long get(int bucket) const {
        return counters[bucket % NUM_BUCKETS];
    }
    
    long long total() const {
        long long sum = 0;
        for (auto c : counters) sum += c;
        return sum;
    }
};

// 細粒度鎖：每個桶一個鎖
class FineGrainedCounters {
private:
    std::array<std::mutex, NUM_BUCKETS> mutexes;
    std::array<long long, NUM_BUCKETS> counters{};
    
public:
    void increment(int bucket) {
        int idx = bucket % NUM_BUCKETS;
        std::lock_guard<std::mutex> lock(mutexes[idx]);  // 只鎖一個桶
        ++counters[idx];
    }
    
    long long get(int bucket) const {
        return counters[bucket % NUM_BUCKETS];
    }
    
    long long total() const {
        long long sum = 0;
        for (auto c : counters) sum += c;
        return sum;
    }
};

template<typename Counter>
void worker(Counter& counter, int threadId, int iterations) {
    for (int i = 0; i < iterations; ++i) {
        // 每個執行緒存取不同的桶（模擬真實場景）
        counter.increment(threadId * 1000 + i);
    }
}

template<typename Counter>
double runTest(int numThreads) {
    Counter counter;
    std::vector<std::thread> threads;
    
    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(worker<Counter>, std::ref(counter), i, ITERATIONS);
    }
    
    for (auto& t : threads) {
        t.join();
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    
    return std::chrono::duration<double, std::milli>(end - start).count();
}

int main() {
    std::cout << "=== 鎖粒度效能比較 ===" << std::endl;
    std::cout << "桶數量：" << NUM_BUCKETS << std::endl;
    std::cout << "每執行緒迭代：" << ITERATIONS << std::endl << std::endl;
    
    std::cout << std::setw(10) << "執行緒數"
              << std::setw(18) << "粗粒度 (ms)"
              << std::setw(18) << "細粒度 (ms)"
              << std::setw(12) << "加速比"
              << std::endl;
    std::cout << std::string(58, '-') << std::endl;
    
    std::cout << std::fixed << std::setprecision(2);
    
    for (int numThreads : {1, 2, 4, 8, 16}) {
        double coarseTime = runTest<CoarseGrainedCounters>(numThreads);
        double fineTime = runTest<FineGrainedCounters>(numThreads);
        double speedup = coarseTime / fineTime;
        
        std::cout << std::setw(10) << numThreads
                  << std::setw(18) << coarseTime
                  << std::setw(18) << fineTime
                  << std::setw(11) << speedup << "x"
                  << std::endl;
    }
    
    return 0;
}
```

#### 典型輸出

```
=== 鎖粒度效能比較 ===
桶數量：16
每執行緒迭代：100000

 執行緒數    粗粒度 (ms)     細粒度 (ms)       加速比
----------------------------------------------------------
         1             4.52             4.78       0.95x
         2            12.34             5.21       2.37x
         4            28.67             6.45       4.45x
         8            65.43             8.92       7.34x
        16           142.56            12.34      11.55x
```

---

### 五、減少臨界區段大小

```cpp
// 檔案：lesson_5_6_minimize_critical_section.cpp
// 說明：減少臨界區段大小提升效能

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>
#include <vector>
#include <cmath>
#include <iomanip>

std::mutex mtx;
double result = 0;

// 耗時計算（模擬複雜運算）
double expensiveComputation(int input) {
    double sum = 0;
    for (int i = 0; i < 1000; ++i) {
        sum += std::sin(input + i) * std::cos(input - i);
    }
    return sum;
}

// 差的做法：在鎖內進行計算
void badApproach(int start, int count) {
    for (int i = start; i < start + count; ++i) {
        std::lock_guard<std::mutex> lock(mtx);  // 鎖定
        double computed = expensiveComputation(i);  // 💀 在鎖內計算！
        result += computed;
    }  // 解鎖
}

// 好的做法：在鎖外進行計算
void goodApproach(int start, int count) {
    for (int i = start; i < start + count; ++i) {
        double computed = expensiveComputation(i);  // ✓ 在鎖外計算
        
        std::lock_guard<std::mutex> lock(mtx);  // 鎖定
        result += computed;  // 只鎖定必要的部分
    }  // 解鎖
}

// 更好的做法：批次累加
void betterApproach(int start, int count) {
    double localSum = 0;  // 本地累加
    
    for (int i = start; i < start + count; ++i) {
        localSum += expensiveComputation(i);  // 完全不需要鎖
    }
    
    std::lock_guard<std::mutex> lock(mtx);  // 只鎖定一次
    result += localSum;
}

template<typename Func>
double runTest(Func&& func, int numThreads, int totalWork) {
    result = 0;
    int workPerThread = totalWork / numThreads;
    
    std::vector<std::thread> threads;
    
    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(func, i * workPerThread, workPerThread);
    }
    
    for (auto& t : threads) {
        t.join();
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    
    return std::chrono::duration<double, std::milli>(end - start).count();
}

int main() {
    const int totalWork = 1000;
    const int numThreads = 4;
    
    std::cout << "=== 臨界區段大小對效能的影響 ===" << std::endl;
    std::cout << "執行緒數：" << numThreads << std::endl;
    std::cout << "總工作量：" << totalWork << std::endl << std::endl;
    
    std::cout << std::fixed << std::setprecision(2);
    
    double badTime = runTest(badApproach, numThreads, totalWork);
    std::cout << "差的做法（鎖內計算）：" << badTime << " ms" << std::endl;
    
    double goodTime = runTest(goodApproach, numThreads, totalWork);
    std::cout << "好的做法（鎖外計算）：" << goodTime << " ms" << std::endl;
    
    double betterTime = runTest(betterApproach, numThreads, totalWork);
    std::cout << "更好做法（批次累加）：" << betterTime << " ms" << std::endl;
    
    std::cout << std::endl;
    std::cout << "加速比（差 vs 好）：" << badTime / goodTime << "x" << std::endl;
    std::cout << "加速比（差 vs 更好）：" << badTime / betterTime << "x" << std::endl;
    
    return 0;
}
```

#### 典型輸出

```
=== 臨界區段大小對效能的影響 ===
執行緒數：4
總工作量：1000

差的做法（鎖內計算）：156.78 ms
好的做法（鎖外計算）：42.35 ms
更好做法（批次累加）：38.92 ms

加速比（差 vs 好）：3.70x
加速比（差 vs 更好）：4.03x
```

---

### 六、臨界區段內應避免的操作

```
┌─────────────────────────────────────────────────────────────┐
│             臨界區段內應避免的操作                           │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  ✗ 避免在臨界區段內進行：                                   │
│                                                             │
│  1. I/O 操作                                                │
│     • 檔案讀寫                                              │
│     • 網路通訊                                              │
│     • 控制台輸出（除錯用途除外）                            │
│                                                             │
│  2. 阻塞等待                                                │
│     • sleep / wait                                          │
│     • 等待其他鎖（死結風險）                                │
│     • 等待條件變數                                          │
│                                                             │
│  3. 耗時計算                                                │
│     • 複雜演算法                                            │
│     • 大量數學運算                                          │
│     • 字串處理                                              │
│                                                             │
│  4. 記憶體配置                                              │
│     • new / malloc                                          │
│     • 容器擴展（可能觸發重新配置）                          │
│                                                             │
│  5. 呼叫未知函式                                            │
│     • 回呼函式                                              │
│     • 虛擬函式                                              │
│     • 使用者提供的函式                                      │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

#### 範例：避免在臨界區段內 I/O

```cpp
// 檔案：lesson_5_6_avoid_io_in_lock.cpp
// 說明：避免在臨界區段內進行 I/O

#include <iostream>
#include <thread>
#include <mutex>
#include <sstream>
#include <vector>

std::mutex mtx;
std::vector<std::string> logs;

// 💀 差的做法：在鎖內進行 I/O
void badLog(const std::string& message) {
    std::lock_guard<std::mutex> lock(mtx);
    std::cout << message << std::endl;  // 💀 I/O 在鎖內！
}

// ✓ 好的做法：只保護共享資料
void goodLog(const std::string& message) {
    {
        std::lock_guard<std::mutex> lock(mtx);
        logs.push_back(message);  // ✓ 只保護共享容器
    }
    // I/O 在鎖外（或由專門的執行緒處理）
}

// ✓ 更好的做法：批次輸出
void flushLogs() {
    std::vector<std::string> localLogs;
    
    {
        std::lock_guard<std::mutex> lock(mtx);
        localLogs.swap(logs);  // 快速交換
    }
    
    // 在鎖外進行 I/O
    for (const auto& log : localLogs) {
        std::cout << log << std::endl;
    }
}
```

---

### 七、Amdahl 定律

```
┌─────────────────────────────────────────────────────────────┐
│                    Amdahl 定律                              │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  加速比 = 1 / (S + P/N)                                     │
│                                                             │
│  S = 程式中串行部分的比例                                    │
│  P = 程式中可並行部分的比例（P = 1 - S）                    │
│  N = 處理器數量                                             │
│                                                             │
│  ─────────────────────────────────────────────────────────  │
│                                                             │
│  範例：假設程式有 10% 必須串行（如鎖保護的部分）             │
│                                                             │
│  N=2:   加速比 = 1/(0.1 + 0.9/2)  = 1.82x                  │
│  N=4:   加速比 = 1/(0.1 + 0.9/4)  = 3.08x                  │
│  N=8:   加速比 = 1/(0.1 + 0.9/8)  = 4.71x                  │
│  N=∞:   加速比 = 1/(0.1 + 0)      = 10x  ← 最大上限！       │
│                                                             │
│  結論：串行部分決定了並行的上限                              │
│       減少臨界區段比增加執行緒更重要！                       │
│                                                             │
│  加速比 ↑                                                   │
│    10 ┤                          ─ ─ ─ ─ ─ 理論上限 10x     │
│     8 ┤                    ·····                            │
│     6 ┤              ·····                                  │
│     4 ┤        ·····                                        │
│     2 ┤   ·····                                             │
│     0 ┼─────────────────────────────→ 處理器數量 N          │
│         2    4    8   16   32   ∞                           │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

### 八、效能優化策略總結

```
┌─────────────────────────────────────────────────────────────┐
│                  效能優化策略總結                            │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  策略 1：減少臨界區段大小                                   │
│  ────────────────────────                                   │
│  • 只鎖定真正需要保護的操作                                 │
│  • 將計算移到鎖外                                          │
│  • 使用本地變數累加後再更新共享資料                         │
│                                                             │
│  策略 2：降低鎖競爭                                         │
│  ──────────────────                                         │
│  • 使用細粒度鎖                                            │
│  • 分離讀寫（讀寫鎖，第七階段學習）                         │
│  • 資料分區，每個分區一個鎖                                 │
│                                                             │
│  策略 3：減少鎖的使用                                       │
│  ──────────────────                                         │
│  • thread_local 變數避免共享                               │
│  • 原子操作替代簡單的鎖（第二十階段學習）                   │
│  • 無鎖演算法（第二十二階段學習）                           │
│                                                             │
│  策略 4：正確選擇鎖類型                                     │
│  ──────────────────────                                     │
│  • 讀多寫少：shared_mutex                                  │
│  • 短臨界區段：自旋鎖                                       │
│  • 需要超時：timed_mutex                                   │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

### 九、實際案例：優化前後對比

```cpp
// 檔案：lesson_5_6_optimization_example.cpp
// 說明：完整的優化前後對比

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
#include <numeric>
#include <iomanip>

const int DATA_SIZE = 100000;
const int NUM_THREADS = 4;

// ===== 優化前：單一全域鎖 =====
class BeforeOptimization {
private:
    std::mutex mtx;
    std::vector<int> data;
    long long sum = 0;
    
public:
    BeforeOptimization() : data(DATA_SIZE) {
        std::iota(data.begin(), data.end(), 1);
    }
    
    void processRange(int start, int end) {
        for (int i = start; i < end; ++i) {
            std::lock_guard<std::mutex> lock(mtx);  // 每次迭代都鎖
            sum += data[i] * data[i];
        }
    }
    
    long long getSum() const { return sum; }
    void reset() { sum = 0; }
};

// ===== 優化後：本地累加 + 最後合併 =====
class AfterOptimization {
private:
    std::mutex mtx;
    std::vector<int> data;
    long long sum = 0;
    
public:
    AfterOptimization() : data(DATA_SIZE) {
        std::iota(data.begin(), data.end(), 1);
    }
    
    void processRange(int start, int end) {
        long long localSum = 0;  // 本地累加
        
        for (int i = start; i < end; ++i) {
            localSum += data[i] * data[i];  // 無鎖計算
        }
        
        std::lock_guard<std::mutex> lock(mtx);  // 只鎖一次
        sum += localSum;
    }
    
    long long getSum() const { return sum; }
    void reset() { sum = 0; }
};

template<typename T>
double runTest(T& processor) {
    processor.reset();
    
    int rangeSize = DATA_SIZE / NUM_THREADS;
    std::vector<std::thread> threads;
    
    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < NUM_THREADS; ++i) {
        int rangeStart = i * rangeSize;
        int rangeEnd = (i == NUM_THREADS - 1) ? DATA_SIZE : (i + 1) * rangeSize;
        threads.emplace_back(&T::processRange, &processor, rangeStart, rangeEnd);
    }
    
    for (auto& t : threads) {
        t.join();
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    
    return std::chrono::duration<double, std::milli>(end - start).count();
}

int main() {
    BeforeOptimization before;
    AfterOptimization after;
    
    std::cout << "=== 優化前後效能對比 ===" << std::endl;
    std::cout << "資料大小：" << DATA_SIZE << std::endl;
    std::cout << "執行緒數：" << NUM_THREADS << std::endl << std::endl;
    
    // 預熱
    runTest(before);
    runTest(after);
    
    // 正式測試
    double beforeTime = runTest(before);
    double afterTime = runTest(after);
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "優化前時間：" << beforeTime << " ms" << std::endl;
    std::cout << "優化後時間：" << afterTime << " ms" << std::endl;
    std::cout << "加速比：" << beforeTime / afterTime << "x" << std::endl;
    std::cout << std::endl;
    std::cout << "結果驗證：" << std::endl;
    std::cout << "優化前 sum = " << before.getSum() << std::endl;
    std::cout << "優化後 sum = " << after.getSum() << std::endl;
    std::cout << "結果一致：" << (before.getSum() == after.getSum() ? "✓" : "✗") << std::endl;
    
    return 0;
}
```

#### 典型輸出

```
=== 優化前後效能對比 ===
資料大小：100000
執行緒數：4

優化前時間：245.67 ms
優化後時間：1.23 ms
加速比：199.73x

結果驗證：
優化前 sum = 333338333350000
優化後 sum = 333338333350000
結果一致：✓
```

---

### 十、效能檢查清單

```
┌─────────────────────────────────────────────────────────────┐
│                  效能優化檢查清單                            │
├─────────────────────────────────────────────────────────────┤
│                                                             │
│  □ 臨界區段是否盡可能小？                                   │
│                                                             │
│  □ 是否有計算可以移到鎖外？                                 │
│                                                             │
│  □ 是否可以使用本地變數累加？                               │
│                                                             │
│  □ 臨界區段內是否有 I/O 操作？                              │
│                                                             │
│  □ 臨界區段內是否有阻塞等待？                               │
│                                                             │
│  □ 是否可以使用細粒度鎖？                                   │
│                                                             │
│  □ 是否可以使用讀寫鎖？                                     │
│                                                             │
│  □ 是否可以用 thread_local 避免共享？                       │
│                                                             │
│  □ 是否可以用原子操作替代鎖？                               │
│                                                             │
│  □ 是否測量了實際的效能影響？                               │
│                                                             │
└─────────────────────────────────────────────────────────────┘
```

---

### 十一、本課重點回顧

1. **鎖不是免費的**：無競爭約 20-50 ns，有競爭可達微秒級
2. **競爭越多越慢**：高競爭場景下多執行緒比單執行緒還慢
3. **細粒度鎖提升並行度**：但增加複雜度和死結風險
4. **減少臨界區段大小**：將計算移到鎖外，使用本地累加
5. **避免在臨界區段內**：I/O、阻塞等待、耗時計算
6. **Amdahl 定律**：串行部分決定並行的上限
7. **測量優先**：優化前先測量，避免過早優化

---

### 🎉 第五階段完成！

恭喜你完成了「互斥鎖基礎」階段！你已經學會：

- ✅ std::mutex 的基本操作（lock/unlock/try_lock）
- ✅ 互斥鎖的內部工作原理
- ✅ 常見錯誤與避免方法
- ✅ 執行緒安全類別的設計
- ✅ 效能考量與優化策略

---

### 下一階段預告

**第六階段：RAII 鎖管理器** 將學習：

| 課程 | 主題 |
|------|------|
| 6.1 | std::lock_guard 基礎 |
| 6.2 | std::unique_lock 入門 |
| 6.3 | unique_lock 進階操作 |
| 6.4 | std::scoped_lock (C++17) |
| 6.5 | 鎖管理器的選擇策略 |
| 6.6 | 自訂鎖管理器 |

這些 RAII 工具將讓你的鎖管理更安全、更優雅！

---

準備好進入第六階段嗎？
*/



// 檔案：lesson_5_6_optimization_example.cpp
// 說明：完整的優化前後對比

#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <chrono>
#include <numeric>
#include <iomanip>

const int DATA_SIZE = 100000;
const int NUM_THREADS = 4;

// ===== 優化前：單一全域鎖 =====
class BeforeOptimization {
private:
    std::mutex mtx;
    std::vector<int> data;
    long long sum = 0;
    
public:
    BeforeOptimization() : data(DATA_SIZE) {
        std::iota(data.begin(), data.end(), 1);
    }
    
    void processRange(int start, int end) {
        for (int i = start; i < end; ++i) {
            std::lock_guard<std::mutex> lock(mtx);  // 每次迭代都鎖
            sum += data[i] * data[i];
        }
    }
    
    long long getSum() const { return sum; }
    void reset() { sum = 0; }
};

// ===== 優化後：本地累加 + 最後合併 =====
class AfterOptimization {
private:
    std::mutex mtx;
    std::vector<int> data;
    long long sum = 0;
    
public:
    AfterOptimization() : data(DATA_SIZE) {
        std::iota(data.begin(), data.end(), 1);
    }
    
    void processRange(int start, int end) {
        long long localSum = 0;  // 本地累加
        
        for (int i = start; i < end; ++i) {
            localSum += data[i] * data[i];  // 無鎖計算
        }
        
        std::lock_guard<std::mutex> lock(mtx);  // 只鎖一次
        sum += localSum;
    }
    
    long long getSum() const { return sum; }
    void reset() { sum = 0; }
};

template<typename T>
double runTest(T& processor) {
    processor.reset();
    
    int rangeSize = DATA_SIZE / NUM_THREADS;
    std::vector<std::thread> threads;
    
    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < NUM_THREADS; ++i) {
        int rangeStart = i * rangeSize;
        int rangeEnd = (i == NUM_THREADS - 1) ? DATA_SIZE : (i + 1) * rangeSize;
        threads.emplace_back(&T::processRange, &processor, rangeStart, rangeEnd);
    }
    
    for (auto& t : threads) {
        t.join();
    }
    
    auto end = std::chrono::high_resolution_clock::now();
    
    return std::chrono::duration<double, std::milli>(end - start).count();
}

int main() {
    BeforeOptimization before;
    AfterOptimization after;
    
    std::cout << "=== 優化前後效能對比 ===" << std::endl;
    std::cout << "資料大小：" << DATA_SIZE << std::endl;
    std::cout << "執行緒數：" << NUM_THREADS << std::endl << std::endl;
    
    // 預熱
    runTest(before);
    runTest(after);
    
    // 正式測試
    double beforeTime = runTest(before);
    double afterTime = runTest(after);
    
    std::cout << std::fixed << std::setprecision(2);
    std::cout << "優化前時間：" << beforeTime << " ms" << std::endl;
    std::cout << "優化後時間：" << afterTime << " ms" << std::endl;
    std::cout << "加速比：" << beforeTime / afterTime << "x" << std::endl;
    std::cout << std::endl;
    std::cout << "結果驗證：" << std::endl;
    std::cout << "優化前 sum = " << before.getSum() << std::endl;
    std::cout << "優化後 sum = " << after.getSum() << std::endl;
    std::cout << "結果一致：" << (before.getSum() == after.getSum() ? "✓" : "✗") << std::endl;
    
    return 0;
}
