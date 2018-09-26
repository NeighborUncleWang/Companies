#include <iostream>

using namespace std;

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *parent;
    TreeNode(int x) : val(x), left(NULL), right(NULL), parent(NULL) { }
};

TreeNode *inorderSuccessor(TreeNode *root, TreeNode *p) {
    TreeNode* successor = nullptr;
    if (p->right) {
        successor = p->right;
        while (successor->left) {
            successor = successor->left;
        }
        return successor;
    } else {
        auto parent = p->parent;
        while (parent && p == parent->right) {
            p = parent;
            parent = p->parent;
        }
        return parent;
    }
}