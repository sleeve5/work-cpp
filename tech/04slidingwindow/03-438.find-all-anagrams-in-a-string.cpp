/*
 * @lc app=leetcode.cn id=438 lang=cpp
 * @lcpr version=30203
 *
 * [438] 找到字符串中所有字母异位词
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
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        unordered_map<char, int> window, need;
        int left = 0, right = 0, valid = 0;
        for (auto i : p) {
            need[i]++;
        }
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (need.count(c)) {
                window[c]++;
                if (window[c] == need[c]) {
                    valid++;
                }
            }
            while (right - left >= p.size()) {
                char d = s[left];
                if (valid == need.size()) {
                    res.push_back(left);
                }
                if (need.count(d)) {
                    if (window[d] == need[d]) {
                        valid--;
                    }
                    window[d]--;
                }
                left++;
            }
        }
        return res;
    }
};
// @lc code=end




/*
// @lcpr case=start
// "cbaebabacd"\n"abc"\n
// @lcpr case=end

// @lcpr case=start
// "abab"\n"ab"\n
// @lcpr case=end

 */

