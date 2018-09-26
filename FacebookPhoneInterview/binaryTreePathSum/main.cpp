#include <iostream>
#include <stack>
#include <vector>
#include <numeric>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

struct Solution {
    int sumRootToLeaf(TreeNode* root) {
        int sum = 0;
        dfs(root, 0, sum);
        return sum;
    }
    int sumRootToLeaf2(TreeNode* root) {
        return dfs2(root, 0);
    }
    int sumRootToLeafIterative(TreeNode* root) {
        stack<TreeNode*> st;
        st.push(root);
        vector<int> sums{root->val};
        int sum = 0;
        while (!st.empty()) {
            auto current = st.top();
            st.pop();
            int currentTop = sums.back();
            sums.pop_back();
            if (current->left == nullptr && current->right == nullptr) {
                sum += currentTop;
                continue;
            }
            if (current->right) {
                st.push(current->right);
                sums.push_back(currentTop + current->right->val);
            }
            if (current->left) {
                st.push(current->left);
                sums.push_back(currentTop + current->left->val);
            }
        }
        return sum;
    }
    int dfs2(TreeNode* current, int currentVal) {
        if (current == nullptr) return 0;
        if (current->left == nullptr && current->right == nullptr) {
            return currentVal + current->val;
        }
        currentVal += current->val;
        return dfs2(current->left, currentVal) + dfs2(current->right, currentVal);
    }
    void dfs(TreeNode* current, int currentVal, int& sum) {
        if (current == nullptr) return ;
        if (current->left == nullptr && current->right == nullptr) {
            currentVal += current->val;
            sum += currentVal;
            return;
        }
        currentVal += current->val;
        dfs(current->left, currentVal, sum);
        dfs(current->right, currentVal, sum);
    }
};

int main() {
    Solution a;
    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);
    root->right->left = new TreeNode(10);
    cout << a.sumRootToLeaf(root) << endl;
    cout << a.sumRootToLeaf2(root) << endl;
    cout << a.sumRootToLeafIterative(root) << endl;
    return 0;
}