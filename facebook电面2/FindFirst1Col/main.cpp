#include <iostream>
#include <vector>

using namespace std;

int FindFirstOne(const vector<vector<int>>& matrix) {
    int row = matrix.size(), col = row ? matrix[0].size() : 0;
    int j = col - 1;
    for (int i = 0; i < row; ++i) {
        while (j >= 0 && matrix[i][j] == 1) --j;
    }
    return j + 1;
}

int main() {
    vector<vector<int>> matrix{{0, 0, 1, 1, 1},
                               {0, 1, 1, 1, 1},
                               {0, 0, 1, 1, 1},
                               {0, 0, 0, 0, 0}};
    cout << FindFirstOne(matrix) << endl;
    matrix = vector<vector<int>>{{0, 0, 0, 0, 1},
                                 {0, 0, 1, 1, 1},
                                 {0, 0, 1, 1, 1},
                                 {1, 1, 1, 1, 1}};
    cout << FindFirstOne(matrix) << endl;
    return 0;
}