/*
 * @lc app=leetcode.cn id=895 lang=cpp
 * @lcpr version=30203
 *
 * [895] 最大频率栈
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
class FreqStack {
    int maxFreq = 0;
    unordered_map<int, int> valToFreq;
    unordered_map<int, stack<int>> freqToVals;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        int freq = valToFreq.count(val) ? valToFreq[val] + 1 : 1;
        valToFreq[val] = freq;
        freqToVals[freq].push(val);
        maxFreq = max(maxFreq, freq);
    }
    
    int pop() {
        int val = freqToVals[maxFreq].top();
        freqToVals[maxFreq].pop();
        valToFreq[val]--;
        if (freqToVals[maxFreq].empty()) {
            maxFreq--;
        }
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
// @lc code=end




/*
// @lcpr case=start
// ["FreqStack","push","push","push","push","push","push","pop","pop","pop","pop"],\n[[],[5],[7],[5],[7],[4],[5],[],[],[],[]]\n
// @lcpr case=end

 */

