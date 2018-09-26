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
    int diameter(TreeNode* root) {
        int diameter = 0;
        TreeNode* middleNode = nullptr;
        dfs(root, diameter, middleNode);
        cout << "middleNode is: " << middleNode->val << endl;
        return diameter;
    }
private:
    int dfs(TreeNode* current, int& diameter, TreeNode*& middleNode) {
        if (current == nullptr) {
            return 0;
        }
        int left = dfs(current->left, diameter, middleNode);
        int right = dfs(current->right, diameter, middleNode);
        if (left + right + 1 > diameter) {
            diameter = left + right + 1;
            middleNode = current;
        }
        return 1 + max(left, right);
    }
};


int main() {
    Solution a;
//    root1:
//             1
//            / \
//           3   2
//          / \
//         4   5
//        /     \
//       6       7
//      /         \
//     8           9
    auto root1 = new TreeNode(1);
    root1->right = new TreeNode(2);
    root1->left = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->left->left = new TreeNode(6);
    root1->left->left->left->left = new TreeNode(8);
    root1->left->right = new TreeNode(5);
    root1->left->right->right = new TreeNode(7);
    root1->left->right->right->right = new TreeNode(9);
    cout << a.diameter(root1) << endl;
    //root2
//             1
//            / \
//           3   2
//          /
//         4
//        /
//       6
//      /
//     8
    auto root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    root2->left = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->left->left = new TreeNode(6);
    root2->left->left->left->left = new TreeNode(8);
    cout << a.diameter(root2) << endl;
    return 0;
}