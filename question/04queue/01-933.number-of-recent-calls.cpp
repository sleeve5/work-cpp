/*
 * @lc app=leetcode.cn id=933 lang=cpp
 * @lcpr version=30300
 *
 * [933] 最近的请求次数
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
class RecentCounter {
public:
    queue<int> q;
    RecentCounter() {
        while (!q.empty()) {
            q.pop();
        }
    }
    
    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000) {
            q.pop();
        }
        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
// @lc code=end





/*
// @lcpr case=start
// ["RecentCounter", "ping", "ping", "ping", "ping"]\n[[], [1], [100], [3001], [3002]]\n
// @lcpr case=end

 */

