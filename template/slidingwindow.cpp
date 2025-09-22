#include <bits/stdc++.h>
using namespace std;

// 1、什么时候应该移动 right 扩大窗口？窗口加入字符时，应该更新哪些数据？
// 2、什么时候窗口应该暂停扩大，开始移动 left 缩小窗口？从窗口移出字符时，应该更新哪些数据？
// 3、什么时候应该更新结果？

void slidingwindow(string s) {
    queue<int> window, need = {};       // 所需数据结构类型
    int left = 0, right = 0;
    while (right < s.size()) {
        char c = s[right];
        if (c) {                        // 若窗口增大，需要进行数据更新
            window.push(c);
        }
        // other data update;
        right++;
        while (left < right) {          // 窗口缩小的条件
            char d = s[left];
            if (!d) {                    // 若窗口缩小，需要进行数据更新
                window.pop();
            }
            // other data update;
            left++;
        }
    }
    return;
}