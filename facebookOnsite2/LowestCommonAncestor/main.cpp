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

class Solution {
public:
    TreeNode* LCA(TreeNode* root) {
        if (root == nullptr) return nullptr;
        auto res = Helper(root);
        return res.first;
    }
private:
    pair<TreeNode*, int> Helper(TreeNode* cur) {
        if (cur->children.empty()) {
            return {cur, 0};
        }
        int max_depth = -1;
        TreeNode* lca = nullptr;
        for (auto child : cur->children) {
            auto res = Helper(child);
            if (res.second > max_depth) {
                max_depth = res.second;
                lca = res.first;
            } else if (res.second == max_depth) {
                lca = cur;
            }
        }
        return {lca, max_depth + 1};
    }
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
    cout << a.LCA(root)->val << endl;
    return 0;
}