/*
 * @lc app=leetcode.cn id=23 lang=cpp
 * @lcpr version=30202
 *
 * [23] 合并 K 个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return nullptr;
        }
        ListNode* dummy = new ListNode(0);
        ListNode* p = dummy;
        class GreaterByVal {
        public:
            bool operator()(ListNode* a, ListNode* b) {
                return a->val > b->val;
            }
        };
        priority_queue<ListNode*, vector<ListNode*>, GreaterByVal> minHeap;
        for (ListNode* head : lists) {
            if (head != nullptr) {
                minHeap.push(head);
            }
        }
        while (!minHeap.empty()) {
            ListNode* node = minHeap.top();
            p->next = node;
            if (node->next != nullptr) {
                minHeap.push(node->next);
            }
            minHeap.pop();
            p = p->next;
        }
        return dummy->next;
    }
};
// @lc code=end




/*
// @lcpr case=start
// [[1,4,5],[1,3,4],[2,6]]\n
// @lcpr case=end

// @lcpr case=start
// []\n
// @lcpr case=end

// @lcpr case=start
// [[]]\n
// @lcpr case=end

 */

