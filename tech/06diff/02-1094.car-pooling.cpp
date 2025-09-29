/*
 * @lc app=leetcode.cn id=1094 lang=cpp
 * @lcpr version=30203
 *
 * [1094] 拼车
 */

#include <bits/stdc++.h>
using namespace std;

class ListNode {
public:
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) { }
    ListNode(int x) : val(x), next(nullptr) { }
    ListNode(int x, ListNode *next) : val(x), next(next) { }
};

class TreeNode {
public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) { }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) { }
};

// @lc code=start
class Solution {
public:
    vector<int> diff, nums;
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        diff = vector<int>(1001, 0);
        int length = 0;
        for (auto trip : trips) {
            increment(trip[1], trip[2] - 1, trip[0]);
            length = max(length, trip[2]);
        }
        nums = vector<int>(length);
        nums[0] = diff[0];
        for (int i = 1; i < length; i++) {
            nums[i] = diff[i] + nums[i - 1];
        }
        for (auto num : nums) {
            if (num > capacity) {
                return false;
            }
        }
        return true;
    }

    void increment(int i, int j, int val) {
        diff[i] += val;
        if (j + 1 < diff.size()) {
            diff[j + 1] -= val;
        }
    }
};
// @lc code=end




/*
// @lcpr case=start
// [[2,1,5],[3,3,7]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[2,1,5],[3,3,7]]\n5\n
// @lcpr case=end

 */

