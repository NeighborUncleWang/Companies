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
    TreeNode* ConvertBT(TreeNode* root) {
        TreeNode dummy_node(0);
        TreeNode* dummy = &dummy_node;
        auto iter = dummy;
        Helper(iter, root);
        iter->right = dummy->right;
        dummy->right->left = iter;
        return dummy->right;
    }
private:
    void Helper(TreeNode*& pre, TreeNode* cur) {
        if (cur == nullptr) {
            return;
        }
        Helper(pre, cur->left);
        cur->left = pre;
        pre->right = cur;
        pre = cur;
        Helper(pre, cur->right);
    }
};

int main() {
    Solution a;
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(8);
    root->right->left = new TreeNode(7);
    root->right->right = new TreeNode(9);
//      5
//     3  8
//    2 4 7 9
    auto head = a.ConvertBT(root);
    auto iter = head;
    while (true) {
        cout << iter->val << " ";
        iter = iter->right;
        if (iter == head) break;
    }
    return 0;
}