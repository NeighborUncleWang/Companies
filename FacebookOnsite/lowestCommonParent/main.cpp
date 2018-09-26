#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Solution {
public:
    TreeNode* lowestCommonParent(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return nullptr;
        if (root->left == p || root->left == q || root->right == p || root->left == q) {
            return root;
        }
        TreeNode* left = lowestCommonParent(root->left, p, q);
        TreeNode* right = lowestCommonParent(root->right, p, q);
        if (left != nullptr && right != nullptr) {
            return root;
        } else if (left != nullptr) {
            return left;
        } else {
            return right;
        }
    }
};

int main() {
    cout << "Hello, World!" << endl;
    return 0;
}