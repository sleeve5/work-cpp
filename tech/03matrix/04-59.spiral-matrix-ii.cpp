/*
 * @lc app=leetcode.cn id=59 lang=cpp
 * @lcpr version=30203
 *
 * [59] 螺旋矩阵 II
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
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int left = 0, right = n - 1, upper = 0, lower = n - 1;
        int num = 1;
        while (num <= n*n) {
            if (upper <= lower) {
                for (int i = left; i <= right; i++) {
                    matrix[upper][i] = num;
                    num++;
                }
                upper++;
            }
            if (right >= left) {
                for (int j = upper; j <= lower; j++) {
                    matrix[j][right] = num;
                    num++;
                }
                right--;
            }
            if (lower >= upper) {
                for (int i = right; i >= left; i--) {
                    matrix[lower][i] = num;
                    num++;
                }
                lower--;
            }
            if (left <= right) {
                for (int j = lower; j >= upper; j--) {
                    matrix[j][left] = num;
                    num++;
                }
                left++;
            }
        }
        return matrix;
    }
};
// @lc code=end




/*
// @lcpr case=start
// 3\n
// @lcpr case=end

// @lcpr case=start
// 1\n
// @lcpr case=end

 */

