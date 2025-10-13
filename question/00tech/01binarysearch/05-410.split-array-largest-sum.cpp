/*
 * @lc app=leetcode.cn id=410 lang=cpp
 * @lcpr version=30203
 *
 * [410] 分割数组的最大值
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
    int splitArray(vector<int>& nums, int k) {
        return shipWithinDays(nums, k);
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int minCap = 1, maxCap = 0;
        for (auto i : weights) {
            maxCap += i;
            minCap = max(minCap, i);
        }
        if (minCap > maxCap) return 0;
        while (minCap <= maxCap) {
            int midCap = minCap + (maxCap - minCap) / 2;
            if (shipdDays(weights, midCap) == days) {
                maxCap = midCap - 1;
            } else if (shipdDays(weights, midCap) < days) {
                maxCap = midCap - 1;
            } else if (shipdDays(weights, midCap) > days) {
                minCap = midCap + 1;
            }
        }
        return minCap;
    }

    int shipdDays(vector<int>& weights, int cap) {
        int days = 0;
        for (int i = 0; i < weights.size();) {
            int x = cap;
            while (i < weights.size()) {
                if (x < weights[i]) {
                    break;
                } else {
                    x -= weights[i];
                }
                i++;
            }
            days++;
        }
        return days;
    }
};
// @lc code=end




/*
// @lcpr case=start
// [7,2,5,10,8]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1,4,4]\n3\n
// @lcpr case=end

 */

