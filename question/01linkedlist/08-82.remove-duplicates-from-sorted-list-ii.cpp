/*
 * @lc app=leetcode.cn id=82 lang=cpp
 * @lcpr version=30203
 *
 * [82] 删除排序链表中的重复元素 II
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
    // ListNode* deleteDuplicates(ListNode* head) {
    //     ListNode* dummyUniq = new ListNode(101);
    //     ListNode* dummyDup = new ListNode(101);
    //     ListNode* Uniq = dummyUniq;
    //     ListNode* Dup = dummyDup;
    //     ListNode* p = head;
    //     while (p) {
    //         if ((p->next && p->val == p->next->val) || p->val == Dup->val) {
    //             Dup->next = p;
    //             Dup = Dup->next;
    //         } else {
    //             Uniq->next = p;
    //             Uniq = Uniq->next;
    //         }
    //         p = p->next;
    //         Dup->next = nullptr;
    //         Uniq->next = nullptr;
    //     }
    //     return dummyUniq->next;
    // }
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(101);
        ListNode* p = dummy;
        ListNode* q = head;
        while (q) {
            if (q->next && q->val == q->next->val) {
                while (q->next && q->val == q->next->val) {
                    q = q->next;
                }
                q = q->next;
                if (q == nullptr) {
                    p->next = nullptr;
                } 
            } else {
                p->next = q;
                p = p->next;
                q = q->next;
            }
        }
        return dummy->next;
    }
};
// @lc code=end




/*
// @lcpr case=start
// [1,2,3,3,4,4,5]\n
// @lcpr case=end

// @lcpr case=start
// [1,1,1,2,3]\n
// @lcpr case=end

 */

