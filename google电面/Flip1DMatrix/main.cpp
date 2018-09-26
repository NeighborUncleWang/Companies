#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> flipMatrix(int width, int height, vector<int>& matrix) {
        vector<int> result = matrix;
        for (int i = 0; i < height; ++i) {
            reverse(result.begin() + i * width, result.begin() + i * width + width);
        }
        return result;
    }
};


int main() {
    vector<int> matrix{1,2,3,4,5,6,7,8};
    Solution a;
    auto result = a.flipMatrix(4, 2, matrix);
    for (int i : result) {
        cout << i << " ";
    }
    return 0;
}