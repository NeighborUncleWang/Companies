#include <iostream>
#include <vector>

using namespace std;

int strStr(vector<string>& haystack, string needle) {
    for (int i = 0, total = 0; i < haystack.size(); ++i) {
        for (int j = 0; j < haystack[i].size(); ++j) {
            int k = 0;
            int positionI = i;
            int positionJ = j;
            while (positionI < haystack.size() && positionJ < haystack[positionI].size()
                    && k < needle.size() && haystack[positionI][positionJ] == needle[k]) {
                ++k;
                ++positionJ;
                if (positionJ == haystack[positionI].size()) {
                    positionJ = 0;
                    ++positionI;
                }
            }
            if (k == needle.size()) {
                return total + j;
            }
        }
        total += haystack[i].size();
    }
    return -1;
}


int main() {
    vector<string> haystack = {"abcc", "cbd"};
    cout << strStr(haystack, "ccbd") << endl;
    cout << strStr(haystack, "bd") << endl;
    return 0;
}