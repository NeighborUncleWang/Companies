#include <iostream>

using namespace std;


  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    int topMinusDown(TreeNode* root) {
        if (root == nullptr) return INT_MIN;
        return max(helper(root->left, root->val), helper(root->right, root->val));
    }
private:
    int helper(TreeNode* cur, int top_max) {
        if (cur == nullptr) return INT_MIN;
        int res = top_max - cur->val;
        top_max = max(top_max, cur->val);
        return max{res, helper(cur->right, top_max), helper(cur->left, top_max)};
    }
};


int main() {
    cout << "Hello, World!" << endl;
    return 0;
}