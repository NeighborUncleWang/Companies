#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

int GCD(int a, int b) {
    if (a % b == 0) {
        return b;
    } else {
        return GCD(b, a % b);
    }
}

int LCM(int a, int b) {
    return a * b / GCD(a, b);
}

int FindProcessNotProcessed3(vector<int>& factors, int n) {

}

int FindProcessNotProcessed(vector<int>& factors, int n) {
    int result = 0;
    for (int i = 1; i <= n; ++i) {
        for (int factor : factors) {
            if (i % factor == 0) {
                ++result;
                break;
            }
        }
    }
    return result;
};

int FindProcessNotProcessed2(vector<int>& factors, int n) {
    sort(factors.begin(), factors.end());
    unordered_set<int> set;
    for (int i = 1; i * factors.front() <= n; ++i) {
        for (int factor : factors) {
            int temp = factor * i;
            if (temp <= n) {
                set.insert(temp);
            }
        }
    }
    return n - set.size();
}

int main() {
    vector<int> factors{3, 5};
    cout << FindProcessNotProcessed(factors, 10) << endl;
    cout << FindProcessNotProcessed2(factors, 10) << endl;
    return 0;
}