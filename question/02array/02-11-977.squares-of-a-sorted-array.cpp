/*
 * @lc app=leetcode.cn id=977 lang=cpp
 * @lcpr version=30203
 *
 * [977] 有序数组的平方
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
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> res(nums.size());
        if (!nums.size()) {
            return nums;
        }
        int left = 0, right = nums.size() - 1;
        int p = nums.size() - 1;
        while (left <= right) {
            if (abs(nums[left]) > abs(nums[right])) {
                res[p] = nums[left] * nums[left];
                p--;
                left++;
            } else {
                res[p] = nums[right] * nums[right];
                p--;
                right--;
            }
        }
        return res;
    }
};
// @lc code=end




/*
// @lcpr case=start
// [-4,-1,0,3,10]\n
// @lcpr case=end

// @lcpr case=start
// [-7,-3,2,3,11]\n
// @lcpr case=end

 */

