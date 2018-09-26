#include <iostream>
#include <vector>

using namespace std;

struct Solution {
    int fibBottomUp(int n) {
        vector<int> fibs(n + 1, 1);
        for (int i = 3; i <= n; ++i) {
            fibs[i] = fibs[i - 1] + fibs[i - 2];
        }
        return fibs[n];
    }
    int fibTopDown(int n) {
        vector<int> cache(n + 1, -1);
        cache[1] = 1;
        cache[2] = 1;
        return fibTopDownHelper(n, cache);
    }
    int fibTopDownHelper(int i, vector<int>& cache) {
        if (cache[i] != -1) {
            return cache[i];
        }
        int fib = fibTopDownHelper(i - 1, cache) + fibTopDownHelper(i - 2, cache);
        cache[i] = fib;
        return fib;
    }
};

int main() {
    Solution a;
    cout << a.fibBottomUp(6) << endl;
    cout << a.fibTopDown(6) << endl;
    return 0;
}