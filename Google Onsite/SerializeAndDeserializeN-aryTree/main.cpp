#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <stack>

using namespace std;

struct TreeNode {
    char val;
    vector<TreeNode*> children;
    TreeNode(char val) {
        this->val = val;
    }
};

//Reference:
//http://www.geeksforgeeks.org/serialize-deserialize-n-ary-tree/
//The following is another iterative way to desrialize
//http://www.1point3acres.com/bbs/thread-116171-1-1.html

struct Solution {
public:
    string SerializeNaryTree(TreeNode* root) {
        if (root == nullptr) return "";
        string result = string{root->val};
        result += " ";
        for (TreeNode* child : root->children) {
            result += SerializeNaryTree(child);
        }
        result += "# ";
        return result;
    }
    TreeNode* DeserializeNaryTree(string& s) {
        if (s.empty()) return nullptr;
        stringstream ss(s);
        return DeserializeNaryTreeHelper(ss);
    }
    TreeNode* BuildTree() {
        auto root = new TreeNode('A');
        root->children.push_back(new TreeNode('B'));
        root->children.push_back(new TreeNode('C'));
        root->children.push_back(new TreeNode('D'));
        root->children[0]->children.push_back(new TreeNode('E'));
        root->children[0]->children.push_back(new TreeNode('F'));
        root->children[2]->children.push_back(new TreeNode('G'));
        root->children[2]->children.push_back(new TreeNode('H'));
        root->children[2]->children.push_back(new TreeNode('I'));
        root->children[2]->children.push_back(new TreeNode('J'));
        root->children[0]->children[1]->children.push_back(new TreeNode('K'));
        return root;
    }
    void printTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto current = q.front();
                q.pop();
                cout << current->val << " ";
                for (auto child : current->children) {
                    q.push(child);
                }
            }
            cout << "# " << endl;
        }
    }
    TreeNode* DeserializeNaryTreeHelper(stringstream& ss) {
        char val;
        ss >> val;
        if (val == '#') {
            return nullptr;
        } else {
            TreeNode* root = new TreeNode(val);
            while (true) {
                TreeNode* child = DeserializeNaryTreeHelper(ss);
                if (child == nullptr) {
                    break;
                } else {
                    root->children.push_back(child);
                }
            }
            return root;
        }
    }
    TreeNode* iterativeDeserializeTree(string& s) {
        if (s.empty()) return nullptr;
        stringstream ss(s);
        stack<TreeNode*> parents;
        char val;
        ss >> val;
        TreeNode* root = new TreeNode(val);
        parents.push(root);
        while (ss >> val) {
            if (val != '#') {
                auto node = new TreeNode(val);
                parents.top()->children.push_back(node);
                parents.push(node);
            } else {
                parents.pop();
            }
        }
        return root;
    }
};


int main() {
    Solution a;
    auto root = a.BuildTree();
    a.printTree(root);
    string tree = a.SerializeNaryTree(root);
    cout << tree << endl;
    auto root2 = a.DeserializeNaryTree(tree);
//    a.printTree(root2);
    auto root3 = a.iterativeDeserializeTree(tree);
    a.printTree(root3);
    return 0;
}