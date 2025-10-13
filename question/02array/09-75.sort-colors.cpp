/*
 * @lc app=leetcode.cn id=75 lang=cpp
 * @lcpr version=30203
 *
 * [75] 颜色分类
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
// class Solution {
// public:
//     void sortColors(vector<int>& nums) {
//         int countR = 0, countW = 0, countB = 0;
//         for (auto i : nums) {
//             if (i == 0) {
//                 countR++;
//             }
//             if (i == 1) {
//                 countW++;
//             }
//             if (i == 2) {
//                 countB++;
//             }
//         }
//         for (int i = 0; i < nums.size(); i++) {
//             while (countR--) {
//                 nums[i] = 0;
//                 i++;
//             }
//             while (countW--) {
//                 nums[i] = 1;
//                 i++;
//             }
//             while (countB--) {
//                 nums[i] = 2;
//                 i++;
//             }
//         }
        
//     }
// };

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1, mid = 0;
        while (mid <= right) {
            if (nums[mid] == 0) {
                swap(nums, left, mid);
                left++;
            } else if (nums[mid] == 2) {
                swap(nums, mid, right);
                right--;
            } else if (nums[mid] == 1) {
                mid++;
            }
            if (mid < left) {
                mid = left;
            }
        }
    }
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
        return;
    }
};
// @lc code=end




/*
// @lcpr case=start
// [2,0,2,1,1,0]\n
// @lcpr case=end

// @lcpr case=start
// [2,0,1]\n
// @lcpr case=end

 */

