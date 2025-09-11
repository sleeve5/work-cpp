#include <bits/stdc++.h>
using namespace std;
int main()
{
    // 标准输入输出
    // int a = 10;
    // int b;
    // cin << b;
    // cout << a << endl;
    // cout << "Hello" << "," << "World!" << endl;
    // string s = "abc";
    // cout << s << " " << a << endl;

    // 控制流
    // if (a > 5) {
    //     cout << "a > 5" << endl;
    // } else if (a == 5) {
    //     cout << "a == 5" << endl;
    // } else {
    //     cout << "a < 5" << endl;
    // }

    // // 循环
    // for (int i = 0; i <5; i++) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // int num = 100;
    // while (num > 0) {
    //     cout << num << " ";
    //     num /= 2;
    // }

    // // data structures
    // // vector
    // using intVec = vector<int>;     // 相当于类型别名alias
    
    // // 动态数组底层还是静态数组，只是自动帮我们进行数组空间的扩缩容，并把增删查改操作进行了封装，让我们使用起来更方便而已。是尾进尾出（LIFO）的 随机访问序列容器
    // vector<int> v1;                 // 各种定义方式
    // intVec v2;
    // vector<int> v3(6);              // 长度，全0
    // vector<int> v4{1, 2, 3, 4};     // 定义
    // intVec v5(v4);                  // 拷贝构造
    // intVec v6(move(v4));            // 移动构造

    // vector<int> arr;
    // for (int i = 0; i < 6; i++) {
    //     arr.push_back(i);               // 尾进
    // }
    // for (auto i : arr) {                // 范围循环
    //     cout << i << endl;
    // }
    // arr.resize(5);                      // 改元素数量size
    // cout << arr.capacity() << endl;     // 打印容量16，每次指数级翻倍
    // cout << arr.size() << endl;         // 打印长度
    // arr.insert(arr.begin() + 2, 666);   // 指定位置插入
    // arr.insert(arr.begin(), -1);
    // arr.pop_back();                     // 尾出
    // arr.erase(arr.begin() + 2);         // 指定位置删除
    // arr[0] = 100;
    // int index = find(arr.begin(), arr.end(), 666) - arr.begin();
    // cout << index << endl;
    // arr.reserve(10);                    // 改容量capacity
    // arr.clear();                        // 清空所有元素

    // //  C++标准库提供的哈希表（Hash Table）容器，用来存放键-值对（key-value pairs），无序（遍历顺序与插入顺序无关）。平均常数时间O(1)的插入、查找、删除（最坏退化到 O(n)）。
    // unordered_map<string, int> map;
    // map["apple"] = 5;
    // map.emplace("banana", 3);
    // cout << map.at("apple") << endl;
    // cout << map.count("banana") << endl;
    // cout << map.size() << endl;
    // for (auto& [k, v] : map) {
    //     cout << k << ":" << v << "  ";
    // }
    // map.clear();

    // // queue是一个“先进先出（FIFO）”的容器，底层默认用std::deque，只暴露“队尾进、队头出”的接口。平均O(1)
    // queue<int> q;
    // for (int i = 0; i < 5; i++) {
    //     q.push(i);                      // 尾进
    // }
    // q.pop();                            // 头出
    // cout << q.size() << endl;           // 长度
    // while (!q.empty()) {
    //     cout << q.front() << "  ";
    //     q.pop();
    // }

    // // 优先级队列priority_queue，即二叉堆是一种能够动态排序的数据结构，是二叉树结构的延伸。默认是大顶堆（top最大），所有操作O(log n)。
    // priority_queue<int> maxHeap;    // 大顶堆
    // priority_queue<int, vector<int>, greater<int>> minHeap; // 小顶堆，greater比较器，a>b，返回1，将a下沉；否则返回0，a上浮
    // // 比较器的写法
    // class Mygreater {
    //     bool operator() (int a, int b) {
    //         return a > b;   // true 即下沉，即把大的数下沉，小数上浮
    //     }
    // };
    // priority_queue<int, vector<int>, Mygreater> minheap;
    // maxHeap.push(1);
    // maxHeap.push(3);
    // maxHeap.push(4);
    // maxHeap.push(2);
    // maxHeap.push(5);
    // while (!maxHeap.empty()) {
    //     cout << maxHeap.top() << "  ";
    //     maxHeap.pop();
    // }
    
    // // std::stack 是 C++ 标准库提供的 “后进先出（LIFO）” 容器适配器，它把底层顺序容器（默认 std::deque）包装成 只暴露“栈顶”接口 的“桶”，所有操作 平均 O(1)，不提供迭代器。
    // stack<int> st;
    // st.push(1);
    // st.push(3);
    // st.push(5);
    // cout << st.top() << endl;   // 5
    // st.pop();
    // cout << st.top() << endl;  // 3

    return 0;
}
