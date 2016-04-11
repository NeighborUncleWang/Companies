#include <iostream>

using namespace std;

int compareTwoString(string s1, string s2) {
    int size1 = s1.size();
    int size2 = s2.size();
    int i1 = 0;
    int i2 = 0;
    while (i1 < size1 && i2 < size2) {
        if (isalpha(s1[i1]) && isalpha(s2[i2])) {
            if (s1[i1] < s2[i2]) return -1;
            if (s1[i1] > s2[i2]) return 1;
            ++i1;
            ++i2;
        } else if (isdigit(s1[i1]) && isdigit(s2[i2])) {
            int num1 = 0;
            while (i1 < size1 && isdigit(s1[i1])) {
                num1 = num1 * 10 + s1[i1] - '0';
                ++i1;
            }
            int num2 = 0;
            while (i2 < size2 && isdigit(s2[i2])) {
                num2 = num2 * 10 + s2[i2] - '0';
                ++i2;
            }
            if (num1 < num2) return -1;
            if (num2 < num1) return 1;
        } else if (isdigit(s1[i1])) {
            return -1;
        } else {
            return 1;
        }
    }
    if (i1 == size1 && i2 == size2) {
        return 0;
    } else if (i1 == size1) {
        return -1;
    } else {
        return 1;
    }
}


int main() {
    cout << compareTwoString("abc9", "abc001") << endl;
    return 0;
}