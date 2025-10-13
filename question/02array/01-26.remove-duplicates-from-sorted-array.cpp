/*
 * @lc app=leetcode.cn id=26 lang=cpp
 * @lcpr version=30203
 *
 * [26] 删除有序数组中的重复项
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
    int removeDuplicates(vector<int>& nums) {
        if (!nums.size()) {
            return 0;
        }
        int fast = 0, slow = 0;
        for (; fast < nums.size() - 1; fast++) {
            if (nums[fast] != nums[fast + 1]) {
                slow++;
                nums[slow] = nums[fast + 1];
            } else {

            }
        }
        return slow + 1;
    }
};
// @lc code=end




/*
// @lcpr case=start
// [1,1,2]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,2,2,3,3,4]\n
// @lcpr case=end

 */

