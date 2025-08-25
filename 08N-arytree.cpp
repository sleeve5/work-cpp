#include<bits/stdc++.h>
using namespace std;

// 简洁版定义
class TreeNode {
    int val;
    vector<TreeNode*> children;
    vector<int> res;
    // 递归遍历
    void DFStraverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        // 前序
        res.push_back(root->val);
        for (auto i : root->children) {
            DFStraverse(i);
        }
        // 后序
    }

    // 层序遍历
    void BFStraverse(TreeNode* root) {
        if (root == nullptr) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = 1;
        while (!q.empty()) {
            int sz = q.size();
            TreeNode* cur = q.front();
            while (sz-- > 0) {
                res.push_back(cur->val);
                for (auto i : cur->children) {
                    q.push(i);
                }
                q.pop();
            }
            depth++;
        }
    }
};



int main() {

    return 0;
}
