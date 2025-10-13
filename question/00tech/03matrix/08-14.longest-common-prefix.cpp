/*
 * @lc app=leetcode.cn id=14 lang=cpp
 * @lcpr version=30203
 *
 * [14] 最长公共前缀
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

//@lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int m = strs.size(), n = strs[0].length();
        for (int col = 0;col < n;col++) {
            for (int row = 1;row < m;row++) {
                string thisStr = strs[row], prevStr = strs[row - 1];
                if (col >= thisStr.length() || col >= prevStr.length() || thisStr[col] != prevStr[col]) {
                    return strs[row].substr(0, col);
                }
            }
        }
        return strs[0];
    }
};
// @lc code=end




/*
// @lcpr case=start
// ["flower","flow","flight"]\n
// @lcpr case=end

// @lcpr case=start
// ["dog","racecar","car"]\n
// @lcpr case=end

 */

