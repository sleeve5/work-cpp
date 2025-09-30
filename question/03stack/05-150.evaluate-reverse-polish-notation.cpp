/*
 * @lc app=leetcode.cn id=150 lang=cpp
 * @lcpr version=30203
 *
 * [150] 逆波兰表达式求值
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
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        for (auto token : tokens) {
            if (token == "+" || token == "-" || token == "*" || token == "/") {
                int a = stk.top();
                stk.pop();
                int b = stk.top();
                stk.pop();
                int tmp;
                if (token == "+") {
                    tmp = b + a;
                }
                if (token == "-") {
                    tmp = b - a;
                }
                if (token == "*") {
                    tmp = b * a;
                }
                if (token == "/") {
                    tmp = b / a;
                }
                stk.push(tmp);
            } else {
                stk.push(stoi(token));
            }
        }
        return stk.top();
    }
};
// @lc code=end




/*
// @lcpr case=start
// ["2","1","+","3","*"]\n
// @lcpr case=end

// @lcpr case=start
// ["4","13","5","/","+"]\n
// @lcpr case=end

// @lcpr case=start
// ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]\n
// @lcpr case=end

 */

