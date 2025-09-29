/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=30203
 *
 * [20] 有效的括号
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
    bool isValid(string s) {
        stack<char> left;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{') {
                left.push(c);
            } else {
                if (!left.empty() && leftBracket(c) == left.top()) {
                    left.pop();
                } else {
                    return false;
                }
            }
        }
        return left.empty();
    }
private:
    char leftBracket(char c) {
        if (c == ')') return '(';
        if (c == ']') return '[';
        return '{';
    }
};
// @lc code=end




/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

// @lcpr case=start
// "([)]"\n
// @lcpr case=end

 */

