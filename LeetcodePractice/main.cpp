#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <unordered_set>
#include <numeric>
#include <fstream>
#include <unordered_map>
#include <sstream>

using namespace std;


void creatFile() {
    const int kRange = 9999 * 2 + 1;
    const int offset = -9999;
    ofstream file;
    file.open("./data.txt");
    for (int i = 0; i < 5000; ++i) {
        for (int j = 0; j < 5; ++j) {
            file << rand() % kRange + offset;
            if (j < 4) {
                file << ",";
            }
        }
        file << endl;
    }
}

int processFile() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    //in my opinion, your rules are not so clear
    //however, I tried my best understanding to implement them
    ifstream file;
    file.open("./data.txt");
    int M, N, P;
    cin >> M >> N >> P;
    if (M > 4 || N > 4) {
        throw invalid_argument("M and N must be no larger than 4.");
    }
    unordered_map<int, int> mapM, mapN;
    string line;
    vector<vector<int>> matrix(5000, vector<int>(5));
    for (int i = 0; i < 5000; ++i) {
        getline(file, line);
        istringstream iss(line);
        for (int j = 0; j < 5; ++j) {
            iss >> matrix[i][j];
        }
        ++mapM[matrix[i][M]];
        ++mapN[matrix[i][N]];
    }
    bool found = false;
    for (int i = 0; i < 5000; ++i) {
        if (found) break;
        for (int j = 0; j < 5; ++j) {
            int count = 0, neighbors = 0;
            if (i == 0) {
                ++count;
            } else if (matrix[i - 1][j] > 0) {
                neighbors += 1;
            } else if (matrix[i - 1][j] < 0) {
                neighbors += -1;
            }
            if (i == 4999) {
                ++count;
            } else if (matrix[i + 1][j] > 0) {
                neighbors += 1;
            } else if (matrix[i + 1][j] < 0) {
                neighbors += -1;
            }
            if (j == 0) {
                ++count;
            } else if (matrix[i][j - 1] > 0) {
                neighbors += 1;
            } else if (matrix[i][j - 1] < 0) {
                neighbors += -1;
            }
            if (j == 4) {
                ++count;
            } else if (matrix[i][j + 1] > 0) {
                neighbors += 1;
            } else if (matrix[i][j + 1] < 0) {
                neighbors += -1;
            }
            unordered_set<int> output;
            if (abs(neighbors) + count == 4 &&
                (matrix[i][j] > 50 || matrix[i][j] < 50)) {
                if (j != M && j != N ||
                    j == M && (matrix[i][j] <= 0 || mapM[matrix[i][j]] >= 50) ||
                    j == N && (matrix[i][j] >= 0 || mapN[matrix[i][j]] <= 10)) {
                    output.insert(matrix[i][j]);
                    if (--P == 0) {
                        found = true;
                        break;
                    }
                }
            }
        }
    }
    for (int num : output) {
        cout << num << endl;
    }
    return 0;
}

int FindOptimal() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    ifstream file;
    file.open("./data.txt");
    unordered_map<int, int> mapM, mapN;
    string line;
    vector<vector<int>> matrix(5000, vector<int>(5));
    unordered_set<int> output;
    int max_M = -1, max_N = -1, res = 0;
    for (int m = 0; m < 5; ++m) {
        for (int n = 0; n < 5; ++n) {
            for (int i = 0; i < 5000; ++i) {
                getline(file, line);
                istringstream iss(line);
                for (int j = 0; j < 5; ++j) {
                    iss >> matrix[i][j];
                }
                ++mapM[matrix[i][m]];
                ++mapN[matrix[i][n]];
            }
            for (int i = 0; i < 5000; ++i) {
                for (int j = 0; j < 5; ++j) {
                    int count = 0, neighbors = 0;
                    if (i == 0) {
                        ++count;
                    } else if (matrix[i - 1][j] > 0) {
                        neighbors += 1;
                    } else if (matrix[i - 1][j] < 0) {
                        neighbors += -1;
                    }
                    if (i == 4999) {
                        ++count;
                    } else if (matrix[i + 1][j] > 0) {
                        neighbors += 1;
                    } else if (matrix[i + 1][j] < 0) {
                        neighbors += -1;
                    }
                    if (j == 0) {
                        ++count;
                    } else if (matrix[i][j - 1] > 0) {
                        neighbors += 1;
                    } else if (matrix[i][j - 1] < 0) {
                        neighbors += -1;
                    }
                    if (j == 4) {
                        ++count;
                    } else if (matrix[i][j + 1] > 0) {
                        neighbors += 1;
                    } else if (matrix[i][j + 1] < 0) {
                        neighbors += -1;
                    }
                    if (abs(neighbors) + count == 4 &&
                        (matrix[i][j] > 50 || matrix[i][j] < 50)) {
                        if (j != m && j != n ||
                            j == m && (matrix[i][j] <= 0 || mapM[matrix[i][j]] >= 50) ||
                            j == n && (matrix[i][j] >= 0 || mapN[matrix[i][j]] <= 10)) {
                            output.insert(matrix[i][j]);
                        }
                    }
                }
            }
            if (output.size() > res) {
                res = output.size();
                max_M = m;
                max_N = n;
            }
            mapM.clear();
            mapN.clear();
            output.clear();
        }
    }
    cout << "Optimal value: M = " << max_M << ", N = " << max_N << endl;
    return 0;
}

int main() {
    creatFile();
    return 0;
}


