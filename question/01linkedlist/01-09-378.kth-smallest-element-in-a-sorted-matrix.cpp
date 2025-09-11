/*
 * @lc app=leetcode.cn id=378 lang=cpp
 * @lcpr version=30203
 *
 * [378] 有序矩阵中第 K 小的元素
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
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        class Greater {
        public:    
            bool operator() (vector<int> a, vector<int> b) {
                return a[0] > b[0];
            }
        };
        priority_queue<vector<int>, vector<vector<int>>, Greater> q;
        for (int i = 0; i < matrix.size(); i++) {
            q.push({matrix[i][0], i, 0});
        }
        int res = -999;
        while (!q.empty() && k > 0) {
            vector<int> tmp = q.top();
            res = tmp[0];
            int i = tmp[1], j = tmp[2];
            if (j < matrix[i].size() - 1) {
                q.push({matrix[i][j+1], i, j + 1});
            }
            q.pop();
            k--;
        }
        return res;
    }
};
// @lc code=end




/*
// @lcpr case=start
// [[1,5,9],[10,11,13],[12,13,15]]\n8\n
// @lcpr case=end

// @lcpr case=start
// [[-5]]\n1\n
// @lcpr case=end

 */

