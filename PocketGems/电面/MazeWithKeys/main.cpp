#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<pair<int, int>> FindPath(vector<string>& maze) {
        int row = maze.size(), col = row ? maze[0].size() : 0;
        unordered_set<string> visited;
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        vector<pair<int, int>> res;
        vector<pair<int, int>> path;
        int keys = 0, min_step = INT_MAX;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (maze[i][j] == '2') {
                    dfs(maze, i, j, row, col, res, path, keys, visited, directions, min_step, 0);
                }
            }
        }
        return res;
    }

private:
    void dfs(vector<string>& maze, int i, int j, int row, int col, vector<pair<int, int>>& res, vector<pair<int, int>>& path,
             int keys, unordered_set<string>& visited, vector<pair<int, int>> directions, int& min_step, int depth) {
//        cout << i << " " << j << endl;
        if (depth >= min_step) {
            return;
        }
        if (islower(maze[i][j])) {
            keys |= 1 << (maze[i][j] = 'a');
        } else if (isupper(maze[i][j])) {
            if ((keys & (1 << (maze[i][j] - 'A'))) == 0) {
                return;
            }
        }
        string cur = "(" + to_string(i) + "," + to_string(j) + ")_" + to_string(keys);
        path.emplace_back(i, j);
        visited.insert(cur);
        if (maze[i][j] == '3') {
            min_step = depth;
            res = path;
            path.pop_back();
            visited.erase(cur);
            return;
        }
        for (auto& direction : directions) {
            int ii = direction.first + i;
            int jj = direction.second + j;
            string tag = "(" + to_string(ii) + "," + to_string(jj) + ")_" + to_string(keys);
            if (ii >= 0 && ii < row && jj >= 0 && jj < col && visited.find(tag) == visited.end() &&
                        (maze[ii][jj] == '1' || maze[ii][jj] == '3' || maze[ii][jj] == '2' || isalpha(maze[ii][jj]))) {
                dfs(maze, ii, jj, row, col, res, path, keys, visited, directions, min_step, depth + 1);
            }
        }
        path.pop_back();
        visited.erase(cur);
    }
};

int main() {
    Solution a;
    vector<string> maze{"02111", "01001", "01003", "01001", "01111"};
    auto res = a.FindPath(maze);
    for (auto pos : res) {
        cout << pos.first << " " << pos.second << endl;
    }
    cout << endl;
    maze = vector<string>{"02a11", "0100A", "01003", "01001", "01111"};
    res = a.FindPath(maze);
    for (auto pos : res) {
        cout << pos.first << " " << pos.second << endl;
    }
    cout << endl;
    maze = vector<string>{"02111", "0100A", "01003", "01000", "0111a"};
    res = a.FindPath(maze);
    for (auto pos : res) {
        cout << pos.first << " " << pos.second << endl;
    }
    return 0;
}