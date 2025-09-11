/*
 * @lc app=leetcode.cn id=373 lang=cpp
 * @lcpr version=30203
 *
 * [373] 查找和最小的 K 对数字
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
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // {nums1[i], nums2[i], i}
        class Greater {
        public:
            bool operator() (vector<int> a, vector<int> b) {
                return a[0] + a[1] > b[0] + b[1];
            }
        };
        priority_queue<vector<int>, vector<vector<int>>, Greater> q;
        for (int i = 0; i < nums1.size(); i++) {
            q.push({nums1[i], nums2[0], 0});
        }
        vector<vector<int>> res;
        while (!q.empty() && k > 0) {
            vector<int> tmp = q.top();
            int j = tmp[2] + 1;
            if (j < nums2.size()) {
                q.push({tmp[0], nums2[j], j});
            }
            res.push_back({tmp[0], tmp[1]});
            q.pop();
            k--;
        }
        return res;
    }
};
// @lc code=end




/*
// @lcpr case=start
// [1,7,11]\n[2,4,6]\n3\n
// @lcpr case=end

// @lcpr case=start
// [1,1,2]\n[1,2,3]\n2\n
// @lcpr case=end

 */

