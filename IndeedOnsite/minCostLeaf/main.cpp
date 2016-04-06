#include <iostream>
#include <vector>

using namespace std;

struct Node;

struct Edge {
    Edge(Node* node, int cost) {
        this->node = node;
        this->cost = cost;
    }
    Node* node;
    int cost;
};

struct Node {
    Node(int val) {
        this->val = val;
    }
    int val;
    vector<Edge*> edges;
};

struct Solution {
    Node* root;
    int minCostLeaf() {
        int minCost = INT_MAX;
        Node* leaf = nullptr;
        dfs(root, 0, minCost, leaf);
        return minCost;
    }
    void dfs(Node* current, int currentCost, int& minCost, Node*& leaf) {
        if (current->edges.empty()) {
            if (currentCost < minCost) {
                minCost = currentCost;
                leaf = current;
            }
            return;
        }
        for (auto edge : current->edges) {
            dfs(edge->node, currentCost + edge->cost, minCost, leaf);
        }
    }
};

int main() {
    Solution a;
    a.root = new Node(0);
    Node* leaf1 = new Node(1);
    Node* leaf2 = new Node(2);
    Edge* edge1 = new Edge(leaf1, 10);
    Edge* edge2 = new Edge(leaf2, 200);
    a.root->edges.push_back(edge1);
    a.root->edges.push_back(edge2);
    cout << a.minCostLeaf();
    return 0;
}