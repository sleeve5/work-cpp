/*
 * @lc app=leetcode.cn id=225 lang=cpp
 * @lcpr version=30203
 *
 * [225] 用队列实现栈
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
class MyStack {
public:
    MyStack() {
        
    }
    queue<int> q;
    int stack_top = 0;
    
    void push(int x) {
        q.push(x);
        stack_top = x;
    }
    
    int pop() {
        int size = q.size();
        while (size > 2) {
            q.push(q.front());
            q.pop();
            size--;
        }
        stack_top = q.front();
        q.push(q.front());
        q.pop();
        int tail = q.front();
        q.pop();
        return tail;
    }
    
    int top() {
        return stack_top;
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end




/*
// @lcpr case=start
// ["MyStack", "push", "push", "top", "pop", "empty"]\n[[], [1], [2], [], [], []]\n
// @lcpr case=end

 */

