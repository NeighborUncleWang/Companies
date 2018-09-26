#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct TreeNode {
    char val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* ToBinaryTree(string expression) {
        if (expression.empty()) return nullptr;
        TreeNode* root = new TreeNode(expression[0]);
        stack<TreeNode*> st;
        st.push(root);
        for (int i = 1; i < expression.size(); i += 2) {
            if (expression[i] == '?') {
                st.top()->left = new TreeNode(expression[i + 1]);
                st.push(st.top()->left);
            } else {
                st.pop();
                auto right = new TreeNode(expression[i + 1]);
                st.top()->right = right;
                st.pop();
                st.push(right);
            }
        }
//        cout << st.top()->val << endl;
        return root;
    }
};

void printTree(TreeNode* root) {
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int size = q.size();
        for (int i = 0; i < size; ++i) {
            auto cur = q.front();
            q.pop();
            cout << cur->val << " ";
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        cout << endl;
    }
};

int main() {
    Solution a;
    auto res = a.ToBinaryTree("a?b?c:d:e");
    printTree(res);
    return 0;
}