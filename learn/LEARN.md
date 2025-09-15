# 学习日记c++版

使用c++完成数据结构与算法的学习，并刷完基本题库，包括：

- cpp语法学习
- 基本数据结构与算法
- 解题方法套路

## 0 基本c++语法复习

### 基本结构与标准输出

```cpp
#include<bits/stdc++.h> // 万能头文件
using namespace std;    // std命名空间

int main() {            // 主函数
    cin << a << endl;   // cin输入
    cout << a << endl;  // cout输出
    cout << endl;       // endl用于换行
    return 0;           // 主函数结束，返回0
}
```

### 控制语句

```cpp
if (a > 5) {
    cout << "a > 5" << endl;
} else if (a == 5) {
    cout << "a = 5" << endl;
}
```

### 循环

```cpp
for (int i = 0; i <5; i++) {    // 正常for循环
    out << i << " ";
}
for (auto i : arr) {            // 范围循环
    cout << i;
}
while (num > 0) {
    cout << num << " ";
    num /= 2;
}
```

### 类与面向对象

```cpp
class Student {
private:
    int number;
public:
    int height;
    int weight;
    Student(): Student(0, 0) {}                     // 无参构造
    Student(int h, int n) : height(h), number(n) {} // 有参构造函数用于初始化
    ~Student() {} = default;                        // 析构函数用于释放
    int getHeight(Student* stu) {
        return stu->height;                         // 指针类型的实例用->，普通用.
    }
}
```

### 数据结构

#### <span id="vector">静态数组与动态数组vector</span>

静态数组的定义：

```cpp
int arr[10];
arr[0] = 0;
arr[1] = 1;
arr[1] = -1;    // 可以用-1表示删除
```

动态数组底层还是静态数组，只是自动帮我们进行数组空间的扩缩容，并把增删查改操作进行了封装，让我们使用起来更方便而已。是尾进尾出（LIFO）的随机访问序列容器。

- 支持 O(1) 随机访问
- 支持 尾部插入/删除 摊 O(1)
- 支持 自动扩容（容量按指数增长）

vector定义：

```cpp
std::vector<int> v1;        
vector<int> v2(5);
vector<int> v3{1, 2, 3, 4};
```

vector常用接口

| 功能    | 代码                    | 复杂度    |
| ----- | --------------------- | ------ |
| 元素个数  | `v.size()`            | O(1)   |
| 是否空   | `v.empty()`           | O(1)   |
| 容量    | `v.capacity()`        | O(1)   |
| 随机访问  | `v[i]`, `v.at(i)`     | O(1)   |
| 尾插    | `v.push_back(x)`      | 摊 O(1) |
| 尾删    | `v.pop_back()`        | O(1)   |
| 任意位置插 | `v.insert(pos, x)`    | O(n)   |
| 任意位置删 | `v.erase(pos)`        | O(n)   |
| 清空    | `v.clear()`           | O(n)   |
| 调整大小  | `v.resize(n, val)`    | O(n)   |
| 预留容量  | `v.reserve(n)`        | O(n)   |
| 获取首/尾 | `v.front(), v.back()` | O(1)   |

#### 哈希表unordered_map

C++标准库提供的哈希表（Hash Table）容器，用来存放键-值对（key-value pairs），无序（遍历顺序与插入顺序无关）。平均常数时间O(1)的插入、查找、删除（最坏退化到 O(n)）。

unordered_map定义：

```cpp
unordered_map<string, int> map;
map["apple"] = 5;
```

unordered_map常用接口（平均O(1)）：

| 功能       | 代码                             |
| -------- | ------------------------------ |
| 插入/更新    | `mp["apple"] = 5;`             |
| 插入（若不存在） | `mp.emplace("banana", 3);`     |
| 取值       | `int v = mp.at("apple");`      |
| 判断存在     | `bool ok = mp.count("apple");` |
| 删除       | `mp.erase("apple");`           |
| 遍历       | `for (auto& [k,v] : mp)`       |
| 清空       | `mp.clear();`                  |
| 大小       | `mp.size();`                   |
| 空        | `mp.empty();`                  |

#### 队列queue

queue是C++标准库提供的先进先出（FIFO）容器适配器。它把某个满足“尾部插入、头部删除”接口的顺序容器封装成 只允许push（队尾进）和pop（队头出）的管道，所有操作平均时间复杂度 O(1)，不提供迭代器。

queue定义：

```cpp
queue<int> q;
```

queue常用接口（平均O(1)）：

| 功能  | 代码         |
| --- | -----------  |
| 入队  | `q.push(x)` |
| 出队  | `q.pop()`   |
| 队头  | `q.front()` |
| 队尾  | `q.back()`  |
| 判空  | `q.empty()` |
| 元素数 | `q.size()`  |

### 其他细节

```cpp
memset();
sizeof();
template
explicit
const int& a
```

## 1 数组与动态数组

[数组的增删改查，以及动态数组的接口](#vector)

## 2 单链表

一条链表不需要一整块连续的内存空间存储元素。链表的元素可以分散在内存空间的天涯海角，通过每个节点上的next（和双链表的prev）指针，将零散的内存块串联起来形成一个链式结构。需要维护head节点来访问链表。

单链表节点的定义：

```cpp
class ListNode {
public:
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
```

可将数组转化为一条单链表：

```cpp
ListNode* createLinkedList(const vector<int> &arr) {
    if (arr.empty()) {
        return nullptr;
    }
    ListNode* head = new ListNode(arr[0]);
    ListNode* cur = head;
    for (int i = 1; i < arr.size(); i++) {
        cur->next = new ListNode(arr[i]);
        cur = cur->next;
    }
    return head;
}
```

单链表的增：

```cpp
// 头部插入
ListNode* headNode = new ListNode(-1);
headNode->next = head;
head = headNode;

// 尾部插入
ListNode* p = head;
for (; p->next != nullptr; ) {
    p = p->next;
}
ListNode* headNode =  new ListNode(7);
p->next = headNode;

// 中间插入，在第三个节点后面添加666
ListNode* p = head;
for (int i = 0; i < 2; i++) {
    p = p->next;
}
ListNode* middleNode = new ListNode(666);
middleNode->next = p->next;
p->next = middleNode;
```

单链表的删：

```cpp
// 头部删除
ListNode* p = head;
head = head->next;

// 尾部删除
ListNode* p = head;
for ( ; p->next->next != nullptr;) {
    p = p->next;
}
p->next = nullptr;
cout <<  << endl;

// 中间删除，删第四个节点
ListNode* p = head;
for (int i = 0; i < 2; i++) {
    p = p->next;
}
p->next = p->next->next;
```

单链表的改/查：

```cpp
// 遍历单链表
for (ListNode* p = head; p != nullptr; p = p->next) {
    std::cout << p->val << std::endl;
}
```

### 3 双链表

双链表即为单链表+prev指针，可前向或者后向进行访问。

双链表节点定义：

```cpp
class DoublyListNode {
public:
    int val;
    DoublyListNode *next, *prev;
    DoublyListNode(int x): val(x), next(nullptr), prev(nullptr) {}
};
```

可将数组转化为一条双链表：

```cpp
DoublyListNode* createDoublyListNode(const vector<int>& arr) {
    if (arr.size() == 0) {
        return nullptr;
    }
    DoublyListNode* head = new DoublyListNode(arr[0]);
    DoublyListNode* cur = head;
    for (int i = 1; i < arr.size(); i++) {
        DoublyListNode* newNode = new DoublyListNode(arr[i]);
        cur->next = newNode;
        newNode->prev = cur;
        cur = cur->next;
    }
    return head;
}
```

双链表的增：

```cpp
// 头部插入
DoublyListNode* headNode = new DoublyListNode({0});
headNode->next = head;
head->prev = headNode;
head = headNode;

// 尾部插入
DoublyListNode* newNode = new DoublyListNode({6});
tail->next = newNode;
newNode->prev = tail;
tail = newNode;

// 中间插入，在第三个节点后插入666
DoublyListNode* newNode = new DoublyListNode({666});
DoublyListNode* p = head;
for (int i = 0; i < 2; i++){
    p = p->next;
}
// 先组装好新节点的prev，next，再插入到原节点之中
newNode->prev = p;
newNode->next = p->next;
p->next = newNode;
p->next->prev = newNode;
```

双链表的删：

```cpp
// 头部删除
DoublyListNode* toDelete = head;
head->next->prev = nullptr;
head = head->next;
toDelete->prev = nullptr; // 释放原head的next

// 尾部删除
DoublyListNode* toDelete = tail;
tail->prev->next = nullptr;
tail = tail->prev;
toDelete->prev = nullptr;

// 中间删除，删除第四个节点
DoublyListNode* p = head;
for (int i = 0; i < 2; i++) {
    p = p->next;
}
DoublyListNode* toDelete = p->next;
p->next = toDelete->next;
toDelete->next->prev = p;
toDelete->next = nullptr; // 释放被删节点的前后指针
toDelete->prev = nullptr;
```

双链表的改/查：

```cpp
// 从头节点向后遍历双链表
for (DoublyListNode* p = head; p != nullptr; p = p->next) {
    cout << p->val << endl;
    tail = p;
}

// 从尾节点向前遍历双链表
for (DoublyListNode* p = tail; p != nullptr; p = p->prev) {
    cout << p->val << endl;
}
```

### 4 环形数组

对于普通数组，当索引i到达数组末尾元素时，i+1和arr.length取余数又会变成0，即会回到数组头部，这样就在逻辑上形成了一个环形数组，永远遍历不完。可以让我们用O(1)的时间在数组头部或尾部增删元素。

环形数组的关键在于，它维护了两个指针start和end，start指向第一个有效元素的索引，end指向最后一个有效元素的下一个位置索引。

这样，当我们在数组头部添加或删除元素时，只需要移动start索引，而在数组尾部添加或删除元素时，只需要移动end索引。

当start, end移动超出数组边界（<0或>=arr.length）时，我们可以通过求模运算%让它们转一圈到数组头部或尾部继续工作，这样就实现了环形数组的效果。

设计左开右闭的环形数组：

```cpp
template<typename T>
class CycleArray {
private:    
    std::vector<T> arr;
    int start;
    int end;
    int count;
    CycleArray() : CycleArray(1) {}
    explicit CycleArray(int size) : arr(size), start(0), end(0), count(0) {}
};
```

环形数组的一些接口定义如下。

环形数组的自动扩缩容辅助函数:

```cpp
private:
void resize(int newSize) {
    // 创建新的数组并复制元素
    std::vector<T> newArr(newSize);
    for (int i = 0; i < count; ++i) {
        newArr[i] = arr[(start + i) % arr.size()];
    }
    arr = std::move(newArr);
    // 重置 start 和 end 指针
    start = 0;
    end = count;
}
```

环形数组的增：

```cpp
// 头部添加元素，时间复杂度 O(1)
void addFirst(const T &val) {
    if (isFull()) {
        resize(arr.size() * 2);
    }
    // 左闭右开，左加，先移位，再赋值
    start = (start - 1 + arr.size()) % arr.size();  // +arr.size()防止负数
    arr[start] = val;
    count++;
}

// 尾部添加元素，时间复杂度 O(1)
void addLast(const T &val) {
    if (isFull()) {
        resize(arr.size() * 2);
    }
    // 左闭右开，右加，先赋值，再移位
    arr[end] = val;
    end = (end + 1) % arr.size();
    count++;
}
```

环形数组的删：

```cpp
// 删除数组头部元素，时间复杂度 O(1)
void removeFirst() {
    if (isEmpty()) {
        throw runtime_error("Array is empty!");
    }
    arr[start] = T();
    start = (start + 1) % arr.size();
    count--;
    // 缩容，留1/4冗余，防止频繁扩/缩容带来的性能损耗
    if (count > 0 && count == arr.size() / 4) {
        arr.resize(arr.size() / 2);
    }
}

// 尾部添加元素，时间复杂度 O(1)
void removeLast() {
    if (isEmpty()) {
        throw runtime_error("Array is empty!");
    }
    // 左闭右开，右减，先移位，再赋值
    end = (end - 1 + arr.size()) % arr.size();
    arr[end] = T();
    count--;
    // 缩容，留1/4冗余，防止频繁扩/缩容带来的性能损耗
    if (count > 0 && count == arr.size() / 4) {
        arr.resize(arr.size() / 2);
    }
}
```

环形数组的改/查，同动态数组一样，需要进行遍历，为O(N)。

```cpp
// 获取数组头部元素，时间复杂度 O(1)
T getFirst() const {
    if (isEmpty()) {
        throw std::runtime_error("Array is empty");
    }
    return arr[start];
}

// 获取数组尾部元素，时间复杂度 O(1)
T getLast() const {
    if (isEmpty()) {
        throw std::runtime_error("Array is empty");
    }
    // end 是开区间，指向的是下一个元素的位置，所以要减 1
    return arr[(end - 1 + arr.size()) % arr.size()];
}
```

判断环形数组是否为满：

```cpp
bool isFull() const {
    return count == arr.size();
}
```

判断环形数组是否为空：

```cpp
bool isEmpty() const {
    return count == 0;
}
```

查看动态数组的大小：

```cpp
int size() const {
    return count;
}
```
