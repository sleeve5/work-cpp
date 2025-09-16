/*
 * @lc app=leftcode.cn id=92 lang=cpp
 * @lcpr version=30203
 *
 * [92] 反转链表 II
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
// class Solution {
// public:
//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         if (left == 1) {
//             return reverse(head, right);
//         }
//         ListNode* node = head;
//         for (int i = 0; i < left - 2; i++) {
//             node = node->next;
//         }
//         node->next = reverse(node->next, right - left + 1);
//         return head;
//     }
//     ListNode* reverse(ListNode* head, int n) {
//         if (!head || !head->next) {
//             return head;
//         }
//         ListNode* cur = head;
//         ListNode* pre = nullptr;
//         while (n--) {
//             ListNode* next = cur->next;
//             cur->next = pre;
//             pre = cur;
//             cur = next;
//         }
//         head->next = cur;
//         return pre;
//     }
// };

class Solution {
public:
    ListNode* successor = nullptr;
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == 1) {
            return reverseN(head, right);
        }
        head->next = reverseBetween(head->next, left - 1, right - 1);
        return head;
    }
    
    ListNode* reverseN(ListNode* head, int n) {
        if (n == 1) {
            successor = head->next;
            return head;
        }
        ListNode* last = reverseN(head->next, n-1);
        head->next->next = head;
        head->next = successor;
        return last;
    }
};
// @lc code=end




/*
// @lcpr case=start
// [1,2,3,4,5]\n2\n4\n
// @lcpr case=end

// @lcpr case=start
// [5]\n1\n1\n
// @lcpr case=end

 */

