#include <iostream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

//reference:
//http://www.geeksforgeeks.org/check-if-a-binary-tree-is-subtree-of-another-binary-tree/

class Solution {
public:
    bool verifySubtree(TreeNode *big, TreeNode *small) {
        //do we really need the two base cases?
//        if (small == nullptr) return true;
//        if (big == nullptr) return false;
        if (isIdentical(big, small)) return true;
        return isIdentical(big->left, small) || isIdentical(big->right, small);
    }

private:
    bool isIdentical(TreeNode *p, TreeNode *q) {
        if (p == nullptr && q == nullptr) return true;
        if (p == nullptr || q == nullptr) return false;
        return p->val == q->val && isIdentical(p->left, q->left)
               && isIdentical(p->right, q->right);
    }
};

int main() {
    Solution a;
    // TREE 1
    /* Construct the following tree
              26
            /   \
          10     3
        /    \     \
      4      6      3
       \
        30
    */
    TreeNode *T = new TreeNode(26);
    T->right = new TreeNode(3);
    T->right->right = new TreeNode(3);
    T->left = new TreeNode(10);
    T->left->left = new TreeNode(4);
    T->left->left->right = new TreeNode(30);
    T->left->right = new TreeNode(6);

    // TREE 2
    /* Construct the following tree
          10
        /    \
      4      6
       \
        30
    */
    TreeNode *S = new TreeNode(10);
    S->right = new TreeNode(6);
    S->left = new TreeNode(4);
    S->left->right = new TreeNode(30);
    cout << a.verifySubtree(T, S);
    return 0;
}