#include <bits/stdc++.h>
using namespace std;

// 差分数组用于频繁对原始数组的某个区间的元素进行增减
// 将diff[i] + val，diff[j+1] -val，可以实现区间[i, j]上加val
class difference {
private:
    vector<int> diff;

public:
    difference(vector<int>& nums) {
        diff = vector<int>(nums.size());
        diff[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            diff[i] = nums[i] - nums[i - 1];
        }
    }

    void increment(int i, int j, int val) {
        diff[i] += val;
        if (j + 1 < diff.size()) {
            diff[j + 1] -= val;
        }
    }

    vector<int> result() {
        vector<int> res(diff.size());
        // 根据差分数组构造结果数组
        res[0] = diff[0];
        for (int i = 1; i < diff.size(); i++) {
            res[i] = res[i - 1] + diff[i];
        }
        return res;
    }
};
