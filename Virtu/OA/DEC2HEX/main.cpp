#include <iostream>
#include <sstream>
#include <vector>
#include <cmath>

using namespace std;

int HowManyApples(vector<int> A) {
    sort(A.begin() + 1, A.end());
    int res = 5000 - A.front();
    for (int i = 1; i < A.size(); ++i) {
        if (res < A[i]) {
            return i - 1;
        } else {
            res -= A[i];
        }
    }
}

int closestFibNumber(int X) {
    if (X < 2) {
        return 0;
    }
    double phi = (1 + sqrt(5)) / 2;
    int FibNumber = int(round(log(X * sqrt(5)) / log(phi)));
    cout << FibNumber;
    return abs(FibNumber - X);
}


int solution2(string &S) {
    if (S.empty()) return 0;
    // write your code in C++14 (g++ 6.2.0)
    int res = 0, n = S.size(), count = 1;
    for (int i = 1 ; i < n; ++i) {
        if (S[i] == S[i - 1]) {
            ++count;
        } else {
            res += (count + 1) * count / 2;
            count = 1;
        }
    }
    res += (count + 1) * count / 2;
    return res;
}

vector<int> solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
    int n = A.size();
    bool change = true;
//    vector<int> res;
    while (change) {
        change = false;
        vector<int> temp(n);
        temp[0] = A[0];
        temp.back() = A.back();
        for (int i = 1; i < n - 1; ++i) {
            if (A[i] < A[i + 1] && A[i] < A[i - 1]) {
                temp[i] = A[i] + 1;
                change = true;
            } else if (A[i] > A[i + 1] && A[i] > A[i - 1]) {
                temp[i] = A[i] - 1;
                change = true;
            } else {
                temp[i] = A[i];
            }
        }
        A = move(temp);
    }
    return A;
}

string DEC2HEX(string S) {
    stringstream ss;
    ss << hex << stoi(S);
    string res = ss.str();
    transform(res.begin(), res.end(), res.begin(), toupper);
    for (char& ch : res) {
        if (ch == '0') {
            ch = 'O';
        } else if (ch == '1') {
            ch = 'I';
        } else if (isdigit(ch)) {
            return "ERROR";
        }
    }
    return res;
}

int main() {
//    cout << DEC2HEX("257") << endl;
    closestFibNumber(13);
    return 0;
}