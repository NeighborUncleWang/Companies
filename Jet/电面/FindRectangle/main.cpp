#include <iostream>
#include <vector>

using namespace std;

int searchRow(vector<vector<int>>& matrix, int row, int col, bool tag) {
    int low = 0, high = row - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int k = 0;
        while (k < col && matrix[mid][k] == 1) ++k;
        if (k < col == tag) {
            mid = high - 1;
        } else {
            mid = low + 1;
        }
    }
    return low;
}

int searchCol(vector<vector<int>>& matrix, int row, int col, bool tag) {
    int low = 0, high = col - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int k = 0;
        while (k < col && matrix[k][mid] == 1) ++k;
        if (k < row == tag) {
            mid = high - 1;
        } else {
            mid = low + 1;
        }
    }
    return low;
}

vector<int> FindSingleRectangle(vector<vector<int>>& matrix) {
    int row = matrix.size(), col = row ? matrix[0].size() : 0;
    int row_l = searchRow(matrix, row, col, true);
    int row_h = searchRow(matrix, row, col, false);
    int col_l = searchCol(matrix, row, col, true);
    int col_h = searchCol(matrix, row, col, false);
    return vector<int>{row_l, col_l, col_h - col_l, row_h - row_l};
};


vector<vector<int>> FindRectangle(vector<vector<int>>& matrix) {
    int row = matrix.size(), col = row ? matrix[0].size() : 0;
    vector<vector<int>> res;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (matrix[i][j] == 0 && (i == 0 || matrix[i - 1][j] == 1) &&
                    (j == 0 || matrix[i][j - 1] == 1)) {
                int ii = i, jj = j;
                while (ii < row && matrix[ii][j] == 0) ++ii;
                while (jj < col && matrix[i][jj] == 0) ++jj;
//                int length = max(ii - i, jj - j), width = min(ii - i, jj - j);
                res.push_back({i, j, jj - j, ii - i});
            }
        }
    }
    return res;
}



int main() {
    vector<vector<int>> matrix{{1,1,1,1,1,1},
                               {1,0,0,0,1,1},
                               {1,0,0,0,1,1},
                               {1,1,1,1,1,1},
                               {1,1,1,1,1,1}};
    auto res = FindRectangle(matrix);
    for (auto& list : res) {
        for (int i : list) {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
    matrix = vector<vector<int>>{{1,1,1,1,0,0},
                                {1,0,0,0,1,1},
                                {1,0,0,0,1,1},
                                {1,1,1,1,0,0},
                                {1,1,1,1,0,0}};
    res = FindRectangle(matrix);
    for (auto& list : res) {
        for (int i : list) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}