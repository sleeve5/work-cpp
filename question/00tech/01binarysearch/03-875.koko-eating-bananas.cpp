/*
 * @lc app=leetcode.cn id=875 lang=cpp
 * @lcpr version=30203
 *
 * [875] 爱吃香蕉的珂珂
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
    int minEatingSpeed(vector<int>& piles, int h) {
        if (piles.empty()) {
            return 0;
        }
        long minSpeed = 1, maxSpeed = 1000000000 + 1;
        while (minSpeed <= maxSpeed) {
            int midSpeed = minSpeed + (maxSpeed - minSpeed) / 2;
            if (eatingTime(piles, midSpeed) == h) {
                maxSpeed = midSpeed - 1;
            } else if (eatingTime(piles, midSpeed) > h) {
                minSpeed = midSpeed + 1;
            } else if (eatingTime(piles, midSpeed) < h) {
                maxSpeed = midSpeed - 1;
            }
        }
        return minSpeed;
    }

    long eatingTime(vector<int>& piles, int k) {
        long time = 0;
        for (auto i : piles) {
            long ti = 0;
            if (!(i % k)) {
                ti = i / k;
            } else {
                ti = (i / k) + 1;
            }
            time += ti;
        }
        return time;
    }
};
// @lc code=end




/*
// @lcpr case=start
// [3,6,7,11]\n8\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n5\n
// @lcpr case=end

// @lcpr case=start
// [30,11,23,4,20]\n6\n
// @lcpr case=end

 */

