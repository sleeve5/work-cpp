/*
 * @lc app=leetcode.cn id=143 lang=cpp
 * @lcpr version=30203
 *
 * [143] 重排链表
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
    void reorderList(ListNode* head) {
        stack<ListNode*> nodes;
        ListNode* p = head;
        while (p) {
            nodes.push(p);
            p = p->next;
        }
        ListNode* p1 = head;
        while (!nodes.empty()) {
            ListNode* lastNode = nodes.top();
            nodes.pop();
            ListNode* next = p1->next;
            if (lastNode == next || (lastNode->next == next)) {
                lastNode->next = nullptr;
                break;
            }
            p1->next = lastNode;
            lastNode->next = next;
            p1 = next;
        }
    }
};
// @lc code=end




/*
// @lcpr case=start
// [1,2,3,4]\n
// @lcpr case=end

// @lcpr case=start
// [1,2,3,4,5]\n
// @lcpr case=end

 */

