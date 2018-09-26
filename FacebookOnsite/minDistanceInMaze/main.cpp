#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int minDistancInMaze(vector<vector<int>>& maze, pair<int, int> start, pair<int, int> end) {
        int rowSize = maze.size();
        int columnSize = rowSize ? maze[0].size() : 0;
        vector<pair<int, int>> directions{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        int distance = 0;
        queue<pair<int, int>> nodesQueue;
        nodesQueue.push(start);
        vector<vector<bool>> visited(rowSize, vector<bool>(columnSize, false));
        visited[start.first][start.second] = true;
        vector<vector<pair<int, int>>> path(rowSize, vector<pair<int, int>>(columnSize));
        bool found = false;
        while (!nodesQueue.empty()) {
            int size = nodesQueue.size();
            for (int i = 0; i < size; ++i) {
                auto current = nodesQueue.front();
                if (current == end) {
                    found = true;
                    break;
                }
                nodesQueue.pop();
                for (auto& direction : directions) {
                    int ii = current.first + direction.first;
                    int jj = current.second + direction.second;
                    if (ii >= 0 && ii < rowSize && jj >= 0 && jj < columnSize
                        && maze[ii][jj] == 1 && visited[ii][jj] == false) {
                        visited[ii][jj] = true;
                        nodesQueue.emplace(ii, jj);
                        path[ii][jj] = current;
                    }
                }
            }
            if (found) break;
            ++distance;
        }
        vector<pair<int, int>> pathToEnd;
        auto current = end;
        while (current != start) {
            pathToEnd.push_back(current);
            current = path[current.first][current.second];
        }
        pathToEnd.push_back(current);
        reverse(pathToEnd.begin(), pathToEnd.end());
        for (auto& position : pathToEnd) {
            cout << position.first << " " << position.second << endl;
        }
        return pathToEnd.size();
    }
};


int main() {
    Solution a;
    vector<vector<int>> maze{{0, 0, 0, 1}, {0, 0, 0, 1}, {0, 1, 1, 1}, {1, 1, 0, 0}};
    cout << a.minDistancInMaze(maze, {0, 3}, {3, 0});
    return 0;
}