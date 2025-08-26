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
