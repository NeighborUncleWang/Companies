#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>

using namespace std;



int func(int n) {
    vector<int> dp(n + 1, 0);
    iota(dp.begin(), dp.begin() + 7, 0);
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i - 3; ++j) {
            dp[i] = max(dp[i], dp[j] * (i - j - 1));
        }
    }
    return dp.back();
}








//int func(int n) {
//    vector<int> dp(n + 1, 0);
//    iota(dp.begin(), dp.begin() + 7, 0);
//    for (int i = 7; i <= n; ++i) {
//        for (int j = i - 3; j >= 1; --j) {
//            dp[i] = max(dp[i], dp[j] * (i - j - 1));
//        }
//    }
//    return dp.back();
//}

int main() {
    for (int i = 10; i <= 20; ++i) {
        cout << i << " " << func(i) << endl;
    }
    cout << func(36);
    return 0;
}