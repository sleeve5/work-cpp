#include <bits/stdc++.h>
using namespace std;

// 滑动窗口法伪代码

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