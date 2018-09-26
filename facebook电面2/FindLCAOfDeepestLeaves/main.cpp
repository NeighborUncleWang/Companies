#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    vector<TreeNode*> children;
    TreeNode(int val) {
        this->val = val;
    }
};


struct Solution {
    TreeNode* treeLCA(TreeNode* root) {
        if (root == nullptr) return nullptr;
        return dfs(root, 0).first;
    }
    pair<TreeNode*, int> dfs(TreeNode* current, int depth) {
        if (current->children.empty()) {
            return make_pair(current, depth);
        }
        //这里设置为-1比较好
        int maxDepth = -1;
        TreeNode* maxDepthLCA = nullptr;
        for (TreeNode* child : current->children) {
            pair<TreeNode*, int> result = dfs(child, depth + 1);
            if (result.second > maxDepth) {
                maxDepth = result.second;
                maxDepthLCA = result.first;
            } else if (result.second == maxDepth) {
                //不能直接返回我感觉
                maxDepthLCA = current;
            }
        }
        return {maxDepthLCA, maxDepth};
    }
    TreeNode* treeLCA2(TreeNode* root) {
        if (root == nullptr) return nullptr;
        return dfs2(root).first;
    }
    pair<TreeNode*, int> dfs2(TreeNode* root) {
        if (root->children.empty()) {
            return {root, 0};
        }
        TreeNode* maxDepthLCA = nullptr;
        int maxDepth = -1;
        for (auto child : root->children) {
            auto res = dfs2(child);
            if (res.second > maxDepth) {
                maxDepth = res.second;
                maxDepthLCA = res.first;
            } else if (res.second == maxDepth) {
                maxDepthLCA = root;
            }
        }
        return {maxDepthLCA, maxDepth + 1};
    };
};
int main() {
    Solution a;
    TreeNode* root = new TreeNode(1);
    root->children.push_back(new TreeNode(2));
    root->children.push_back(new TreeNode(3));
    root->children[0]->children.push_back(new TreeNode(4));
    root->children[0]->children.push_back(new TreeNode(5));
    root->children[0]->children.push_back(new TreeNode(6));
    root->children[0]->children[2]->children.push_back(new TreeNode(7));
//    root->children[0]->children[2]->children.push_back(new TreeNode(8));

    cout << a.treeLCA(root)->val << endl;
    return 0;
}