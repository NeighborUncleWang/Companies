#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <stack>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};


struct Solution {
    TreeNode* validateBST(unordered_set<TreeNode*> nodeSet) {
        unordered_set<TreeNode*> hasParent;
        for (TreeNode* node : nodeSet) {
            if (node->left) {
                hasParent.insert(node->left);
            }
            if (node->right) {
                hasParent.insert(node->right);
            }
        }
        TreeNode* root = nullptr;
        for (TreeNode* node : nodeSet) {
            if (hasParent.find(node) == hasParent.end()) {
                if (root == nullptr) {
                    root = node;
                } else {
                    return nullptr;
                }
            }
        }
        int visited = 0;
        stack<TreeNode*> st;
        TreeNode* current = root;
        TreeNode* predecessor = nullptr;
        while (!st.empty() || current != nullptr) {
            if (current != nullptr) {
                st.push(current);
                current = current->left;
            } else {
                current = st.top();
                st.pop();
                if (predecessor != nullptr && predecessor->val >= current->val) {
                    return nullptr;
                }
                predecessor = current;
                ++visited;
                current = current->right;
            }
        }
        return visited == nodeSet.size() ? root : nullptr;
    }
};

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->right = new TreeNode(6);
    unordered_set<TreeNode*> nodesSet;
    nodesSet.insert(root);
    nodesSet.insert(root->left);
    nodesSet.insert(root->right);
    nodesSet.insert(new TreeNode(100));
    Solution a;
    cout << (a.validateBST(nodesSet) == root);
    return 0;
}