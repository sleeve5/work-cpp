/*
 * @lc app=leetcode.cn id=80 lang=cpp
 * @lcpr version=30203
 *
 * [80] 删除有序数组中的重复项 II
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
        int slow = 0, fast = 0;
        int count = 0;
        while (fast < nums.size()) {
            if (count < 2) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
            count++;
            if (fast < nums.size() && nums[fast] != nums[fast - 1]) {
                count = 0;
            }
        }
        return slow;
    }
};
// @lc code=end




/*
// @lcpr case=start
// [1,1,1,2,2,3]\n
// @lcpr case=end

// @lcpr case=start
// [0,0,1,1,1,1,2,3,3]\n
// @lcpr case=end

 */

