/*
 * @lc app=leetcode.cn id=445 lang=cpp
 * @lcpr version=30203
 *
 * [445] 两数相加 II
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
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> stk1;
        stack<int> stk2;
        ListNode* dummy = new ListNode(10);
        ListNode* p = dummy;
        while (l1) {
            stk1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            stk2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        while (!stk1.empty() || !stk2.empty() || carry > 0) {
            int val = carry;
            if (!stk1.empty()) {
                val += stk1.top();
                stk1.pop();
            }
            if (!stk2.empty()) {
                val += stk2.top();
                stk2.pop();
            }
            carry = val / 10;
            val = val % 10;
            ListNode* newNode = new ListNode(val);
            newNode->next = p->next;
            p->next = newNode;
        }
        return dummy->next;
    }
};
// @lc code=end




/*
// @lcpr case=start
// [7,2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [2,4,3]\n[5,6,4]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

 */

