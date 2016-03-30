#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <sstream>
#include <list>
#include <queue>
#include <unordered_set>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) { }
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        stringstream ss;
        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }

private:
    void serializeHelper(TreeNode *current, stringstream &ss) {
        if (current == nullptr) {
            ss << "# ";
            return;
        }
        ss << current->val << " ";
        serializeHelper(current->left, ss);
        serializeHelper(current->right, ss);
    }

    TreeNode *deserializeHelper(stringstream &ss) {
        string val;
        ss >> val;
        if (val == "#") {
            return nullptr;
        } else {
            TreeNode *current = new TreeNode(stoi(val));
            current->left = deserializeHelper(ss);
            current->right = deserializeHelper(ss);
            return current;
        }
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
    Codec a;
    string temp = a.serialize(nullptr);
    TreeNode* root = a.deserialize(temp);
    return 0;
}