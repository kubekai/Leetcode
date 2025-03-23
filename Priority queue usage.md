# C++ 優先佇列（priority_queue）用法

## 1. `priority_queue` 的基本語法
C++ 標準函式庫提供 `priority_queue`，其定義方式如下：
```cpp
priority_queue<T, Container, Compare> pq;
```
- `T`：存入佇列的資料型態。
- `Container`（可選）：內部儲存的容器，預設為 `vector<T>`。
- `Compare`（可選）：用來決定優先順序的比較函式，預設為 `less<T>`（最大堆）。

## 2. 預設為最大堆（Max-Heap）
在 C++ 中，`priority_queue` 預設是一個**最大堆**，即數值越大，優先級越高。
```cpp
#include <queue>
#include <iostream>
using namespace std;

int main() {
    priority_queue<int> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    
    while (!pq.empty()) {
        cout << pq.top() << " ";  // 30 20 10
        pq.pop();
    }
    return 0;
}
```

## 3. 最小堆（Min-Heap）的建立
要改為最小堆（Min-Heap），我們需要使用 `greater<T>`：
```cpp
priority_queue<int, vector<int>, greater<int>> pq;
```
這樣 `priority_queue` 會按照從小到大的順序排列。

### 例子：
```cpp
#include <queue>
#include <iostream>
using namespace std;

int main() {
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(10);
    pq.push(30);
    pq.push(20);
    
    while (!pq.empty()) {
        cout << pq.top() << " ";  // 10 20 30
        pq.pop();
    }
    return 0;
}
```

## 4. 儲存 `pair` 型態的 `priority_queue`
在圖演算法（如 Dijkstra）中，通常會使用 `pair` 來儲存**(時間, 節點)**，並按照時間排序。

### 宣告方式（最小堆）：
```cpp
priority_queue<pair<long long, long long>,
               vector<pair<long long, long long>>,
               greater<pair<long long, long long>>> pq;
```
### 解釋：
- `pair<long long, long long>`：存儲 (時間, 節點) 的 `pair`。
- `vector<pair<long long, long long>>`：內部容器使用 `vector`。
- `greater<pair<long long, long long>>`：根據**第一個元素（時間）由小到大排序**。

### 應用示例（Dijkstra 最短路徑）：
```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    priority_queue<pair<long long, long long>,
                   vector<pair<long long, long long>>,
                   greater<pair<long long, long long>>> pq;
    
    pq.push({5, 1});
    pq.push({2, 3});
    pq.push({8, 2});
    
    while (!pq.empty()) {
        cout << "時間: " << pq.top().first << " , 節點: " << pq.top().second << endl;
        pq.pop();
    }
    return 0;
}
```
### 執行結果：
```
時間: 2 , 節點: 3
時間: 5 , 節點: 1
時間: 8 , 節點: 2
```
這樣可以確保時間最短的節點**優先被處理**。

## 5. 總結
- 預設 `priority_queue<int>` 是最大堆。
- 使用 `greater<T>` 變成最小堆。
- 可存儲 `pair`，用 `greater<pair<T1, T2>>` 來按照第一個值排序（如 Dijkstra 演算法）。


