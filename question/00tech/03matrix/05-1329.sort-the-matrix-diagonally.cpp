/*
 * @lc app=leetcode.cn id=1329 lang=cpp
 * @lcpr version=30203
 *
 * [1329] 将矩阵按对角线排序
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
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        unordered_map<int, vector<int>> diags;
        int m = mat.size(), n = mat[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int id = i - j;
                diags[id].push_back(mat[i][j]);
            }
        }
        for (auto& i : diags) {
            sort(i.second.begin(), i.second.end(), greater<int>());
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                vector<int>& diag = diags[i - j];
                mat[i][j] = diag.back();
                diag.pop_back();
            }
        }
        return mat;
    }
};
// @lc code=end




/*
// @lcpr case=start
// [[3,3,1,1],[2,2,1,2],[1,1,1,2]]\n
// @lcpr case=end

// @lcpr case=start
// [[11,25,66,1,69,7],[23,55,17,45,15,52],[75,31,36,44,58,8],[22,27,33,25,68,4],[84,28,14,11,5,50]]\n
// @lcpr case=end

 */

