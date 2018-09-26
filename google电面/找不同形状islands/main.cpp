#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string getKey(vector<pair<int, int>>& island) {
        int size = island.size();
        auto start = island.front();
        for (int i = 1; i < size; ++i) {
            island[i].first -= start.first;
            island[i].second -= start.second;
        }
        string key = "(0,0)";
        for (int i = 1; i < size; ++i) {
            key += "#(" + to_string(island[i].first) + ",";
            key += to_string(island[i].second) + ")";
        }
        return key;
    }

    int findIslands(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = row ? matrix[0].size() : 0;
        vector<vector<bool>> visited(row, vector<bool>(column, false));
        vector<pair<int, int>> directions{{-1, -1},
                                          {-1, 0},
                                          {-1, 1},
                                          {0,  -1},
                                          {0,  1},
                                          {1,  -1},
                                          {1,  0},
                                          {1,  1}};
        queue<pair<int, int>> nodesQueue;
        vector<vector<pair<int, int>>> islands;
        //if we can modify the input matrix, we don't need the visited matrix
        //we can just set visited matrix 1 to be 0
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                if (matrix[i][j] == 1 && visited[i][j] == false) {
                    nodesQueue.emplace(i, j);
                    visited[i][j] = true;
                    vector<pair<int, int>> island;
                    while (!nodesQueue.empty()) {
                        auto node = nodesQueue.front();
                        nodesQueue.pop();
                        int currentI = node.first;
                        int currentJ = node.second;
                        island.push_back(move(node));
                        for (int ii = max(0, currentI - 1); ii <= min(row - 1, currentI + 1); ++ii) {
                            for (int jj = max(0, currentJ - 1); jj <= min(column - 1, currentJ + 1); ++jj) {
                                if (ii == currentI && jj == currentJ) continue;
                                if (matrix[ii][jj] == 1 && visited[ii][jj] == false) {
                                    nodesQueue.emplace(ii, jj);
                                    visited[ii][jj] = true;
                                }
                            }
                        }
                    }
                    islands.push_back(move(island));
                }
            }
        }
        unordered_set<string> hashSet;
        for (auto& island : islands) {
            hashSet.insert(getKey(island));
        }
        return hashSet.size();
    }
};

int main() {
    vector<vector<int>> matrix{
            {1,0,1,0},
            {0,1,0,0},
            {0,0,0,0},
            {1,0,1,0},
            {0,1,0,0},
    };
    Solution a;
    cout << a.findIslands(matrix) << endl;
    vector<vector<int>> matrix2{
            {1,0,1,0},
            {0,1,0,0},
            {0,0,0,0},
            {1,0,1,0},
            {0,1,0,0},
            {0,0,0,1}
    };
    cout << a.findIslands(matrix2) << endl;
    return 0;
}