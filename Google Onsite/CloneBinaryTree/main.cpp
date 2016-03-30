#include <iostream>
#include <unordered_map>
#include <queue>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    TreeNode* cloneBinaryTree(TreeNode* root) {
        if (root == nullptr) return nullptr;
//        unordered_map<TreeNode*, TreeNode*> hashMap;
//        hashMap[node] = new TreeNode(node->val);
        queue<TreeNode*> nodesQueue;
        nodesQueue.push(root);
        TreeNode* newRoot = new TreeNode(root->val);
        nodesQueue.push(newRoot);
        while (!nodesQueue.empty()) {
            TreeNode* current = nodesQueue.front();
            nodesQueue.pop();
            TreeNode* copyCurrent = nodesQueue.front();
            nodesQueue.pop();
            if (current->left) {
                nodesQueue.push(current->left);
                copyCurrent->left = new TreeNode(current->left->val);
                nodesQueue.push(copyCurrent->left);
            }
            if (current->right) {
                nodesQueue.push(current->right);
                copyCurrent->right = new TreeNode(current->right->val);
                nodesQueue.push(copyCurrent->right);
            }
        }
        return newRoot;
    }
};

void printTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto current = q.front();
            q.pop();
            cout << current->val << " ";
            if (current->left) {
                q.push(current->left);
            }
            if (current->right) {
                q.push(current->right);
            }
        }
        cout << endl;
    }
}


int main() {
    Solution a;
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(0);
    root->right = new TreeNode(3);
    printTree(root);
    printTree(a.cloneBinaryTree(root));
    return 0;
}