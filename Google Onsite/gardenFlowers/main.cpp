#include <iostream>
#include <vector>
#include <utility>

using namespace std;

class Solution {
public:
    //0 is nothing
    //1 is flower
    //2 is wall
    void findPosition(vector<vector<int>> &matrix) {
        int rowSize = matrix.size();
        int columnSize = rowSize ? matrix[0].size() : 0;
        vector<vector<int>> dp(matrix);
        for (int i = 0; i < rowSize; ++i) {
            int leftMax = 0;
            int rightMax = 0;
            for (int j = 0; j < columnSize; ++j) {
                if (matrix[i][j] != 2) {
                    dp[i][j] += leftMax;
                    leftMax += matrix[i][j];
                } else {
                    dp[i][j] = 0;
                    leftMax = 0;
                }
                if (matrix[i][columnSize - 1 - j] != 2) {
                    dp[i][columnSize - 1 - j] += rightMax;
                    rightMax += matrix[i][columnSize - 1 - j];
                } else {
                    rightMax = 0;
                }
            }
        }
        vector<pair < int, int>>
        bestPositions;
        int maxFlowers = 0;
        for (int j = 0; j < columnSize; ++j) {
            int upMax = 0;
            int downMax = 0;
            for (int i = 0; i < rowSize; ++i) {
                if (matrix[i][j] != 2) {
                    dp[i][j] += upMax;
                    upMax += matrix[i][j];
                } else {
                    upMax = 0;
                }
                if (matrix[rowSize - 1 - i][j] != 2) {
                    dp[rowSize - 1 - i][j] += downMax;
                    downMax += matrix[rowSize - 1 - i][j];
                } else {
                    downMax = 0;
                }
                if (dp[i][j] > maxFlowers) {
                    bestPositions.clear();
                    bestPositions.emplace_back(i, j);
                    maxFlowers = dp[i][j];
                } else if (dp[i][j] == maxFlowers) {
                    bestPositions.emplace_back(i, j);
                }
                if (dp[rowSize - 1 - i][j] > maxFlowers) {
                    bestPositions.clear();
                    bestPositions.emplace_back(rowSize - 1 - i, j);
                    maxFlowers = dp[i][j];
                } else if (dp[rowSize - 1 - i][j] == maxFlowers) {
                    bestPositions.emplace_back(rowSize - 1 - i, j);
                }
            }
        }
        cout << "maxFlowers = " << maxFlowers << endl;
        cout << "bestPositions = " << endl;
        for (auto &position : bestPositions) {
            cout << position.first << " " << position.second << endl;
        }
    }

    void findPositions2(vector<vector<int>> &matrix) {
        int rowSize = matrix.size();
        int columnSize = rowSize ? matrix[0].size() : 0;
        auto dp = matrix;
        for (int i = 0; i < rowSize; ++i) {
            int max = 0;
            for (int j = 0; j < columnSize; ++j) {
                if (matrix[i][j] != 2) {
                    dp[i][j] += max;
                    max += matrix[i][j];
                } else {
                    dp[i][j] = 0;
                    max = 0;
                }
            }
        }
        for (int i = 0; i < rowSize; ++i) {
            int max = 0;
            for (int j = columnSize - 1; j >= 0; --j) {
                if (matrix[i][j] != 2) {
                    dp[i][j] += max;
                    max += matrix[i][j];
                } else {
                    max = 0;
                }
            }
        }
        for (int j = 0; j < columnSize; ++j) {
            int max = 0;
            for (int i = 0; i < rowSize; ++i) {
                if (matrix[i][j] != 2) {
                    dp[i][j] += max;
                    max += matrix[i][j];
                } else {
                    max = 0;
                }
            }
        }
        vector<pair<int, int>> bestPositions;
        int maxFlowers = 0;
        for (int j = 0; j < columnSize; ++j) {
            int max = 0;
            for (int i = rowSize - 1; i >= 0; --i) {
                if (matrix[i][j] != 2) {
                    dp[i][j] += max;
                    max += matrix[i][j];
                } else {
                    max = 0;
                }
                if (dp[i][j] > maxFlowers) {
                    bestPositions.clear();
                    bestPositions.emplace_back(i, j);
                    maxFlowers = dp[i][j];
                } else if (dp[i][j] == maxFlowers) {
                    bestPositions.emplace_back(i, j);
                }
            }
        }
        cout << "maxFlowers = " << maxFlowers << endl;
        cout << "bestPositions = " << endl;
        for (auto &position : bestPositions) {
            cout << position.first << " " << position.second << endl;
        }
    }
};


int main() {
    Solution a;
    vector<vector<int>> matrix{
            {1, 0, 0, 2, 1},
            {1, 1, 0, 0, 0},
            {0, 0, 1, 2, 1},
            {1, 1, 0, 2, 0}
    };
    a.findPositions2(matrix);
    a.findPosition(matrix);
    return 0;
}