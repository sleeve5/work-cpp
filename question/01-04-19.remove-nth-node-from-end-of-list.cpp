/*
 * @lc app=leetcode.cn id=19 lang=cpp
 * @lcpr version=30203
 *
 * [19] 删除链表的倒数第 N 个结点
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

// class TreeNode {
// public:
//     int val;
//     TreeNode *left;
//     TreeNode *right;
//     TreeNode() : val(0), left(nullptr), right(nullptr) { }
//     TreeNode(int x) : val(x), left(nullptr), right(nullptr) { }
//     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) { }
// };

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p2 = findFromEnd(dummy, n+1);
        p2->next = p2->next->next;
        return dummy->next;
    }

    ListNode* findFromEnd(ListNode* head, int n) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        for (int i = 0; i < n; i++) {
            p1 = p1->next;
        }
        while (p1 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2;
    }
};
// @lc code=end




/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n
// @lcpr case=end

// @lcpr case=start
// [1]\n1\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n1\n
// @lcpr case=end

 */

