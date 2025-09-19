#include <bits/stdc++.h>
using namespace std;

// 滑动窗口法伪代码

void slidingwindow(string s) {
    auto window, need = datastrucure;
    int left = 0, right = 0;
    while (right < s.size()) {
        char c = s[right];
        if (need c) {
            window.add(c);
        }
        // other data update;

        right++;
        while (window moves left) {
            char d = s[left];
            if (need d) {
                window.remove(d);
            }
            // other data update;
            
            left++;
        }
    }
}