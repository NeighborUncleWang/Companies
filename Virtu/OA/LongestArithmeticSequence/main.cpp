#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int LongestArithmeticSequence(vector<int> nums) {
    sort(nums.begin(), nums.end());
    int n = nums.size(), res = 0;
    vector<vector<int>> dp(n, vector<int>(n, 2));
    for (int j = n - 2; j >= 0; --j) {
        int i = j - 1, k = j + 1;
        while (i >= 0 && k < n) {
            if (nums[i] + nums[k] == nums[j] * 2) {
                dp[i][j] = dp[j][k] + 1;
                res = max(dp[i][j], res);
                --i;
                ++k;
            } else if (nums[i] + nums[k] < nums[j] * 2) {
                ++k;
            } else {
                --i;
            }
        }
    }
    return res;
}

const double phi = (1 + sqrt(5)) / 2;

int fib(int n) {
    return (pow(phi, n) - pow(1 - phi, n)) / sqrt(5);
}

int closestFibNumber(int X) {
    if (X < 2) {
        return 0;
    }

    int FibNumber = int(round(log(X * sqrt(5)) / log(phi)));
    cout << FibNumber << endl;
    return abs(FibNumber - X);
}

int closestFibNumber2(int X) {
    if (X < 2) {
        return 0;
    }
    int low = 1, high = 32;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (fib(mid) <= X) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    int fib1 = fib(low);
    int fib2 = fib(high);
    return min(abs(fib1 - X), abs(fib2 - X));
}

int main() {
    cout << fib(3) << endl;
//    cout << closestFibNumber(12) << endl;
//    cout << closestFibNumber2(12) << endl;
    return 0;
}