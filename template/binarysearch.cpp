#include <bits/stdc++.h>
using namespace std;

// 1、确定 x, f(x), target 分别是什么，并写出函数 f 的代码。
// 2、找到 x 的取值范围作为二分搜索的搜索区间，初始化 left 和 right 变量。
// 3、根据题目的要求，确定应该使用搜索左侧还是搜索右侧的二分搜索算法，写出解法代码。

int f(int x) {

}

int left_bound(vector<int>& nums, int target) {
    if (nums.size() == 0) return -1;
    int left = 0;                   // x最小值
    int right = nums.size() - 1;    // x最大值
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (f(mid) == target) {
            right = mid - 1;    // 左边界？还是右边界
        } else if (f(mid) < target) {
            left = mid + 1;     // 让f(x)更大
        } else if (f(mid) > target) {
            right = mid - 1;    // 让f(x)更小
        }
    }
    return left;
}
