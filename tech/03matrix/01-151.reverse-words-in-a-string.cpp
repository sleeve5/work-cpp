/*
 * @lc app=leetcode.cn id=151 lang=cpp
 * @lcpr version=30203
 *
 * [151] 反转字符串中的单词
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
    string reverseWords(string s) {
        if (s.empty()) {
            return s;
        }
        s = reverse(s);
        string newString = "";
        string sub = "";
        bool inWord = false;
        for (int i = 0; i< s.length(); i++) {
            if (s[i] !=' ') {
                sub += s[i];
                inWord = true;
                continue;
            }
            if (inWord) {
                newString += (reverse(sub) + ' ');
                sub.clear();
                inWord = false;
            }
        }
        if (!sub.empty()) {                 // 处理最后一段
            newString += reverse(sub);
        }
        while (newString.back() == ' ') {
            newString.pop_back();
        }
        return newString;
    }

    string reverse(string s) {
    for (int i = 0; i < s.length() / 2; i++) {
        swap(s[i], s[s.length() - 1 - i]);
    }
    return s;
}
};

// @lc code=end




/*
// @lcpr case=start
// "the sky is blue"\n
// @lcpr case=end

// @lcpr case=start
// "  hello world  "\n
// @lcpr case=end

// @lcpr case=start
// "a good   example"\n
// @lcpr case=end

 */

