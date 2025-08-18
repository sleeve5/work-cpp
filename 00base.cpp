#include <bits/stdc++.h>
using namespace std;
int main()
{
    // int a = 10;
    // standard output
    // cout << a << endl;
    // cout << "Hello" << "," << "World!" << endl;
    // string s = "abc";
    // cout << s << " " << a << endl;

    // control flow
    // if (a > 5) {
    //     cout << "a > 5" << endl;
    // } else if (a == 5) {
    //     cout << "a == 5" << endl;
    // } else {
    //     cout << "a < 5" << endl;
    // }

    // // loop
    // for (int i = 0; i <5; i++) {
    //     cout << i << " ";
    // }
    // cout << endl;
    // int num = 100;
    // while (num > 0) {
    //     cout << num << " ";
    //     num /= 2;
    // }

    // data structures
    // vector
    using intVec = vector<int>;     // 相当于类型别名alias
    
    // 动态数组底层还是静态数组，只是自动帮我们进行数组空间的扩缩容，并把增删查改操作进行了封装，让我们使用起来更方便而已。是尾进尾出（LIFO）的 随机访问序列容器
    vector<int> v1;                 // 各种定义方式
    intVec v2;
    vector<int> v3(8);
    vector<int> v4{1, 2, 3, 4};
    intVec v5(v4);                  // 拷贝构造
    intVec v6(move(v4));            // 移动构造

    vector<int> arr;
    for (int i = 0; i < 10; i++) {
        arr.push_back(i);               // 尾进
    }
    arr.resize(5);                      // 改元素数量size
    cout << arr.capacity();             // 打印16，每次指数级翻倍
    arr.insert(arr.begin() + 2, 666);   // 指定位置插入
    arr.insert(arr.begin(), -1);
    arr.pop_back();                     // 尾出
    arr.erase(arr.begin() + 2);         // 指定位置删除
    arr[0] = 100;
    int index = find(arr.begin(), arr.end(), 666) - arr.begin();
    cout << index << endl;
    arr.reserve(10);                    // 改容量capacity
    arr.clear();                        // 清空所有元素

    return 0;
}
