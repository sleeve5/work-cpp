/*
 * @lc app=leetcode.cn id=54 lang=cpp
 * @lcpr version=30203
 *
 * [54] 螺旋矩阵
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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int m = matrix.size(), n = matrix[0].size();
        int upper = 0, lower = m - 1, left = 0, right = n - 1;
        while (res.size() < m * n) {
            if (upper <= lower) {
                for (int j = left; j <= right; j++) {
                    res.push_back(matrix[upper][j]);
                }
                upper++;
            }
            if (right >= left) {
                for (int j = upper; j <= lower; j++) {
                    res.push_back(matrix[j][right]);
                }
                right--;
            }
            if (lower >= upper) {
                for (int j = right; j >= left; j--) {
                    res.push_back(matrix[lower][j]);
                }
                lower--;
            }
            if (left <= right) {
                for (int j = lower; j >= upper; j--) {
                    res.push_back(matrix[j][left]);
                }
                left++;
            }
        }
        return res;
    }
};
// @lc code=end




/*
// @lcpr case=start
// [[1,2,3],[4,5,6],[7,8,9]]\n
// @lcpr case=end

// @lcpr case=start
// [[1,2,3,4],[5,6,7,8],[9,10,11,12]]\n
// @lcpr case=end

 */

