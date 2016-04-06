#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    vector<vector<vector<pair<int, int>>>> nextPoints;
public:
    void getNextPoints(vector<vector<int>>& matrix) {
        int rowSize = matrix.size();
        int columnSize = rowSize ? matrix[0].size() : 0;
        nextPoints = vector<vector<vector<pair<int, int>>>>
                (rowSize, vector<vector<pair<int, int>>>(columnSize));
        for (int i = 0; i < rowSize; ++i) {
            int lastCol = 0;
            for (int j = 0; j <= columnSize; ++j) {
                if (j == columnSize || matrix[i][j] == 1) {
                    for (int k = lastCol; k < j; ++k) {
                        nextPoints[i][k].emplace_back(i, j - 1);
                        nextPoints[i][k].emplace_back(i, lastCol);
                    }
                    lastCol = j + 1;
                }
            }
        }
        for (int j = 0; j < columnSize; ++j) {
            int lastRow = 0;
            for (int i = 0; i <= rowSize; ++i) {
                if (i == rowSize || matrix[i][j] == 1) {
                    for (int k = lastRow; k < i; ++k) {
                        nextPoints[k][j].emplace_back(i - 1, j);
                        nextPoints[k][j].emplace_back(lastRow, j);
                    }
                    lastRow = i + 1;
                }
            }
        }
    }
    void printNextPoints() {
        for (int i = 0; i < nextPoints.size(); ++i) {
            for (int j = 0; j < nextPoints[0].size(); ++j) {
                cout << "i = " << i << " j = " << j << " : ";
                for (auto& position : nextPoints[i][j]) {
                    cout << "(" << position.first << "," << position.second << "),";
                }
                cout << endl;
            }
        }
    }
    int Maze(vector<vector<int>>& matrix, int i, int j, int iEnd, int jEnd) {
        int rowSize = matrix.size();
        int columnSize = rowSize ? matrix[0].size() : 0;
        queue<pair<int, int>> q;
        q.emplace(i, j);
        int step = 1;
        vector<vector<bool>> visited(rowSize, vector<bool>(columnSize, false));
        visited[i][j] = true;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto current = q.front();
                q.pop();
                for (auto& next : nextPoints[current.first][current.second]) {
                    if (next.first == iEnd && next.second == jEnd) {
                        return step;
                    } else if (!visited[next.first][next.second]) {
                        q.push(next);
                        visited[next.first][next.second] = true;
                    }
                }
            }
            ++step;
        }
        return -1;
    }
};


int main() {
    Solution a;
    vector<vector<int>> matrix{
            {0,0,1,0,0,0},
            {0,0,0,0,0,1},
            {0,1,1,0,0,0},
            {0,0,1,0,0,0}
    };
    a.getNextPoints(matrix);
    a.printNextPoints();
    cout << a.Maze(matrix, 0, 0, 3, 5);
    return 0;
}