#include <bits/stdc++.h>
using namespace std;

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





