/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=30203
 *
 * [5] 最长回文子串
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
    string longestPalindrome(string s) {
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            string s1 = getPalindrome(s, i, i);
            string s2 = getPalindrome(s, i, i + 1);
            string tmp = s1.size() > s2.size() ? s1 : s2;
            res = tmp.size() > res.size() ? tmp : res;
        }
        return res;
    }
    string getPalindrome(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        string result = "";
        left++;
        while (left < right) {
            result += s[left];
            left++;
        }
        return result;
    }
};
// @lc code=end




/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

