/*
 * @lc app=leetcode.cn id=388 lang=cpp
 * @lcpr version=30203
 *
 * [388] 文件的最长绝对路径
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
    int lengthLongestPath(string input) {
        deque<int> stk;
        vector<string> parts = split(input, '\n');
        int maxLen = 0;
        for (auto part : parts) {
            int level = part.rfind("\t") + 1;
            while (level < stk.size()) {
                stk.pop_back();
            }
            stk.push_back(part.size() - level);
            if (part.find('.') != string::npos) {
                int sum = 0;
                for (auto i : stk) {
                    sum += i;
                }
                sum += stk.size() - 1; 
                maxLen = max(maxLen, sum);
            }
        }
        return maxLen;
    }

    vector<string> split(string& s, char c) {
        vector<string> res;
        string token;
        istringstream mystream(s);
        while (getline(mystream, token, c)) {
            res.push_back(token);
        }
        return res;
    }
};
// @lc code=end


/*
// @lcpr case=start
// "dir\n\tsubdir1\n\tsubdir2\n\t\tfile.ext"\n
// @lcpr case=end

// @lcpr case=start
// "dir\n\tsubdir1\n\t\tfile1.ext\n\t\tsubsubdir1\n\tsubdir2\n\t\tsubsubdir2\n\t\t\tfile2.ext"\n
// @lcpr case=end

// @lcpr case=start
// "a"\n
// @lcpr case=end

// @lcpr case=start
// "file1.txt\nfile2.txt\nlongfile.txt"\n
// @lcpr case=end

 */

