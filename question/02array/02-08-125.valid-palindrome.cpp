/*
 * @lc app=leetcode.cn id=125 lang=cpp
 * @lcpr version=30203
 *
 * [125] 验证回文串
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
    bool isPalindrome(string s) {
        string str;
        for (auto i : s) {
            if (isalnum(i)) {
                str += tolower(i);
            }
        }
        int left = 0, right = str.length() - 1;
        bool res = true;
        while (left < right) {
            if (str[left] != str[right]) {
                res = false;
            }
            left++;
            right--;
        }
        return res;
    }
};
// @lc code=end




/*
// @lcpr case=start
// "A man, a plan, a canal: Panama"\n
// @lcpr case=end

// @lcpr case=start
// "race a car"\n
// @lcpr case=end

// @lcpr case=start
// " "\n
// @lcpr case=end

 */

