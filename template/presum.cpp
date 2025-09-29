#include <bits/stdc++.h>
using namespace std;

// 前缀和，适用于快速、频繁地计算一个索引区间内的元素之和即数列求和
// 通过presum[j+1] - presum[i]来计算[i, j]内的和

class PreSum {
public:
    vector<int> presum;

    PreSum(vector<int>& nums) {
        presum.resize(nums.size() + 1);
        for (int i = 1; i <= nums.size(); i++) {
            presum[i] = presum[i - 1] + nums[i - 1];
        }
    }

    int numSum(int i, int j) {
        return presum[i + 1] - presum[j];
    }
};
