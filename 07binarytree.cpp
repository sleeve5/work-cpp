#include<bits/stdc++.h>
using namespace std;

// 二叉树
class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    // 二叉树的遍历
    /*
    递归遍历DFS
        |----前序
        |----中序
        |----后序
    层序遍历BFS
        |----方法1
        |----方法2
        |----方法3
    */

    // 递归遍历
    void DFStraverse(TreeNode* node, vector<int> &res, const string &method) {
        if (node == nullptr) {
            return;
        }
        // traverse左右互换可得到反向遍历
        // 前中后序区别在于push的位置
        if (method == "pre") {
            res.push_back(node->val);
        }
        DFStraverse(node->left, res, method);
        if (method == "mid") {
            res.push_back(node->val);
        }
        DFStraverse(node->right, res, method);
        if (method == "post") {
            res.push_back(node->val);
        }
    }

    // 层序遍历，第二种写法，去掉for、depth为第一种
    void BFStraverse(TreeNode* root, vector<int> &res) {
        if (root == nullptr) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;
        while (!q.empty()) {                // 遍历层数
            int sz = q.size();
            for (int i = 0; i < sz; i++) {  // 或while (sz-- > 0) {} 遍历每层的节点
                TreeNode* cur = q.front();
                res.push_back(cur->val);
                if (cur->left != nullptr) {
                    q.push(cur->left);
                }
                if (cur->right != nullptr) {
                    q.push(cur->right);
                }
                q.pop();
            }
            depth++;
        }
        cout << depth << endl;
    }

    // method：level为层序递归，pre为前序遍历。mid为中序遍历，post为后序遍历
    vector<int> order(TreeNode* root, const string &method) {
        vector<int> res;
        if (method == "level") {
            BFStraverse(root, res);
        }
        DFStraverse(root, res, method);
        return res;
    }

    void printVector(vector<int> &res) {
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << "  ";
        }
    }
};

int main() {
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(6);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(4);
    // 构建出来的二叉树是这样的：
    //     1
    //    / \
    //   3   2
    //  /   / \
    // 6       4
    vector<int> res = root->order(root, "level");
    root->printVector(res);     // 1 3 6 2 5 4
    return 0;
}