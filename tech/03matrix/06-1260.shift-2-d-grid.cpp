/*
 * @lc app=leetcode.cn id=1260 lang=cpp
 * @lcpr version=30203
 *
 * [1260] 二维网格迁移
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
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        int mn = m * n;
        if(mn <=1 ) {
            return grid;
        }
        k = k % mn;
        vector<int> v;
        for (int i = 0; i < mn - k; i++) {
            v.push_back(get(grid, i));
        }
        for (int j = 0; j < mn - v.size(); j++) {
            set(grid, j, get(grid, v.size() + j));
        }
        for (int t = 0; t < v.size(); t++) {
            set(grid, k + t, v[t]);
        }
        return grid;
    }

    int get(vector<vector<int>>& grid, int idx) {
        int n = grid[0].size();
        int i = idx / n, j = idx % n;
        return grid[i][j];
    }

    void set(vector<vector<int>>& grid, int idx, int val) {
        int n = grid[0].size();
        int i = idx / n, j = idx % n;
        grid[i][j] = val;
        return;
    }
};
// @lc code=end




/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n1\n
// @lcpr case=end

// @lcpr case=start
// [[3,8,1,9],[19,7,2,5],[4,6,11,10],[12,0,21,13]]\n4\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n9\n
// @lcpr case=end

 */

